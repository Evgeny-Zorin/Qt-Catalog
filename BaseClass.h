#ifndef BASECLASS_H
#define BASECLASS_H
#include <QString>
#include <QDebug>
#include <iostream> //убрать общее подключение
// this new test
//std::vector<std::shared_ptr<BaseClass> >

//============================================================
//need to think about inheritance from class : public QObject
//============================================================

class BaseClass
{
protected:
    BaseClass();
public:
    static int give_number_to_case(const QString& str);
    //virtual void input_data() = 0;
    virtual void Show_name() = 0;
    virtual ~BaseClass() = 0;
};



//*******************************************************************************************
//*******************************************************************************************

#endif //
