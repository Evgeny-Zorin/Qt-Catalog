#include "projectclass.h"

void Project::Show_name(){ qDebug()<<"I am Show_name:: Project"<<endl;}

int Project::P_idGenerator = 1;

//к копирования(реализация)
Project::Project(const Project& _prj):
//Нет необходимости выполнять проверку входящих значений тут здесь, так как эта проверка уже осуществляется в конструкторе класса Project
     proj_id(_prj.proj_id),                             // номер проекта (10.1,10.2 и т.д.)  -->
     proj_firm(_prj.get_proj_firm()),                   // номер компании разработчика  -->
     proj_name(_prj.get_proj_name()),                   // Наименование проекта  -->
     proj_state_order(_prj.proj_state_order),           // Правительственные программы, в рамках которой выполняется проект  -->
     proj_branch(_prj.proj_branch),                     // Отрасли, которые могут использовать результаты проекта  -->
     proj_inform_type(_prj.proj_inform_type),           // Тип предоставляемой информации  -->
     proj_stage(_prj.proj_stage),                       // Стадия, на которой находится проект  -->
     proj_keywd(_prj.proj_keywd),                       // Ключевые слова проекта (для поиска по ключевым словам)  -->
     proj_short_descr(_prj.proj_short_descr),           // Краткое описание проекта  -->
     proj_description(_prj.proj_description),           // Подробное описание проекта  -->
     proj_innov(_prj.proj_innov),                       // Инновационные аспекты технологии  -->
     proj_owner(_prj.proj_owner),                       // Владелец технологии  -->
     proj_poss_use(_prj.proj_poss_use),                 // Возможное использование результатов проекта  -->
     proj_coll_type(_prj.proj_coll_type),               // Предлагаемые типы сотрудничества  -->
     proj_coll_partner(_prj.proj_coll_partner),         // Возможные типы партнеров по проекту  -->
     proj_partner_tasks(_prj.proj_partner_tasks),       // Перечень задач, которые должен будет решать партнер по проекту. Допускается HTML верстка  -->
     proj_contact_name(_prj.proj_contact_name),         // Контактное лицо по проекту  -->
     proj_contact_position(_prj.proj_contact_position), // Должность контактного лица  -->
     proj_contact_phone(_prj.proj_contact_phone),       // Контактные телефоны по проекту  -->
     proj_contact_email(_prj.proj_contact_email),       // email  -->
     proj_present(_prj.proj_present),                   // Имя файла с презентацией проекта  -->
     proj_additional(_prj.proj_additional)              // Имя папки с дополнительной информацией  -->
        {
          //  std::cout << "Project:: copy constructor worked here!\n"; // просто чтобы показать, что это работает
        }


//оператор присваивания(реализация)
Project& Project::operator=(const Project& _prj)
{
 // Проверка на самоприсваивание
    if (this == &_prj)
    {
        std::cout<<"Project:: himself!!!"<<std::endl;
        return *this;
    }
    else {
// Выполняем копирование значений
  this->proj_id = _prj.proj_id;                              // номер проекта (10.1,10.2 и т.д.)  -->
        proj_firm = _prj.proj_firm;                          // номер компании разработчика  -->
        proj_name = _prj.proj_name;                          // Наименование проекта  -->
        proj_state_order = _prj.proj_state_order;            // Правительственные программы, в рамках которой выполняется проект  -->
        proj_branch = _prj.proj_branch;                      // Отрасли, которые могут использовать результаты проекта  -->
        proj_inform_type = _prj.proj_inform_type;            // Тип предоставляемой информации  -->
        proj_stage = _prj.proj_stage;                        // Стадия, на которой находится проект  -->
        proj_keywd = _prj.proj_keywd;                        // Ключевые слова проекта (для поиска по ключевым словам)  -->
        proj_short_descr = _prj.proj_short_descr;            // Краткое описание проекта  -->
        proj_description = _prj.proj_description;            // Подробное описание проекта  -->
        proj_innov = _prj.proj_innov;                        // Инновационные аспекты технологии  -->
        proj_owner = _prj.proj_owner;                        // Владелец технологии  -->
        proj_poss_use = _prj.proj_poss_use;                  // Возможное использование результатов проекта  -->
        proj_coll_type = _prj.proj_coll_type;                // Предлагаемые типы сотрудничества  -->
        proj_coll_partner = _prj.proj_coll_partner;          // Возможные типы партнеров по проекту  -->
        proj_partner_tasks = _prj.proj_partner_tasks;        // Перечень задач, которые должен будет решать партнер по проекту. Допускается HTML верстка  -->
        proj_contact_name = _prj.proj_contact_name;          // Контактное лицо по проекту  -->
        proj_contact_position = _prj.proj_contact_position;  // Должность контактного лица  -->
        proj_contact_phone = _prj.proj_contact_phone;        // Контактные телефоны по проекту  -->
        proj_contact_email = _prj.proj_contact_email;        // email  -->
        proj_present = _prj.proj_present;                    // Имя файла с презентацией проекта  -->
        proj_additional = _prj.proj_additional;              // Имя папки с дополнительной информацией  -->

         std::cout << "Project:: Operator= worked here!\n";
     return *this;        // Возвращаем текущий объект
    }
}

