#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"
using namespace std;
class EmployeeManager
{
public:
	static void printClientMenu()
	{
		cout << "===== Client Menu ===== \n";
		cout << "1. Deposite \n";
		cout << "2. Withdraw \n";
		cout << "3. TransferTo \n";
		cout << "4. Check Balance \n";
	}

	static void newClient(Employee* employee)
	{
		if (employee == nullptr)
		{
			cerr << "Invalid Employee Pointer \n";
		}
		else
		{

		}
	}
};

