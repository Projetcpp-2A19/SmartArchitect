#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQueryModel>
#include <QTableWidget>

class Client
{
public:
    Client();
    Client(QString nom, QString prenom, QString region, QString telephone, QString email);
    Client(int id, QString nom, QString prenom, QString region, QString telephone, QString email);

    // Getters
    int getId() const { return id; }
    QString getNom() const { return nom; }
    QString getPrenom() const { return prenom; }
    QString getRegion() const { return region; }
    QString getTelephone() const { return telephone; }
    QString getEmail() const { return email; }

    // Setters
    void setId(int id) { this->id = id; }
    void setNom(const QString &nom) { this->nom = nom; }
    void setPrenom(const QString &prenom) { this->prenom = prenom; }
    void setRegion(const QString &region) { this->region = region; }
    void setTelephone(const QString &telephone) { this->telephone = telephone; }
    void setEmail(const QString &email) { this->email = email; }

    // CRUD
    bool ajouter();
    bool modifier(int id);
    bool supprimer(int id);
    QSqlQueryModel *afficher();
    Client recupererClient(int id);

    // Affichage tableWidget
    void afficherDansTableWidget(QTableWidget *tableWidget);

private:
    int id;
    QString nom, prenom, region, telephone, email;
};

#endif // CLIENT_H
