#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "implementation.h"
//#include "BaseClass.h"
#include <QMessageBox>
#include <QEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Сделаем первоначальную инициализацию перевода для окна прилоежния
    //QTranslator trans;
    //trans.load(QString("Catalog_") + QString("ru"));
    //translator->load(QApplication::applicationName() + "_" + QLocale::system().name());
    //qApp->installTranslator(translator);
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

//простая реализация динамической смены языка
void MainWindow::changeTranslator(QString postfix)
{
    QApplication::removeTranslator(translator); //отклоючаю текущий переводчик
    translator = new QTranslator(this);
    translator->load(QApplication::applicationName() + "_" + postfix); //загружаю но
    QApplication::installTranslator(translator);    //подключаю новый переводчик с новым словарем
    ui->statusBar->showMessage(tr("Current Language changed to %1").arg(postfix));

}

void MainWindow::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange) //проверяем тип события
    {
        ui->retranslateUi(this);//вызов метода, созданного дизайнером
    }
    else
    QMainWindow::changeEvent(event);
}


void MainWindow::on_actionRussian_triggered()
{
    changeTranslator("ru");
}

void MainWindow::on_actionEnglish_triggered()
{
    changeTranslator("en");
}

// we create the menu entries dynamically, dependent on the existing translations.
//void MainWindow::createLanguageMenu(void)
//{
// QActionGroup* langGroup = new QActionGroup(ui->menuLanguage);
// langGroup->setExclusive(true);

// connect(langGroup, SIGNAL (triggered(QAction *)), this, SLOT (slotLanguageChanged(QAction *)));

// // format systems language
// QString defaultLocale = QLocale::system().name();
// defaultLocale.truncate(defaultLocale.lastIndexOf('_'));

// m_langPath = QApplication::applicationDirPath();
// m_langPath.append("/languages");
// QDir dir(m_langPath);
// QStringList fileNames = dir.entryList(QStringList("Catalog_*.qm"));

// for (int i = 0; i < fileNames.size(); ++i) {
//  // get locale extracted by filename
//  QString locale;
//  locale = fileNames[i]; // "TranslationExample_de.qm"
//  locale.truncate(locale.lastIndexOf('.')); // "TranslationExample_de"
//  locale.remove(0, locale.indexOf('_') + 1); // "de"

// QString lang = QLocale::languageToString(QLocale(locale).language());
// QIcon ico(QString("%1/%2.png").arg(m_langPath).arg(locale));

// QAction *action = new QAction(ico, lang, this);
// action->setCheckable(true);
// action->setData(locale);

// ui->menuLanguage->addAction(action);
// langGroup->addAction(action);

// // set default translators and language checked
// if (defaultLocale == locale)
// {
// action->setChecked(true);
// }
// }
//}

//// Called every time, when a menu entry of the language menu is called
//void MainWindow::slotLanguageChanged(QAction* action)
//{
// if(0 != action) {
//  // load the language dependant on the action content
//  loadLanguage(action->data().toString());
//  setWindowIcon(action->icon());
// }
//}

//void switchTranslator(QTranslator& translator, const QString& filename)
//{
// // remove the old translator
// qApp->removeTranslator(&translator);

// // load the new translator
//QString path = QApplication::applicationDirPath();
//    path.append("/languages/");
// if(translator.load(path + filename)) //Here Path and Filename has to be entered because the system didn't find the QM Files else
//  qApp->installTranslator(&translator);
//}

//void MainWindow::loadLanguage(const QString& rLanguage)
//{
// if(m_currLang != rLanguage) {
//  m_currLang = rLanguage;
//  QLocale locale = QLocale(m_currLang);
//  QLocale::setDefault(locale);
//  QString languageName = QLocale::languageToString(locale.language());
//  switchTranslator(m_translator, QString("Catalog_%1.qm").arg(rLanguage));
//  switchTranslator(m_translatorQt, QString("qt_%1.qm").arg(rLanguage));
//  ui->statusBar->showMessage(tr("Current Language changed to %1").arg(languageName));
// }
//}

//void MainWindow::changeEvent(QEvent* event)
//{
//    if(event->type() == QEvent::LanguageChange) {
//     switch(event->type()) {
//      // this event is send if a translator is loaded
//      case QEvent::LanguageChange:
//       ui->retranslateUi(this);
//       break;

//      // this event is send, if the system, language changes
//      case QEvent::LocaleChange:
//      {
//       QString locale = QLocale::system().name();
//       locale.truncate(locale.lastIndexOf('_'));
//       loadLanguage(locale);
//      }
//      break;
//     }
//    }
//    QMainWindow::changeEvent(event);
//}
