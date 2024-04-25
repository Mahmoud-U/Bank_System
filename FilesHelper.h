#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Employee.h"
#include "Admin.h"
#include "Client.h"
#include "Parser.h"
using namespace std;

class FilesHelper
{
public:

	/*this class is for the fet functions only, saving functions are put in different class
	-getLast function returns the content of any file provided to the function in its parameter
	-getClients function returns the content of clients file the function doesn't take any parameters
	-getEmployees function returns the content of employees file the function doesn't take any parameters
	-getAdmins function returns the content of Admins file the function doesn't take any parameters
	*/
					//Get

	static int getLast(string fileName)
	{
		int id{};
		ifstream file;
		file.open(fileName);
		file >> id;
		file.close();
		
		return id;
	}

	static int getLastID(const string& fileName)
	{
		ifstream inputFile(fileName);
		string data;
		string line;
		int firstn = -1;
		if (inputFile.is_open())
		{
			while (getline(inputFile, line)) {
				data = line;
			}

			istringstream iss(data);
			int number;

			if (iss >> number)
			{
				firstn = number;
			}

			inputFile.close();
		}
		else 
		{
			cerr << "Error opening file";
		}
		return firstn;
	}

	static string getLast(const string& fileName) 
	{
		ifstream inputFile(fileName);
		string data;
		string line;

		if (inputFile.is_open()) 
		{

			while (getline(inputFile, line)) 
			{
				cout << line << endl;
			}

			inputFile.close();
			cout << "data from file: " << fileName << endl;

		}
		else {
			cerr << "Error opening file";
		}
		return data;
	}

	//Get All Clients
	static void getClients()
	{
		vector<Client> clients;
		string  fileName;
		fileName = "Clients.txt";
		ifstream employeesFile(fileName);
		string line;

		if (employeesFile.is_open())
		{

			while (getline(employeesFile, line))
			{
				clients.push_back(Parser::parseToClient(line));
			}

			for (Client& client : clients)
			{
				cout << "Client ID: " << client.getId() << ", Name: " << client.getName() << ", Password: " <<
					client.getPassword() << ", Balance: " << client.getBalance() << endl;
				cout << "---------------------" << endl;
			}
			employeesFile.close();
		}
		else {
			cerr << "Unable to open Clients file \n";
		}
		cout << "Clients Data From File: " << fileName << endl;
	}

	//Get All Employees
	static void getEmployees()
	{
		vector<Employee> employees;
		
		string  fileName;
		fileName = "Employee.txt";
		ifstream employeesFile(fileName);
		string line;

		if (employeesFile.is_open())
		{
			while (getline(employeesFile, line))
			{
				employees.push_back(Parser::parseToEmployee(line));
			}

			for (Employee& employee : employees)
			{
				cout << "Employee ID: " << employee.getId() << ", Name: " << employee.getName() << ", Password: " <<
					employee.getPassword() << ", Salary: " << employee.getSalary() << endl;
				cout << "---------------------" << endl;
			}
			employeesFile.close();
		}
		else {
			cerr << "Unable to open the file \n";
		}
		cout << "Employee Data From File: " << fileName << endl;
	}

	//Get All Admins
	static void getAdmins() 
	{
		vector<Admin> admins;

		string  fileName;
		fileName = "Admins.txt";
		ifstream adminFile(fileName);
		string line;

		if (adminFile.is_open()) 
		{
			while (getline(adminFile, line)) {
				admins.push_back(Parser::parseToAdmin(line));
			}

			for (Admin& admin : admins)
			{
				cout << "Employee ID: " << admin.getId() << ", Name: " << admin.getName() << ", Password: " <<
					admin.getPassword() << ", Salary: " << admin.getSalary() << endl;
				cout << "---------------------" << endl;
			}

			adminFile.close();
		}
		else {
			cerr << "Error opening file";
		}
		cout << "Admins Data From File: " << fileName << endl;
	}

					//Save

	static void saveLast(string lastIdFile, int id)
	{
		ofstream file;
		file.open(lastIdFile);
		file << id;
		file.close();
	}

	//Save Client
	static void saveClient(Client c)
	{
		ofstream file("Clients.txt", ios::app);
		ofstream file1("New Client.txt", ios::app);

		int id = FilesHelper::getLastID("New Client.txt") + 1;
		saveLast("New Client.txt", id);

		if (file.is_open() && file1.is_open())
		{
			file << id << "$" << c.getName() << "$" << c.getPassword() << "$" << c.getBalance() << endl;
			file.close();
			cout << "Client Information Saved \n";
		}
		else
		{
			cerr << "Unable to open Clients file \n";
		}
	}

