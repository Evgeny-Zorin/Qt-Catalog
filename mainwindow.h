#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QEvent>
#include "BaseClass.h"
#include "implementation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionHide_menuBar_triggered(bool checked);

    void on_actionExit_triggered();

    void on_actionEanglish_triggered();

    void on_actionRussian_triggered();

private:
    Ui::MainWindow *ui;
    QTranslator* translator;
    void changeTranslator(QString postfix);
    void changeEvent(QEvent* event);    //перехватит событие смены языка для перевода иконок\меню
    void retranslateUi();
};


#endif // MAINWINDOW_H
