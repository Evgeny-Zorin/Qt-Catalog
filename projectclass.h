#ifndef PROJECTCLASS_H
#define PROJECTCLASS_H
#include "BaseClass.h"


class Project :public BaseClass
{
private:
    static int P_idGenerator;
    int P_id;

    static QStringList Project_list_to_case;

// Данные по разработке. Заполняются для всех разработок. Если номер компании - 10, то разработки нумеруются 10.1, 10.2 и т.д.  -->
private:
        QString proj_id;                    // номер проекта (10.1,10.2 и т.д.)  -->
        QString proj_firm;                  // номер компании разработчика  -->
        QString proj_name;                  // Наименование проекта  -->
        QString proj_state_order;           // Правительственные программы, в рамках которой выполняется проект  -->
        QString proj_branch;                // Отрасли, которые могут использовать результаты проекта  -->
        QString proj_inform_type;                // Тип предоставляемой информации  -->
        QString proj_stage;                 // Стадия, на которой находится проект  -->
        QString proj_keywd;                 // Ключевые слова проекта (для поиска по ключевым словам)  -->
        QString proj_short_descr;           // Краткое описание проекта  -->
        QString proj_description;           // Подробное описание проекта  -->
        QString proj_innov;                 // Инновационные аспекты технологии  -->
        QString proj_owner;                 // Владелец технологии  -->
        QString proj_poss_use;              // Возможное использование результатов проекта  -->
        QString proj_coll_type;             // Предлагаемые типы сотрудничества  -->
        QString proj_coll_partner;          // Возможные типы партнеров по проекту  -->
        QString proj_partner_tasks;         // Перечень задач, которые должен будет решать партнер по проекту. Допускается HTML верстка  -->
        QString proj_contact_name;          // Контактное лицо по проекту  -->
        QString proj_contact_position;      // Должность контактного лица  -->
        QString proj_contact_phone;         // Контактные телефоны по проекту  -->
        QString proj_contact_email;         // email  -->
        QString proj_present;               // Имя файла с презентацией проекта  -->
        QString proj_additional;            // Имя папки с дополнительной информацией  -->

public:
    Project(QString _proj_id = "12345", QString _proj_firm = "empty", QString _proj_name = "Кузя", QString _proj_state_order = "empty",
            QString _proj_branch = "empty", QString _proj_inform_type = "empty", QString _proj_stage = "empty", QString _proj_keywd = "empty",
            QString _proj_short_descr = "empty", QString _proj_description = "empty", QString _proj_innov = "empty",
            QString _proj_owner = "empty", QString _proj_poss_use = "empty", QString _proj_coll_type = "empty",
            QString _proj_coll_partner = "empty", QString _proj_partner_tasks = "empty", QString _proj_contact_name = "empty",
            QString _proj_contact_position = "empty", QString _proj_contact_phone = "empty",
            QString _proj_contact_email = "empty", QString _proj_present = "empty",QString _proj_additional = "empty"):
//Data(),
        proj_id(_proj_id),proj_firm(_proj_firm),proj_name(_proj_name),proj_state_order(_proj_state_order),
        proj_branch(_proj_branch),proj_inform_type(_proj_inform_type),proj_stage(_proj_stage),proj_keywd(_proj_keywd),
        proj_short_descr(_proj_short_descr),proj_description(_proj_description),proj_innov(_proj_innov),
        proj_owner(_proj_owner),proj_poss_use(_proj_poss_use),proj_coll_type(_proj_coll_type),
        proj_coll_partner(_proj_coll_partner),proj_partner_tasks(_proj_partner_tasks),proj_contact_name(_proj_contact_name),
        proj_contact_position(_proj_contact_position),proj_contact_phone(_proj_contact_phone),
        proj_contact_email(_proj_contact_email),proj_present(_proj_present),proj_additional(_proj_additional)
    {
        // тут бы надо организовать проверку, но кому она нужна??
        assert(_proj_id != "");
        P_id = P_idGenerator++;
    }

public: //к копирования
//========================================================================
//МОДЕРНИЗИРОВАТЬ В СЛУЧАЕ ПОЯВЛЕНИЯ УКАЗАТЕЛЕЙ В КЛАССЕ
//========================================================================
        Project(const Project& _prj);                //реализация в data.cpp

public: //опишем явный оператор присваивания
//========================================================================
//МОДЕРНИЗИРОВАТЬ В СЛУЧАЕ ПОЯВЛЕНИЯ УКАЗАТЕЛЕЙ В КЛАССЕ
//========================================================================
        Project& operator=(const Project& _prj);     //реализация в data.cpp

public:
    QString get_proj_id() const{return proj_id;}
    QString get_proj_firm() const{return proj_firm;}
    QString get_proj_name() const{return proj_name;}
    QString get_proj_state_order() const{return proj_state_order;}
    QString get_proj_branch() const{return proj_branch;}
    QString get_proj_inform_type() const{return proj_inform_type;}
    QString get_proj_stage() const{return proj_stage;}
    QString get_proj_keywd() const{return proj_keywd;}
    QString get_proj_short_descr() const{return proj_short_descr;}
    QString get_proj_description() const{return proj_description;}
    QString get_proj_innov() const{return proj_innov;}
    QString get_proj_owner() const{return proj_owner;}
    QString get_proj_poss_use() const{return proj_poss_use;}
    QString get_proj_coll_type() const{return proj_coll_type;}
    QString get_proj_coll_partner() const{return proj_coll_partner;}
    QString get_proj_partner_tasks() const{return proj_partner_tasks;}
    QString get_proj_contact_name() const{return proj_contact_name;}
    QString get_proj_contact_position() const{return proj_contact_position;}
    QString get_proj_contact_phone() const{return proj_contact_phone;}
    QString get_proj_contact_email() const{return proj_contact_email;}
    QString get_proj_present() const{return proj_present;}
    QString get_proj_additional() const{return proj_additional;}

    friend  QDebug operator<<(QDebug out, const Project& prj);
    friend  std::ostream& operator<<(std::ostream& out, const Project& prj);
    int getID_Project() const { return P_id; }
    static int get_idGenerator_Project() { return P_idGenerator;}

public: //виртуальные
        static int give_number_to_case(const QString& str);

        virtual void Show_name();  //определена в cpp
    virtual ~Project()
    {
       // std::cout << "Destructing Project " << std::endl;
    }


//public:
//        static int give_size_Firm_list_to_case() {return Firm_list_to_case.size();}
//        static QString give_str_Firm_list_to_case(int i){return Firm_list_to_case[i];}
        static void add_buffer(int for_case, Project *buf_One, const QString& str);
//        void clear_date(){
//            qDebug()<<"clear_date : Начало: "<<endl;
//            *this = Firm();   //ТУТ СТОИТ ПОДУМАТЬ НАД РЕАЛИЗАЦИЕЙ
//            qDebug()<<"clear_date : Конец!"<<endl;}



//public: //переопределённые методы
//        static int give_number_to_case(const QString& str);
//        virtual void Show_name(); //определена в cpp




};


#endif // PROJECTCLASS_H
