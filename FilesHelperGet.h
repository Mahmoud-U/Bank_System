#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include <sstream>
#include "Employee.h"
#include "Admin.h"
#include "Client.h"
using namespace std;
class FilesHelperGet {
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
		std::ifstream employeesFile(fileName);
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
		std::ifstream adminFile(fileName);
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

	/*static void saveLast(string fileName, int id)
	{
		ofstream file(fileName);
		if (file.is_open()) {
			file << id;
			file.close();
		}
		else {
			cerr << "Unable to save in the file \n";
		}
	}

	static int getLast(string fileName)
	{
		int id{};
		ifstream file(fileName);
		if (file.is_open()) {
			file >> id;
			file.close();
		}
		else {
			cerr << "Unable to get data from the file \n";
		}

		return id;
	}

	static void saveClient(Client c)
	{
		ofstream file("Clients.txt", ios::app);
		if (file.is_open()) 
		{
			file << c.getId() << "$" << c.getName() << "$" << c.getPassword() << "$" << c.getBalance() << endl;
			file.close();
			cout << "Client Information Saved \n";
		}
		else
		{
			cerr << "Unable to open Clients file \n";
		}
	}*/


};