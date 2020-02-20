#ifndef FIRMCLASS_H
#define FIRMCLASS_H
#include "BaseClass.h"



class Firm  : public BaseClass
{
private:
    static int F_idGenerator;       //общий счетчик объектов класса (remove it)
    int F_id;                       //уникальный номер класса (remove it)

    static QStringList Firm_list_to_case;

private:                       // Данные по компании
        QString firm_logo;                       // Имя файла с логотипом компании -->
        QString firm_id;                         // Номер компании в каталоге. Связан с именем логотипа: если компания 10, то файл логотипа - 10.jpg или 10.png  -->
        QString firm_logo_style;                 //  0 - маленький логотип,  1 - широкий логотип, 2 - высокий -->
        QString firm_keywd;                      // ключевые слова по компании  -->
        QString firm_short_name;                 // Краткое имя компании (для использования в списках)  -->
        QString firm_name;                       // Полное имя компании  -->
        QString firm_year;                       // Год образования компании  -->
        QString firm_emp;                        // Количество сотрудников  -->
        QString firm_address;                    // Адрес компании  -->
        QString firm_phone_number;               // Телефоны компании  -->
        QString firm_fax_number;                 // Факс  -->
        QString firm_email1;                     // email 1  -->
        QString firm_email2;                     // email 2  -->
        QString firm_url1;                       // Адрес сайта 1  -->
        QString firm_url2;                       // Адрес сайта 2  -->
        QString firm_branch;                     // Отрасли, для которых работает компания (формат - номера отраслей из каталога, разделенные символом "|")  -->
        QString firm_description;                // Описание компании. Допускается HTML верстка  -->
        QString firm_present;                    // Имя файла с презентацией компании  -->
        QString firm_additional;                 // Имя папки с дополнительной информацией по компании  -->
        QString firm_coll_type;                  // типы сотрудничества, интересующие компанию (формат - номера типов сотрудничества из каталога, разделенные символом "|")  -->
        QString firm_partner_tasks;              // Перечень задач, которые должен будет решать партнер компании. Допускается HTML верстка    -->
        QString firm_contact_name;               // Контактное лицо компании  -->
        QString firm_contact_position;           // Должность контактного лица  -->
        QString firm_contact_email;              // Email контактного лица -->

 public:
       // Firm(){}
//к по умолчанию+к от параметров
        Firm(QString _logo = "empty", QString _id = "empty", QString _logo_style = "empty", QString _keywd = "empty",
             QString _short_name = "empty", QString _name = "TestName", QString _firm_year = "empty",
             QString _firm_emp = "empty", QString _address = "empty", QString _phone_number = "empty",
             QString _fax_number = "empty", QString _email1 = "empty",QString _email2 = "empty",
             QString _url1 = "empty",QString _url2 = "empty", QString _firm_branch = "empty",
             QString _firm_description = "empty", QString _firm_present = "empty", QString _firm_additional = "empty",
             QString _firm_coll_type = "empty", QString _firm_partner_tasks = "empty", QString _contact_name = "empty",
             QString _contact_position = "empty", QString _contact_email = "empty"):
//Data(),
            firm_logo(_logo),firm_id(_id),firm_logo_style(_logo_style),firm_keywd(_keywd),firm_short_name(_short_name),
            firm_name(_name),firm_year(_firm_year),firm_emp(_firm_emp),firm_address(_address),firm_phone_number(_phone_number),
            firm_fax_number(_fax_number),firm_email1(_email1),firm_email2(_email2),firm_url1(_url1),firm_url2(_url2),
            firm_branch(_firm_branch),firm_description(_firm_description),firm_present(_firm_present),
            firm_additional(_firm_additional),firm_coll_type(_firm_coll_type),firm_partner_tasks(_firm_partner_tasks),
            firm_contact_name(_contact_name),firm_contact_position(_contact_position),firm_contact_email(_contact_email)
        {
            // тут бы надо организовать проверку
            assert(_logo != "");
            F_id = F_idGenerator++;
           // qDebug()<<"Сработал конструктор Firm"<<endl;
        }

public: //к копирования
//========================================================================
//МОДЕРНИЗИРОВАТЬ В СЛУЧАЕ ПОЯВЛЕНИЯ УКАЗАТЕЛЕЙ В КЛАССЕ
//========================================================================
        Firm(const Firm& _firm);                //реализация в data.cpp

public: //опишем явный оператор присваивания
//========================================================================
//МОДЕРНИЗИРОВАТЬ В СЛУЧАЕ ПОЯВЛЕНИЯ УКАЗАТЕЛЕЙ В КЛАССЕ
//========================================================================
        Firm& operator=(const Firm& _firm);     //реализация в data.cpp

public:
        QString get_logo() const{return firm_logo;}
        QString get_id() const{return firm_id;}
        QString get_logo_style() const{return firm_logo_style;}
        QString get_keywd() const{return firm_keywd;}
        QString get_short_name() const{return firm_short_name;}
        QString get_name() const{return firm_name;}
        QString get_firm_year() const{return firm_year;}
        QString get_firm_emp() const{return firm_emp;}
        QString get_address() const{return firm_address;}
        QString get_phone_number() const{return firm_phone_number;}
        QString get_fax_number() const{return firm_fax_number;}
        QString get_email1() const{return firm_email1;}
        QString get_email2() const{return firm_email2;}
        QString get_url1() const{return firm_url1;}
        QString get_url2() const{return firm_url2;}
        QString get_firm_branch() const{return firm_branch;}
        QString get_firm_description() const{return firm_description;}
        QString get_firm_present() const{return firm_present;}
        QString get_firm_additional() const{return firm_additional;}
        QString get_firm_coll_type() const{return firm_coll_type;}
        QString get_firm_partner_tasks() const{return firm_partner_tasks;}
        QString get_contact_name() const{return firm_contact_name;}
        QString get_contact_position() const{return firm_contact_position;}
        QString get_contact_email() const{return firm_contact_email;}
//Сеттеры наверно не нужны ?
        void set_logo(const QString& atr){firm_logo = atr;}
        void set_id(const QString& atr){firm_id = atr;}
        void set_logo_style(const QString& atr){firm_logo_style = atr;}
        void set_keywd(const QString& atr){firm_keywd = atr;}
        void set_short_name(const QString& atr){firm_short_name = atr;}
        void set_name(const QString& atr){firm_name = atr;}
        void set_firm_year(const QString& atr){firm_year = atr;}

        friend  QDebug operator<<(QDebug out, const Firm& frm);
        friend  std::ostream& operator<<(std::ostream& out, const Firm& frm);
        int getID_Firm() const { return F_id; }
        static int get_idGenerator_Firm() { return F_idGenerator;}

public:
        static int give_size_Firm_list_to_case() {return Firm_list_to_case.size();}
        static QString give_str_Firm_list_to_case(int i){return Firm_list_to_case[i];}
        static void add_buffer(int for_case, Firm *buf_One, const QString& str);
        void clear_date(){
           // qDebug()<<"clear_date : Начало: "<<endl;
            *this = Firm();   //ТУТ СТОИТ ПОДУМАТЬ НАД РЕАЛИЗАЦИЕЙ
           // qDebug()<<"clear_date : Конец!"<<endl;
        }


public: //переопределённые методы
        static int give_number_to_case(const QString& str); //реализация в data.cpp
        virtual void Show_name(); //определена в cpp

        virtual ~Firm()
        {
          //  std::cout << "Destructing Firm " << std::endl;
        }

};

#endif // FIRMCLASS_H
