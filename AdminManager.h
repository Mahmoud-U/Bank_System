#pragma once
#include <iostream>
#include <string>

#include "FileManager.h"
using namespace std;
class AdminManager
{
public:
    //Admin Menu
    static void printAdminMenu() {
        cout << "===== Admin Menu ===== \n";
        cout << "1. Admin Login \n";
        cout << "2. My Information \n";
        cout << "3. Search Employee \n";
        cout << "4. List Employee \n";
        cout << "5. Edit Employee \n";
    }

    //Admin LogIn
    static Admin* adminLogin(int id, string password) 
    {
        FileManager f;
        f.getAllAdmins();

        if (adminX->getId() == id && adminX->getPassword() == password)
            return adminX._Ptr;
        else
            return nullptr;
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

    //List Employees
    static void listAllEmployees(Admin* admin)
    {
        if (admin == nullptr)
        {
            cerr << "Invalid admin Pointer \n";
            return;
        }
        else
        {
            FileManager f;
            f.getAllEmployees();
            admin->listEmployee();
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

            int choice{};
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                int id{};
                string password;
                cout << "Enter your ID: "; cin >> id;
                cout << "Enter your password "; cin >> password;

                adminLogin(id, password);
                break;
            }
            case 2:
            {
                admin->Display();
                break;
            }

            case 3:
            {
                searchForEmployee(admin);
                break;
            }

            case 4:
            {
                admin->listEmployee();
                break;
            }

            case 5:
            {
                int id{};
                string name, password;
                double salary{};

                cout << "Enter new name for the client: ";
                cin >> name;

                cout << "Enter new password for the client: ";
                cin >> password;

                cout << "Enter new balance for the client: ";
                cin >> salary;

                admin->editEmployee(id, name, password, salary);
                cout << "Employee information updated successfully." << endl;

                break;
            }
            default:
            {
                cout << "Invalid Operation \n";
                cout << "Please, Try Again \n";
                break;
            }

            }
        }
        return true;
    }
};