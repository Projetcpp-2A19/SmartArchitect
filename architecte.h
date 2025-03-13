#ifndef ARCHITECTE_H
#define ARCHITECTE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class architecte
{
private:
    int id, telephone;  // Déplacer les int en premier
    QString nom, prenom, email, experience;


public:
    // Constructeurs
    architecte() : id(0), telephone(0), nom(""), prenom(""), email(""), experience("") {}


    architecte(int, QString, QString, int, QString, QString);

    // Getters
    QString getName() const { return nom; }
    QString getPrenom() const { return prenom; }
    QString getEmail() const { return email; }
    QString getExperience() const { return experience; }
    int getTelephone() const { return telephone; }
    int getID() const { return id; }

    // Setters
    void setName(const QString &n) { nom = n; }
    void setPrenom(const QString &p) { prenom = p; }
    void setEmail(const QString &e) { email = e; }
    void setExperience(const QString &ex) { experience = ex; }
    void setTelephone(int t) { telephone = t; }
    void setID(int i) { id = i; }

    // Fonctions CRUD pour l'entité Architecte
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* searchByName(const QString& name);
    QSqlQueryModel* trierParNom();


    bool supprimer(int);
    bool mettreAJour();
    bool genererPDF(int id);



    // Destructeur
    ~architecte() {}
};

#endif // ARCHITECTE_H
