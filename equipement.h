#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class equipement
{
    QString nom,type,caracteristiques,code_barre;
    QDate datedachat;
    int id,quantite,budget;

public:
        equipement(){}
        equipement(QString nom, int quantite, QString type, QDate datedachat, int budget, QString caracteristiques);



        QString getNom(){return nom;}
        QString getType(){return type;}
        QDate getDatedachat(){return datedachat;}
        QString  getCaracteristiques(){return caracteristiques;}
        QString  getCode_barre(){return code_barre;}

        int getQuantité(){return quantite;}
        int getBudget(){return budget;}

        void setNom(QString n){nom=n;}
        void setType(QString p){type=p;}
        void setCaracteristiques(QString j){caracteristiques =j;}
        void setCode_barre(QString c){code_barre =c;}
        void setDatedachat(QDate k){datedachat=k;}
        void setQuantité(int quantité){this->quantite=quantité;}
        void setBudget(int budget){this->budget=budget;}




        bool ajouter();
        QSqlQueryModel *afficher();
        bool supprimer(int);
        bool modifier(int id, QString nom, int quantite, QString type, QDate datedachat, int budget, QString caracteristiques);
    private:



        QString code_barre_path;


};

#endif // EQUIPEMENT_H
