#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"
#include <iomanip>
#include <iostream>

class PhoneBook
{
private:
  Contact contacts[8];
  size_t oldest_contact;
  size_t contact_count;

public:
  PhoneBook();
  ~PhoneBook();

  void addContact(const std::string &first_name, const std::string &last_name,
                  const std::string &nickname, const std::string &phone,
                  const std::string &darkest_secret);
  void searchContact() const;
};

#endif