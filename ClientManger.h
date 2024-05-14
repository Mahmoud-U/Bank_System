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
        cout << "1. My Information \n";
        cout << "2. Update Password \n";
        cout << "3. Deposite \n";
        cout << "4. Withdraw \n";
        cout << "5. Transfer To \n";
        cout << "6. Check Balance \n";
        cout << "7. Back to Client Menu \n";
        cout << "8. Logout \n";
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

        for (clientX = allClients.begin(); clientX != allClients.end(); clientX++)
        {
            if (clientX->getId() == id && clientX->getPassword() == password) 
            {
                return clientX._Ptr;
            }
        }
        return NULL;
    }

    //Back to menu
    static void back(Client* client) 
    {
        system("pause");
        clientOptions(client);
    }

    //Client Options
    static bool clientOptions(Client* client)
    {
        double amount{};
        Employee employee;
        FileManager f;

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

            switch (choice) {
            case 1:
            {
                system("cls");
                client->Display();
                break;
            }

            case 2:
            {
                system("cls");
                updatePassword(client);
                f.updateClient();
                break;
            }

            case 3:
            {
                system("cls");
                cout << "\nEnter the amount.. \n";
                cin >> amount;
                client->Deposit(amount);
                f.updateClient();
                break;
            }

            case 4:
            {
                system("cls");
                cout << "\nEnter the amount.. \n";
                cin >> amount;
                client->Withdraw(amount);
                f.updateClient();
                break;
            }

            case 5:
            {
                system("cls");
                cout << "\nPlease Enter the Recipient ID\n";
                int id;
                cin >> id;
                while (employee.searchClient(id) == NULL) {
                    cout << "Invalid ID \n";
                    cout << "Please Enter a Valid ID \n";
                    cin >> id;
                }

                cout << "Enter the amount.. \n";
                cin >> amount;
                client->Transfer_To(amount, *employee.searchClient(id));
                f.updateClient();
                break;
            }

            case 6:
            {
                system("cls");
                client->Check_Balance();
                break;
            }

            case 7:
            {
                system("cls");
                back(client);
                break;
            }

            case 8:
            {
                system("cls");
                return false;
                break;
            }

            default:
            {
                system("cls");
                cout << "\nPlease Enter a Number Exists in the Menu!!!!\n";
                clientOptions(client);
                break;
            }
            }
            char flag = 'y';
            if (flag == 'y' || flag == 'Y') {
                cout << "\nDo you Want Another Operation?(Y/N)\n";
                cin >> flag;
                system("cls");
                if (flag == 'y' || flag == 'Y') {
                    clientOptions(client);
                }
                else {
                    return false;
                }
            }
            return true;
        }
    }
};