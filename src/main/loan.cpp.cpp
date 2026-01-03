#include <iostream>
#include <fstream>
using namespace std;

struct Loan {
	int loanID ;
	int custID ;
	float amount ;
	float interestRate ;
	string status ;
};

// Add Loan
void addLoan() {
	Loan l ;
	ofstream file("loans.txt" , ios ::app);
	
	cout<<"\n--- Add Loan ---\n";
	cout<<"Enter Loan ID :";
	cin>>l.loanID;
	
	cout<<"Enter Customer ID:";
	cin>>l.custID;
	
	cout<<"Enter Loan Amount:";
	cin>>l.amount;
	
	cout<<"Enter InterestRate:";
	cin>>l.interestRate;
	
	cout<< "Enter Status (Approved/Pending):";
	cin>>l.status;
	
	file <<l.loanID<<" "
	     <<l.custID<<" "
	     <<l.amount<<" "
	     <<l.interestRate<<" "
	     <<l.status<<endl;
	     
	     file.close();
	     cout<<"Loan Added Sucessfullying!\n";
	
}
//View Loans
void viewLoans() {
	Loan l;
	ifstream file("loans.txt");
	
	cout<<"\n--- All Loans---\n";
	while (file >>l.loanID>>
	l.custID>>l.amount>>
	l.interestRate>>l.status){
		cout<<"\nLoan ID :"<<l.loanID;
		cout<<"\nCustomer ID :"<<l.custID;
		cout<<"\nAmount :"<<l.amount;
		cout<<"\nInterestRate :"<<l.interestRate;
		cout<<"\nStatus :"<<l.status;
		cout<<"\n-------------";
	}
	file.close();
	
}
//Update Loan
void UpdateLoan(){
	Loan l;
	int ID;
	bool found = false;
	
	ifstream file("loans.txt");
	ofstream temp("temp.txt");
	
	cout<<"Enter  Loan ID to Update :";
	cin>>ID;
	
	while(file>>l.loanID>>
	l.custID>>l.amount>>
	l.interestRate>>l.status){
		if (l.loanID== ID){
			cout<<"Enter New Amount :";
			cin>>l.amount;
			cout<<"Enter New InterestRate:";
			cin>>l.interestRate;
			cout<<"Enter new Status :";
			cin>>l.status;
			found = true;	
		}
		temp << l.loanID<< " "
		     << l.custID<< " "
		     << l.amount << " "
		     << l.interestRate<<" "
		     << l.status <<endl;
			 
	}
	file.close();
	temp.close();
	
	remove("loans.txt");
	rename("temp.txt", "loans.txt");
	
	if (found)
	    cout<<"Loan Updated Sucessfully!\n";
    else 
        cout<<"Loan Not Found!\n";
}
//Delete Loan
void deleteLoan(){
	Loan l ;
	int ID;
	bool found = false;
	
	ifstream file("loans.txt");
	ofstream temp("temp.txt");
	
	cout<<"Enter  Loan ID to Delete:";
	cin>>ID;
	
	while(file>>l.loanID>>
	l.custID>>l.amount>>
	l.interestRate>>l.status){
		if (l.loanID != ID){
			temp<<l.loanID<<" "
			    <<l.custID<<" "
			    <<l.amount<<" "
			    <<l.interestRate<<" "
			    <<l.status<<endl;
				
		}else{
			 found = true ;
		}
}
    file.close();
    temp.close();
    
    remove("loans.txt");
    rename("temp.txt", "loans.txt");
    
    if (found)
        cout<<"Loan Deleted Sucessfully!\n";
    else 
        cout<<"Loan Not Found !\n";
}
//Main Menu
int main(){
	int choice;
	
	do{
		cout <<"\n===== Loan Management System =====";
		cout <<"\n1.Add Loan" ;
		cout <<"\n2.View Loans" ;
		cout <<"\n3.Update Loan" ;
		cout <<"\n4.Delete Loan" ;
		cout <<"\n5.Exit";
		cout <<"\nEnter Your Choice : ";
		cin>>choice ;
		
		switch(choice) {
			case 1 : addLoan(); break;
			case 2 : viewLoans(); break;
			case 3 : UpdateLoan(); break;
			case 4 : deleteLoan(); break;
			case 5 : cout<< " Program Exit"; break;
			default : cout<<" Invalid Choice!";
		}
		
	}   while (choice != 5);
	return 0 ;
}
