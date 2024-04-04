#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <regex>
#include <exception>
#include "Person.h"
class Employee : public Person
{
protected:
	double salary;
public:
	Employee()
	{
		salary = 0.0;
	}
	Employee(int id, string name, string password, double balance, double salary)
		:Person(id, name, password, balance)
	{
		try {
			setSalary(salary);
		}
		catch (const exception& e) {
			cerr << e.what() << endl;
		}
	}

	// Salary Validation
	void setSalary(double salary)
	{
		if (salary < 5000) {
			throw runtime_error("Minimum salary requirement not met. Salary should be at least 5000.");
		}

		this->salary = salary;
	}

	double getSalary()
	{
		return this->salary = salary;
	}

	void Display()
	{
		cout << "Person Details : " << endl;
		cout << "ID : " << getId() << endl;
		cout << "Name : " << getName() << endl;
		cout << "Password : " << getPassword() << endl;
		cout << "Balance : " << getBalance() << endl;
		cout << "Salary : " << getSalary() << endl;
	}
	/*Person* display() {
		return this;
	};*/

	~Employee()
	{

	}
};

