#include "firmclass.h"

void Firm::Show_name(){qDebug()<<"I am Show_name:: Firm"<<endl;}

int Firm::F_idGenerator = 1;


//к копирования(реализация)
Firm::Firm(const Firm& _firm):
//Нет необходимости выполнять проверку входящих значений тут здесь, так как эта проверка уже осуществляется в конструкторе класса Firm
     firm_logo(_firm.firm_logo),                               // Имя файла с логотипом компании -->
     firm_id(_firm.firm_id),                                   // Номер компании в каталоге. Связан с именем логотипа: если компания 10, то файл логотипа - 10.jpg или 10.png  -->
     firm_logo_style(_firm.firm_logo_style),                   //  0 - маленький логотип,  1 - широкий логотип, 2 - высокий -->
     firm_keywd(_firm.firm_keywd),                             // ключевые слова по компании  -->
     firm_short_name(_firm.firm_short_name),                   // Краткое имя компании (для использования в списках)  -->
     firm_name(_firm.firm_name),                               // Полное имя компании  -->
     firm_year(_firm.firm_year),                     // Год образования компании  -->
     firm_emp(_firm.firm_emp),                       // Количество сотрудников  -->
     firm_address(_firm.firm_address),                         // Адрес компании  -->
     firm_phone_number(_firm.firm_phone_number),               // Телефоны компании  -->
     firm_fax_number(_firm.firm_fax_number),                   // Факс  -->
     firm_email1(_firm.firm_email1),                           // email 1  -->
     firm_email2(_firm.firm_email2),                           // email 2  -->
     firm_url1(_firm.firm_branch),                        // Адрес сайта 1  -->
     firm_url2(_firm.firm_url2),                               // Адрес сайта 2  -->
     firm_branch(_firm.firm_branch),                 // Отрасли, для которых работает компания (формат - номера отраслей из каталога, разделенные символом "|")  -->
     firm_description(_firm.firm_description),       // Описание компании. Допускается HTML верстка  -->
     firm_present(_firm.firm_present),               // Имя файла с презентацией компании  -->
     firm_additional(_firm.firm_additional),         // Имя папки с дополнительной информацией по компании  -->
     firm_coll_type(_firm.firm_coll_type),           // типы сотрудничества, интересующие компанию (формат - номера типов сотрудничества из каталога, разделенные символом "|")  -->
     firm_partner_tasks(_firm.firm_partner_tasks),   // Перечень задач, которые должен будет решать партнер компании. Допускается HTML верстка    -->
     firm_contact_name(_firm.firm_contact_name),               // Контактное лицо компании  -->
     firm_contact_position(_firm.firm_contact_position),       // Должность контактного лица  -->
     firm_contact_email(_firm.firm_contact_email)              // Email контактного лица -->

        {
           // std::cout << "Firm:: Copy constructor worked here!\n"; // просто чтобы показать, что это работает
        }

//оператор присваивания(реализация)
Firm& Firm::operator=(const Firm& _firm)
{
// Проверка на самоприсваивание
    if (this == &_firm)
    {
        std::cout<<"Firm himself!!!"<<std::endl;
        return *this;
    }
    else {
// Выполняем копирование значений
         firm_logo = _firm.firm_logo;                              // Имя файла с логотипом компании -->
         firm_id = _firm.firm_id;                                  // Номер компании в каталоге. Связан с именем логотипа: если компания 10, то файл логотипа - 10.jpg или 10.png  -->
         firm_logo_style = _firm.firm_logo_style;                  //  0 - маленький логотип,  1 - широкий логотип, 2 - высокий -->
         firm_keywd = _firm.firm_keywd;                            // ключевые слова по компании  -->
         firm_short_name = _firm.firm_short_name;                  // Краткое имя компании (для использования в списках)  -->
         firm_name = _firm.firm_name;                              // Полное имя компании  -->
         firm_year = _firm.firm_year;                    // Год образования компании  -->
         firm_emp = _firm.firm_emp;                      // Количество сотрудников  -->
         firm_address = _firm.firm_address;                        // Адрес компании  -->
         firm_phone_number = _firm.firm_phone_number;              // Телефоны компании  -->
         firm_fax_number = _firm.firm_fax_number;                  // Факс  -->
         firm_email1 = _firm.firm_email1;                          // email 1  -->
         firm_email2 = _firm.firm_email2;                          // email 2  -->
         firm_url1 = _firm.firm_url1;                              // Адрес сайта 1  -->
         firm_url2 = _firm.firm_url2;                              // Адрес сайта 2  -->
         firm_branch = _firm.firm_branch;                // Отрасли, для которых работает компания (формат - номера отраслей из каталога, разделенные символом "|")  -->
         firm_description = _firm.firm_description;      // Описание компании. Допускается HTML верстка  -->
         firm_present = _firm.firm_present;              // Имя файла с презентацией компании  -->
         firm_additional = _firm.firm_additional;        // Имя папки с дополнительной информацией по компании  -->
         firm_coll_type = _firm.firm_coll_type;          // типы сотрудничества, интересующие компанию (формат - номера типов сотрудничества из каталога, разделенные символом "|")  -->
         firm_partner_tasks = _firm.firm_partner_tasks;  // Перечень задач, которые должен будет решать партнер компании. Допускается HTML верстка    -->
         firm_contact_name = _firm.firm_contact_name;              // Контактное лицо компании  -->
         firm_contact_position = _firm.firm_contact_position;      // Должность контактного лица  -->
         firm_contact_email = _firm.firm_contact_email;

        // std::cout << "Firm:: Operator= worked here!\n";

     return *this;        // Возвращаем текущий объект
    }
}

