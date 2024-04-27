#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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
		ifstream file;
		file.open("Clients.txt");
		string line;
		while (getline(file, line))
		{
			allClients.push_back(Parser::parseToClient(line));
		}
		file.close();
	}

	//Get All Employees
	static void getEmployees()
	{
		ifstream file;
		file.open("Employee.txt");
		string line;
		while (getline(file, line))
		{
			allEmployees.push_back(Parser::parseToEmployee(line));
		}
		file.close();
	}

	//Get All Admins
	static void getAdmins() 
	{

		ifstream file;
		file.open("Admins.txt");
		string line;
		while (getline(file, line)) 
		{
			allAdmins.push_back(Parser::parseToAdmin(line));
		}
		file.close();
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