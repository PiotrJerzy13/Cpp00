#include "PhoneBook.hpp"

// Contact Class Definitions
void Contact::setContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret) {
    firstName = first;
    lastName = last;
    nickname = nick;
    phoneNumber = phone;
    darkestSecret = secret;
}

void Contact::display(int index, bool summary) const {
    if (summary) {
        // Display summary
        std::cout << std::setw(10) << index << "|"
                  << std::setw(10) << truncateField(firstName) << "|"
                  << std::setw(10) << truncateField(lastName) << "|"
                  << std::setw(10) << truncateField(nickname) << std::endl;
    } else {
        // Display details
        std::cout << "First Name: " << firstName << std::endl;
        std::cout << "Last Name: " << lastName << std::endl;
        std::cout << "Nickname: " << nickname << std::endl;
        std::cout << "Phone Number: " << phoneNumber << std::endl;
        std::cout << "Darkest Secret: " << darkestSecret << std::endl;
    }
}

bool Contact::isEmpty() const {
    return firstName.empty();
}

// Add 'static' here to match the header declaration
std::string Contact::truncateField(const std::string &field) {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

// PhoneBook Class Definitions
PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {}

void PhoneBook::addContact() {
    std::cin.ignore(); // Clear the input buffer
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);

    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "Error: All fields must be filled!" << std::endl;
        return;
    }

    contacts[currentIndex].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    currentIndex = (currentIndex + 1) % 8;
    totalContacts = std::min(totalContacts + 1, 8);

    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContacts() const {
    if (totalContacts == 0) {
        std::cout << "No contacts to display." << std::endl;
        return;
    }

    // Display headers
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(44, '-') << std::endl;

    // Display summaries
    for (int i = 0; i < totalContacts; ++i) {
        contacts[i].display(i, true);
    }

    // Prompt for detailed view
    std::cout << "Enter the index of the contact to view details: ";
    int index;
    std::cin >> index;

    if (index < 0 || index >= totalContacts || contacts[index].isEmpty()) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    // Display details
    contacts[index].display();
}

// Menu Function Definition
void Menu() {
    std::cout << "************ MENU *************" << std::endl;
    std::cout << "1. Add a new Contact" << std::endl;
    std::cout << "2. Search available Contacts" << std::endl;
    std::cout << "3. Exit Phonebook" << std::endl;
    std::cout << "*******************************" << std::endl;
}

