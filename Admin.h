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
public:
	Admin() {}
	Admin(int id, string name, string password, double balance, double Salary)
		:Employee(id, name, password, balance, Salary) {}

	void Display()
	{
		Employee::Display();
	}

	// Methods
	//void addClient(Client& client)
	//{
	//	vector<Client*> clients;			//use pointers to save a lot of copies
	//	clients.push_back(new Client);
	//}

	void addClient(Client& client)
	{
		vector<Client> clients;
		clients.push_back(client);
	}

	Client* searchClient(int id)
	{

	}

	/*Person* display() {
		return this;
	};*/

	~Admin()
	{

	}
};

