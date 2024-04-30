#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "FileManager.h"
using namespace std;
class EmployeeManager 
{
public:
	//Employee Menu
	static void printEmployeeMenu()
	{
		cout << "===== Employee Menu ===== \n";
		cout << "1. Employee Login \n";
		cout << "2. My Information \n";
		cout << "3. Add Client \n";
		cout << "4. Search Client \n";
		cout << "5. list Client \n";
		cout << "6. Edit Client \n";
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
			int id{};
			cout << "Enter an ID to search \n";
			cin >> id;

			FileManager f;
			f.getAllClients();

			if (employee->searchClient(id) == nullptr)
			{
				cout << "Client Not Found \n";
			}
			else 
			{
				int id{};
				string name, password;
				double balance{};

				cout << "Enter new name for the client: ";
				cin >> name;

				cout << "Enter new password for the client: ";
				cin >> password;

				cout << "Enter new balance for the client: ";
				cin >> balance;

				employee->editClient(id, name, password, balance);

				cout << "Client information updated successfully." << endl;
			}
		}
	}

	//Employee LogIn
	static Employee* loginEmployee(int id, string password)
	{
		FileManager f;
		f.getAllEmployees();

		if (employeeX->getId() == id && employeeX->getPassword() == password)
			return employeeX._Ptr;
		else
			return nullptr;
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
			{
				int id{};
				string password;

				cout << "Enter your ID: "; cin >> id;
				cout << "Enter your password "; cin >> password;

				loginEmployee(id, password);
				break;
			}

			case 2:
			{
				employee->Display();
				break;
			}

			case 3:
			{
				newClient(employee);
				break;
			}
				
			case 4:
			{
				listAllClients(employee);
				break;
			}

			case 5:
			{
				searchForClient(employee);
				break;
			}

			case 6:
			{
				editClientInfo(employee);
				break;
			}

			case 7:
			{
				int id{};
				string password;

				cin >> id;
				cin >> password;

				loginEmployee(id, password);
				break;
			}

			default:
			{
				cout << "Invalid Operation \n";
				cout << "Please, Try Again \n";
				break;
			}

			}
		}
		return true;
	}
};

