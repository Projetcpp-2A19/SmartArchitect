#ifndef FIDELITE_H
#define FIDELITE_H

#include <QMap>
#include <QString>
#include <QVector>

class FideliteManager
{
public:
    struct ScoreFidelite {
        int id;
        QString nomComplet;
        QString region;
        int score;
    };

    FideliteManager();
    void analyserClients(const QVector<QVector<QString>>& clientsData);
    QVector<ScoreFidelite> getScoresFidelite() const; // Nouvelle méthode
    int getPoints(int clientId) const;
    void resetCompteurs();


private:
    QMap<int, int> pointsParClient;
    QMap<int, QString> nomsClients;  // Pour stocker nom+prenom
    QMap<int, QString> regionsClients; // Pour stocker la région

};

#endif // FIDELITE_H
