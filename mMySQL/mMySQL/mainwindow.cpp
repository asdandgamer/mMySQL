#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qsLang = new QSettings("Lang.ini", QSettings::IniFormat);
    qsSettings = new QSettings("Settings.ini", QSettings::IniFormat);

    curLang = getIniValueInLatin1(qsSettings, "Settings/curLang", "eng");

    statusBarLabel_1 = new QLabel();
    db = QSqlDatabase::addDatabase("QMYSQL");
    bConnected = false;

    ui->setupUi(this);

    setLang();
}

MainWindow::~MainWindow()
{
    delete qsLang;
    delete qsSettings;
    delete statusBarLabel_1;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    LogIn();
}

void MainWindow::LogIn()
{
    QStringList connectionData;                 // contains list of MySQL connection parameters
    ConnectionDataDialog connectionDataDialog;  // Displays connecton parametrs dialog

    if(!connectionDataDialog.exec()) return;    // if clicked on [Cancel]

    connectionData = connectionDataDialog.getConnectionData();  // Gets connection parametrs list
    db.setHostName(connectionData[0]);
    db.setDatabaseName(connectionData[1]);
    db.setUserName(connectionData[2]);
    db.setPassword(connectionData[3]);
    db.setPort(connectionData[0].toInt());

    if (!db.open())
    {
       QMessageBox::critical(this, getIniValueInLatin1(qsLang, curLang+"/MDBError","Database Error"),
                db.lastError().text());
       statusBarLabel_1->setText(getIniValueInLatin1(qsLang, curLang+"/MWConnStatusFailed", "Connection: failed;"));
    }
    else
    {
        bConnected = true;
        statusBarLabel_1->setText(getIniValueInLatin1(qsLang, curLang+"/MWConnStatusSuccesful", "Connection: succesful;"));
        ui->label_1->setText(getIniValueInLatin1(qsLang, curLang+"/MWlabel_1", "DB: ") + " " + db.databaseName());

        QSqlQuery query;
        query.exec("SHOW TABLES");
        // Clear tables list if it's contain items
        if(ui->listWidget->count() != 0)
            ui->listWidget->clear();

        int index = 0;
        while (query.next())
        {
            ui->listWidget->addItem(query.value(0).toString());
            index++;
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
//    fillTable();
}

void MainWindow::fillTable(QString tableName)
{
    QStringList strList; // contains columns names in Horizontal Header
    QSqlQuery query;

    requestString = "SELECT * FROM " + tableName;
    query.exec(requestString);

    int columnsCount = query.record().count();
    int rowsCount = query.size();

    ui->tableWidget->setColumnCount(columnsCount);
    ui->tableWidget->setRowCount(rowsCount);

    int index=0;
    while (query.next())
    {
        for(int i = 0; i < columnsCount; i++)
        {
            strList.append(query.record().fieldName(i));
            ui->tableWidget->setItem(index,i,new QTableWidgetItem(query.value(i).toString()));
        }
        index++;
    }
    ui->tableWidget->setHorizontalHeaderLabels(strList); //set columns names in Horizontal Header
    ui->tableWidget->verticalHeader()->setVisible(false); //hide Vertical Header
    // resizes ---------------------------------
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    fillTable(item->text());
}

void MainWindow::on_pushButton_3_clicked()
{
    if(!bConnected)
    {
        QMessageBox::warning(this,
            getIniValueInLatin1(qsLang, curLang+"/MNotConnectedHeader", "Not connected"),
            getIniValueInLatin1(qsLang, curLang+"/MNotConnectedMessage", "You must connect to database first!" ));
        return;
    }
}

void MainWindow::setLang()
{
    ui->label_5->setText(getIniValueInLatin1(qsLang, curLang+"/MWlabel_5", "Host name(adress):"));
    ui->label_2->setText("Database name:");
    ui->label_3->setText("User name:");
    ui->label_4->setText("Password:");
    ui->label_1->setText(getIniValueInLatin1(qsLang, curLang+"/MWlabel_1", "DB: "));

    ui->groupBox->setTitle(getIniValueInLatin1(qsLang, curLang+"/MWgroupBox", "Tables list"));

    ui->pushButton->setText("Connect");
    ui->pushButton_2->setText("Read");
    ui->pushButton_3->setText(getIniValueInLatin1(qsLang, curLang+"/MWpushButton_3", "Add Table"));
    // add Label to status bar for displaying connection status;
    ui->statusBar->insertWidget(0,statusBarLabel_1);
    // for _debug
    //    qsLang->setValue("ru/sdgfdh", "VAlue");
}
