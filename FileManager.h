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

	//Get
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
		else
		{
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
				stringstream ss(line);
				string idstr, name, password, salaryStr;
				if (getline(ss, idstr, '$') && getline(ss, name, '$') && getline(ss, password, '$') && getline(ss, salaryStr, '$'))
				{
					int id = stoi(idstr);
					double salary = stod(salaryStr);
					employees.emplace_back(id, name, password, salary);
				}
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
		ifstream file("Employee.txt", ios::in);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				stringstream ss(line);
				string idstr, name, password, salaryStr;
				if (getline(ss, idstr, '$') && getline(ss, name, '$') && getline(ss, password, '$') && getline(ss, salaryStr, '$'))
				{
					int id = stoi(idstr);
					double salary = stod(salaryStr);
					admins.emplace_back(id, name, password, salary);
				}
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
	void removeData(string fileName)
	{
		ofstream file(fileName, ios::trunc);
		file.close();
	}

	void removeAllClients() override
	{
		ofstream file("Clients.txt", ios::trunc);
		file.close();
		removeData("Clients.txt");
		cout << "All Clients Removed \n";
	}

	void removeAllEmployees()
	{
		removeData("Employee.txt");
		cout << "All Employees Removed \n";
	}

	void removeAllAdmins()
	{
		removeData("Admins.txt");
		cout << "All Admins Removed \n";
	}

	//Display
	/*void displayVector()
	{
		vector<string> Display;
		for (auto& )
	}*/
};

