#include "fidelite.h"

FideliteManager::FideliteManager()
{
    // Constructeur - initialisation si nécessaire
}

void FideliteManager::analyserClients(const QVector<QVector<QString>>& clientsData)
{
    pointsParClient.clear();
    nomsClients.clear();
    regionsClients.clear();
    QMap<QString, int> repetitions;

    for (const auto& client : clientsData) {
        if (client.size() < 5) continue;

        int id = client[0].toInt();
        QString cle = client[1] + "|" + client[2] + "|" + client[3];

        // Stocker les infos client
        nomsClients[id] = client[1] + " " + client[2];
        regionsClients[id] = client[3];

        repetitions[cle]++;
    }

    for (const auto& client : clientsData) {
        if (client.size() < 5) continue;

        int id = client[0].toInt();
        QString cle = client[1] + "|" + client[2] + "|" + client[3];
        pointsParClient[id] = repetitions[cle] * 5;
    }
}



void FideliteManager::resetCompteurs()
{
    pointsParClient.clear();
}
QVector<FideliteManager::ScoreFidelite> FideliteManager::getScoresFidelite() const
{
    QVector<ScoreFidelite> result;

    for (auto it = pointsParClient.begin(); it != pointsParClient.end(); ++it) {
        int id = it.key();
        result.append({
            id,
            nomsClients.value(id, "Inconnu"),
            regionsClients.value(id, "Inconnue"),
            it.value()
        });
    }

    return result;
}
