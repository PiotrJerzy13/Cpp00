#include "PhoneBook.hpp"

int main() {
    PhoneBook phoneBook;
    int choice;
    bool running = true;

    while (running) {
        Menu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Adding a new contact" << std::endl;
            phoneBook.addContact();
            break;
        case 2:
            std::cout << "Searching available contacts" << std::endl;
            phoneBook.searchContacts();
            break;
        case 3:
            std::cout << "Exiting Phonebook" << std::endl;
            std::cout << "Goodbye!" << std::endl;
            running = false;
            break;
        default:
            std::cout << "Invalid choice, please try again!" << std::endl;
        }
    }

    return 0;
}
