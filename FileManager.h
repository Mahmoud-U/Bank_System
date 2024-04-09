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
	// Add
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

	//Get
	vector<Client> getAllClients()
	{
		vector<Client> getAllClientsVector;
		Client client;
		ifstream file("Clients.txt", ios::in);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				getAllClientsVector.push_back(client);
			}
			file.close();
		}
		else
		{
			cerr << "Unable to open the file \n";
		}

		return getAllClientsVector;
	}

	vector<Employee> getAllEmployees()
	{
		vector<Employee> getAllEmployeesVector;
		Employee employee;
		ifstream file("Employee.txt", ios::in);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				getAllEmployeesVector.push_back(employee);
			}
			file.close();
		}
		else
		{
			cerr << "Unable to open the file \n";
		}

		return getAllEmployeesVector;
	}

	vector<Admin> getAllAdmins()
	{
		vector<Admin> getAllAdminsVector;
		Admin admin;
		ifstream file("Admins.txt", ios::in);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				getAllAdminsVector.push_back(admin);
			}
			file.close();
		}
		else
		{
			cerr << "Unable to open the file \n";
		}

		return getAllAdminsVector;
	}

	//Remove
	void removeData(string fileName)
	{
		ofstream file(fileName, ios::trunc);
		file.close();
	}

	void removeAllClients() override
	{
		removeData("Clients.txt");
		cout << "All Clients Removed \n";
	}

	void removeAllEmployees()
	{
		removeData("Employee.txt");
	}

	void removeAllAdmins()
	{
		removeData("Admins.txt");
	}

	//Display
	/*void displayVector()
	{
		vector<string> Display;
		for (auto& )
	}*/
};

