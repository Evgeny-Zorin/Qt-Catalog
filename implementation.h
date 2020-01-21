#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H

#include <QtXml>
#include <QTextCodec> // подключение класса кодека текста
#include <QVector>
//#include "BaseClass.h"
#include "firmclass.h"
#include "projectclass.h"






void readNode_frm(QDomElement root, QVector<Firm>& vec_firm, Firm *buf_One);
void readNode_prj(QDomElement root, QVector<Project>& vec_Project, Project *buf_One);
void input_Firm(QVector<Firm>& vec_firm, const QDomDocument document);
void input_Project(QVector<Project>& vec_Project,const QDomDocument document);
void plus_frm(QVector<Firm>& vec_firm, Firm& one);  //не используется
//void plus_prj(QVector<Project>& vec_Project, Project& one);





#endif // IMPLEMENTATION_H
