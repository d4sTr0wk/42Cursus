#include "Contact.hpp"
#include <iostream>

Contact::Contact()
    : first_name(""), last_name(""), nickname(""), phone(""),
      darkest_secret("") {}
Contact::~Contact() {}

void Contact::setContact(const std::string &first_name,
                         const std::string &last_name,
                         const std::string &nickname, const std::string &phone,
                         const std::string &darkest_secret) {
  this->first_name = first_name;
  this->last_name = last_name;
  this->nickname = nickname;
  this->phone = phone;
  this->darkest_secret = darkest_secret;
}

std::string Contact::getFirstName() const
{
  return first_name;
}

std::string Contact::getLastName() const
{
  return last_name;
}

std::string Contact::getNickname() const
{
  return nickname;
}

std::string Contact::getPhone() const
{
  return phone;
}

std::string Contact::getDarkestSecret() const
{
  return darkest_secret;
}
