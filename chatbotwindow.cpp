#include "chatbotwindow.h"
#include "ui_chatbotwindow.h"

ChatbotWindow::ChatbotWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatbotWindow)
{
    ui->setupUi(this);
    setWindowTitle("Assistant Fournisseur 🤖");
}

ChatbotWindow::~ChatbotWindow()
{
    delete ui;
}

void ChatbotWindow::on_btnEnvoyer_clicked()
{
    QString message = ui->lineEditMessage->text().trimmed();
    if (!message.isEmpty()) {
        ui->textBrowserChat->append("<b>Vous :</b> " + message);
        QString reponse = getChatbotResponse(message);
        ui->textBrowserChat->append("<b>Bot :</b> " + reponse);
        ui->lineEditMessage->clear();
    }
}

QString ChatbotWindow::getChatbotResponse(const QString &message)
{
    QString msg = message.toLower();

    if (msg.contains("bonjour"))
        return "Bonjour ! Comment puis-je vous aider avec les fournisseurs ?";
    else if (msg.contains("ajouter"))
        return "Pour ajouter un fournisseur, allez dans l'onglet principal et remplissez les champs.";
    else if (msg.contains("supprimer"))
        return "Sélectionnez un fournisseur puis cliquez sur 'Supprimer'.";
    else if (msg.contains("qr code"))
        return "Cliquez sur le bouton QR pour générer un QR code du fournisseur sélectionné.";
    else
        return "Désolé, je ne comprends pas encore cette demande.";
}

