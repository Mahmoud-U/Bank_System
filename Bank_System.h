#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class Bank_System
{
};
class Person {
protected:
	int id;
	string name;
	string password;
public:
	Person() 
	{
		id = 0;
	}
	Person(int id, string name, string password) {
		this->id = id;
		if (name.size() > 5 && name.size() < 20) {
			this->name = name;
		}
		for (int i = 0; i < password.size(); i++) {
			if ((i >= 'a' && i <= 'z') && (password.size() > 8 && password.size() < 20)) {
				this->password = password;
			}
		}
	}
	//setters
	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		this->name = name;
	}
	void setPassword(string password) {
		this->password = password;
	}
	int getId() {
		return this->id;
	}
	string getName() {
		return this->name;
	}
	string getPassword() {
		return this->password;
	}
	/*virtual Person display() = 0;*/
};
class Client : public Person {
private:
	double balance;
public:
	Client() {
		balance = 1500.0;
	}
	Client(int id, string name, string password, double balance) :Person(id, name, password) {
		this->balance = balance;

	}
	void setBalance(double balance) {
		this->balance = balance;
	}
	double getBalance() {
		return balance;
	}
	//deposite
	double deposite(double amount) {
		balance += amount;
		return balance;
	}
	//withdraw
	double withdraw(double amount) {
		if (amount <= balance)
			balance -= amount;
		else
			cout << "Amount Exceeds" << endl;
		return balance;
	}

	//TransferTo
	double transferTo(double amount, Client& x) 
	{
		if (amount <= balance) {
			balance -= balance;
			x.deposite(amount);
		}
		else
			cout << "Amount Exceed" << endl;
	}


	Person* display() {
		return this;
	};
};