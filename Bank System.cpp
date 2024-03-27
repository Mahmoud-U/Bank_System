#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include "Bank_System.h"
using namespace std;

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

void showMenu() {
	int choice;

	do {
		cout << "Choose an option:" << endl;
		cout << "1. Client" << endl;
		cout << "2. Employee" << endl;
		cout << "3. Admin" << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		if (cin.fail() || choice < 1 || choice > 3) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid operation. Please choose a valid option." << endl;
		}
	} while (choice < 1 || choice > 3);

	switch (choice) {
	case 1:
		cout << "You chose Client." << endl;
		// Add Client functionality here
		break;
	case 2:
		cout << "You chose Employee." << endl;
		// Add Employee functionality here
		break;
	case 3:
		cout << "You chose Admin." << endl;
		// Add Admin functionality here
		break;
	}
}