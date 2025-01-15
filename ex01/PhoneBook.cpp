
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0), familyAdded(false) {}

void PhoneBook::addContact()
{
    std::cin.ignore();
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    if (handleEOF()) return;

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);
    if (handleEOF()) return;

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);
    if (handleEOF()) return;

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);
    if (handleEOF()) return;

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
    if (handleEOF()) return;

    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
	{
        std::cout << "Error: All fields must be filled!" << std::endl;
        return;
    }

    contacts[currentIndex].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    currentIndex = (currentIndex + 1) % 8;
    totalContacts = std::min(totalContacts + 1, 8);
}

void PhoneBook::addFamily()
{
    if (familyAdded) 
	{
        std::cout << "Family contacts have already been added." << std::endl;
        return;
    }

    struct PredefinedContact 
	{
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
    };

    const PredefinedContact familyContacts[5] = {
        {"John", "Doe", "Johnny", "123456789", "Loves pizza"},
        {"Jane", "Doe", "Janie", "987654321", "Afraid of spiders"},
        {"Jim", "Beam", "Jimmy", "112233445", "Loves whiskey"},
        {"Jill", "Hill", "Jilly", "556677889", "Secretly sings"},
        {"Jack", "Black", "Jacky", "998877665", "Fears heights"}
    };

    for (int i = 0; i < 5; ++i) 
	{
        contacts[currentIndex].setContact(
            familyContacts[i].firstName,
            familyContacts[i].lastName,
            familyContacts[i].nickname,
            familyContacts[i].phoneNumber,
            familyContacts[i].darkestSecret
        );
        currentIndex = (currentIndex + 1) % 8;
        totalContacts = std::min(totalContacts + 1, 8);
    }

    familyAdded = true;
    std::cout << "Family contacts added successfully!" << std::endl;
}

void PhoneBook::searchContacts() const
{
    if (totalContacts == 0)
	{
        std::cout << "No contacts to display." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(44, '-') << std::endl;

    for (int i = 0; i < totalContacts; ++i)
	{
        contacts[i].display(i + 1, true);
    }

    std::cout << "Enter the index of the contact to view details: ";
    int index;
    std::cin >> index;

    if (std::cin.fail() || index < 1 || index > totalContacts)
	{
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    contacts[index - 1].display();
}


void Contact::setContact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret)
{
    firstName = first;
    lastName = last;
    nickname = nick;
    phoneNumber = phone;
    darkestSecret = secret;
}

void Contact::display(int index, bool summary) const
{
    if (summary)
	{
        std::cout << std::setw(10) << index << "|"
                  << std::setw(10) << truncateField(firstName) << "|"
                  << std::setw(10) << truncateField(lastName) << "|"
                  << std::setw(10) << truncateField(nickname) << std::endl;
    } 
	else
	{
        std::cout << "First Name: " << firstName << std::endl;
        std::cout << "Last Name: " << lastName << std::endl;
        std::cout << "Nickname: " << nickname << std::endl;
        std::cout << "Phone Number: " << phoneNumber << std::endl;
        std::cout << "Darkest Secret: " << darkestSecret << std::endl;
    }
}

std::string Contact::truncateField(const std::string& field)
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

bool clearScreen()
{
    int ret = system("clear");
    if (ret != 0) {
        std::cerr << "Failed to clear the screen!" << std::endl;
        return false;
    }
    return true;
}

void pauseBeforeClear(int seconds)
{
    clock_t start_time = clock();
    while ((clock() - start_time) / CLOCKS_PER_SEC < static_cast<unsigned long>(seconds)) {}
    clearScreen();
}

bool handleEOF()
{
    if (std::cin.eof()) {
        std::cout << "\nEOF detected (Ctrl+D). Exiting program." << std::endl;
        std::cin.clear();
        return true;
    }
    return false;
}

void Menu()
{
    std::cout << "************ MENU **************" << std::endl;
    std::cout << "* 1. Add a new Contact         *" << std::endl;
    std::cout << "* 2. Search Contacts           *" << std::endl;
    std::cout << "* 3. Add Family (5)            *" << std::endl;
    std::cout << "* 4. Exit Phonebook            *" << std::endl;
    std::cout << "********************************" << std::endl;
}

