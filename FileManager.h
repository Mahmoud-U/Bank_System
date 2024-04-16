#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "DataSourceInterface.h"
#include "FilesHelper.h"
using namespace std;

class FileManager : public DataSourceInterface
{
public:
				// Add

	void addClient(Client& c) override
	{
		FilesHelper::saveClient(c);
	}

	void addEmployee(Employee& e) override
	{
		FilesHelper::saveEmployee("Employee.txt", "New Employee.txt", e);
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
		FilesHelper::getClients();

		return getAllClients();
	}

	vector<Employee> getAllEmployees()
	{
		FilesHelper::getEmployees();

		return getAllEmployees();
	}

	vector<Admin> getAllAdmins()
	{
		FilesHelper::getAdmins();
		return getAllAdmins();
	}

				//Remove

	void removeAllClients() override
	{
		FilesHelper::clearFile("Clients.txt", "New Client.txt");
	}

	void removeAllEmployees()
	{
		FilesHelper::clearFile("Employee.txt", "New Employee.txt");
	}

	void removeAllAdmins()
	{
		FilesHelper::clearFile("Admins.txt", "New Admin.txt");
	}

	//Display
	/*void displayVector()
	{
		vector<string> Display;
		for (auto& )
	}*/
};

