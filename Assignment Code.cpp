// Group 4 Assignment: Personal Budget Calculator
// HENRY, LUI, FARAH
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
using namespace std;

int Mode,Choice;
void WelcomeMenu();
double displayMoney(double,double,double);
struct Budget{
	double income,expenses,sum,balance;
	string input;
};
string FinancialRecord;


int main(){
	fstream outfile,infile;
	Budget money;
	
	WelcomeMenu();
	cin>>Mode;
	while(Mode!=0 && Mode!=1 && Mode!=2){
		cout<<"\nInvalid Response, please try again. \n";
		cin>>Mode;
		}
	
	switch (Mode){
	case 0:
		exit(0);
		
		break;
		
	case 1:
		cout<<"\nPlease enter your monthly income."<<endl;
		cin>>money.income;
		cout<<"\nPlease enter your expenses for today, press 0 to calculate your spendings."<<endl;
		cin>>money.expenses;
		while(money.expenses>0){
		money.sum+=money.expenses;
		cin>>money.expenses;
		}
		
		money.balance=money.income-money.sum;
		displayMoney(money.income,money.sum,money.balance);
		
		cout<<"\nPress 0 to terminate financial record \n"<<"Press 1 to save and exit \n";
		cin>>Choice;
		
		while(Choice!=0 && Choice!=1){
		cout<<"\nInvalid Response, please try again. \n";
		cin>>Choice;
		}
		
		if (Choice==1){
		outfile.open("FinancialRecord.txt",ios::app);
		outfile<<"Income:"<<money.income<<" Expenses:"<<money.sum<<" Balance:"<<money.balance<<endl;
		outfile.close();
		cout<<"\nRecord saved successfully, Bye Bye!";
		}
		
		else if (Choice==0){
		outfile.open("FinancialRecord.txt",ios::out);
		ios::trunc;
		outfile.close();
		cout<<"\nRecord terminated successfully, Bye Bye!";
		}
		
		break;
		
	case 2:
		infile.open("FinancialRecord.txt",ios::in);
		if(infile){
		getline(infile,money.input);
		while(infile){
		cout<<money.input<<endl;
		getline(infile,money.input);
		}
		infile.close();
		}
		
		cout<<"\nPress 0 to terminate financial record \n"<<"Press 1 to exit. \n";
		cin>>Choice;
		
		while(Choice!=0 && Choice!=1){
		cout<<"\nInvalid Response, please try again. \n";
		cin>>Choice;
		}
		
		if (Choice==0){
		outfile.open("FinancialRecord.txt",ios::out);
		ios::trunc;
		outfile.close();
		cout<<"\nRecord terminated successfully, Bye Bye!";
		}
		
		else if (Choice==1)
		exit(0);
		
		break;
	
	}
	

	return 0;
}


void WelcomeMenu(){
	cout<<"WELCOME, PLEASE CHOOSE MODE."<<endl;
	cout<<"Press 0 to exit program,"<<endl<<"Press 1 to calculate daily expenditure,"<<endl<<"Press 2 to financial history."<<endl;
}
	

double displayMoney(double num1,double num2,double num3){
	cout<<"\nMonthly Income: "<<num1<<endl;
	cout<<"Total Expenses: "<<num2<<endl;
	cout<<"Balance: "<<num3<<endl;
	
	return num1,num2,num3;
}
