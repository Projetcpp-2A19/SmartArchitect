#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class equipement
{
    QString nom,type,caracteristiques;
    QDate datedachat;
    int id,quantite,budget;

public:
        equipement(){}
        equipement(QString nom, int quantite, QString type, QDate datedachat, int budget, QString caracteristiques);


        QString getNom(){return nom;}
        QString getType(){return type;}
        QDate getDatedachat(){return datedachat;}
        QString  getCaracteristiques(){return caracteristiques;}

        int getQuantité(){return quantite;}
        int getBudget(){return budget;}

        void setNom(QString n){nom=n;}
        void setType(QString p){type=p;}
        void setCaracteristiques(QString j){caracteristiques =j;}
        void setDatedachat(QDate k){datedachat=k;}
        void setQuantité(int quantité){this->quantite=quantité;}
        void setBudget(int budget){this->budget=budget;}




        bool ajouter();
        QSqlQueryModel *afficher();
        bool supprimer(int);
        bool modifier(int id, QString nom, int quantite, QString type, QDate datedachat, int budget, QString caracteristiques);

};

#endif // EQUIPEMENT_H
