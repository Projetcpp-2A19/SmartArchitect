#include "loginform.h"
#include "ui_loginform.h"
#include <QMessageBox>
#include "passwordresetform.h"

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    ui->lineEditMdp->setEchoMode(QLineEdit::Password); // Masquer le mot de passe par défaut
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_btnLogin_clicked()
{
    QString email = ui->lineEditEmail->text();
    QString mdp = ui->lineEditMdp->text();

    if (email.isEmpty() || mdp.isEmpty()) {
        ui->labelMessage->setText("Veuillez remplir tous les champs !");
        return;
    }

    if (login.verifierUtilisateur(email, mdp)) {
        QMessageBox::information(this, "Succès", "Connexion réussie !");
        this->close(); // Fermer la fenêtre de login
        // TODO: Ouvrir l'application principale ici
    } else {
        ui->labelMessage->setText("E-mail ou mot de passe incorrect !");
    }
}

void LoginForm::on_checkBoxShowPassword_toggled(bool checked)
{
    if (checked) {
        ui->lineEditMdp->setEchoMode(QLineEdit::Normal);
    } else {
        ui->lineEditMdp->setEchoMode(QLineEdit::Password);
    }
}


void LoginForm::on_pushButton_clicked()
{
    PasswordResetForm *resetForm = new PasswordResetForm();
    resetForm->show();

    // Fermer le login après réinitialisation (optionnel)
    connect(resetForm, &PasswordResetForm::passwordResetSuccess, this, [this]() {
        this->close();
    });
}

