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

void MainWindow::changeTranslator(QString postfix)
{
    QApplication::removeTranslator(translator); //отклоючаю текущий переводчик
    translator = new QTranslator(this);
    translator->load(QApplication::applicationName() + " " + postfix); //загружаю но
    QApplication::installTranslator(translator);    //подключаю новый переводчик с новым словарем

}

void MainWindow::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange) //проверяем тип события
    {
        retranslateUi();
    }
    //else
    QMainWindow::changeEvent(event);
}

void MainWindow::retranslateUi()
{
    setWindowTitle(tr("Current Langage"));
    //ui->push
    //setText(tr("Hello Ev!"));
}

void MainWindow::on_actionEanglish_triggered()
{
    changeTranslator("en");
}

void MainWindow::on_actionRussian_triggered()
{
    changeTranslator("ru");
}
