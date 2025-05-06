#include "chatbot.h"
#include "ui_chatbot.h"
#include <QScrollBar>
#include <QtTextToSpeech/QTextToSpeech>

chatbot::chatbot(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::chatbot)
{
    ui->setupUi(this);
    initChatbotMemory();

    connect(ui->sendButton, &QPushButton::clicked, this, &chatbot::onSendMessage);
    connect(ui->messageInput, &QLineEdit::returnPressed, this, &chatbot::onSendMessage);

    // Placeholder text
    ui->messageInput->setPlaceholderText("Tapez votre question ici...");

    // Style simple
    ui->chatBox->setStyleSheet("background-color: white; font: 10pt 'Arial';");
    ui->messageInput->setStyleSheet("background-color: #f2f2f2; border: 1px solid #ccc;");
    ui->sendButton->setStyleSheet("background-color: #4CAF50; color: white;");
}

chatbot::~chatbot()
{
    delete ui;
}

void chatbot::onSendMessage()
{
    QString userMessage = ui->messageInput->text().trimmed();  // Récupérer le message de l'utilisateur
    if (userMessage.isEmpty()) return;

    ui->chatBox->append("👤 Vous : " + userMessage);  // Afficher le message de l'utilisateur
    QString response = getDynamicResponse(userMessage);  // Obtenir une réponse dynamique
    ui->chatBox->append("🤖 Chatbot : " + response);  // Afficher la réponse du chatbot
    ui->messageInput->clear();  // Effacer le champ de saisie

    // Auto-scroll vers le bas
    ui->chatBox->verticalScrollBar()->setValue(ui->chatBox->verticalScrollBar()->maximum());

    // **Synthèse vocale** pour faire parler le chatbot
    QTextToSpeech *tts = new QTextToSpeech(this);  // Créer l'objet de synthèse vocale
    tts->say(response);  // Lire la réponse à haute voix
}

void chatbot::initChatbotMemory()
{
    // Initialiser la mémoire du chatbot avec des réponses prédéfinies
    chatbotMemory["bonjour"] = "Bonjour ! Comment puis-je vous aider ?";
    chatbotMemory["salut"] = "Salut à vous !";
    chatbotMemory["aide"] = "Je peux vous aider à gérer vos équipements.";
    chatbotMemory["problème"] = "Pouvez-vous décrire votre problème en détail ?";
    chatbotMemory["merci"] = "Avec plaisir ! 😊";
    chatbotMemory["au revoir"] = "À bientôt !";
}

QString chatbot::getDynamicResponse(const QString &message)
{
    QString lowerMessage = message.toLower();  // Convertir le message de l'utilisateur en minuscule
    // Chercher une correspondance dans la mémoire du chatbot
    for (auto it = chatbotMemory.begin(); it != chatbotMemory.end(); ++it) {
        if (lowerMessage.contains(it.key())) {
            return it.value();  // Retourner la réponse associée
        }
    }
    return "Désolé, je ne comprends pas votre question.";  // Réponse par défaut
}
