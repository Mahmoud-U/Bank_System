#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <regex>
using namespace std;
class Bank_System
{

};
class Person 
{
protected:
	//Attributes
	int id;
	string name;
	string password;
public:
	//Constructors
	Person()
	{
		id = 0;
	}
	Person(int id, string name, string password) {
		this->id = id;

		if (Valid_Password(password) && Valid_Name(name)) {
			this->name = name;
			this->password = password;
		}
	}

	//Name & Password Validation
	bool Valid_Name(string& name)
	{
		regex pattern("^[A-Z][a-z]{4,19}$");

		return regex_match(name, pattern);
	}

	bool Valid_Password(string& password)
	{
		regex pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[A-Za-z0-9]{8,20}$");

		return regex_match(password, pattern);
	}
	
	//setters:
	void setId(int id) 
	{
		this->id = id;
	}
	void setName(string name) 
	{
		this->name = name;
	}
	void setPassword(string password)
	{
		this->password = password;
	}

	//Getters
	int getId() 
	{
		return this->id;
	}
	string getName() 
	{
		return this->name;
	}
	string getPassword() 
	{
		return this->password;
	}
};

class Client : public Person 
{
private:
	//Attributes
	double balance;
public:
	//Constructors
	Client() {
		balance = 1500.0;
	}
	Client(int id, string name, string password, double balance)
			:Person(id, name, password)
	{
		this->balance = balance;
	}

	//Setters
	void setBalance(double balance)
	{
		this->balance = balance;
	}
	double getBalance() 
	{
		return balance;
	}

	//Deposite
	double deposite(double amount) 
	{
		balance += amount;
		return balance;
	}

	//Withdraw
	double withdraw(double amount) 
	{
		if (amount <= balance)
			balance -= amount;
		else
			cout << "Amount Exceeds" << endl;
		return balance;
	}

	//TransferTo
	double transferTo(double amount, Client& x) 
	{
		if (amount <= balance) 
		{
			balance -= amount;
			x.deposite(amount);
		}
		else
		{
			cout << "Amount Exceed" << endl;
		}
		return balance;
	}

	Person* display() {
		return this;
	};
};