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
	//Print Client Menu
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
			Client c;
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
	static Client* login(int id, string password)
	{
		vector<Client*> allClients;
		for (Client* client : allClients)
		{
			if (client->getId() == id && client->getPassword() == password)
			{
				return client;
			}
		}
		return nullptr;
	}

	//Employee Options
	static bool employeeOptions(Client* client)
	{
		if (client == nullptr)
		{
			cout << "Invalid client." << endl;
			return false;
		}
		else {

		}
	}
};