int Firm::give_number_to_case(const QString& str)   //доработать до полиморфизма бы
{
    int buf = 0;    //возвращаемое число=номер строчки
        for (auto it = Firm_list_to_case.begin(); it != Firm_list_to_case.end(); it++)
        {
          if(*it == str)
          {
              return buf;
          }
          buf++;
        }
    return -1;
}

void Firm::add_buffer(int for_case, Firm *buf_One, const QString& str) //можно добавить в метод класса
{
    switch (for_case)
        {
            case 0:{
                buf_One->firm_logo = str;
                break;
        }
            case 1:{
                buf_One->firm_id = str;
                break;
        }
            case 2:{
                buf_One->firm_logo_style = str;
                break;
        }

            case 3:{
                buf_One->firm_keywd = str;
                break;
        }
            case 4:{
                buf_One->firm_short_name = str;
                break;
        }
            case 5:{
                buf_One->firm_name = str;
                break;
        }
            case 6:{
                buf_One->firm_year = str;
                break;
        }
            case 7:{
                buf_One->firm_emp = str;
                break;
        }
            case 8:{
                buf_One->firm_address = str;
                break;
        }
            case 9:{
                buf_One->firm_phone_number = str;
                break;
        }
            case 10:{
                buf_One->firm_fax_number = str;
                break;
        }
            case 11:{
                buf_One->firm_email1 = str;
                break;
        }
            case 12:{
                buf_One->firm_email2 = str;
                break;
        }
            case 13:{
                buf_One->firm_url1 = str;
                break;
        }
            case 14:{
                buf_One->firm_url2 = str;
                break;
        }
            case 15:{
                buf_One->firm_branch = str;
                break;
        }
            case 16:{
                buf_One->firm_description = str;
                break;
        }
            case 17:{
                buf_One->firm_present = str;
                break;
        }
            case 18:{
                buf_One->firm_additional = str;
                break;
        }
            case 19:{
                buf_One->firm_coll_type = str;
                break;
        }
            case 20:{
                buf_One->firm_partner_tasks = str;
                break;
        }
            case 21:{
                buf_One->firm_contact_name = str;
                break;
        }
            case 22:{
                buf_One->firm_contact_position = str;
                break;
        }
            case 23:{
                buf_One->firm_contact_email = str;
                break;
        }
//            case 24:{
//                buf_One- = str;
//                break;
//        }

        case -1:{
                //qDebug()<<"Вай Вай, не находить такой строка в тваема класс!!"<<endl;
                break;
        }
        default:{
            //qDebug()<<"Прилетела петрушка в Firm::add_buffer"<<endl;
            }
        }
}


QDebug operator<<(QDebug out, const Firm& frm)
{
    out<<"logo:: "<<frm.firm_logo<<" id:: "<<frm.firm_id
    <<" logo_style:: "<<frm.firm_logo_style<<" keywd:: "<<frm.firm_keywd<<
      " short_name:: "<<frm.firm_short_name<<" name:: "<<frm.firm_name<<
      " firm_year:: "<<frm.firm_year<<" firm_emp:: "<<frm.firm_emp;
//    out<<"\nя QDebug Firm!"<<endl;
    return out.space();
}


std::ostream& operator<<(std::ostream& out, const Firm& frm)
{
    out<<"Ты попал на простой cout!!"<<std::endl;
    out<<frm.firm_logo<<frm.firm_name<<std::endl;
    return out;
}

QStringList Firm::Firm_list_to_case= {"logo","id","logo_style","keywd","short_name","name","firm_year",
                                      "firm_emp","address","phone_number","fax_number","email1","email2",
                                      "url1","url2","firm_branch","firm_description","firm_present",
                                      "firm_additional","firm_coll_type","firm_partner_tasks",
                                      "contact_name","contact_position","contact_email"};






