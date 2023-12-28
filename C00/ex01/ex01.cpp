#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

std::string GetNewLine(std::string message)
{
    std::string input;

    std::cout << message;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, input);

    return(input);
}

void printer10(std::string message)
{
    if(message.size() >= 10)
        std::cout << '|' << message.substr(0, 9) << '.';
    else
        std::cout << '|' << std::setw(10) << message;
}

std::string NO_EMPTY_INPUT(std::string message)
{
    std::string input;

    while (1)
    {
        input = GetNewLine(message);
        if (!input.size())
            std::cout << "Lutfen bos birakmayiniz" << std::endl;
        else
            break;
    }
    return(input);
}

class Contact{
private:
    std::string first;
    std::string last;
    std::string nickname;
    std::string phone;
    std::string DARKEST;
public:
    void push_info(std::string, std::string, std::string, std::string, std::string);
    std::string clone_info(std::string info);
};

std::string Contact::clone_info(std::string info){
    if(!info.compare("first"))
        return(this->first);
    else if(!info.compare("last"))
        return(this->last);
    else if(!info.compare("nickname"))
        return(this->nickname);
    else if (!info.compare("phone"))
        return(this->phone);
    else if(!info.compare("DARKEST"))
        return(this->DARKEST);
    return ("salak misin evladim");
}

class PhoneBook{
private:
    Contact contacts[8];
    int index;
public:
    PhoneBook();
    void add(void);
    void search(void);
    void init(void);
};

PhoneBook::PhoneBook(){
    index = 0;
}

void Contact::push_info(std::string first, std::string last, std::string nickname, std::string phone, std::string DARKEST){
    this->first = first;
    this->last = last;
    this->nickname = nickname;
    this->phone = phone;
    this->DARKEST = DARKEST;
}

void PhoneBook::add(void){
    std::string first;
    std::string last;
    std::string nickname;
    std::string phone;
    std::string DARKEST;

    first = NO_EMPTY_INPUT("Lütfen eklemek istediğiniz kişinin ilk adini girinis: ");
    last = NO_EMPTY_INPUT("Lütfen soyadini giriniz: ");
    nickname = NO_EMPTY_INPUT("Lütfen takma adini giriniz: ");
    phone = NO_EMPTY_INPUT("Lütfen telefon numarasini giriniz: ");
    DARKEST = NO_EMPTY_INPUT("Lütfen EN KARANLIK SIRRINI giriniz: ");

    if (this->index == 8)
        this->index = 0;
    this->contacts[this->index++].push_info(first, last, nickname, phone, DARKEST);
}

void PhoneBook::search(void){
    int input_n;
    std::string input;
    size_t size = sizeof(this->contacts) / sizeof(this->contacts[0]);

    std::cout   << "|--------------Contact Display--------------|\n"
                << "|-------------------------------------------|\n"
	            << "|     Index|First Name| Last Name|  Nickname|\n"
	            << "|-------------------------------------------|\n";

    for(int i = 0; i < size; i++){
        std::cout << '|' << std::setw(10) << i + 1;
        printer10(this->contacts[i].clone_info("first"));
        printer10(this->contacts[i].clone_info("last"));
        printer10(this->contacts[i].clone_info("nickname"));
        std::cout << '|' << "\n";
    }
    
    while(1)
    {
        input = GetNewLine("Kaçinci kullanicinin numarasina erişmek istiyorsunuz: ");
        input_n = std::stoi(input);
        if (input_n > 8 && input_n < 0)
            std::cout << "Lutfen min 1 max 8 rakamlari arasinda bir deger giriniz" << std::endl;
        else
            break ;
    }
    std::cout << "First name: " << this->contacts[input_n - 1].clone_info("first") << std::endl;
    std::cout << "Last name: " << this->contacts[input_n - 1].clone_info("last") << std::endl;
    std::cout << "Phone number: " << this->contacts[input_n - 1].clone_info("phone") << std::endl;
}

int main()
{
    int i = 0;
    PhoneBook phoneBook;
    std::string command;


    while(1)
    {
        command = GetNewLine("Lütfen ADD, SEARCH veya EXIT komutlarindan birisini giriniz: ");
        if (!command.compare("ADD"))
            phoneBook.add();
        else if (!command.compare("SEARCH"))
            phoneBook.search();
        else if(!command.compare("EXIT"))
            return(0);
    }
}
