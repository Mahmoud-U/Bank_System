#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class Parser
{
private:
	static vector<string> split(string& line, char delimiter)
	{
		vector<string> tokens;
		istringstream ss(line);
		string token;

		while (getline(ss, token, delimiter)) 
		{
			tokens.push_back(token);
		}
		return tokens;
	}

public:
	static Client parseToClient(string& line)
	{
		vector <string> tokens = split(line, '$');
		int id = stoi(tokens[0]);
		double balance = stod(tokens[3]);
		return Client(id, tokens[1], tokens[2], balance);
	}

	static Employee parseToEmployee(string line)
	{
		vector<string> tokens = split(line, '$');
		int id = stoi(tokens[0]);
		double salary = stod(tokens[3]);
		return Employee(id, tokens[1], tokens[2], salary);
	}

	static Admin parseToAdmin(string line)
	{
		vector<string> tokens = split(line, '$');
		int id = stoi(tokens[0]);
		double salary = stod(tokens[3]);
		return Admin(id, tokens[1], tokens[2], salary);
	}

};

