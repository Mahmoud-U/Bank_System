#pragma once
#include <iostream>
#include <string>

#include "FileManager.h"
using namespace std;
class AdminManager
{
public:
    //Client Menu
    static void printClientMenu() {
        cout << "===== Client Menu ===== \n";
        cout << "1. My Information \n";
        cout << "2. Deposite \n";
        cout << "3. Withdraw \n";
        cout << "4. Transfer To \n";
        cout << "5. Check Balance \n";
    }

    //Client LogIn
    static Client* clientLogin(int id, string password) 
    {
        FileManager f;
        f.getAllClients();
        if (clientX->getId() == id && clientX->getPassword() == password)
            return clientX._Ptr;
        else
            return nullptr;
    }

    //Client Options
    static bool AdminOptions(Client* client) 
    {
        if (client == nullptr)
        {
            cout << "Invalid client." << endl;
            return false;
        }
        else
        {
            printClientMenu();

            int choice{};
            cin >> choice;

            switch (choice)
            {
            case 1:
                client->Display();
                break;

            case 2:
            {
                double amount{};
                client->Deposit(amount);
                break;
            }
            case 3:
            {
                double amount{};
                client->Withdraw(amount);
                break;
            }
            case 4:
            {
                double amount{};
                Client recipient;
                client->Transfer_To(amount, recipient);
                break;
            }
            case 5:
            {
                client->Check_Balance();
            }
            default:
            {
                cout << "Invalid Operation \n";
                cout << "Please, Try Again \n";
                break;
            }

            }
        }
       
    }
};