QStringList Project::Project_list_to_case =
{
    "proj_id","proj_firm","proj_name","proj_state_order","proj_branch","proj_inform_type",
    "proj_stage","proj_keywd","proj_short_descr","proj_description","proj_innov","proj_owner",
    "proj_poss_use","proj_coll_type","proj_coll_partner","proj_partner_tasks","proj_contact_name",
    "proj_contact_position","proj_contact_phone","proj_contact_email","proj_present","proj_additional"};

int Project::give_number_to_case(const QString& str)   //доработать до полиморфизма бы
{
    int buf = 0;
        for (auto it = Project_list_to_case.begin(); it != Project_list_to_case.end(); it++)
        {
          if(*it == str)
          {
              return buf;
          }
          buf++;
        }
    return -1;
}

void Project::add_buffer(int for_case, Project *buf_One, const QString& str) //можно добавить в метод класса
{
    switch (for_case)
        {
            case 0:{
                buf_One->proj_id = str;
                break;
        }
            case 1:{
                buf_One->proj_firm = str;
                break;
        }
            case 2:{
                buf_One->proj_name = str;
                break;
        }

            case 3:{
                buf_One->proj_state_order = str;
                break;
        }
            case 4:{
                buf_One->proj_branch = str;
                break;
        }
            case 5:{
                buf_One->proj_inform_type = str;
                break;
        }
            case 6:{
                buf_One->proj_stage = str;
                break;
        }
            case 7:{
                buf_One->proj_keywd = str;
                break;
        }
            case 8:{
                buf_One->proj_short_descr = str;
                break;
        }
            case 9:{
                buf_One->proj_description = str;
                break;
        }
            case 10:{
                buf_One->proj_innov = str;
                break;
        }
            case 11:{
                buf_One->proj_owner = str;
                break;
        }
            case 12:{
                buf_One->proj_poss_use = str;
                break;
        }
            case 13:{
                buf_One->proj_coll_type = str;
                break;
        }
            case 14:{
                buf_One->proj_coll_partner = str;
                break;
        }
            case 15:{
                buf_One->proj_partner_tasks = str;
                break;
        }
            case 16:{
                buf_One->proj_contact_name = str;
                break;
        }
            case 17:{
                buf_One->proj_contact_position = str;
                break;
        }
            case 18:{
                buf_One->proj_contact_phone = str;
                break;
        }
            case 19:{
                buf_One->proj_contact_email = str;
                break;
        }
            case 20:{
                buf_One->proj_present = str;
                break;
        }
            case 21:{
                buf_One->proj_additional = str;
                break;
        }
//            case :{
//                buf_One- = str;
//                break;
//        }


        case -1:{
                //qDebug()<<"Вай Вай, не находить такой строка в тваема класс!!"<<endl;
                break;
        }
        default:{
            //qDebug()<<"Прилетела петрушка в Project::add_buffer"<<endl;
            }
        }
}




QDebug operator<<(QDebug out, const Project& prj)
{
    out<<"Name Project::"<<prj.proj_name<<"Short Name::"<<prj.proj_id;
    //out<<"\nя QDebug Project!"<<endl;
    return out.space();
}
