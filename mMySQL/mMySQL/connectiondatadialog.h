#ifndef CONNECTIONDATADIALOG_H
#define CONNECTIONDATADIALOG_H

#include <QDialog>
#include "globals.h"

namespace Ui {
class ConnectionDataDialog;
}

class ConnectionDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDataDialog(QWidget *parent = 0);
    QStringList getConnectionData();
    ~ConnectionDataDialog();

private:
    Ui::ConnectionDataDialog *ui;

    void setLang();
};

#endif // CONNECTIONDATADIALOG_H
