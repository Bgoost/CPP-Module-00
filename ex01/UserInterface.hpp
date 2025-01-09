#ifndef USERINTERFACE_HPP
# define USERINTERFACE_HPP

# include <iostream>
# include <string>
# include "PhoneBook.hpp"

// class PhoneBook;

class UserInterface
{
    private:
        PhoneBook phonebook;
        std::string input;
        int error;
    public:
        UserInterface();
        ~UserInterface();
        void manager();
        void ask_user_contact();
        void search_contact();
        std::string prompt();
        std::string get_input();
};

#endif