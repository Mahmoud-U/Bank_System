#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"
using namespace std;

class Admin : public Employee
{
protected:
	//singleton design pattern
	//1.private constructor
	//2.static object pointer
    static Admin* obj;    
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

                // Methods        
       
    //Add Employee
    void addEmployee(Employee& employee) 
    {
        string name, password;
        double salary{};

        cout << "Enter Your Name: "; cin >> name;
        employee.setName(name);

        cout << "Enter Your Password: "; cin >> password;
        employee.setPassword(password);

        cout << "Enter Your Balance: "; cin >> salary;
        employee.setSalary(salary);

        allEmployees.push_back(employee);
    }

    //Search Employee
    Employee* searchEmployee(int id)
    {
        for (employeeX = allEmployees.begin(); employeeX != allEmployees.end(); employeeX++)
        {
            if (employeeX->getId() == id)
                return employeeX._Ptr;
        }
        return nullptr;
    }

    //List Employee
    void listEmployee() {
        for (employeeX = allEmployees.begin(); employeeX != allEmployees.end(); employeeX++)
        {
            employeeX->Display();
        }
    }

    //Edit Employee
    void editEmployee(int id, string name, string password, double salary)
    {
        searchEmployee(id)->setName(name);
        searchEmployee(id)->setPassword(password);
        searchEmployee(id)->setSalary(salary);
    }

    // Check Salary
    void Check_Salary()
    {
        cout << "Current Salary : " << salary << endl;
    }

	void Display()
	{
        cout << "Admin Details : " << endl;
        cout << "ID : " << getId() << ", Name : " << getName() << ", Password : "
             << getPassword() << ", Salary : " << getSalary() << endl;
    }

	~Admin()
	{

	}
};
static vector<Admin> allAdmins;
static vector<Admin>::iterator adminX;