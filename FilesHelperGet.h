#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include <sstream>

#include "Employee.h"
#include "Admin.h"
#include "Client.h"
#include "Parser.h"
using namespace std;

class FilesHelperGet 
{
public:

	/*this class is for the fet functions only, saving functions are put in different class
	-getLast function returns the content of any file provided to the function in its parameter
	-getClients function returns the content of clients file the function doesn't take any parameters
	-getEmployees function returns the content of employees file the function doesn't take any parameters
	-getAdmins function returns the content of Admins file the function doesn't take any parameters
	*/

	static string getLast(const string& fileName) {
		ifstream inputFile(fileName);
		string data;
		string line;

		if (inputFile.is_open()) {

			while (getline(inputFile, line)) {
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

	static int getLastID(const string& fileName) {
		ifstream inputFile(fileName);
		string data;
		string line;
		int firstn = -1;
		if (inputFile.is_open()) {

			while (getline(inputFile, line)) {
				data = line;
			}
			istringstream iss(data);
			int number;
			if (iss >> number) {
				firstn = number;


			}

			inputFile.close();
			cout << "data from file: " << fileName << endl;


		}
		else {
			cerr << "Error opening file";
		}
		return firstn;


	}
	
	static void getClients() {
		string  fileName;
		fileName = "Clients.txt";
		ifstream clientsFile(fileName);
		string data;
		string line;

		if (clientsFile.is_open()) {

			while (getline(clientsFile, line)) {
				cout << line << endl;
			}

			clientsFile.close();
			cout << "data from file: " << fileName << endl;

		}
		else {
			cerr << "Error opening file";
		}


	}

	static void getEmployees() {
		string  fileName;
		fileName = "Employee.txt";
		ifstream employeesFile(fileName);
		string data;
		string line;

		if (employeesFile.is_open()) {

			while (getline(employeesFile, line)) {
				cout << line << endl;
			}

			employeesFile.close();
			cout << "data from file: " << fileName << endl;

		}
		else {
			cerr << "Error opening file";
		}
	}

	static void getAdmins() {
		string  fileName;
		fileName = "Admins.txt";
		ifstream adminFile(fileName);
		string data;
		string line;

		if (adminFile.is_open()) {

			while (getline(adminFile, line)) {
				cout << line << endl;
			}

			adminFile.close();
			cout << "data from file: " << fileName << endl;

		}
		else {
			cerr << "Error opening file";
		}
	}

	//.....................................................................
	 // Mahmoud Attempt

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

	//static void saveEmployee(string fileName, string lastIdFile, Employee e)
	//{
	//	int LastId = getLast("New Employee.txt");
	//	LastId++;

	//	saveLast("New Employee.txt", LastId);

	//	ofstream file("Employee.txt", ios::app);
	//	if (file.is_open())
	//	{
	//		file << LastId << "$" << e.getName() << "$" << e.getPassword() << "$" << e.getSalary() << endl;
	//		file.close();
	//		cout << "Employee Information Saved \n";
	//	}
	//}

	//static void getClients()
	//{
	//	vector<Client> clients;
	//	ifstream file("Clients.txt");

	//	if (file.is_open())
	//	{
	//		string line;
	//		while (getline(file, line))
	//		{
	//			clients.push_back(Parser::parseToClient(line));
	//		}
	//		file.close();
	//	}
	//	else {
	//		cerr << "Unable to open the file \n";
	//	}
	//}

	//static void getEmployees()
	//{
	//	vector<Employee> employees;
	//	ifstream file("Employee.txt");

	//	if (file.is_open())
	//	{
	//		string line;
	//		while (getline(file, line))
	//		{
	//			employees.push_back(Parser::parseToEmployee(line));
	//		}
	//		file.close();
	//	}
	//	else {
	//		cerr << "Unable to open the file \n";
	//	}
	//}

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


};