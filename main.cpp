#include "mainwindow.h"
#include "implementation.h"
#include "xmlparser.h"
#include <QApplication>
#include <QVector>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

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
