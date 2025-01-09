#include "UserInterface.hpp"
#include "PhoneBook.hpp"

UserInput::UserInput()
{
    input = "";
    error = 0;
    std::cout << "UserInput created" << std::endl;
}

UserInput::~UserInput()
{
    std::cout << "UserInput destroyed" << std::endl;
}

void UserInput::manager()
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

void UserInput::ask_user_contact()
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string secret;

    std::cout << "Enter first name: ";
    first_name = get_input();
    std::cout << "Enter last name: ";
    last_name = get_input();
    std::cout << "Enter nickname: ";
    nickname = get_input();
    std::cout << "Enter phone number: ";
    phone_number = get_input();
    std::cout << "Enter secret: ";
    secret = get_input();

    phonebook.add_contact(first_name, last_name, nickname, phone_number, secret);
    std::cout << YELLOW << "Contact added" << RESET << std::endl;
}

void UserInput::search_contact()
{
    std::cout << "Searching contact" << std::endl;
    phonebook.display_all_contacts();
    std::cout << "Enter contact index to reveal more info: ";
    std::string input = get_input();
    std::cout << "You entered: " << input << std::endl;

}

std::string UserInput::prompt()
{
    std::cout << "Enter input: ";
    return get_input();
}

std::string UserInput::get_input()
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