	//Save Employee
	static void saveEmployee(string fileName, string lastIdFile, Employee e)
	{
		ofstream file(fileName, ios::app);
		ofstream file1(lastIdFile, ios::app);

		int result = FilesHelper::getLastID(lastIdFile) + 1;
		saveLast("New Employee.txt", result);

		if (file.is_open() && file1.is_open())
		{
			file << result;
			file << "$" << e.getName() << "$" << e.getPassword() << "$" << e.getSalary() << endl;
			file.close();
			cout << "Employee Information Saved \n";
		}
		else
		{
			cerr << "Unable to open Employees file \n";
		}
	}

					// Clear
				
	static void clearFile(string fileName, string lastIdFile) 
	{
		ofstream file(fileName, ios::out);
		file.close();

		ofstream idfile(lastIdFile);
		if (idfile.is_open())
		{
			idfile << 0;
			cout << " Information is cleared \n";
		}
		else
		{
			cerr << "Unable to clear data \n";
		}
	}
};
	//.....................................................................
	 // Another Attempt

	//static void saveLast(string fileName, int id)
	//{
	//	ofstream file(fileName, ios::app);
	//	if (file.is_open()) {
	//		file << id;
	//		file.close();
	//	}
	//	else {
	//		cerr << "Unable to save in the file \n";
	//	}
	//}

	//static int getLast(string fileName)
	//{
	//	int id{};
	//	ifstream file(fileName);
	//	if (file.is_open()) {
	//		file >> id;
	//		file.close();
	//	}
	//	else {
	//		cerr << "Unable to get data from the file \n";
	//	}

	//	return id;
	//}

	//static void saveClient(Client c)
	//{
	//	ofstream file("Clients.txt", ios::app);
	//	if (file.is_open()) 
	//	{
	//		file << c.getId() << "$" << c.getName() << "$" << c.getPassword() << "$" << c.getBalance() << endl;
	//		file.close();
	//		cout << "Client Information Saved \n";
	//	}
	//	else
	//	{
	//		cerr << "Unable to open Clients file \n";
	//	}
	//}

	/*static void saveEmployee(string fileName, string lastIdFile, Employee e)
	{
		int LastId = FilesHelper::getLastID("New Employee.txt");
		LastId++;

		saveLast("New Employee.txt", LastId);

		ofstream file("Employee.txt", ios::app);
		if (file.is_open())
		{
			file << LastId << "$" << e.getName() << "$" << e.getPassword() << "$" << e.getSalary() << endl;
			file.close();
			cout << "Employee Information Saved \n";
		}
	}*/

	/*static void getClients()
	{
		vector<Client> clients;
		string line;
		ifstream file("Clients.txt");

		if (file.is_open())
		{
			
			while (getline(file, line))
			{
				clients.push_back(Parser::parseToClient(line));
			}
			file.close();

			for (Client& client : clients)
			{
				cout << "Client ID: " << client.getId() << ", Name: " << client.getName() << ", Password: " <<
					client.getPassword() << ", Balance: " << client.getBalance() << endl;
				cout << "---------------------" << endl;
			}
		}
		else {
			cerr << "Unable to open Clients file \n";
		}
	}*/

	/*static void getEmployees()
	{
		vector<Employee> employees;
		ifstream file("Employee.txt");

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				employees.push_back(Parser::parseToEmployee(line));
			}
			file.close();
		}
		else {
			cerr << "Unable to open the file \n";
		}
	}*/

	//static void getAdmins()
	//{
	//	vector<Admin> admins;
	//	ifstream file("Admins.txt");

	//	if (file.is_open())
	//	{
	//		string line;
	//		while (getline(file, line))
	//		{
	//			admins.push_back(Parser::parseToAdmin(line));
	//		}
	//		file.close();
	//	}
	//	else {
	//		cerr << "Unable to open the file \n";
	//	}
	//}

	//static void clearFile(string fileName, string lastIdFile)
	//{
	//	ofstream file(fileName, ios::trunc);
	//	ofstream fileanother(lastIdFile, ios::trunc);
	//	file.close();
	//	cout << "Information Removed Successfully \n";
	//	saveLast(lastIdFile, 0);

	//	if (!file)
	//	{
	//		cerr << "Unable To Clear Data \n";
	//	}
	//}	
