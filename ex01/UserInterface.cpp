#include "UserInterface.hpp"

UserInterface::UserInterface()
{
    input = "";
    error = 0;
    std::cout << "UserInterface created" << std::endl;
}

UserInterface::~UserInterface()
{
    std::cout << "UserInterface destroyed" << std::endl;
}


void UserInterface::manager()
{
    while(1)
    {
        std::string input = prompt();
        if(error)
            return;
        std::cout << "You entered: " << input << std::endl;
        if(input == "exit" || input == "EXIT")
            return;
        else if(input == "add" || input == "ADD")
            ask_user_contact();
        else if(input == "search" || input == "SEARCH")
            search_contact();
        std::cout << GREEN << "PhoneBook" << RESET << std::endl;
    }
}

std::string UserInterface::ask_user_prompt(std::string prompt, bool (*f)(const std::string &))
{
    std::string tmp;
    while (tmp.empty())
    {
        std::cout << prompt;
        tmp = get_input();
        if (tmp.empty())
            std::cout << RED << "Can't input an empty string" << RESET << std::endl;
        else if (f(tmp) == false)
        {
            std::cout << RED << "Invalid input" << RESET << std::endl;
            tmp.clear();
        }
    }
    return tmp;
}

static bool is_alpha(const std::string &str)
{
    for (int i = 0; i < str[i]; i++)
    {
        if(!isalpha(str[i]))
            return false;
    }
    return true;
}

static bool is_alnum(const std::string &str)
{
    for (int i = 0; i < str[i]; i++)
    {
        if(!isalnum(str[i]))
            return false;
    }
    return true;
}



static bool is_num(const std::string &str)
{
    for (int i = 0; i < str[i]; i++)
    {
        if(!isdigit(str[i]))
            return false;
    }
    return true;
}

static bool is_empty(const std::string &str)
{
    for (int i = 0; i < str[i]; i++)
    {
        if(isspace(str[i]))
            return false;
    }
    return true;
}

void UserInterface::ask_user_contact()
{
    std::string tmp;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string secret;

    tmp = ask_user_prompt("Enter first name: ", is_num);
    first_name = tmp;
    tmp = ask_user_prompt("Enter last name: ", is_alpha);
    last_name = tmp;
    tmp = ask_user_prompt("Enter nickname: ", is_alnum);
    nickname = tmp;
    tmp = ask_user_prompt("Enter phone number: ", is_num);
    phone_number = tmp;
    tmp = ask_user_prompt("Enter secret: ", is_empty);
    secret = tmp;

    phonebook.add_contact(first_name, last_name, nickname, phone_number, secret);
    std::cout << YELLOW << "Contact added" << RESET << std::endl;
}

void UserInterface::search_contact()
{
    if(phonebook.get_len() == 0)
    {
        std::cout << RED << "No contacts to search, try adding some with the command add | ADD" << RESET << std::endl;
        return;
    }
    std::cout << "Searching contact" << std::endl;
    phonebook.display_all_contacts();
    std::cout << "Enter contact index to reveal more info: ";
    std::string input = get_input();
    std::cout << "You entered: " << input << std::endl;
    phonebook.display_contact(input);
}

std::string UserInterface::prompt()
{
    std::cout << "Enter input: ";
    return get_input();
}

std::string UserInterface::get_input()
{
    if(!getline(std::cin, input))
    {
        std::cout << "Don't CTRL+D mf(my friend)" << std::endl;
        std::cout << RED << "Exiting now" << RESET << std::endl;
        exit(1);
        return "";
    }
    return input;
}
