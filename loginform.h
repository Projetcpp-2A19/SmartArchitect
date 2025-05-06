#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QMessageBox>
#include "login.h"

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

private slots:
    void on_btnLogin_clicked();  // Connexion
    void on_checkBoxShowPassword_toggled(bool checked); // Afficher/Masquer le mot de passe

    void on_pushButton_clicked();

private:
    Ui::LoginForm *ui;
    Login login;
};

#endif // LOGINFORM_H
