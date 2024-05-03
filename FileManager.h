#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "DataSourceInterface.h"
#include "FilesHelper.h"
using namespace std;

class FileManager
{
public:
				// Add

	void addClient(Client& c) 
	{
		FilesHelper::saveClient(c);
	}

	void addEmployee(Employee& e) 
	{
		FilesHelper::saveEmployee("Employee.txt", "New Employee.txt", e);
	}

	void addAdmin(Admin& a) 
	{
		string name, password;
		double salary{};

		cout << "Enter Your Name: "; cin >> name;
		a.setName(name);

		cout << "Enter Your Password: "; cin >> password;
		a.setPassword(password);

		cout << "Enter Your Balance: "; cin >> salary;
		a.setSalary(salary);

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

	void removeAllClients() 
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

						//IMPORTANT METHODS						

	void getAllData()
	{
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}

	void updateClient() {
		removeAllClients();
		for (clientX = allClients.begin(); clientX != allClients.end(); clientX++)
		{
			addClient(*clientX);
		}
	}

	void updateEmployee() {
		removeAllEmployees();
		for (employeeX = allEmployees.begin(); employeeX != allEmployees.end(); employeeX++)
		{
			addEmployee(*employeeX);
		}
	}

	void updateAdmin() {
		removeAllAdmins();
		for (adminX = allAdmins.begin(); adminX != allAdmins.end(); adminX++)
		{
			addAdmin(*adminX);
		}
	}

};