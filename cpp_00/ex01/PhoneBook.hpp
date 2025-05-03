#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
  private:
    Contact contacts[8];
    size_t oldestContact;
    size_t contactCount;

  public:
    PhoneBook();
    ~PhoneBook();

    void addContact(const std::string &first_name, const std::string &last_name, 
                    const std::string &nickname, const std::string &phone,
                    const std::string &darkest_secret);
    void searchContact() const;
};

#endif