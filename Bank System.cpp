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
#include "FileManager.h"
#include"FilesHelperGet.h"
using namespace std;

//void clearScreen();
//void showMenu();

int main()
//{
//	Test file manager
//
//	/*Client C1(123, "Batman", "Baaat1234", 4000);
//	Client C2(245, "Superman", "Uranium985", 7000);*/
//
//	FileManager f;
//	/*f.addClient(C1);
//	f.addClient(C2);
//	cout << endl;*/
//
//	vector<Client> clients = f.getAllClients();
//
//	cout << "Clients : \n";
//	for (Client& client : clients)
//	{
//		cout << client.getId() << client.getName() << client.getPassword() << client.getBalance() << endl;
//	}
//
//	cout << "\n===================================\n";

	/*showMenu();*/

	//Test 1
	/*Client C1(1, "Batman", "Baaat1234", 4000);
	C1.Display();
	cout << endl;

	C1.Deposit(1800);
	C1.Withdraw(2700);
	cout << endl;

	Client C2(2, "Superman", "Uranium985", 7000);
	C2.Display();
	cout << endl;
	C1.Transfer_To(900, C2);
	cout << endl;

	cout << "Client 1 ";
	C1.Check_Balance();

	cout << "Client 2 ";
	C2.Check_Balance();
	cout << "\n===================================\n";

	Client C3(3, "Ronaldo", "Maghawry123", 60000);
	C3.Display();
	cout << "\n===================================\n";

	Employee E1(8, "Spiderman", "Spider12345*$@#", 30000, 12000);
	E1.Display(); 
	cout << "\n===================================\n";

	Admin A1(5, "Ironman", "Iron12345", 30000, 8000);
	A1.Display();*/

	//Test2
	/*Client g(250, "Ali", "Alibaba2020", 10000);
	g.Display();
	cout << "\n===================================\n";

	Employee E1(100, "Spiderman", "Spider45*$@#", 30000, 12000);
	E1.Display();
	cout << "\n===================================\n";*/

	//Test file helper get 
	cout << "get data from test file:" << endl;
	cout << "contents:" << endl;
    cout << FilesHelperGet::getLast("TEST.txt");
	cout << "**********************************************\n";
	cout << "get data from clients file:" << endl;
	cout << "contents:" << endl;
	FilesHelperGet::getClients();
	cout << "**********************************************\n";
	cout << "get data from employees file:" << endl;
	cout << "contents:" << endl;
	FilesHelperGet::getEmployees();
	cout << "**********************************************\n";
	cout << "get data from Admin file:" << endl;
	cout << "contents:" << endl;
	FilesHelperGet::getEmployees();
	cout << "**********************************************\n";
	cout << "get last id from file:" << endl;
	cout << "contents:" << endl;
	cout << FilesHelperGet::getLastID("TEST.txt");
	cout << "**********************************************\n";
	


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