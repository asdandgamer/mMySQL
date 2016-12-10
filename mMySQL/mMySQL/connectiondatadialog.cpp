#include "connectiondatadialog.h"
#include "ui_connectiondatadialog.h"

ConnectionDataDialog::ConnectionDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDataDialog)
{
    ui->setupUi(this);

    setLang();

    ui->lineEdit_5->setText("3306");

    //for Debug remove @ Release ------------
    ui->lineEdit_1->setText("192.168.1.4");
    ui->lineEdit_2->setText("test");
    ui->lineEdit_3->setText("andrew");
    ui->lineEdit_4->setText("cpp123add");
    //end for Debug -------------------------

}

ConnectionDataDialog::~ConnectionDataDialog()
{
    delete ui;
}

QStringList ConnectionDataDialog::getConnectionData()
{
    QStringList DBConnectionData;

    DBConnectionData.append(ui->lineEdit_1->text());
    DBConnectionData.append(ui->lineEdit_2->text());
    DBConnectionData.append(ui->lineEdit_3->text());
    DBConnectionData.append(ui->lineEdit_4->text());
    DBConnectionData.append(ui->lineEdit_5->text());

    return DBConnectionData;
}

void ConnectionDataDialog::setLang()
{
    this->setWindowTitle(getIniValueInLatin1(qsLang, curLang+"/CDDTitle", "Connection data"));

    ui->label_1->setText(getIniValueInLatin1(qsLang, curLang+"/CDDlabel_1", "Host name(adress):"));
    ui->label_2->setText(getIniValueInLatin1(qsLang, curLang+"/CDDlabel_2", "Database name:"));
    ui->label_3->setText(getIniValueInLatin1(qsLang, curLang+"/CDDlabel_3", "User name:"));
    ui->label_4->setText(getIniValueInLatin1(qsLang, curLang+"/CDDlabel_4", "Password:"));
    ui->label_5->setText(getIniValueInLatin1(qsLang, curLang+"/CDDlabel_5", "Port:"));
}
