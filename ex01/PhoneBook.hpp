#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>

// Class to represent a single contact
class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void setContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
    void display(int index = -1, bool summary = false) const;
    bool isEmpty() const;

private:
    static std::string truncateField(const std::string &field);
};

// Class to manage the phonebook
class PhoneBook {
private:
    Contact contacts[8];
    int currentIndex;
    int totalContacts;

public:
    PhoneBook();
    void addContact();
    void searchContacts() const;
};

// Function to display the menu
void Menu();

#endif // PHONEBOOK_HPP
