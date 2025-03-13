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
    Employee(int IDEMPLOYEE, QString NOM, QString PRENOM, QString EMAIL, QString MDP,
             QString POSTE, QString SALAIRE, QString DATEEMBOCHE );

    bool ajouterEmploye();
    bool modifierEmploye(int IDEMPLYEE, const QString &nom, const QString &email);
    bool updateEmployee(int id, const QString &nom, const QString &prenom,
                        const QString &email, const QString &poste,
                        const QString &salaire, const QString &dateEmbauche);
    // bool modifierEmploye();
    bool supprimerEmploye(int IDEMPLYEE);
    QSqlQueryModel *afficherEmployes();

private:
    int IDEMPLYEE;
    QString NOM, PRENOM, EMAIL, MDP, POSTE,SALAIRE, DATEEMBOCHE;
    //double SALAIRE;
};

#endif // EMPLOYEE_H


