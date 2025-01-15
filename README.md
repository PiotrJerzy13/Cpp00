# README for C++ Module 00 - Exercises 00 and 01

## Overview

This repository contains solutions for **Exercise 00: Megaphone** and **Exercise 01: My Awesome PhoneBook**, which are part of C++ Module 00. These exercises introduce fundamental concepts of C++ programming, such as classes, member functions, input/output streams, and object-oriented design.

---

## Exercise 00: Megaphone

### Description
The **Megaphone** program is a simple utility that converts any given input into uppercase letters. If no input is provided, it outputs a predefined message to simulate a "megaphone" effect.

### Features
- Converts lowercase letters to uppercase.
- Accepts multiple arguments and combines them into a single uppercase string.
- Outputs a default message if no arguments are provided.

### Example Usage
```bash
$ ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$ ./megaphone Damnit "!" "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

$ ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

---

## Exercise 01: My Awesome PhoneBook

### Description
The **My Awesome PhoneBook** program is a basic console-based contact management system. It allows users to store, search, and manage up to 8 contacts. It demonstrates class-based design, encapsulation, and interactive console I/O.

### Features
1. **Contact Management**
   - Store up to 8 contacts in the phonebook.
   - Automatically overwrite the oldest contact when the limit is reached.

2. **Commands**
   The program offers a menu-driven system for user interaction. The menu looks as follows:

   ```
   ************ MENU **************
   * 1. Add a new Contact         *
   * 2. Search Contacts           *
   * 3. Add Family (5)            *
   * 4. Exit Phonebook            *
   ********************************
   ```

   - **Option 1 (`ADD`)**: Add a new contact by providing details for the following fields:
     - First Name
     - Last Name
     - Nickname
     - Phone Number
     - Darkest Secret

   - **Option 2 (`SEARCH`)**: Display all saved contacts in a tabular format with the following columns:
     - Index
     - First Name
     - Last Name
     - Nickname
     - Each column is truncated to 10 characters and right-aligned. You can then select a contact by index to view detailed information.

   - **Option 3 (`ADD FAMILY`)**: Add up to 5 predefined "family" contacts at once. This allows for quick batch additions without manual input for each field.

   - **Option 4 (`EXIT`)**: Quit the program and clear all saved data.

3. **Batch Contact Addition**
   - Using the "Add Family" option, users can quickly populate the phonebook with multiple contacts simultaneously, saving time and effort.

4. **Screen Cleaning Feature**
   - The program includes a **screen-clearing feature** that automatically clears the console after a few seconds, ensuring a cleaner interface between operations.

5. **Input Validation**
   - Ensures no contact field is left empty during the `ADD` command.
   - Handles invalid inputs gracefully in the `SEARCH` command.

---

### Example Usage
```bash
************ MENU **************
* 1. Add a new Contact         *
* 2. Search Contacts           *
* 3. Add Family (5)            *
* 4. Exit Phonebook            *
********************************

Enter your choice: 3
Adding family contacts
Family contacts added successfully!

[The screen will clear after a few seconds for a cleaner interface.]

************ MENU **************
* 1. Add a new Contact         *
* 2. Search Contacts           *
* 3. Add Family (5)            *
* 4. Exit Phonebook            *
********************************

Enter your choice: 2
Index     |First Name|Last Name |Nickname  
--------------------------------------------
1         |John      |Doe       |Johnny    
2         |Jane      |Doe       |Janie     
3         |Jim       |Beam      |Jimmy     
4         |Jill      |Hill      |Jilly     
5         |Jack      |Black     |Jacky     

Enter the index of the contact to view details: 3
First Name: Jim
Last Name: Beam
Nickname: Jimmy
Phone Number: 112233445
Darkest Secret: Loves whiskey
```

---

## Key Learning Points
- **Exercise 00** introduces basic input/output handling and string manipulation in C++.
- **Exercise 01** builds on this by implementing object-oriented principles like class design, encapsulation, and user interaction.

This program showcases practical enhancements such as batch contact addition and screen clearing, offering a clean and efficient user experience.
