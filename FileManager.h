#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Client.h"
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
		FilesHelper::saveEmployee("Admins.txt", "New Admin.txt", a);
	}

				// Get

	virtual void getAllClients()
	{
		FilesHelper::getClients();
	}

	virtual void getAllEmployees()
	{
		FilesHelper::getEmployees();
	}

	virtual void getAllAdmins()
	{
		FilesHelper::getAdmins();
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

