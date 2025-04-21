#include "passwordresetform.h"
#include "ui_passwordresetform.h"
#include "emailsender.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
PasswordResetForm::PasswordResetForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasswordResetForm)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEditNewPassword->setEchoMode(QLineEdit::Password);
    ui->lineEditConfirmPassword->setEchoMode(QLineEdit::Password);
    // Ajoutez ceci pour vérifier le nombre de pages
    qDebug() << "Nombre de pages dans stackedWidget:" << ui->stackedWidget->count();
}

PasswordResetForm::~PasswordResetForm()
{
    delete ui;
}

void PasswordResetForm::on_btnRequestCode_clicked()
{
    currentEmail = ui->lineEditEmail->text().trimmed();

    if (currentEmail.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer votre adresse email.");
        return;
    }

    // Vérification de l'email dans la base
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EMPLOYEE WHERE EMAIL = :email");
    checkQuery.bindValue(":email", currentEmail);

    if (!checkQuery.exec() || !checkQuery.next()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la vérification de l'email");
        return;
    }

    if (checkQuery.value(0).toInt() == 0) {
        QMessageBox::warning(this, "Erreur", "Cet email n'existe pas dans notre système");
        return;
    }

    generatedCode = generateCode();

    if (sendCodeByEmail(currentEmail, generatedCode)) {
        // Ne changez pas de page, restez sur la même
        QMessageBox::information(this, "Succès", "Code envoyé par email!");

        // Activez plutôt les champs pour entrer le code et nouveau mot de passe
        ui->lineEditCode->setEnabled(true);
        ui->lineEditNewPassword->setEnabled(true);
        ui->lineEditConfirmPassword->setEnabled(true);
        ui->btnReset->setEnabled(true);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'envoi du code par email");
    }
}

void PasswordResetForm::on_btnReset_clicked()
{
    QString newPassword = ui->lineEditNewPassword->text();
    QString confirmPassword = ui->lineEditConfirmPassword->text();
    QString code = ui->lineEditCode->text().trimmed();

    if (newPassword.isEmpty() || confirmPassword.isEmpty() || code.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs sont obligatoires");
        return;
    }

    if (newPassword != confirmPassword) {
        QMessageBox::warning(this, "Erreur", "Les mots de passe ne correspondent pas");
        return;
    }

    if (code != generatedCode) {
        QMessageBox::warning(this, "Erreur", "Code de vérification incorrect");
        return;
    }

    if (updatePasswordInDatabase(currentEmail, newPassword)) {
        QMessageBox::information(this, "Succès", "Mot de passe mis à jour avec succès!");
        this->close();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la mise à jour du mot de passe");
    }
}

bool PasswordResetForm::updatePasswordInDatabase(const QString &email, const QString &newPassword)
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYEE SET MDP = :password WHERE EMAIL = :email");
    query.bindValue(":password", newPassword); // À hasher en production
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Erreur de mise à jour:" << query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}

QString PasswordResetForm::generateCode()
{
    const QString chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    QString code;
    for (int i = 0; i < 6; ++i) {
        code += chars.at(QRandomGenerator::global()->bounded(chars.length()));
    }
    return code;
}

bool PasswordResetForm::sendCodeByEmail(const QString &email, const QString &code)
{
    EmailSender sender;
    QString subject = "Code de réinitialisation";
    QString message = QString("Bonjour,\n\n"
                              "Voici votre code de réinitialisation : %1\n\n"
                              "Cordialement,\n"
                              "Votre équipe").arg(code);

    qDebug() << "Envoi du code à" << email << ":" << code;
    return sender.sendEmail(email, subject, message);
}

void PasswordResetForm::on_btnResendCode_clicked()
{
    if (currentEmail.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun email enregistré");
        return;
    }

    generatedCode = generateCode();
    if (sendCodeByEmail(currentEmail, generatedCode)) {
        QMessageBox::information(this, "Succès", "Nouveau code envoyé!");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'envoi du nouveau code");
    }
}
