#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : oldestContact(0), contactCount(0) {}

void PhoneBook::addContact(const std::string &first_name,
                           const std::string &last_name,
                           const std::string &nickname,
                           const std::string &phone,
                           const std::string &darkest_secret) {
  if (contactCount == 8) {
    contacts[oldestContact].setContact(first_name, last_name, nickname, phone, darkest_secret);
    oldestContact = (oldestContact == 7) ? 0 : oldestContact + 1;
  } else {
    contacts[contactCount].setContact(first_name, last_name, nickname, phone, darkest_secret);
    contactCount++;
  }
}