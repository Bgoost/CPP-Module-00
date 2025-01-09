#include "PhoneBook.hpp"
#include "UserInterface.hpp"

int main()
{
    // PhoneBook phonebook;
    UserInput userinput;

    // phonebook.add_contact("John", "Doe", "JD", "123456789", "secret1");
    // phonebook.add_contact("Jane", "Doe", "Jane", "987654", "secret2");
    // phonebook.add_contact("Dave", "Smith", "JS", "123456", "secret3");
    // phonebook.add_contact("Cristina", "Smith", "Jane", "987654", "secret4");
    // phonebook.add_contact("Pablo", "Johnson", "JJ", "123", "secret5");
    // phonebook.add_contact("12345678", "12345678910", "12345678910", "12345678910", "12345678910");

    // phonebook.display_all_contacts();

    std::cout << RED << "████▓▓▓▓▒▒▒▒░░░░" << RESET << std::endl;
    std::cout << BLUE << "████▓▓▓▓▒▒▒▒░░░░" << RESET << std::endl;
    std::cout << GREEN << "████▓▓▓▓▒▒▒▒░░░░" << RESET << std::endl;
    std::cout << YELLOW << "████▓▓▓▓▒▒▒▒░░░░" << RESET << std::endl;
    std::cout << CYAN << "████▓▓▓▓▒▒▒▒░░░░" << RESET << std::endl;
    std::cout << MAGENTA << "████▓▓▓▓▒▒▒▒░░░░" << RESET << std::endl;
    std::cout << WHITE << "████▓▓▓▓▒▒▒▒░░░░" << RESET << std::endl;
    std::cout << BOLDBLACK << "████▓▓▓▓▒▒▒▒░░░░" << RESET << std::endl;
    std::cout << BOLDRED << "████▓▓▓▓▒▒▒▒░░░░" << RESET << std::endl;


    userinput.manager();



    return 0;
}