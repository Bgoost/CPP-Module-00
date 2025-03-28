#include "Contact.hpp"

Contact::Contact()
{
    first_name = "";
    last_name = "";
    nickname = "";
    phone_number = "";
    secret = "";
}

Contact::~Contact()
{
}

void Contact::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}

void Contact::set_last_name(std::string last_name)
{
    this->last_name = last_name;
}

void Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}

void Contact::set_phone_number(std::string phone_number)
{
    this->phone_number = phone_number;
}

void Contact::set_secret(std::string secret)
{
    this->secret = secret;
}

std::string Contact::get_first_name()
{
    return first_name;
}

std::string Contact::get_last_name()
{
    return last_name;
}

std::string Contact::get_nickname()
{
    return nickname;
}

std::string Contact::get_phone_number()
{
    return phone_number;
}

std::string Contact::get_secret()
{
    return secret;
}
