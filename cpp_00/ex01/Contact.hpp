#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>

class Contact {
private:
  std::string first_name;
  std::string last_name;
  std::string nickname;
  std::string phone;
  std::string darkest_secret;

public:
  Contact();
  ~Contact();

  void setContact(const std::string &first_name, const std::string &last_name, 
                  const std::string &nickname, const std::string &phone, 
                  const std::string &darkest_secret);
  

  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getNickname() const;
  std::string getPhone() const;
  std::string getDarkestSecret() const;
};

#endif