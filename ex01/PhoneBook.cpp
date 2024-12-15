#include "PhoneBook.hpp"

using namespace std;

// Contact Class Definitions
void Contact::setContact(string first, string last, string nick, string phone, string secret) {
    firstName = first;
    lastName = last;
    nickname = nick;
    phoneNumber = phone;
    darkestSecret = secret;
}

void Contact::display(int index, bool summary) const {
    if (summary) {
        // Display summary
        cout << setw(10) << index << "|"
             << setw(10) << truncateField(firstName) << "|"
             << setw(10) << truncateField(lastName) << "|"
             << setw(10) << truncateField(nickname) << endl;
    } else {
        // Display details
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Nickname: " << nickname << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Darkest Secret: " << darkestSecret << endl;
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
    cin.ignore(); // Clear the input buffer
    string firstName, lastName, nickname, phoneNumber, darkestSecret;

    cout << "Enter First Name: ";
    getline(cin, firstName);
    cout << "Enter Last Name: ";
    getline(cin, lastName);
    cout << "Enter Nickname: ";
    getline(cin, nickname);
    cout << "Enter Phone Number: ";
    getline(cin, phoneNumber);
    cout << "Enter Darkest Secret: ";
    getline(cin, darkestSecret);

    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
        cout << "Error: All fields must be filled!" << endl;
        return;
    }

    contacts[currentIndex].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    currentIndex = (currentIndex + 1) % 8;
    totalContacts = min(totalContacts + 1, 8);

    cout << "Contact added successfully!" << endl;
}

void PhoneBook::searchContacts() const {
    if (totalContacts == 0) {
        cout << "No contacts to display." << endl;
        return;
    }

    // Display headers
    cout << setw(10) << "Index" << "|"
         << setw(10) << "First Name" << "|"
         << setw(10) << "Last Name" << "|"
         << setw(10) << "Nickname" << endl;
    cout << string(44, '-') << endl;

    // Display summaries
    for (int i = 0; i < totalContacts; ++i) {
        contacts[i].display(i, true);
    }

    // Prompt for detailed view
    cout << "Enter the index of the contact to view details: ";
    int index;
    cin >> index;

    if (index < 0 || index >= totalContacts || contacts[index].isEmpty()) {
        cout << "Invalid index!" << endl;
        return;
    }

    // Display details
    contacts[index].display();
}

// Menu Function Definition
void Menu() {
    cout << "************ MENU *************" << endl;
    cout << "1. Add a new Contact" << endl;
    cout << "2. Search available Contacts" << endl;
    cout << "3. Exit Phonebook" << endl;
    cout << "*******************************" << endl;
}
