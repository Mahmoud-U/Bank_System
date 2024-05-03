#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <conio.h>
#include<fstream>

#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "ClientManger.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
#include "Screens.h"
using namespace std;

int main()
{
	ClientManger c;
	Client* aa = new Client;
	c.updatePassword(aa);

	//Screens::runApp();

	return 0;
}













//void clearScreen() 
//{
//    system("cls"); // Clear the console screen on Windows
//}
//
//void showMenu() 
//{
//    int choice;
//    do {
//        void clearScreen();         // Clear the screen before displaying the menu
//        cout << "\nChoose an option:" << endl;
//        cout << "1. Client" << endl;
//        cout << "2. Employee" << endl;
//        cout << "3. Admin" << endl;
//
//        cout << "\nEnter your choice: ";
//        cin >> choice;
//
//        if (cin.fail() || choice < 1 || choice > 3) 
//        {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "\nInvalid operation. Please choose a valid option. \n" <<
//                    "Hit Enter button to start again" << endl;
//            cout << "\n................................................................\n";
//            cin.get();              // Wait for user to press Enter to continue
//        }
//
//    } while (choice < 1 || choice > 3);
//
//    switch (choice) 
//    {
//    case 1:
//        clearScreen();
//        cout << "Press 0 to go back to the menu or press Esc to exit the program." << endl;
//        cout << "You chose Client." << endl;
//        while (true) 
//        {
//            char key = _getch();
//            if (key == '0') 
//            {
//                cin.get();
//                showMenu();
//                break;
//            }
//            else if (key == 27)      // 27 is the ASCII code for Esc
//            {  
//                exit(0);
//            }
//        }
//        break;
//
//    case 2:
//        clearScreen();
//        cout << "Press 0 to go back to the menu or press Esc to exit the program." << endl;
//        cout << "You chose Employee." << endl;
//        while (true) 
//        {
//            char key = _getch();
//            if (key == '0') 
//            {
//                cin.get();
//                showMenu();
//                break;
//            }
//            else if (key == 27) 
//            {  
//                exit(0);
//            }
//        }
//        break;
//
//    case 3:
//        clearScreen();
//        cout << "Press 0 to go back to the menu or press Esc to exit the program." << endl;
//        cout << "You chose Admin. Moving to the Admin screen..." << endl;
//        while (true) 
//        {
//            char key = _getch();
//            if (key == '0') 
//            {
//                cin.get();
//                showMenu();
//                break;
//            }
//            else if (key == 27) 
//            {  
//                exit(0);
//            }
//        }
//        break;
//    }
//}