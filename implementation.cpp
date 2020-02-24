//#include "BaseClass.h"
#include "implementation.h"


void plus_frm(QVector<Firm>& vec_firm, Firm& one)   //ТРЕБУЕТСЯ ДОРАБОТКА ДЛЯ УНИВЕРСАЛЬНОСТИ
{

    //если мы хотим, чтобы не происходило динамического расширения контейнера вектор:
    //1 задать сразу необходимый размер, узнав число базовых элементов
    //добавлять в контейнер циклом, меня сеттерами значения полей объекта
    //2 использовать статический массив
    vec_firm.push_back(one);
}
//void plus_prj(QVector<Project>& vec_Project, Project& one)   //ТРЕБУЕТСЯ ДОРАБОТКА ДЛЯ УНИВЕРСАЛЬНОСТИ
//{
//    vec_Project.push_back(one);
//}


void readNode_frm(QDomElement root, QVector<Firm>& vec_firm, Firm *buf_One)
{
       QDomNode domNode = root.firstChild();
       while(!domNode.isNull())
       {
           if(domNode.isElement())
           {
              QDomElement domElement = domNode.toElement();
              if(!domElement.isNull())
              {
                 // qDebug() <<"tagName "<<domElement.tagName();
                 //qDebug()<<"text "<<domElement.text();

                  //запишем тег в буферный объект класса Firm
                  buf_One->add_buffer(Firm::give_number_to_case(domElement.tagName()), buf_One, domElement.text());
              }

           }
           domNode = domNode.nextSibling();
        }
       vec_firm.push_back(*buf_One);
       //plus(vec_firm, *buf_One);    //добавим сформированный буферный объект в вектор объектов класса Firm
       buf_One->clear_date();       //чистим буфер
}

void readNode_prj(QDomElement root, QVector<Project>& vec_Project, Project *buf_One)
{
       QDomNode domNode = root.firstChild();
       while(!domNode.isNull())
       {
           if(domNode.isElement())
           {
              QDomElement domElement = domNode.toElement();
              if(!domElement.isNull())
              {
                 // qDebug() <<"tagName "<<domElement.tagName();
                 //qDebug()<<"text "<<domElement.text();

                  //запишем тег в буферный объект класса Firm
                  buf_One->add_buffer(Project::give_number_to_case(domElement.tagName()), buf_One, domElement.text());
              }

           }
           domNode = domNode.nextSibling();
        }
       vec_Project.push_back(*buf_One);
       //plus(vec_Project, *buf_One);    //добавим сформированный буферный объект в вектор объектов класса Firm
      // buf_One->clear_date();       //чистим буфер
}

void input_Firm(QVector<Firm>& vec_firm,const QDomDocument document)
{
    //get the root element
    QDomElement root = document.firstChildElement();
    //List the books
    //qDebug()<<"Started "<<endl;

    Firm *buf_One = new Firm;
       buf_One->clear_date();

       //get the chapters
       QDomNodeList books = root.elementsByTagName("Exponent"); //лист объектов Exponent
       for(int i = 0; i < books.count(); i++)
       {
           QDomNode booknode = books.at(i);
           //conver to an element
           if(booknode.isElement())
           {
               QDomElement book = booknode.toElement();
               readNode_frm(book,vec_firm, buf_One);    //читаем теги объекта Exponent
           }
       }

           delete buf_One;
    qDebug()<<"vec_firm.size"<< vec_firm.size()<<endl;

    //printed to console
   // qDebug()<<"Printed 1 vec_firm: ";
            //for(const auto &i: vec_firm)
                //  qDebug() << i<<endl;

//            return true;
}

void input_Project(QVector<Project>& vec_Project,const QDomDocument document)
{
    //get the root element
    QDomElement root = document.firstChildElement();
    //List the books
    //qDebug()<<"Started "<<endl;

    Project *buf_One = new Project;
//       buf_One->clear_date();

       //get the chapters
       QDomNodeList books = root.elementsByTagName("Project"); //лист объектов Exponent
       for(int i = 0; i < books.count(); i++)
       {
           QDomNode booknode = books.at(i);
           //conver to an element
           if(booknode.isElement())
           {

               QDomElement book = booknode.toElement();
               readNode_prj(book,vec_Project, buf_One);    //читаем теги объекта Exponent
           }
       }

           delete buf_One;
    qDebug()<<"vec_Project.size"<< vec_Project.size()<<endl;

    //printed to console
    //qDebug()<<"Printed 1 vec_Project: ";
            //for(const auto &i: vec_Project)
                //  qDebug() << i<<endl;

//            return true;
}
