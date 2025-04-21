#ifndef PASSWORDRESETFORM_H
#define PASSWORDRESETFORM_H

#include <QWidget>

namespace Ui {
class PasswordResetForm;
}

class PasswordResetForm : public QWidget {
    Q_OBJECT

public:
    explicit PasswordResetForm(QWidget *parent = nullptr);
    ~PasswordResetForm();

signals:
    void passwordResetSuccess();
    void resetRequested(const QString &email);
    void passwordReset(const QString &email, const QString &newPassword, const QString &code);

private slots:
    void on_btnRequestCode_clicked();
    void on_btnReset_clicked();
    void on_btnResendCode_clicked();
private:
    Ui::PasswordResetForm *ui;
    QString currentEmail;
    QString generatedCode;
    QString generateCode();
    bool sendCodeByEmail(const QString &email, const QString &code);
    bool updatePasswordInDatabase(const QString &email, const QString &newPassword);

};

#endif // PASSWORDRESETFORM_H
