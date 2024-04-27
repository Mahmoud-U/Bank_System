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
	//Print Employee Menu
	static void printEmployeeMenu()
	{
		cout << "===== Employee Menu ===== \n";
		cout << "1. My Information \n";
		cout << "2. Add Client \n";
		cout << "3. Search Client \n";
		cout << "4. list Client \n";
		cout << "5. Edit Client \n";
	}

	//Add New Client
	static void newClient(Employee* employee)
	{
		if (employee == nullptr)
		{
			cerr << "Invalid Employee Pointer \n";
			return;
		}
		else
		{
			Client c;
			employee->addClient(c);
			FileManager f;
			f.addClient(c);
		}
	}

	//List All Clients
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
			employee->listClient();
		}
	}

	//Search For Clients
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
			cout << "Enter an ID to search \n";
			cin >> id;

			FileManager f;
			f.getAllClients();

			if (employee->searchClient(id) == nullptr)
			{
				cout << "Client Not Found \n";
			}
			else {
				cout << "Client Found \n";
			}
		}
	}

	//Edit Client Info
	static void editClientInfo(Employee* employee)
	{
		if (employee == nullptr)
		{
			cerr << "Invalid Employee Pointer \n";
			return;
		}
		else
		{
			string newName, newPass;
			double newBalance{};

			ofstream file("Clients.txt");
			if (file.is_open())
			{
				//employee->editClient(1, "Mido", "PassAttemp3t", 450500);
			}
		}
	}

	//Client Login
	static Employee* loginEmployee(int id, string password)
	{
		if (employeeX->getId() == id && employeeX->getPassword() == password)
		{

		}
	}

	//Employee Options
	static bool employeeOptions(Employee* employee)
	{
		if (employee == nullptr)
		{
			cout << "Invalid client." << endl;
			return false;
		}
		else 
		{
			printEmployeeMenu();

			cout << "Enter a choice \n";
			int choice{};
			cin >> choice;

			switch (choice)
			{
			case 1:
				employee->Display();
				break;

			case 2:
				newClient(employee);
				break;
				
			case 3:
				listAllClients(employee);
				break;

			case 4:
				searchForClient(employee);
				break;

			case 5:
				editClientInfo(employee);
				break;

			case 6:
			{
				int id{};
				string password;

				cin >> id;
				cin >> password;

				loginEmployee(id, password);
				break;
			}

			default:
				cout << "Invalid Operation \n";
				cout << "Please, Try Again \n";
				break;
			}
		}
	}
};

