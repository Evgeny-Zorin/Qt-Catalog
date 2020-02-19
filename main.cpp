#include "mainwindow.h"
#include "implementation.h"
//#include "BaseClass.h"
#include "xmlparser.h"
#include <QApplication>
#include <QVector>

//#include <windows.h>    //<<<<  !!!!!temporary solution!!!!!   >>>


int main(int argc, char *argv[])
{
  //  SetConsoleCP(1251);
  //  SetConsoleOutputCP(1251);
 //   setlocale(LC_ALL,"russian");

    QApplication a(argc, argv);

    //QTranslator trans;
    //trans.load(QApplication::applicationName() + "_" + QLocale::system().name());       //load может искать не дословно
    //a.installTranslator(&trans);

    QString nmf = "data.xml";
    QString name_main_tag = "Exponent";

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //создам указатель на функцию через type alias
         //using validate_gNtC = int(*)(const QString&);
         //validate_gNtC gNtC= Firm::give_number_to_case;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//стоит добавить функцию-демо режим,
//которая будет закрывать дополнительные открытые окна-справки через определенные промежуток времени (5 минут)
//реализовать через?: время бездействия,время жизни окна...


    XmlParser();

    MainWindow w;
    w.show();


    return a.exec();
}
