#include "equipement.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QSqlError>
#include "equipement.h"
#include <QDate>
#include <mainwindow.cpp>


equipement::equipement(QString nom, int quantite, QString type, QDate datedachat, int budget, QString caracteristiques) {

    this->nom = nom;
    this->quantite = quantite;
    this->type = type;
    this->datedachat = datedachat;
    this->budget = budget;
    this->caracteristiques = caracteristiques;
    this->code_barre = QString("Nom: %1\nType: %2\nQuantité: %3\nDate Achat: %4\nBudget: %5\nCaractéristiques: %6")
                           .arg(nom)
                           .arg(type)
                           .arg(quantite)
                           .arg(datedachat.toString("dd/MM/yyyy"))
                           .arg(budget)
                           .arg(caracteristiques);




}
// equipement.cpp

QImage drawCode39Barcode(const QString &data, int width = 400, int height = 100) {
    QMap<QChar, QString> code39Map = {
        {'0',"101001101101"}, {'1',"110100101011"}, {'2',"101100101011"},
        {'3',"110110010101"}, {'4',"101001101011"}, {'5',"110100110101"},
        {'6',"101100110101"}, {'7',"101001011011"}, {'8',"110100101101"},
        {'9',"101100101101"}, {'A',"110101001011"}, {'B',"101101001011"},
        {'C',"110110100101"}, {'D',"101011001011"}, {'E',"110101100101"},
        {'F',"101101100101"}, {'G',"101010011011"}, {'H',"110101001101"},
        {'I',"101101001101"}, {'J',"101011001101"}, {'K',"110101010011"},
        {'L',"101101010011"}, {'M',"110110101001"}, {'N',"101011010011"},
        {'O',"110101101001"}, {'P',"101101101001"}, {'Q',"101010110011"},
        {'R',"110101011001"}, {'S',"101101011001"}, {'T',"101011011001"},
        {'U',"110010101011"}, {'V',"100110101011"}, {'W',"110011010101"},
        {'X',"100101101011"}, {'Y',"110010110101"}, {'Z',"100110110101"},
        {'-',"100101011011"}, {'.',"110010101101"}, {' ',"100110101101"},
        {'$',"100100100101"}, {'/',"100100101001"}, {'+',"100101001001"},
        {'%',"101001001001"}, {'*',"100101101101"}
    };

    QString encoded = "*";
    for (QChar ch : data.toUpper()) {
        if (code39Map.contains(ch))
            encoded += ch;
    }
    encoded += "*";

    QString bars;
    for (int i = 0; i < encoded.length(); ++i) {
        bars += code39Map.value(encoded[i]) + "0"; // inter-character gap
    }

    QImage image(width, height, QImage::Format_RGB32);
    image.fill(Qt::white);
    QPainter painter(&image);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);

    int x = 10;
    int barWidth = 2;
    for (int i = 0; i < bars.length(); ++i) {
        if (bars[i] == '1') {
            painter.drawRect(x, 0, barWidth, height);
        }
        x += barWidth;
    }

    return image;
}

bool equipement::ajouter() {
    QSqlQuery query;

    // Générer le contenu du code-barres (exemple : nom + type)
    QString contenu_code = QString("NOM=%1/QTE=%2/TYPE=%3/DATE=%4/BUDGET=%5/CARAC=%6")
                               .arg(nom)
                               .arg(quantite)
                               .arg(type)
                               .arg(datedachat.toString("ddMMyyyy"))
                               .arg(budget)
                               .arg(caracteristiques);

    // Nettoyage : enlever accents, mettre en majuscules, retirer caractères non autorisés
    contenu_code = contenu_code.toUpper();
    contenu_code.remove(QRegularExpression("[^A-Z0-9\\.\\- /]")); // conserve que caractères Code 39 valides


    QImage barcodeImage = drawCode39Barcode(contenu_code);


    // Sauvegarder l’image
    QString dossier = QDir::currentPath() + "/codebarres";
    QDir().mkpath(dossier);
    code_barre_path = dossier + QString("/barcode_%1.png").arg(nom);
    barcodeImage.save(code_barre_path);

    // Insertion SQL avec l'image du code-barres
    query.prepare("INSERT INTO EQUIPEMENT (NOM, QUANTITE, TYPE, DATEDACHAT, BUDGET, CARACTERISTIQUES, CODE_BARRE, CODE_BARRE_PATH) "
                  "VALUES (:nom, :quantite, :type, :datedachat, :budget, :caracteristiques, :code_barre, :code_barre_path)");

    query.bindValue(":nom", nom);
    query.bindValue(":quantite", quantite);
    query.bindValue(":type", type);
    query.bindValue(":datedachat", datedachat);
    query.bindValue(":budget", budget);
    query.bindValue(":caracteristiques", caracteristiques);
    query.bindValue(":code_barre", contenu_code);
    query.bindValue(":code_barre_path", code_barre_path);

    if (!query.exec()) {
        qDebug() << "❌ Erreur insertion :" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Équipement ajouté avec code-barres : " << contenu_code;
    return true;
}




bool equipement::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM EQUIPEMENT WHERE ID_EQUIPEMENT = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "❌ Erreur de suppression : " << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Suppression réussie de l'équipement avec ID :" << id;
    return true;

}
QSqlQueryModel* equipement::afficher() {
    // Création d'un modèle pour la requête SQL
    QSqlQueryModel* model = new QSqlQueryModel();

    // Exécution de la requête SQL pour récupérer toutes les lignes de la table EQUIPEMENT
    model->setQuery("SELECT * FROM EQUIPEMENT");

    // Vérification si la requête a échoué
    if (model->lastError().isValid()) {
        qDebug() << "Erreur de la requête : " << model->lastError().text();
        return nullptr;  // Retourne nullptr en cas d'erreur
    }

    // Définir les en-têtes des colonnes (optionnel mais utile pour avoir des titres visibles)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQUIPEMENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEDACHAT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("BUDGET"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("CARACTERISTIQUES"));

    return model;  // Retourne le modèle avec les données récupérées
}
bool equipement::modifier(int id, QString nom, int quantite, QString type, QDate datedachat, int budget, QString caracteristiques) {
    QSqlQuery query;
    query.prepare("UPDATE EQUIPEMENT SET NOM = :nom, QUANTITE = :quantite, TYPE = :type, "
                  "DATEDACHAT = :datedachat, BUDGET = :budget, CARACTERISTIQUES = :caracteristiques "
                  "WHERE ID_EQUIPEMENT = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":quantite", quantite);
    query.bindValue(":type", type);
    query.bindValue(":datedachat", datedachat);
    query.bindValue(":budget", budget);
    query.bindValue(":caracteristiques", caracteristiques);

    if (!query.exec()) {
        qDebug() << "❌ Erreur de mise à jour :" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Mise à jour réussie !";
    return true;
}

