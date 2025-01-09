#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
{
    len = 0;
    index = 0;
    std::cout << "PhoneBook created" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook destroyed" << std::endl;
}

void PhoneBook::display_contact(int index)
{
    std::cout << "First name: " << contact_arr[index].get_first_name() << std::endl;
    std::cout << "Last name: " << contact_arr[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << contact_arr[index].get_nickname() << std::endl;
    std::cout << "Phone number: " << contact_arr[index].get_phone_number() << std::endl;
    std::cout << "Secret: " << contact_arr[index].get_secret() << std::endl;
}

void PhoneBook::display_all_contacts()
{
    std::cout << CYAN << "╔══════════╦══════════╦══════════╦══════════╗" << RESET << std::endl;
    std::cout << CYAN << "║   " << RESET << "Index  "<< CYAN<< "║" << RESET << "First name"<< CYAN << "║ " << RESET << "Last name"<< CYAN << "║ " << RESET << "Nickname "<< CYAN << "║" << RESET << std::endl;
    std::cout << CYAN << "╠──────────╬──────────╬──────────╬──────────╣" << RESET << std::endl;

    for(int i = 0; i < len; i++)
    {
        std::cout << CYAN << "║" << RESET << std::setw(10) << i + 1 << CYAN << "│" << RESET;
        print_str(contact_arr[i].get_first_name(), 0);
        print_str(contact_arr[i].get_last_name(), 0);
        print_str(contact_arr[i].get_nickname(), 1);
        std::cout << std::endl;
    }
    std::cout << CYAN << "╚══════════╩══════════╩══════════╩══════════╝" << RESET << std::endl;
}

void PhoneBook::print_str(std::string str, int print_pretty)
{
    if(str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << str;
    if(!print_pretty)
        std::cout << CYAN << "│" << RESET;
    else
        std::cout << CYAN << "║" << RESET;
}

void PhoneBook::add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string secret)
{
    contact_arr[index].set_first_name(first_name);
    contact_arr[index].set_last_name(last_name);
    contact_arr[index].set_nickname(nickname);
    contact_arr[index].set_phone_number(phone_number);
    contact_arr[index].set_secret(secret);
    if(len < 8)
        len++;
    index++;
    index %= 8;
}

int PhoneBook::get_len()
{
    return len;
}

int PhoneBook::get_index()
{
    return index;
}

Contact *PhoneBook::get_contact_arr()
{
    return contact_arr;
}

