#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : oldest_contact(0), contact_count(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const std::string &first_name,
                           const std::string &last_name,
                           const std::string &nickname,
                           const std::string &phone,
                           const std::string &darkest_secret)
{
  if (contact_count == 8)
  {
    contacts[oldest_contact].setContact(first_name, last_name, nickname, phone, darkest_secret);
    oldest_contact = (oldest_contact == 7) ? 0 : oldest_contact + 1;
  }
  else
  {
    contacts[contact_count].setContact(first_name, last_name, nickname, phone, darkest_secret);
    contact_count++;
  }
}

std::string formatColumn(const std::string &text)
{
  if (text.length() > 10)
  {
    return (text.substr(0,9) + ".");
  }
  return text;
}

void PhoneBook::searchContact() const
{
  for (size_t i = 0; i < contact_count; i++)
  {
    std::cout << "|"
              << std::setw(10) << std::right << i << "|"
              << std::setw(10) << std::right << formatColumn(contacts[i].getFirstName()) << "|"
              << std::setw(10) << std::right << formatColumn(contacts[i].getLastName()) << "|"
              << std::setw(10) << std::right << formatColumn(contacts[i].getNickname()) << "|";
    std::cout << std::endl;
  }
}