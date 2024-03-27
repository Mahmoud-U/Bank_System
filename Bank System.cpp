#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <conio.h>
#include "Bank_System.h"
using namespace std;

void clearScreen();
void showMenu();
int main()
{
	showMenu();

	////Test 1
	//Client C1(1, "Batman", "Baaat1234", 4000);
	//C1.Display();
	//cout << endl;

	//C1.Deposit(1800);
	//C1.Withdraw(2700);
	//cout << endl;

	//Client C2(2, "Superman", "Baaat1234", 7000);
	//C2.Display();
	//cout << endl;
	//C1.Transfer_To(900, C2);
	//cout << endl;

	//cout << "Client 1 ";
	//C1.Check_Balance();

	//cout << "Client 2 ";
	//C2.Check_Balance();
	//cout << "\n===================================\n";

	//Client C3(3, "Ronaldo", "Maghawry123", 60000);
	//C3.Display();
	//cout << "\n===================================\n";

	//Employee E1(4, "Spiderman", "Spider12345", 300, 1200);
	//E1.Display();
	

	//Admin A1(5, "Ironman", "Iron12345", 30000, 8000);
	//A1.Display();


	//Test2
	/*Client c(123, "Maged", "CorrectPass123", 100000);
	c.Display();
	cout << "\n===================================\n";

	Employee e(123, "Maged", "CorrectPass123", 100000,8000);
	e.Display();*/

	return 0;
}

void clearScreen() 
{
    system("cls"); // Clear the console screen on Windows
}

void showMenu() 
{
    int choice;

    do {
        void clearScreen();         // Clear the screen before displaying the menu
        cout << "\nChoose an option:" << endl;
        cout << "1. Client" << endl;
        cout << "2. Employee" << endl;
        cout << "3. Admin" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 3) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid operation. Please choose a valid option. \n" <<
                    "Hit Enter button to start again" << endl;
            cout << "\n................................................................\n";
            cin.get();              // Wait for user to press Enter to continue
        }

    } while (choice < 1 || choice > 3);

    switch (choice) 
    {
    case 1:
        clearScreen();
        cout << "Press 0 to go back to the menu or press Esc to exit the program." << endl;
        cout << "You chose Client." << endl;
        while (true) 
        {
            char key = _getch();
            if (key == '0') 
            {
                cin.get();
                showMenu();
                break;
            }
            else if (key == 27)      // 27 is the ASCII code for Esc
            {  
                exit(0);
            }
        }
        break;

    case 2:
        clearScreen();
        cout << "Press 0 to go back to the menu or press Esc to exit the program." << endl;
        cout << "You chose Employee." << endl;
        while (true) 
        {
            char key = _getch();
            if (key == '0') 
            {
                cin.get();
                showMenu();
                break;
            }
            else if (key == 27) 
            {  
                exit(0);
            }
        }
        break;

    case 3:
        clearScreen();
        cout << "Press 0 to go back to the menu or press Esc to exit the program." << endl;
        cout << "You chose Admin. Moving to the Admin screen..." << endl;
        while (true) 
        {
            char key = _getch();
            if (key == '0') 
            {
                cin.get();
                showMenu();
                break;
            }
            else if (key == 27) 
            {  
                exit(0);
            }
        }
        break;
    }
}