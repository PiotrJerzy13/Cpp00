#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    int choice;
    bool running = true;

    while (running)
	{
        Menu();
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice))
		{
            if (handleEOF()) break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again!" << std::endl;
            continue;
        }

        switch (choice) 
		{
            case 1:
                std::cout << "Adding a new contact" << std::endl;
                phoneBook.addContact();
                pauseBeforeClear(2);
                clearScreen();
                break;
            case 2:
                std::cout << "Searching available contacts" << std::endl;
                phoneBook.searchContacts();
                pauseBeforeClear(4);
                clearScreen();
                break;
            case 3:
                std::cout << "Adding family contacts" << std::endl;
                phoneBook.addFamily();
                pauseBeforeClear(2);
                clearScreen();
                break;
            case 4:
                std::cout << "Exiting Phonebook" << std::endl;
                std::cout << "Goodbye!" << std::endl;
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again!" << std::endl;
                pauseBeforeClear(2);
                clearScreen();
                break;
        }
    }

    return 0;
}
