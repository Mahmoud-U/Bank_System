#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <exception>

#include "Person.h"
using namespace std;

class Client : public Person
{
public:
	Client() {}
	Client(int id, string name, string password, double balance)
		:Person(id, name, password, balance) {}

	//Deposite
	void Deposit(double amount)
	{
		if (amount > 0)
		{
			balance += amount;
			cout << "Deposit of " << amount << " successful. New balance : " << balance << endl;
		}
		else
		{
			cout << "Invalid deposit amount. Please enter a positive value." << endl;
		}
	}

	//Withdraw
	void Withdraw(double amount)
	{
		if (amount > 0 && balance - amount >= 1500)
		{
			balance -= amount;
			cout << "Withdrawal of " << amount << " successful. New balance : " << balance << endl;
		}
		else
		{
			cout << "Invalid withdrawal amount or insufficient balance." << endl;
		}
	}

	//TransferTo
	void Transfer_To(double amount, Client& recipient)
	{
		if (amount > 0 && balance - amount >= 1500)
		{
			balance -= amount;
			recipient.balance += amount;
			cout << "Transfer of " << amount << " successful. New balance : " << balance << endl;
		}
		else
		{
			cout << "Invalid transfer amount or insufficient balance." << endl;
		}
	}

	// Check Balance
	void Check_Balance()
	{
		cout << "Current balance : " << balance << endl;
	}

	void Display()
	{
		cout << "Client Details : " << endl;
		cout << "ID : " << getId() << ", Name : " << getName() << ", Password : "
			 << getPassword() << ", Balance : " << getBalance() << endl;
	}

	~Client()
	{

	}
};
static vector<Client> allClients;
static vector<Client>::iterator clientX;