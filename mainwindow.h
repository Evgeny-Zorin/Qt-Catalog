#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
