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
#include "FilesHelperGet.h"
using namespace std;

class FileManager : public DataSourceInterface
{
protected:
	friend class FilesHelperGet;
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
		FilesHelperGet::getClients();

		return getAllClients();
	}

	vector<Employee> getAllEmployees()
	{
		FilesHelperGet::getEmployees();

		return getAllEmployees();
	}

	vector<Admin> getAllAdmins()
	{
		FilesHelperGet::getAdmins();
		return getAllAdmins();
	}

				//Remove

	/*void removeAllClients() override
	{
		FilesHelperGet::clearFile("Clients.txt", "New Client.txt");
	}

	void removeAllEmployees()
	{
		FilesHelperGet::clearFile("Employee.txt", "New Employee.txt");
	}

	void removeAllAdmins()
	{
		FilesHelperGet::clearFile("Admins.txt", "New Admin.txt");
	}*/

	//Display
	/*void displayVector()
	{
		vector<string> Display;
		for (auto& )
	}*/
};

