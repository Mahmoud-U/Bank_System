#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <exception>
using namespace std;

class Person
{
protected:
	// Attributes
	int id;
	string name;
	string password;
	double balance;
public:
	// Constructors
	Person()
	{
		id = 0;
		balance = 0.0;
	}
	Person(int id, string name, string password, double balance) {

		try {
			setId(id);
		}
		catch (const exception& e) {
			cerr << e.what() << endl;
		}

		try {
			setName(name);
		}
		catch (const exception& e) {
			cerr << e.what() << endl;
		}

		try {
			setPassword(password);
		}
		catch (const exception& e) {
			cerr << e.what() << endl;
		}

		try {
			setBalance(balance);
		}
		catch (const exception& e) {
			cerr << e.what() << endl;
		}
	}

	// Setters

	// ID Validation
	void setId(int id) {
		string idStr = to_string(id);

		if (idStr.empty()) {
			throw invalid_argument("Invalid ID format. ID cannot be empty.");
		}

		if (idStr.find_first_not_of("0123456789") != string::npos) {
			throw invalid_argument("Invalid ID format. ID should contain only numbers.");
		}

		int idValue = stoi(idStr);
		if (idValue < 1 || idValue > 1000) {
			this->id = 0000000;
			throw out_of_range("Invalid ID range. ID should be between 1 and 1000.");
		}

		this->id = idValue;
	}

	// Name Validation using regular expressions
	void setName(string name)
	{
		if (regex_search(name, regex("\\s"))) {
			throw invalid_argument("Invalid name format. Name cannot contain spaces.");
		}
		if (name.empty()) {
			throw runtime_error("Invalid name format. Name cannot be empty.");
		}
		if (regex_search(name, regex("\\d"))) {
			throw invalid_argument("Invalid name format. Name cannot contain numbers.");
		}
		if (!regex_match(name, regex("^[A-Z][a-z]{2,19}$"))) {
			throw invalid_argument("Invalid name format. Name must start with an uppercase letter, followed by 2 to 19 lowercase letters.");
		}

		this->name = name;
	}

	// Password Validation
	void setPassword(string password)
	{
		if (password.find(' ') != string::npos) {
			throw runtime_error("Invalid password format. Password cannot contain spaces.");
		}
		if (password.empty()) {
			throw runtime_error("Invalid password format. Password cannot be empty.");
		}
		if (!regex_match(password, regex(".*\\d.*"))) {
			throw runtime_error("Invalid password format. Password must contain at least one digit.");
		}
		if (!regex_match(password, regex(".*[a-z].*"))) {
			throw runtime_error("Invalid password format. Password must contain at least one lowercase letter.");
		}
		if (!regex_match(password, regex(".*[A-Z].*"))) {
			throw runtime_error("Invalid password format. Password must contain at least one uppercase letter.");
		}
		if (password.size() < 8 || password.size() > 20) {
			throw runtime_error("Invalid password format. Password must be 8 to 20 characters long.");
		}

		this->password = password;
	}

	// Balance Validation
	void setBalance(double balance)
	{
		if (balance < 1500) {
			throw runtime_error("Minimum balance requirement not met. Balance should be at least 1500.");
		}

		this->balance = balance;
	}

	// Getters
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
	double getBalance()
	{
		return this->balance;
	}
	
	virtual void Display() = 0;

	~Person()
	{

	}
};

