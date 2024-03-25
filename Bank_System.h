#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <regex>
using namespace std;
class Bank_System
{

};

class Person 
{
protected:
	//Attributes
	int id;
	string name;
	string password;
	double balance;
public:
	//Constructors
	Person()
	{
		id = 0;
		balance = 0.0;
	}
	Person(int id, string name, string password,double balance) 
	{
		this->id = id;
		this->password = password;
		this->balance = balance;

		//Name Valid
		if (Valid_Name(name))
			this->name = name;
		else
			cout << "Invalid name format. Name must have a length between 5 and 20." << endl;

		//Pass Valid
		if (Valid_Password(password))
			this->password = password;
		else
			cout << "Invalid password format. Password must have a length between 8 and 20" << endl;

		//Balance Valid
		if (balance < 1500)
		{
			balance = 1500;
		}
	}

	//Name & Password Validation
	static bool Valid_Name(string name)
	{
		regex pattern("^[A-Z][a-z]{5,20}$");

		return regex_match(name, pattern);
	}

	static bool Valid_Password(string password)
	{
		regex pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[A-Za-z0-9]{8,20}$");

		return regex_match(password, pattern);
	}
	
	//setters:
	void setId(int id) 
	{
		this->id = id;
	}
	void setName(string name)
	{
		if (Valid_Name(name))
			this->name = name;
		else
			cout << "Invalid name format. Name must have a length between 5 and 20." << endl;
	}
	void setPassword(string password)
	{
		if (Valid_Password(password))
			this->password = password;
		else
			cout << "Invalid password format. Password must have a length between 8 and 20" << endl;
	}
	void setBalance(double balance)
	{
		if (balance >= 1500)
			this->balance = balance;
	}

	//Getters
	int getId() 
	{
		return this->id;
	}
	string getName() 
	{
		return this->name;
	}
	string getPassword() 
	{
		return this->password;
	}
	double getBalance()
	{
		return balance;
	}

	virtual void Display()
	{
		std::cout << "Person Details : " << endl;
		std::cout << "ID : " << id << endl;
		std::cout << "Name : " << name << endl;
		std::cout << "Balance : " << balance << endl;
	}

	~Person()
	{
		
	}
};

class Client : public Person 
{
private:
	//Attributes
	double balance;
public:
	//Constructors
	Client() 
	{
		balance = 0.0;
	}
	Client(int id, string name, string password, double balance)
		:Person(id, name, password, balance)
	{
		this->balance = balance;
	}

	//Deposite
	void Deposit(double amount) 
	{
		if (amount > 0) 
		{
			balance += amount;
			cout << "Deposit of " << amount << " successful. New balance : " << balance << endl;
		}
		else 
		{
			cout << "Invalid deposit amount. Please enter a positive value." << endl;
		}
	}

	//Withdraw
	void Withdraw(double amount) 
	{
		if (amount > 0 && balance - amount >= 1500) 
		{
			balance -= amount;
			cout << "Withdrawal of " << amount << " successful. New balance : " << balance << endl;
		}
		else 
		{
			cout << "Invalid withdrawal amount or insufficient balance." << endl;
		}
	}

	//TransferTo
	void Transfer_To(double amount, Client& recipient) 
	{
		if (amount > 0 && balance - amount >= 1500) 
		{
			balance -= amount;
			recipient.balance += amount;
			cout << "Transfer of " << amount << " successful. New balance : " << balance << endl;
		}
		else 
		{
			cout << "Invalid transfer amount or insufficient balance." << endl;
		}
	}

	//Check Balance
	void Check_Balance() 
	{
		cout << "Current balance: " << balance << std::endl;
	}

	void Display() 
	{
		Person::Display();
	}

	/*Person* display() {
		return this;
	};*/

	~Client()
	{
		
	}
};

class Employee : public Person
{
private:
	//Attributes
	double Salary;
public:
	//Constructors
	Employee() 
	{
		Salary = 0.0;
	}
	Employee(int id, string name, string password, double balance, double Salary)
		:Person(id, name, password, balance)
	{
		this->Salary = Salary;

		if (Salary < 5000)
		{
			Salary = 5000;
		}
	}

	//Setters
	void setSalary(double Salary)
	{
		if (Salary >= 5000)
			this->Salary = Salary;
	}

	//Getters
	double getSalary()
	{
		return this->Salary = Salary;
	}
	
	void Display()
	{
		Person::Display();
		cout << "Salary : " << Salary << endl;
	}
	/*Person* display() {
		return this;
	};*/

	~Employee()
	{
		
	}
};

class Admin : public Person
{
private:
	//Attributes
	double Salary;
public:
	//Constructors
	Admin()
	{
		Salary = 0.0;
	}
	Admin(int id, string name, string password, double balance, double Salary)
		:Person(id, name, password, balance)
	{
		this->Salary = Salary;

		if (Salary < 5000)
		{
			Salary = 5000;
		}
	}

	//Setters
	void setSalary(double Salary)
	{
		if (Salary >= 5000)
			this->Salary = Salary;
	}

	//Getters
	double getSalary()
	{
		return this->Salary = Salary;
	}

	void Display()
	{
		Person::Display();
		cout << "Salary : " << Salary << endl;
	}

	/*Person* display() {
		return this;
	};*/

	~Admin()
	{
		
	}
};