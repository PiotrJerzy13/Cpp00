#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>


class Contact 
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void setContact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret);
    void display(int index = -1, bool summary = false) const;

private:
    static std::string truncateField(const std::string &field);
};

class PhoneBook 
{
private:
    Contact contacts[8];
    int currentIndex;
    int totalContacts;
	bool familyAdded;

public:
    PhoneBook();
    void addContact();
    void searchContacts() const;
	void addFamily();
};

void Menu();
void pauseBeforeClear(int seconds);
bool clearScreen();
bool handleEOF();

#endif
