#ifndef CARTEFIDELITEDIALOG_H
#define CARTEFIDELITEDIALOG_H

#include <QDialog>
#include <QPixmap>
#include <QDate>

class CarteFideliteDialog : public QDialog
{
    Q_OBJECT

public:
    CarteFideliteDialog(int clientId, const QString& nom, int score, QWidget *parent = nullptr);
    QPixmap generateQRCode(const QString &data);

private:
    int m_clientId;
    QString m_nom;
    int m_score;
    QPixmap m_logo;

    void setupUI();
};

#endif // CARTEFIDELITEDIALOG_H
