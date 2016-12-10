#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

#include "globals.h"

#include "connectiondatadialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    //-------------------------
    QLabel *statusBarLabel_1; //Status bar label
    QSqlDatabase db; //DB connection
    QString requestString; // Contains request string

    bool bConnected;

    void LogIn();
    void fillTable(QString tableName);
    void setLang();
    //inline QString getIniValueInLatin1(QSettings *iniFile, QString key, QString defaultValue) const;

};

#endif // MAINWINDOW_H
