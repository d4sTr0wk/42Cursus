#include "PhoneBook.hpp"

void addContact(PhoneBook &phonebook)
{
  std::string firstName, lastName, nickname, phone, darkestSecret;

  std::cout << "Introduce first_name: ";
  std::cin >> firstName;
  std::cout << "Introduce last_name: ";
  std::cin >> lastName;
  std::cout << "Introduce nickname: ";
  std::cin >> nickname;
  std::cout << "Introduce phone: ";
  std::cin >> phone;
  std::cout << "Introduce darkest secret: ";
  std::cin >> darkestSecret;
  phonebook.addContact(firstName, lastName, nickname, phone, darkestSecret);
  std::cout << "Contact added!" << std::endl;
}

int main()
{
  PhoneBook *phonebook = new PhoneBook();
  std::string command;
  std::string firstName, lastName, nickname, phone, darkestSecret;
  while (true)
  {
    std::cout << "Introduce command (ADD, SEARCH, EXIT): ";
    std::cin >> command;
    if (command == "EXIT")
    {
      std::cout << "Exiting program." << std::endl;
      delete phonebook;
      break;
    }
    else if (command == "ADD")
      addContact(*phonebook);
    else if (command == "SEARCH")
      phonebook->searchContact();
    else
      std::cout << "Introduce a valid command." << std::endl;
  }
  return 0;
}