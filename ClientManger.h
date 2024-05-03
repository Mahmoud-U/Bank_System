#pragma once
#include <iostream>
#include <string>

#include "FileManager.h"
using namespace std;
class ClientManger
{
public:
    //Client Menu
    static void printClientMenu() {
        cout << "===== Client Menu ===== \n";
        cout << "1. Client Login \n";
        cout << "2. My Information \n";
        cout << "3. Update Password \n";
        cout << "4. Deposite \n";
        cout << "5. Withdraw \n";
        cout << "6. Transfer To \n";
        cout << "7. Check Balance \n";
    }

    //Update Password
    static void updatePassword(Person* person) 
    {
        int id{};
        cout << "Enter an ID to search \n";
        cin >> id;

        FileManager f;
        f.getAllClients();

        if (clientX->getId() == id)
        {
            string password;
            cout << "Enter new password: \n";
            cin >> password;

            person->setPassword(password);
            cout << "Password updated successfully for \n";
        }
        else
        {
            cout << "Client Not Found \n";
        }
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
    static bool clientOptions(Client* client)
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
            {
                int id{};
                string password;
                cout << "Enter your ID: "; cin >> id;
                cout << "Enter your password "; cin >> password;

                clientLogin(id, password);

                break;
            }
            case 2:
            {
                client->Display();
                break;
            }

            case 3:
            {
                updatePassword(client);
                break;
            }

            case 4:
            {
                double amount{};
                cout << "Enter the amount \n";
                cin >> amount;
                client->Deposit(amount);
                break;
            }

            case 5:
            {
                double amount{};
                cout << "Enter the amount \n";
                cin >> amount;
                client->Withdraw(amount);
                break;
            }

            case 6:
            {
                double amount{};
                Client recipient;

                cout << "Enter the amount \n";
                cin >> amount;

                client->Transfer_To(amount, recipient);
                break;
            }

            case 7:
            {
                client->Display();
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

    }


};

