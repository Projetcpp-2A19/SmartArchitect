#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QMap>

class Client
{
public:
    // Constructors
    Client();
    Client(QString nom, QString prenom, QString region, QString telephone, QString email);
    Client(int id, QString nom, QString prenom, QString region, QString telephone, QString email);

    // CRUD Operations
    bool ajouter();
    bool ajouterManualId();
    bool modifier(int id);
    bool supprimer(int id);

    // Query Operations
    static QSqlQueryModel* afficher();
    static Client recupererClient(int id);
    static QSqlQueryModel* chercherParNom(QString nom);
    static void afficherDansTableWidget(QTableWidget *tableWidget);
    static void afficherTrieDansTableWidget(QTableWidget *tableWidget, bool ascending);
    static QMap<QString, int> getStatsByRegion();

    // Utility
    static bool exporterPDF(const QString &filePath);
    QString getLastError() const;

    // Getters
    int getId() const { return id; }
    QString getNom() const { return nom; }
    QString getPrenom() const { return prenom; }
    QString getRegion() const { return region; }
    QString getTelephone() const { return telephone; }
    QString getEmail() const { return email; }

private:
    int id;
    QString nom;
    QString prenom;
    QString region;
    QString telephone;
    QString email;
    QString lastError;
};

#endif // CLIENT_H
