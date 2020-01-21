#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "implementation.h"
//#include "BaseClass.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    QMessageBox *msg = new  QMessageBox;
    msg->setText("New File");
    msg->exec();
}

void MainWindow::on_actionHide_menuBar_triggered(bool checked)
{
    //ДОРАБОТАТЬ ВОЗВРАТ
    if (checked)
    {
        ui->menuBar->hide(); // hide menubar
    }
    else
        ui->menuBar->show(); // in case you want to restore it
}

void MainWindow::on_actionExit_triggered()
{
    close();
}
