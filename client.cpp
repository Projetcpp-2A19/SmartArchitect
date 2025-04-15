#include "client.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QRegularExpression>
#include <QObject>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QPageSize>
#include <QFileDialog>
#include <QMessageBox>
Client::Client() : id(0) {}

Client::Client(QString nom, QString prenom, QString region, QString telephone, QString email) :
    id(0), nom(nom), prenom(prenom), region(region), telephone(telephone), email(email) {}

Client::Client(int id, QString nom, QString prenom, QString region, QString telephone, QString email) :
    id(id), nom(nom), prenom(prenom), region(region), telephone(telephone), email(email) {}

bool Client::ajouter() {
    QSqlQuery query;

    query.prepare("INSERT INTO clients (id, nom, prenom, region, telephone, email) "
                  "VALUES (client_seq.NEXTVAL, ?, ?, ?, ?, ?)");

    query.addBindValue(nom);
    query.addBindValue(prenom);
    query.addBindValue(region);
    query.addBindValue(telephone);
    query.addBindValue(email);

    if (!query.exec()) {
        lastError = query.lastError().text();  // Stocke l'erreur SQL pour l'affichage
        qDebug() << "Erreur lors de l'insertion :" << lastError;
        return false;
    }

    return true;
}


QString Client::getLastError() const {
    return lastError;
}


bool Client::modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE clients SET NOM=:nom, PRENOM=:prenom, REGION=:region, "
                  "TELEPHONE=:telephone, EMAIL=:email WHERE ID=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":region", region);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);

    return query.exec();
}

bool Client::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM clients WHERE ID=:id");
    query.bindValue(":id", id);
    return query.exec();
}

QSqlQueryModel *Client::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM clients");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Région"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));

    return model;
}

Client Client::recupererClient(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM clients WHERE ID=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return Client(
            query.value("ID").toInt(),
            query.value("NOM").toString(),
            query.value("PRENOM").toString(),
            query.value("REGION").toString(),
            query.value("TELEPHONE").toString(),
            query.value("EMAIL").toString()
            );
    }
    return Client();
}

QSqlQueryModel *Client::chercherParNom(QString nom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM clients WHERE NOM LIKE :nom");
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
void Client::afficherDansTableWidget(QTableWidget *tableWidget)
{
    tableWidget->clearContents();
    tableWidget->setRowCount(0); // Réinitialise

    QSqlQuery query("SELECT * FROM clients");
    int row = 0;
    while (query.next()) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID").toString()));
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("PRENOM").toString()));
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("REGION").toString()));
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("TELEPHONE").toString()));
        tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("EMAIL").toString()));
        row++;
    }
}
bool Client::exporterPDF(const QString &filePath)
{
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageOrientation(QPageLayout::Landscape);
    writer.setPageMargins(QMarginsF(10, 10, 10, 10)); // Marges minimes

    QPainter painter(&writer);
    if (!painter.isActive()) return false;

    // Dimensions du PDF
    const int pdfWidth = writer.width();
    const int pdfHeight = writer.height();

    // Réserver de l'espace pour le titre et le pied de page
    const int titleHeight = 300;  // Réduction pour agrandir le tableau
    const int footerHeight = 200;  // Réduction du pied de page

    // Définir la zone disponible pour le tableau
    const int tableWidth = pdfWidth - 100;  // Largeur max optimisée
    const int tableHeight = pdfHeight - titleHeight - footerHeight; // Hauteur max disponible

    // Configuration des colonnes (mieux équilibrées)
    const QStringList headers = {"ID", "NOM", "PRENOM", "REGION", "TELEPHONE", "EMAIL"};
    const QVector<int> colWidths = {
        static_cast<int>(tableWidth * 0.12),  // ID (un peu plus large)
        static_cast<int>(tableWidth * 0.20),  // NOM
        static_cast<int>(tableWidth * 0.20),  // PRENOM
        static_cast<int>(tableWidth * 0.16),  // REGION
        static_cast<int>(tableWidth * 0.16),  // TELEPHONE
        static_cast<int>(tableWidth * 0.16)   // EMAIL
    };

    // Ajustement de la hauteur des lignes
    const int headerHeight = 60; // Plus grand pour meilleure lisibilité
    const int rowHeight = (tableHeight - headerHeight) / 15;  // Ajusté

    // --- Titre ---
    painter.setFont(QFont("Arial", 16, QFont::Bold));
    painter.drawText(0, 50, pdfWidth, titleHeight, Qt::AlignCenter, "LISTE DES CLIENTS");

    // --- En-tête du tableau ---
    int xPos = 20, yPos = titleHeight + 20;
    painter.setFont(QFont("Arial", 13, QFont::Bold)); // Police plus grande
    painter.setBrush(QColor(200, 220, 255));

    for (int i = 0; i < headers.size(); ++i) {
        painter.drawRect(xPos, yPos, colWidths[i], headerHeight);
        painter.drawText(xPos, yPos, colWidths[i], headerHeight, Qt::AlignCenter, headers[i]);
        xPos += colWidths[i];
    }
    yPos += headerHeight;
    painter.setBrush(Qt::NoBrush);

    // --- Données du tableau ---
    painter.setFont(QFont("Arial", 11));
    QSqlQuery query("SELECT * FROM clients ORDER BY NOM, PRENOM");

    int rowCount = 0;
    while (query.next() && rowCount < 15) {  // Max 15 lignes sur la page
        xPos = 20;
        const QStringList fields = {
            query.value("ID").toString(),
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

    // --- Pied de page ---
    painter.setFont(QFont("Arial", 9));
    painter.drawText(0, pdfHeight - footerHeight, pdfWidth, footerHeight,
                     Qt::AlignRight | Qt::AlignVCenter,
                     QString("Généré le %1").arg(QDate::currentDate().toString("dd/MM/yyyy")));

    painter.end();
    return true;
}
void Client::afficherTrieDansTableWidget(QTableWidget *tableWidget, bool ascending)
{
    tableWidget->clearContents();
    tableWidget->setRowCount(0);

    QSqlQuery query;
    query.prepare("SELECT * FROM clients ORDER BY NOM " + QString(ascending ? "ASC" : "DESC"));

    if (query.exec()) {
        int row = 0;
        while (query.next()) {
            tableWidget->insertRow(row);
            tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID").toString()));
            tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
            tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("PRENOM").toString()));
            tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("REGION").toString()));
            tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("TELEPHONE").toString()));
            tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("EMAIL").toString()));
            row++;
        }
    }
}
QMap<QString, int> Client::getStatsByRegion()
{
    QMap<QString, int> stats;
    QSqlQuery query("SELECT REGION, COUNT(*) as count FROM clients GROUP BY REGION");

    while (query.next()) {
        QString region = query.value("REGION").toString();
        int count = query.value("count").toInt();
        stats.insert(region, count);
    }

    return stats;
}
