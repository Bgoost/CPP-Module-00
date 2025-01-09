#ifndef USERINPUT_HPP
# define USERINPUT_HPP

# include <iostream>
# include <string>
# include "PhoneBook.hpp"

// class PhoneBook;

class UserInput
{
    private:
        PhoneBook phonebook;
        std::string input;
        int error;
    public:
        UserInput();
        ~UserInput();
        void manager();
        void ask_user_contact();
        void search_contact();
        std::string prompt();
        std::string get_input();
};

#endif