#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"
#include "Client.h"
using namespace std;

class Admin : public Employee
{
protected:
	//singleton design pattern
	//1.private constructor
	//2.static object pointer

    static Admin* obj;
	vector<Employee*> employees;
    
public:
    Admin() {}
    Admin(int id, string name, string password, double Salary)
        :Employee(id, name, password, Salary) {}
	
	//3.remove the copy constructor
 //   Admin(const Admin& obj) = delete;          //deleting copy constructor
 //   Admin& operator=(const Admin& other) = delete;

	////4.create public static method to return or assign value to the object
 //   static Admin* getInstance()
 //   {
 //       // If there is no instance of class
 //       // then we can create an instance.
 //       if (obj == nullptr)
 //       {
 //           // We can access private members 
 //           // within the class.
 //           obj = new Admin();

 //           // returning the instance pointer
 //           return obj;
 //       }
 //       else
 //       {
 //           // if instancePtr != NULL that means 
 //           // the class already have an instance. 
 //           // So, we are returning that instance 
 //           // and not creating new one.
 //           return instance;
 //       }
 //   }

                // Functions        
            
    void addEmployee(Employee& employee) 
    {
        employees.push_back(&employee);
    }

    Employee* searchEmployee(int id) 
    {
        for (Employee* employee : employees) {
            if (employee->id == id) {
                return employee;
            }
        }
        return nullptr;
    }

    void editEmployee(int id, string name, string password, double salary) 
    {
        Employee* employee = searchEmployee(id);
        if (employee) {
            employee->name = name;
            employee->password = password;
            employee->salary = salary;
            cout << "Employee information updated successfully." << endl;
        }
        else {
            cout << "Employee not found." << endl;
        }
    }

    void listEmployees() 
    {
        cout << "List of Employees:" << endl;
        for (Employee* employee : employees) {
            cout << "ID: " << employee->id << ", Name: " << employee->name << ", Salary: $" << employee->salary << endl;
        }
    }

	void Display()
	{
		Employee::Display();
	}

	/*Person* display() {
		return this;
	};*/

	~Admin()
	{

	}
};

static vector<Admin> allAdmins;
static vector<Admin>::iterator adminX;