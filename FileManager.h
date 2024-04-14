#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
		vector<Client> clients;
		ifstream file("Clients.txt", ios::in);
		if (file.is_open())
		{
			string line;
			while (getline(file, line)) 
			{
				stringstream ss(line);
				string idstr, name, password, balanceStr;
				if (getline(ss, idstr, '$') && getline(ss, name, '$') && getline(ss, password, '$') && getline(ss, balanceStr, '$')) {
					int id = stoi(idstr);
					double balance = stod(balanceStr);
					clients.emplace_back(id, name, password, balance);
				}
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
				string idstr, name, password, balanceStr, salaryStr;
				if (getline(ss, idstr, '$') && getline(ss, name, '$') && getline(ss, password, '$') && getline(ss, balanceStr, '$') && getline(ss, salaryStr, '$')) {
					int id = stoi(idstr);
					double balance = stod(balanceStr);
					double salary = stod(salaryStr);
					employees.emplace_back(id, name, password, balance, salary);
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
				string idstr, name, password, balanceStr, salaryStr;
				if (getline(ss, idstr, '$') && getline(ss, name, '$') && getline(ss, password, '$') && getline(ss, balanceStr, '$') && getline(ss, salaryStr, '$')) {
					int id = stoi(idstr);
					double balance = stod(balanceStr);
					double salary = stod(salaryStr);
					admins.emplace_back(id, name, password, balance, salary);
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

