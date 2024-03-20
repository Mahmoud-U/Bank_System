#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
class Bank_System
{
};
class Person 
{
protected:
	//Attributes:
	int id;
	string name;
	string password;
public:
	//Constructors:
	Person() {
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

	//Setters:
	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		this->name = name;
	}
	void setPassword(string password) {
		this->password = password;
	}

	//Getters:
	int getId() {
		return this->id;
	}
	string getName() {
		return this->name;
	}
	string getPassword() {
		return this->password;
	}

	//Methods:
	/*virtual Person display() = 0;*/
};
class Client : public Person 
{
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

	/*Person* display() {
		return this;
	};*/
};
