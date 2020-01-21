#include "xmlparser.h"
//#include "BaseClass.h"
#include "implementation.h"


bool XmlParser()
{
    QDomDocument document_firm,document_prj;
    QVector<Firm> v_Firm;   //вектор объектов класса Firm
    QVector<Project> v_Prj;
    //Load the file
    QFile file_data("data.xml");
    QFile file_projects("projects.xml");
//data
    if(!file_data.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Failed to open file_data!"<<endl;
        return -1;
    }
    else {
        if(!document_firm.setContent((&file_data)))
        {
            qDebug()<<"Failed to load document!"<<endl;
            return -1;
        }
        file_data.close();
    }
    input_Firm(v_Firm, document_firm);

    qDebug()<<"Printed 2 vec_firm: ";
          //  for(const auto &i: v_Firm)
           //       qDebug() << i<<endl;

//projects
    if(!file_projects.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Failed to open file_projects!"<<endl;
        return -1;
    }
    else {
        if(!document_prj.setContent((&file_projects)))
        {
            qDebug()<<"Failed to load document!"<<endl;
            return -1;
        }
        file_projects.close();
    }

    input_Project(v_Prj,document_prj);
    qDebug()<<"Printed 2 v_Prj: ";
         //   for(const auto &i: v_Prj)
          //        qDebug() << i<<endl;

    return true;
}


