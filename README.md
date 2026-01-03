# Bank-Managment-System
# Bank Management System (C++)

## Team Members

* **Sundas** (Team Leader) – 25011519-013
* **Kainat** – 25011519-004
* **Khizra** – 25011519-005
* **Nayab** – 25011519-044

## Programming Language

* C++

## Overview

This project is a **Bank Management System** developed in **C++** to manage customer records, accounts, transactions, and loans.
The system is designed using a structured and modular approach and demonstrates the use of core C++ programming concepts.

## Modules Implemented

### 1. Customer Management

* Add new customer
* View customer details
* Update customer information
* Delete customer records

**Customer Structure:**
Customer { CustID, Name, Address, Phone, Email }

### 2. Account Management

* Open new bank account
* View account details
* Balance inquiry

**Account Structure:**
Account { AccNo, CustID, Type (Savings/Current), Balance, OpenDate }

### 3. Transaction Management

* Deposit money
* Withdraw money
* View transaction history

**Transaction Structure:**
Transaction { TransID, AccNo, Type, Amount, Date, Description }

### 4. Loan Management

* Apply for loan
* View loan status

**Loan Structure:**
Loan { LoanID, CustID, Amount, InterestRate, Status }

## Features Used

* Object-Oriented Programming (Classes & Objects)
* File Handling (Store and retrieve records)
* Menu-driven interface
* Structures and functions
* Input validation

## Tools & Environment

* C++ Compiler (GCC / MinGW / Online Compiler)
* Console-based application

## How to Run the Code

### Using VS Code or Any IDE

1. Open the project folder in VS Code or any C++ IDE.
2. Make sure a C++ compiler (GCC / MinGW) is installed.
3. Open the main `.cpp` file.
4. Compile the program.
5. Run the executable file.

### Using Command Line (Windows / Linux)

1. Open Terminal or Command Prompt.

2. Navigate to the project folder.

3. Compile the code using:

   ```
   g++ main.cpp -o bank
   ```

4. Run the program:

   * On Windows:

     ```
     bank.exe
     ```
   * On Linux / macOS:

     ```
     ./bank
     ```
