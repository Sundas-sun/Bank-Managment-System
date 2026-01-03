#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Account
{
    string AccNo;     
    string CustID;
    string Type;      
    long long Balance;
    string OpenDate;
};

void addAccount()
{
    Account acc;
    ofstream file("accounts.txt", ios::app);

    cout << "\nEnter Account Number: ";
    cin >> acc.AccNo;

    cout << "Enter Customer ID: ";
    cin >> acc.CustID;

    cout << "Enter Account Type (Savings/Current): ";
    cin >> acc.Type;

    cout << "Enter Balance: ";
    cin >> acc.Balance;

    cout << "Enter Open Date (DD/MM/YYYY): ";
    cin >> acc.OpenDate;

    file << acc.AccNo << " "
         << acc.CustID << " "
         << acc.Type << " "
         << acc.Balance << " "
         << acc.OpenDate << endl;

    file.close();
    cout << "Account added successfully.\n";
}

void viewAccounts()
{
    Account acc;
    ifstream file("accounts.txt");

    cout << "\n----- Account Records -----\n";
    while (file >> acc.AccNo >> acc.CustID >> acc.Type >> acc.Balance >> acc.OpenDate)
    {
        cout << "\nAccount No: " << acc.AccNo;
        cout << "\nCustomer ID: " << acc.CustID;
        cout << "\nType: " << acc.Type;
        cout << "\nBalance: Rs " << acc.Balance;
        cout << "\nOpen Date: " << acc.OpenDate << endl;
    }

    file.close();
}

void updateAccount()
{
    string searchAcc;
    bool found = false;
    Account acc;

    ifstream file("accounts.txt");
    ofstream temp("temp.txt");

    cout << "\nEnter Account Number to Update: ";
    cin >> searchAcc;

    while (file >> acc.AccNo >> acc.CustID >> acc.Type >> acc.Balance >> acc.OpenDate)
    {
        if (acc.AccNo == searchAcc)
        {
            cout << "Enter New Customer ID: ";
            cin >> acc.CustID;

            cout << "Enter New Account Type: ";
            cin >> acc.Type;

            cout << "Enter New Balance: ";
            cin >> acc.Balance;

            cout << "Enter New Open Date: ";
            cin >> acc.OpenDate;

            found = true;
        }

        temp << acc.AccNo << " "
             << acc.CustID << " "
             << acc.Type << " "
             << acc.Balance << " "
             << acc.OpenDate << endl;
    }

    file.close();
    temp.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (found)
        cout << "Account updated successfully.\n";
    else
        cout << "Account not found.\n";
}

void deleteAccount()
{
    string searchAcc;
    bool found = false;
    Account acc;

    ifstream file("accounts.txt");
    ofstream temp("temp.txt");

    cout << "\nEnter Account Number to Delete: ";
    cin >> searchAcc;

    while (file >> acc.AccNo >> acc.CustID >> acc.Type >> acc.Balance >> acc.OpenDate)
    {
        if (acc.AccNo != searchAcc)
        {
            temp << acc.AccNo << " "
                 << acc.CustID << " "
                 << acc.Type << " "
                 << acc.Balance << " "
                 << acc.OpenDate << endl;
        }
        else
        {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (found)
        cout << "Account deleted successfully.\n";
    else
        cout << "Account not found.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== BANK ACCOUNT SYSTEM =====\n";
        cout << "1. Add Account\n";
        cout << "2. View Accounts\n";
        cout << "3. Update Account\n";
        cout << "4. Delete Account\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: addAccount(); break;
            case 2: viewAccounts(); break;
            case 3: updateAccount(); break;
            case 4: deleteAccount(); break;
            case 5: cout << "Exiting.\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
