#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QRegularExpression>


class Employee
{
public:
    Employee();
    Employee(int ID_EMPLOYE, QString NOM, QString PRENOM, QString EMAIL, QString MDP,
             QString POSTE, QString SALAIRE, QString DATEEMBOCHE );

    bool ajouterEmploye();
    bool modifierEmploye(int ID_EMPLOYE, const QString &nom, const QString &email);
    bool updateEmployee(int id, const QString &nom, const QString &prenom,
                        const QString &email, const QString &mdp,
                        const QString &poste, const QString &salaire,
                        const QString &dateEmbauche);
    // bool modifierEmploye();
    bool supprimerEmploye(int ID_EMPLOYE);
    QSqlQueryModel *afficherEmployes();
    QSqlQueryModel*trierEmployesParSalaireCroissant();
    QSqlQueryModel* rechercherEmployee(const QString &idOuNom);
    QMap<QString, int> getStatsByPoste();
private:
    int ID_EMPLOYE;
    QString NOM, PRENOM, EMAIL, MDP, POSTE,SALAIRE, DATEEMBOCHE;
    //double SALAIRE;
};

#endif // EMPLOYEE_H


