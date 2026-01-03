#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Customer {
private:
    int custID;
    string name;
    string address;
    string phone;
    string email;

public:
    void addCustomer();
    void viewCustomers();
    void searchCustomer();
    void updateCustomer();
    void deleteCustomer();
};

// Add new customer
void Customer::addCustomer() {
    ofstream file("customers.txt", ios::app);

    cout << "\nEnter Customer ID: ";
    cin >> custID;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Address: ";
    getline(cin, address);

    cout << "Enter Phone: ";
    getline(cin, phone);

    cout << "Enter Email: ";
    getline(cin, email);

    file << custID << "|" << name << "|" << address << "|"
         << phone << "|" << email << endl;

    file.close();
    cout << "\nCustomer Added Successfully!\n";
}

// View all customers
void Customer::viewCustomers() {
    ifstream file("customers.txt");
    if (!file) {
        cout << "\nNo records found!\n";
        return;
    }

    cout << "\n--- Customer List ---\n";
    while (file >> custID) {
        file.ignore();
        getline(file, name, '|');
        getline(file, address, '|');
        getline(file, phone, '|');
        getline(file, email);

        cout << "\nID: " << custID
             << "\nName: " << name
             << "\nAddress: " << address
             << "\nPhone: " << phone
             << "\nEmail: " << email << endl;
    }
    file.close();
}

// Search customer by ID
void Customer::searchCustomer() {
    int id;
    bool found = false;
    ifstream file("customers.txt");

    cout << "\nEnter Customer ID to Search: ";
    cin >> id;

    while (file >> custID) {
        file.ignore();
        getline(file, name, '|');
        getline(file, address, '|');
        getline(file, phone, '|');
        getline(file, email);

        if (custID == id) {
            cout << "\nCustomer Found!\n";
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Phone: " << phone << endl;
            cout << "Email: " << email << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nCustomer Not Found!\n";

    file.close();
}

// Update customer
void Customer::updateCustomer() {
    int id;
    bool found = false;
    ifstream file("customers.txt");
    ofstream temp("temp.txt");

    cout << "\nEnter Customer ID to Update: ";
    cin >> id;
    cin.ignore();

    while (file >> custID) {
        file.ignore();
        getline(file, name, '|');
        getline(file, address, '|');
        getline(file, phone, '|');
        getline(file, email);

        if (custID == id) {
            cout << "\nEnter New Name: ";
            getline(cin, name);
            cout << "Enter New Address: ";
            getline(cin, address);
            cout << "Enter New Phone: ";
            getline(cin, phone);
            cout << "Enter New Email: ";
            getline(cin, email);

            temp << custID << "|" << name << "|" << address << "|"
                 << phone << "|" << email << endl;
            found = true;
        } else {
            temp << custID << "|" << name << "|" << address << "|"
                 << phone << "|" << email << endl;
        }
    }

    file.close();
    temp.close();

    remove("customers.txt");
    rename("temp.txt", "customers.txt");

    if (found)
        cout << "\nCustomer Updated Successfully!\n";
    else
        cout << "\nCustomer Not Found!\n";
}

// Delete customer
void Customer::deleteCustomer() {
    int id;
    bool found = false;
    ifstream file("customers.txt");
    ofstream temp("temp.txt");

    cout << "\nEnter Customer ID to Delete: ";
    cin >> id;

    while (file >> custID) {
        file.ignore();
        getline(file, name, '|');
        getline(file, address, '|');
        getline(file, phone, '|');
        getline(file, email);

        if (custID == id) {
            found = true;
            continue;
        }
        temp << custID << "|" << name << "|" << address << "|"
             << phone << "|" << email << endl;
    }

    file.close();
    temp.close();

    remove("customers.txt");
    rename("temp.txt", "customers.txt");

    if (found)
        cout << "\nCustomer Deleted Successfully!\n";
    else
        cout << "\nCustomer Not Found!\n";
}

// Main Menu
int main() {
    Customer c;
    int choice;

    do {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Customer";
        cout << "\n2. View Customers";
        cout << "\n3. Search Customer";
        cout << "\n4. Update Customer";
        cout << "\n5. Delete Customer";
        cout << "\n6. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        
    } while (choice != 6);

    return 0;
}

