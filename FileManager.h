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
			myFile << "Employee ID : " << "," << "Name : " << c.getName() << "," << "Password : " << c.getPassword() << ","
				<< "Balance : " << c.getBalance() << "," << "Salary : " << endl;

			cout << "Client Information Saved \n";
			myFile.close();
		}
		else
			cerr << "Unable to open the file \n";
	}

	void addEmployee(Employee& e) override
	{
		// Stream class to write on files
		ofstream myFile("Employee.txt", ios::app);

		if (myFile.is_open())
		{
			myFile << "Employee ID : " << "," << "Name : " << e.getName() << "," << "Password : " << e.getPassword() << "," 
				   << "Balance : " << e.getBalance() << "," << "Salary : " << e.getSalary() << endl;

			cout << "Employee Information Saved \n";
			myFile.close();
		}
		else
			cerr << "Unable to open the file \n";
	}

	void addAdmin(Admin& a) override
	{
		// Stream class to write on files
		ofstream myFile("Admins.txt", ios::app);

		if (myFile.is_open())
		{
			myFile << "Admin ID : " << "," << "Name : " << a.getName() << "," << "Password : " << a.getPassword() << ","
				<< "Balance : " << a.getBalance() << "," << "Salary : " << a.getSalary() << endl;

			cout << "Admin Information Saved \n";
			myFile.close();
		}
		else
			cerr << "Unable to open the file \n";
	}


};

