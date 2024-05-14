#pragma once
#include <iostream>
#include <string>

#include "FileManager.h"
#include "ClientManger.h"
#include "EmployeeManager.h"
using namespace std;
class AdminManager
{
public:
    //Admin Menu
    static void printAdminMenu() {
        cout << "===== Admin Menu ===== \n";
        cout << "1. Display Information \n";
        cout << "2. Check Salary \n";
        cout << "3. Edit Password \n";
        cout << "4. Add New Employee \n";
        cout << "5. Add New Client \n";
        cout << "6. List all Employees \n";
        cout << "7. List all Clients \n";
        cout << "8. Search For An Employee \n";
        cout << "9. Search For A Client \n";
        cout << "10. Edit Employee Information \n";
        cout << "11. Edit Client Information \n";
        cout << "12. Back To Admin Menu \n";
        cout << "13. Logout \n";
    }

    //Back
    static void back(Admin* admin)
    {
        printAdminMenu();
    }

    //Add Employee
    static void newEmployee(Admin* admin)
    {
        string name, password;
        double balance{};

        Employee employee;
        employee.setName(name);
        employee.setPassword(password);
        employee.setBalance(balance);

        admin->addEmployee(employee);
        FileManager f;
        f.updateEmployee();
        cout << "\nEmployee is Added Successfully \n";
    }

    //List Employees
    static void listAllEmployees(Admin* admin)
    {
        admin->listEmployee();
    }


    //Admin LogIn
    static Admin* adminLogin(int id, string password)
    {
        for (adminX = allAdmins.begin(); adminX != allAdmins.end(); adminX++)
        {
            if (adminX->getId() == id && adminX->getPassword() == password) {
                return adminX._Ptr;
            }
            else {
                return NULL;
            }
        }
    }

    //Search For Employees
    static void searchForEmployee(Admin* admin)
    {
        if (admin == nullptr)
        {
            cerr << "Invalid Admin Pointer \n";
            return;
        }
        else
        {
            int id{};
            cout << "Enter an ID to search \n";
            cin >> id;

            FileManager f;
            f.getAllEmployees();

            system("cls");
            if (admin->searchEmployee(id) == nullptr)
            {
                cout << "Employee Not Found \n";
            }
            else {
                cout << "Employee Found ";
                admin->searchEmployee(id)->Display();
            }
        }
    }

    //Edit Employee Info
    static void editEmployeeInfo(Admin* admin)
    {
        cout << "Please Enter Employee ID\n";
        int id;
        cin >> id;

        system("cls");
        if (admin->searchEmployee(id) == NULL)
        {
            cout << "\nEmployee is not Found\n";
        }
        else
        {
            int id{};
            string name, password;
            double balance{};
            Employee e;

            cout << "Enter new name for the client: ";
            cin >> name;
            e.setName(name);

            cout << "Enter new password for the client: ";
            cin >> password;
            e.setPassword(password);

            cout << "Enter new balance for the client: ";
            cin >> balance;
            e.setBalance(balance);

            admin->editEmployee(id, name, password, balance);
            FileManager f;
            f.updateEmployee();

            cout << "Employee information updated successfully." << endl;
        }
    }

    //Admin Options
    static bool adminOptions(Admin* admin)
    {
        if (admin == nullptr)
        {
            cout << "Invalid Admin" << endl;
            return false;
        }
        else
        {
            printAdminMenu();
            FileManager f;

            int choice{};
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                system("cls");
                admin->Display();
                break;
            }
            case 2:
            {
                system("cls");
                admin->Check_Salary();
                break;
            }

            case 3:
            {
                system("cls");
                ClientManger::updatePassword(admin);
                f.updateAdmin();
                break;
            }

            case 4:
            {
                system("cls");
                newEmployee(admin);
                break;
            }

            case 5:
            {
                system("cls");
                EmployeeManager::newClient(admin);
                break;
            }

            case 6:
            {
                system("cls");
                listAllEmployees(admin);
                break;
            }

            case 7:
            {
                system("cls");
                EmployeeManager::listAllClients(admin);
                break;
            }

            case 8:
            {
                system("cls");
                searchForEmployee(admin);
                break;
            }

            case 9:
            {
                system("cls");
                EmployeeManager::searchForClient(admin);
                break;
            }

            case 10:
            {
                system("cls");
                editEmployeeInfo(admin);
                break;
            }

            case 11:
            {
                system("cls");
                EmployeeManager::editClientInfo(admin);
                break;
            }

            case 12:
            {
                system("cls");
                back(admin);
                break;
            }

            case 13:
            {
                system("cls");
                return false;
                break;
            }

            default:
            {
                system("cls");
                cout << "\nPlease Enter a Number Exists in the Menu!\n";
                back(admin);
                break;
            }
            }
            char flag = 'y';
            if (flag == 'y' || flag == 'Y') {
                cout << "\nDo you Want Another Operation?(Y/N)\n";
                cin >> flag;
                system("cls");
                if (flag == 'y' || flag == 'Y') {
                    adminOptions(admin);
                }
                else {
                    return false;
                }
            }
            return true;
        }
    }
};