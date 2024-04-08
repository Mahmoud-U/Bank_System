#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "DataSourceInterface.h"
using namespace std;
class FileManager : public DataSourceInterface
{
public:
	void addClient(Client& c) override
	{
		// Stream class to write on files
		ofstream myFile("Clients.txt", ios::app);

		if (myFile.is_open())
		{
			myFile << c.getId() << "$" << c.getName() << "$" << c.getPassword() << "$"
				<< c.getBalance() << "$" << endl;

			cout << "Client Information Saved \n";
			myFile.close();
		}
		else
			cerr << "Unable to open the file \n";
	}

	void addEmployee(Employee& e) override
	{
		ofstream myFile("Employee.txt", ios::app);

		if (myFile.is_open())
		{
			myFile << e.getId() << "$" << e.getName() << "$" << e.getPassword() << "$" 
				   << e.getBalance() << "$" << e.getSalary() << endl;

			cout << "Employee Information Saved \n";
			myFile.close();
		}
		else
			cerr << "Unable to open the file \n";
	}

	void addAdmin(Admin& a) override
	{
		ofstream myFile("Admins.txt", ios::app);

		if (myFile.is_open())
		{
			myFile << a.getId() << "$" << a.getName() << "$" << a.getPassword() << "$"
				<< a.getBalance() << "$" << a.getSalary() << endl;

			cout << "Admin Information Saved \n";
			myFile.close();
		}
		else
			cerr << "Unable to open the file \n";
	}

	vector<Client> getAllClients()
	{

	}

};

