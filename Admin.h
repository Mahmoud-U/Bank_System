#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <regex>
#include <exception>
#include "Employee.h"
class Admin : public Employee
{
private://singleton design pattern
	//2.static object pointer
	static Admin* obj;
	//1.private constructor
	Admin() {}
	Admin(int id, string name, string password, double balance, double Salary)
		:Employee(id, name, password, balance, Salary) {}


public:
	//3.remove the copy constructor
	Admin(const Admin& obj)
		= delete; //deleting copy constructor
	//4.create public static method to return or assign value to the object
	static Admin* getInstance()
	{
		// If there is no instance of class
		// then we can create an instance.
		if (instance == NULL)
		{
			// We can access private members 
			// within the class.
			instance = new Admin();

			// returning the instance pointer
			return instance;
		}
		else
		{
			// if instancePtr != NULL that means 
			// the class already have an instance. 
			// So, we are returning that instance 
			// and not creating new one.
			return instance;
		}
	}

	void Display()
	{
		Employee::Display();
	}

	/*Person* display() {
		return this;
	};*/

	~Admin()
	{

	}
};