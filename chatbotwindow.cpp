#include "chatbotwindow.h"
#include "ui_chatbotwindow.h"

ChatbotWindow::ChatbotWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatbotWindow)
{
    ui->setupUi(this);
    setWindowTitle("Assistant Fournisseur 🤖");

    // Ensure modality for dialog behavior
    setModal(true);
}

ChatbotWindow::~ChatbotWindow()
{
    delete ui;
}

void ChatbotWindow::on_btnEnvoyer_clicked()
{
    QString message = ui->lineEditMessage->text().trimmed();
    if (!message.isEmpty()) {
        ui->textBrowserChat->append("<b>Vous :</b> " + message.toHtmlEscaped());
        QString reponse = getChatbotResponse(message);
        ui->textBrowserChat->append("<b>Bot :</b> " + reponse.toHtmlEscaped());
        ui->lineEditMessage->clear();
    }
}

QString ChatbotWindow::getChatbotResponse(const QString &message)
{
    QString msg = message.toLower();

    if (msg.contains("bonjour"))
        return "Bonjour ! Comment puis-je vous aider avec la gestion des fournisseurs ?";
    else if (msg.contains("ajouter"))
        return "Pour ajouter un fournisseur, accédez à l'onglet principal, remplissez les champs requis, puis cliquez sur 'Ajouter'.";
    else if (msg.contains("supprimer"))
        return "Sélectionnez un fournisseur dans la liste, puis cliquez sur le bouton 'Supprimer' pour le retirer.";
    else if (msg.contains("qr code"))
        return "Pour générer un QR code, sélectionnez un fournisseur et cliquez sur le bouton 'Générer QR'. Le code contiendra les informations du fournisseur.";
    else
        return "Désolé, je ne comprends pas cette demande. Essayez des mots-clés comme 'ajouter', 'supprimer', ou 'qr code'.";
}
