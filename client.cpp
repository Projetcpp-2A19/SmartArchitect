#include "client.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QRegularExpression>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QPageSize>
#include <QFileDialog>
#include <QMessageBox>
#include <QUuid>

Client::Client() : id(0) {}

Client::Client(QString nom, QString prenom, QString region, QString telephone, QString email) :
    id(0), nom(nom), prenom(prenom), region(region), telephone(telephone), email(email) {}

Client::Client(int id, QString nom, QString prenom, QString region, QString telephone, QString email) :
    id(id), nom(nom), prenom(prenom), region(region), telephone(telephone), email(email) {}

bool Client::ajouter() {
    QSqlQuery query;

    // Get the next available ID
    if (!query.exec("SELECT NVL(MAX(ID_CLIENT), 0) + 1 FROM CLIENTS")) {
        lastError = "Failed to get next ID: " + query.lastError().text();
        return false;
    }

    if (!query.next()) {
        lastError = "No ID returned from query";
        return false;
    }

    int newId = query.value(0).toInt();

    // Insert with the generated ID
    query.prepare("INSERT INTO CLIENTS (ID_CLIENT, NOM, PRENOM, REGION, TELEPHONE, EMAIL) "
                  "VALUES (:id, :nom, :prenom, :region, :telephone, :email)");

    query.bindValue(":id", newId);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":region", region);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }

    this->id = newId;
    return true;
}

bool Client::ajouterManualId() {
    QSqlQuery query;

    // Get max existing ID + 1
    if (!query.exec("SELECT NVL(MAX(ID_CLIENT), 0) + 1 FROM clients")) {
        lastError = "Failed to get max ID: " + query.lastError().text();
        return false;
    }

    if (!query.next()) {
        lastError = "No max ID returned";
        return false;
    }

    int newId = query.value(0).toInt();

    // Insert with calculated ID
    query.prepare("INSERT INTO clients (ID_CLIENT, NOM, PRENOM, REGION, TELEPHONE, EMAIL) "
                  "VALUES (:id, :nom, :prenom, :region, :telephone, :email)");

    query.bindValue(":id", newId);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":region", region);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }

    this->id = newId;
    return true;
}

bool Client::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE clients SET NOM=:nom, PRENOM=:prenom, REGION=:region, "
                  "TELEPHONE=:telephone, EMAIL=:email WHERE ID_CLIENT=:id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":region", region);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}

bool Client::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM clients WHERE ID_CLIENT=:id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        lastError = query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}

QSqlQueryModel* Client::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_CLIENT, NOM, PRENOM, REGION, TELEPHONE, EMAIL FROM clients");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Région"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));

    return model;
}

Client Client::recupererClient(int id) {
    QSqlQuery query;
    query.prepare("SELECT ID_CLIENT, NOM, PRENOM, REGION, TELEPHONE, EMAIL FROM clients WHERE ID_CLIENT=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return Client(
            query.value("ID_CLIENT").toInt(),
            query.value("NOM").toString(),
            query.value("PRENOM").toString(),
            query.value("REGION").toString(),
            query.value("TELEPHONE").toString(),
            query.value("EMAIL").toString()
            );
    }
    return Client();
}

QSqlQueryModel* Client::chercherParNom(QString nom) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID_CLIENT, NOM, PRENOM, REGION, TELEPHONE, EMAIL FROM clients WHERE NOM LIKE :nom");
    query.bindValue(":nom", "%" + nom + "%");

    if (query.exec()) {
        model->setQuery(std::move(query));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Région"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Téléphone"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
    } else {
        qDebug() << "Erreur SQL : " << query.lastError().text();
        delete model;
        return nullptr;
    }
    return model;
}

void Client::afficherDansTableWidget(QTableWidget *tableWidget) {
    tableWidget->clearContents();
    tableWidget->setRowCount(0);

    QSqlQuery query("SELECT ID_CLIENT, NOM, PRENOM, REGION, TELEPHONE, EMAIL FROM clients");
    int row = 0;
    while (query.next()) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID_CLIENT").toString()));
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("PRENOM").toString()));
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("REGION").toString()));
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("TELEPHONE").toString()));
        tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("EMAIL").toString()));
        row++;
    }
}

