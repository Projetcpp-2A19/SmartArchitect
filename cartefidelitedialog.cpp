#include "carteFideliteDialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPainter>
#include <QDate>
#include <QImage>
#include <QBuffer>
#include <QHBoxLayout>
#include <QSpacerItem>
#include "qrcodegen.hpp"

using namespace qrcodegen;

CarteFideliteDialog::CarteFideliteDialog(int clientId, const QString& nom, int score, QWidget *parent)
    : QDialog(parent), m_clientId(clientId), m_nom(nom), m_score(score)
{
    setWindowTitle("Carte de Fidélité");
    setFixedSize(600, 500);
    m_logo = QPixmap(":/images/logo.png").scaled(100, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setupUI();
}

QPixmap CarteFideliteDialog::generateQRCode(const QString &data) {
    try {
        const QrCode qr = QrCode::encodeText(data.toUtf8().constData(), qrcodegen::Ecc::MEDIUM);
        const int size = qr.getSize();
        const int border = 4;

        // Calcul automatique du scale pour avoir une image de 250x250
        const int targetSize = 250;
        const int scale = targetSize / (size + 2 * border);

        const int imageSize = (size + 2 * border) * scale;
        QImage image(imageSize, imageSize, QImage::Format_RGB32);
        image.fill(Qt::white);

        QPainter painter(&image);
        painter.setBrush(Qt::black);
        painter.setPen(Qt::NoPen);

        for (int y = 0; y < size; ++y) {
            for (int x = 0; x < size; ++x) {
                if (qr.getModule(x, y)) {
                    QRect rect((x + border) * scale,
                               (y + border) * scale,
                               scale, scale);
                    painter.drawRect(rect);
                }
            }
        }

        return QPixmap::fromImage(image);
    } catch (const std::exception &e) {
        qWarning() << "Erreur génération QR Code:" << e.what();
        QPixmap errorPixmap(250, 250);
        errorPixmap.fill(Qt::white);
        QPainter painter(&errorPixmap);
        painter.setPen(Qt::black);
        painter.drawText(errorPixmap.rect(), Qt::AlignCenter, "Erreur QR Code");
        return errorPixmap;
    }
}

void CarteFideliteDialog::setupUI()
{
    QString niveau;
    QColor couleurFond;

    if (m_score >= 50) {
        niveau = "PLATINUM";
        couleurFond = QColor("#e5e4e2");
    } else if (m_score >= 30) {
        niveau = "GOLD";
        couleurFond = QColor("#ffd700");
    } else {
        niveau = "SILVER";
        couleurFond = QColor("#c0c0c0");
    }

    setFixedSize(650, 750);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(40, 30, 40, 30);

    // Carte contenant les infos
    QWidget *carteWidget = new QWidget(this);
    carteWidget->setFixedSize(550, 630);
    carteWidget->setStyleSheet(QString(
                                   "background-color: %1;"
                                   "border-radius: 18px;"
                                   "border: 2px solid #aaa;")
                                   .arg(couleurFond.name()));

    QVBoxLayout *carteLayout = new QVBoxLayout(carteWidget);
    carteLayout->setContentsMargins(25, 25, 25, 25);
    carteLayout->setSpacing(20);

    // En-tête avec logo + titre
    QVBoxLayout *headerLayout = new QVBoxLayout();
    headerLayout->setAlignment(Qt::AlignCenter);

    QLabel *logoLabel = new QLabel(carteWidget);
    QPixmap logoPixmap("C:/Users/Marwen/Desktop/logo.png");
    if (!logoPixmap.isNull()) {
        logoLabel->setPixmap(logoPixmap.scaled(120, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    logoLabel->setAlignment(Qt::AlignCenter);
    headerLayout->addWidget(logoLabel);

    QLabel *titreLabel = new QLabel("CARTE DE FIDÉLITÉ", carteWidget);
    titreLabel->setStyleSheet("font-size: 26px; font-weight: bold; color: #333;");
    titreLabel->setAlignment(Qt::AlignCenter);
    headerLayout->addWidget(titreLabel);

    carteLayout->addLayout(headerLayout);

    // Nom
    QLabel *nomLabel = new QLabel(m_nom.toUpper(), carteWidget);
    nomLabel->setStyleSheet("font-size: 22px; font-weight: bold; color: #222;");
    nomLabel->setAlignment(Qt::AlignCenter);
    carteLayout->addWidget(nomLabel);

    // ID
    QLabel *idLabel = new QLabel(QString("ID : %1").arg(m_clientId), carteWidget);
    idLabel->setStyleSheet("font-size: 18px; color: #555;");
    idLabel->setAlignment(Qt::AlignCenter);
    carteLayout->addWidget(idLabel);

    // Score + Niveau
    QHBoxLayout *infoLayout = new QHBoxLayout();
    infoLayout->setSpacing(30);

    QLabel *niveauLabel = new QLabel(QString("NIVEAU : %1").arg(niveau), carteWidget);
    niveauLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: #333;");
    infoLayout->addWidget(niveauLabel, 0, Qt::AlignCenter);

    QLabel *scoreLabel = new QLabel(QString("SCORE : %1 pts").arg(m_score), carteWidget);
    scoreLabel->setStyleSheet("font-size: 20px; color: #333;");
    infoLayout->addWidget(scoreLabel, 0, Qt::AlignCenter);

    carteLayout->addLayout(infoLayout);

    // QR Code
    QString qrData = QString("Nom: %1\nID: %2\nScore: %3\nNiveau: %4")
                         .arg(m_nom)
                         .arg(m_clientId)
                         .arg(m_score)
                         .arg(niveau);

    QPixmap qrPixmap = generateQRCode(qrData);
    QLabel *qrLabel = new QLabel(carteWidget);
    qrLabel->setPixmap(qrPixmap);
    qrLabel->setAlignment(Qt::AlignCenter);
    qrLabel->setFixedSize(qrPixmap.size());
    carteLayout->addWidget(qrLabel, 0, Qt::AlignCenter);

    // Date
    QLabel *dateLabel = new QLabel(QString("Émise le %1").arg(QDate::currentDate().toString("dd/MM/yyyy")), carteWidget);
    dateLabel->setStyleSheet("font-size: 16px; color: #666;");
    dateLabel->setAlignment(Qt::AlignRight);
    carteLayout->addWidget(dateLabel);

    // Ajout de la carte au layout principal
    mainLayout->addWidget(carteWidget, 0, Qt::AlignCenter);

    // Bouton fermer
    QPushButton *closeButton = new QPushButton("Fermer", this);
    closeButton->setFixedSize(150, 45);
    closeButton->setStyleSheet(
        "QPushButton {"
        "  font-size: 18px;"
        "  background-color: #4CAF50;"
        "  color: white;"
        "  border: none;"
        "  border-radius: 8px;"
        "}"
        "QPushButton:hover {"
        "  background-color: #45a049;"
        "}");
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
    mainLayout->addSpacing(20);
    mainLayout->addWidget(closeButton, 0, Qt::AlignCenter);
}
