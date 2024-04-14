#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "DataSourceInterface.h"
#include "Parser.h"
using namespace std;

class FileManager : public DataSourceInterface
{
public:
				// Add

	void addClient(Client& c) override
	{
		// Stream class to write on files
		ofstream myFile("Clients.txt", ios::app);

		if (myFile.is_open())
		{
			myFile << c.getId() << "$" << c.getName() << "$" << c.getPassword() << "$" << c.getBalance() << endl;

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
			myFile << e.getId() << "$" << e.getName() << "$" << e.getPassword() << "$" << e.getSalary() << endl;

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
			myFile << a.getId() << "$" << a.getName() << "$" << a.getPassword() << "$" << a.getSalary() << endl;

			cout << "Admin Information Saved \n";
			myFile.close();
		}
		else
			cerr << "Unable to open the file \n";
	}

				// Get

	vector<Client> getAllClients()
	{
		vector<Client> clients;
		ifstream file("Clients.txt", ios::in);
		if (file.is_open()) 
		{
			string line;
			while (getline(file, line)) 
			{
				clients.push_back(Parser::parseToClient(line));
			}
			file.close();
		}
		else {
			cerr << "Unable to open the file \n";
		}

		return clients;
	}

	vector<Employee> getAllEmployees()
	{
		vector<Employee> employees;
		ifstream file("Employee.txt", ios::in);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				employees.push_back(Parser::parseToEmployee(line));
			}
			file.close();
		}
		else
		{
			cerr << "Unable to open the file \n";
		}

		return employees;
	}

	vector<Admin> getAllAdmins()
	{
		vector<Admin> admins;
		ifstream file("Admins.txt", ios::in);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				admins.push_back(Parser::parseToAdmin(line));
			}
			file.close();
		}
		else
		{
			cerr << "Unable to open the file \n";
		}

		return admins;
	}

				//Remove

	void removeAllClients() override
	{
		ofstream file("Clients.txt", ios::trunc);
		file.close();
		cout << "All Clients Removed \n";
		
		if (!file) {
			cerr << "Unable to clear all clients \n";
		}
	}

	void removeAllEmployees()
	{
		ofstream file("Employee.txt", ios::trunc);
		file.close();
		cout << "All Employees Removed \n";

		if (!file) {
			cerr << "Unable to clear all employees \n";
		}
	}

	void removeAllAdmins()
	{
		ofstream file("Admins.txt", ios::trunc);
		file.close();
		cout << "All Admins Removed \n";

		if (!file) {
			cerr << "Unable to clear all admins \n";
		}
	}

	//Display
	/*void displayVector()
	{
		vector<string> Display;
		for (auto& )
	}*/
};