bool Client::exporterPDF(const QString &filePath) {
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageOrientation(QPageLayout::Landscape);
    writer.setPageMargins(QMarginsF(10, 10, 10, 10));

    QPainter painter(&writer);
    if (!painter.isActive()) return false;

    const int pdfWidth = writer.width();
    const int pdfHeight = writer.height();
    const int titleHeight = 300;
    const int footerHeight = 200;
    const int tableWidth = pdfWidth - 100;
    const int tableHeight = pdfHeight - titleHeight - footerHeight;

    const QStringList headers = {"ID", "NOM", "PRENOM", "REGION", "TELEPHONE", "EMAIL"};
    const QVector<int> colWidths = {
        static_cast<int>(tableWidth * 0.12),
        static_cast<int>(tableWidth * 0.20),
        static_cast<int>(tableWidth * 0.20),
        static_cast<int>(tableWidth * 0.16),
        static_cast<int>(tableWidth * 0.16),
        static_cast<int>(tableWidth * 0.16)
    };

    const int headerHeight = 60;
    const int rowHeight = (tableHeight - headerHeight) / 15;

    painter.setFont(QFont("Arial", 16, QFont::Bold));
    painter.drawText(0, 50, pdfWidth, titleHeight, Qt::AlignCenter, "LISTE DES CLIENTS");

    int xPos = 20, yPos = titleHeight + 20;
    painter.setFont(QFont("Arial", 13, QFont::Bold));
    painter.setBrush(QColor(200, 220, 255));

    for (int i = 0; i < headers.size(); ++i) {
        painter.drawRect(xPos, yPos, colWidths[i], headerHeight);
        painter.drawText(xPos, yPos, colWidths[i], headerHeight, Qt::AlignCenter, headers[i]);
        xPos += colWidths[i];
    }
    yPos += headerHeight;
    painter.setBrush(Qt::NoBrush);

    painter.setFont(QFont("Arial", 11));
    QSqlQuery query("SELECT ID_CLIENT, NOM, PRENOM, REGION, TELEPHONE, EMAIL FROM clients ORDER BY NOM, PRENOM");

    int rowCount = 0;
    while (query.next() && rowCount < 15) {
        xPos = 20;
        const QStringList fields = {
            query.value("ID_CLIENT").toString(),
            query.value("NOM").toString(),
            query.value("PRENOM").toString(),
            query.value("REGION").toString(),
            query.value("TELEPHONE").toString(),
            query.value("EMAIL").toString()
        };

        for (int i = 0; i < fields.size(); ++i) {
            painter.drawRect(xPos, yPos, colWidths[i], rowHeight);
            QTextOption align;
            align.setAlignment(i == 0 ? Qt::AlignCenter : Qt::AlignLeft | Qt::AlignVCenter);
            painter.drawText(QRect(xPos + 3, yPos + 3, colWidths[i] - 6, rowHeight - 6), fields[i], align);
            xPos += colWidths[i];
        }
        yPos += rowHeight;
        rowCount++;
    }

    painter.setFont(QFont("Arial", 9));
    painter.drawText(0, pdfHeight - footerHeight, pdfWidth, footerHeight,
                     Qt::AlignRight | Qt::AlignVCenter,
                     QString("Généré le %1").arg(QDate::currentDate().toString("dd/MM/yyyy")));

    painter.end();
    return true;
}

void Client::afficherTrieDansTableWidget(QTableWidget *tableWidget, bool ascending) {
    tableWidget->clearContents();
    tableWidget->setRowCount(0);

    QSqlQuery query;
    query.prepare("SELECT ID_CLIENT, NOM, PRENOM, REGION, TELEPHONE, EMAIL FROM clients ORDER BY NOM " + QString(ascending ? "ASC" : "DESC"));

    if (query.exec()) {
        int row = 0;
        while (query.next()) {
            tableWidget->insertRow(row);
            tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID_CLIENT").toString()));
            tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
            tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("PRENOM").toString()));
            tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("REGION").toString()));
            tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("TELEPHONE").toString()));
            tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("EMAIL").toString()));
            row++;
        }
    }
}

QMap<QString, int> Client::getStatsByRegion() {
    QMap<QString, int> stats;
    QSqlQuery query("SELECT REGION, COUNT(*) as count FROM clients GROUP BY REGION");

    while (query.next()) {
        QString region = query.value("REGION").toString();
        int count = query.value("count").toInt();
        stats.insert(region, count);
    }
    return stats;
}

QString Client::getLastError() const {
    return lastError;
}
