#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "FileManager.h"
#include "ClientManger.h"
using namespace std;
class EmployeeManager 
{
public:
	//Employee Menu
	static void printEmployeeMenu()
	{
		cout << "===== Employee Menu ===== \n";
		cout << "1. My Information \n";
		cout << "2. Check Salary \n";
		cout << "3. Edit Password \n";
		cout << "4. Add New Client \n";
		cout << "5. Search For A Client \n";
		cout << "6. list All Clients \n";
		cout << "7. Edit Client Information \n";
		cout << "8. Back To Employee Menu \n";
		cout << "9. Logout \n";
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
			string name, password;
			double balance{};

			Client client;
			client.setName(name);
			client.setPassword(password);
			client.setBalance(balance);

			employee->addClient(client);
			FileManager f;
			f.updateClient();
			cout << "\nClient is Added Successfully \n";
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

			system("cls");
			if (employee->searchClient(id) == nullptr)
			{
				cout << "Client Not Found \n";
			}
			else {
				cout << "Client Found, ";
				employee->searchClient(id)->Display();
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

			system("cls");
			if (employee->searchClient(id) == nullptr)
			{
				cout << "Client Not Found \n";
			}
			else
			{
				int id{};
				string name, password;
				double balance{};
				Client c;

				cout << "Enter new name for the client: ";
				cin >> name;
				c.setName(name);

				cout << "Enter new password for the client: ";
				cin >> password;
				c.setPassword(password);

				cout << "Enter new balance for the client: ";
				cin >> balance;
				c.setBalance(balance);

				employee->editClient(id, name, password, balance);
				FileManager f;
				f.updateClient();

				cout << "Client information updated successfully." << endl;
			}
		}
	}

	//Employee LogIn
	static Employee* loginEmployee(int id, string password)
	{
		for (employeeX = allEmployees.begin(); employeeX != allEmployees.end(); employeeX++)
		{
			if (employeeX->getId() == id && employeeX->getPassword() == password) {
				return employeeX._Ptr;
			}
			else {
				return NULL;
			}
		}
	}

	//Back
	static void back(Employee* employee) {
		/*system("pause");*/
		employeeOptions(employee);
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
			FileManager f;

			switch (choice)
			{
			case 1:
			{
				system("cls");
				employee->Display();
				break;
			}
			case 2:
			{
				system("cls");
				employee->Check_Salary();
				break;
			}

			case 3:
			{
				system("cls");
				ClientManger::updatePassword(employee);
				f.updateEmployee();
				break;
			}

			case 4:
			{
				system("cls");
				ClientManger::updatePassword(employee);
				f.updateEmployee();
				break;
			}
				
			case 5:
			{
				system("cls");
				searchForClient(employee);
				break;
			}

			case 6:
			{
				system("cls");
				listAllClients(employee);
				break;
			}

			case 7:
			{
				system("cls");
				editClientInfo(employee);
				break;
			}

			case 8:
			{
				system("cls");
				back(employee);
				break;
			}

			case 9:
			{
				system("cls");
				return false;
				break;
			}

			default:
			{
				system("cls");
				cout << "\nPlease Enter a Number Exists in the Menu!\n";
				back(employee);
				break;
			}
			}
			char flag = 'y';
			if (flag == 'y' || flag == 'Y') {
				cout << "\nDo you Want Another Operation?(Y/N)\n";
				cin >> flag;
				system("cls");
				if (flag == 'y' || flag == 'Y') {
					employeeOptions(employee);
				}
				else {
					return false;
				}
			}
			return true;
		}
	}
};