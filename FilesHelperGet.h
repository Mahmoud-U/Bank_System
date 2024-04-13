#include<string>
#include<iostream>
#include<vector>
#include<fstream>
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
		std::ifstream inputFile(fileName);
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
		std::ifstream inputFile(fileName);
		string data;
		string line;
		int firstn = -1;
		if (inputFile.is_open()) {

			while (getline(inputFile, line)) {
				data = line;
			}
			std::istringstream iss(data);
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
		std::ifstream clientsFile(fileName);
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
};