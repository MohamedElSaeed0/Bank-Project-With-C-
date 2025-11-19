# Bank System Project (OOP Version)

This is a console-based Banking System I developed to master **C++ Object-Oriented Programming (OOP)**.
The main goal of this project was to move away from procedural programming and build a modular, clean, and organized system using Classes and Objects.

 About the Project
Unlike simple console apps, I designed this system to mimic real-world logic. It doesn't use a SQL database; instead, I built my own **File Handling System** to store Clients and Users data in text files, acting as a simple database.

**Key concepts I applied:**
* **OOP Principles:** Encapsulation, Inheritance, Polymorphism, and Abstraction.
* **Separation of Concerns:** I separated the Logic (Classes) from the UI (Screens).
* **File Streaming:** Reading/Writing data to `.txt` files securely.

 Features is:
* **Client Operations:** Add, Delete, Update, and Find clients.
* **Transactions:** Deposit, Withdraw, and Transfer money between accounts.
* **Security:**
    * Users Login/Logout system.
    * **Permissions System:** Admins can have specific access rights.
    * Failed password attempts limits.
* **Logs:** The system keeps a log of all transfers and login activities.

## Code Structure
I organized the code into header files for better readability:
* `clsBankClient.h`: Handles client logic.
* `clsUser.h`: Handles system users logic.
* `clsMainScreen.h`: The entry point menu.
* `clsInputValidate.h`: My custom library to handle user input errors.

## Quick Start
Open `BankProject.sln` in Visual Studio and run (Ctrl+F5).

> ** Login Credentials:
> * **User:** `User11`
> * **Pass:** `1234`
