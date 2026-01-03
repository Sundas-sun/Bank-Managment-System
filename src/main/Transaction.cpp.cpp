#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Transaction {
int transID;
int AccNo;
char type[10];
float Amount;
char date[5];
char description[50];

};

void addTransaction() {
	Transaction t;
	ofstream file("transaction.txt , ios::app");
	
	cout << "Enter Transaction ID: ";
	cin >> t.transID;
	
	
	cout<< "Enter Account Number: ";
	cin >> t.AccNo;
	
	cout <<"Enter type (debit/credit): ";
	cin >> t.type;
	
	cout << "Enter Amount: ";
	cin >> t.Amount;
	
	 cout<< "Enter date :";
	 cin>> t.date;
	 
	 cout << "Enter Description: ";
	 cin.ignore();
	 cin.getline(t.description, 50);
	 
	 file.write((char*)&t, sizeof(t));
	 file.close();
	 
	 cout << "Transaction Added Successfully!\n";
	
}





void viewTransaction() {
	Transaction t;
	ifstream file("transaction.txt");
	
	while (file.read((char*)&t, sizeof(t))) {
		cout << "\nTransaction ID: " << t.transID;
		cout << "\nAccount No; " << t.type;
		cout << "\nType: " << t.type;
		cout << "\nAmount: " << t.Amount;
		cout << "\nDate: " <<t.date;
		cout << "\nDescription: " << t.description;
		cout << "\n---";
		
	}
	file.close();
	
}





void searchTransaction(){
	Transaction t;
	int acc;
	bool found = false;
	
	cout <<"Enter Account Number: ";
	cin >> acc;
	
	
ifstream file("transaction.txt");

while(file.read((char*)& t, sizeof(t))) {
	if (t.AccNo == acc) {
		cout << "\nTransaction ID: " << t.transID;
		cout << "\nAmount; " << t.Amount;
		cout << "\nType: " << t.type;
		found = true;
		
	}
	
}

	if (!found)
	cout << "Record Not Found!\n";
	
	file.close();
	
}











void updateTransaction() {
	Transaction t;
	int id;
	bool found = false;
	
	fstream file("transaction txt", ios::in | ios::out);
	
	cout << "Enter Tranaction ID: ";
	cin >> id;
	
	while(file.read((char*)&t, sizeof(t))) {
		if (t.transID == id) {
			cout << "Enter New Amount: ";
			cin >> t.Amount;
			
			int pos = file.tellg();
			file.seekp(pos - sizeof(t));
			cout << "Update Successfully\n";
			found = true;
			break;
		}
	}
	if (!found)
	cout << "Transaction Not Found!\n";
	file.close();
	
}









void deleteTransaction() {
	Transaction t;
	int id;
	bool found = false;
	
	ifstream file("transaction.txt");
	ofstream temp("temp.txt");
	cout << " Enter Transaction ID:";
	cin >> id;
	
	while (file.read((char*)&t, sizeof(t))) {
	if (t.transID != id)	
	temp.write((char*)&t, sizeof(t));
		else
		found = true;
			
	}
		
		file.close();
		temp.close();
		
		remove("transaction.txt");
		rename("temp.txt", "transaction.txt");
		
		if(found)
		cout << "Deleted Successfully!\n";
		else
		cout << "Transaction Not Found!\n";
		
		
		
	}
	
	
	
	













int main() {
	int choice;
	
	do{
		cout<< "\n1. Add Transaction";
		cout<< "\n2. View Transactions";
		cout << "\n3. Search Transaction";
		cout << "\n4. Update Transaction";
		cout << "\n5.Delete Transaction";
		cout << "\n6. Exit";
		cout << "\nEnter Choice:";
		cin >> choice;
		
		switch (choice) {
			case 1: addTransaction(); break;
			case 2: viewTransaction(); break;
			case 3: searchTransaction(); break;
			case 4: updateTransaction(); break;
			case 5: deleteTransaction(); break;
			case 6: cout << "Bye!"; break;
			default: cout << "Invalid Choice!";
			
		}
	} while (choice != 6);
	return 0;

}
