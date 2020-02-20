#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
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

    void on_actionRussian_triggered();

    void on_actionEnglish_triggered();

private:
    Ui::MainWindow *ui;
    QTranslator* translator;
protected:
    void changeTranslator(QString postfix);
    void changeEvent(QEvent* event) override;    //перехватит событие смены языка для перевода иконок\меню
//====================================
//protected:
// // this event is called, when a new translator is loaded or the system language is changed
// void changeEvent(QEvent*);

//protected slots:
// // this slot is called by the language menu actions
// void slotLanguageChanged(QAction* action);

//private:
// // loads a language by the given language shortcur (e.g. de, en)
// void loadLanguage(const QString& rLanguage);

// // creates the language menu dynamically from the content of m_langPath
// void createLanguageMenu(void);

// QTranslator m_translator; // contains the translations for this application
// QTranslator m_translatorQt; // contains the translations for qt
// QString m_currLang; // contains the currently loaded language
// QString m_langPath; // Path of language files. This is always fixed to /languages.
};


#endif // MAINWINDOW_H
