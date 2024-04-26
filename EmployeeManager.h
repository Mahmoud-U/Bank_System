#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "fstream"

#include "FileManager.h"
using namespace std;
class EmployeeManager 
{
public:
	static void printClientMenu()
	{
		cout << "===== Client Menu ===== \n";
		cout << "1. Add Client \n";
		cout << "2. Search Client \n";
		cout << "3. list Client \n";
		cout << "4. Edit Client \n";
	}

	static void newClient(Employee* employee)
	{
		if (employee == nullptr)
		{
			cerr << "Invalid Employee Pointer \n";
			return;
		}
		else
		{
			int id{};
			string name, password;
			double balance{};

			cout << "ID: "; cin >> id;
			cout << "Name: "; cin >> name;
			cout << "Password: "; cin >> password;
			cout << "Balance: "; cin >> balance;

			Client newClient(id, name, password, balance);
			FileManager f;
			f.addClient(newClient);

			cout << "Client " << name << " added successfully by Employee " << employee->getId() << endl;
		}
	}

	static void listAllClients(Employee* employee)
	{
		if (employee == nullptr)
		{
			cerr << "Invalid Employee Pointer \n";
			return;
		}
		else
		{
			FileManager f;
			f.getAllClients();
		}
	}

	static void searchForClient(Employee* employee)
	{
		if (employee == nullptr)
		{
			cerr << "Invalid Employee Pointer \n";
			return;
		}
		else
		{
			int id{};
			cout << "Enter client ID to search: \n";
			cin >> id;

			ifstream file("Client.txt");
			if (!file.is_open())
			{
				cerr << "Error Opening file \n";
			}
			else
			{

			}
		}
	}
};

