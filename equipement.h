#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QString>
#include <QDate>
#include <QImage>
#include <QSqlQueryModel>

class equipement {
public:
    equipement();
    equipement(int id, QString nom, int quantite, QString type, QDate datedachat, int budget, QString caracteristiques);
    bool ajouter();
    bool supprimer(int id);
    QSqlQueryModel* afficher();
    bool modifier();
    void setCode_barre(const QString &code) { code_barre = code; }

private:
    int id_equipement;
    QString nom;
    int quantite;
    QString type;
    QDate datedachat;
    int budget;
    QString caracteristiques;
    QString code_barre;
    QString code_barre_path;
};

QImage drawCode39Barcode(const QString &data, int width = 400, int height = 100);

#endif // EQUIPEMENT_H
