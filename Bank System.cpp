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
using namespace std;

//void clearScreen();
//void showMenu();

int main()
{
	AdminManager a;
	Admin* Amigo = new Admin;
	a.searchForEmployee(Amigo);

	/*m.printClientMenu();
	cout << endl;
	m.listAllClients(Amigo);*/

	//FileManager Test
	//FileManager f;

	/*Client c1(100, "Mido", "PassAttemp3t", 450500);
	Client c2(104, "Tarek", "eifewfgweg5A", 87900);
	Client c3(108, "Mido", "oktopmiht5N", 22000);

	Employee e1(100, "Mido", "PassAttemp3t", 450500);
	Employee e2(104, "Tarek", "eifewfgweg5A", 87900);
	Employee e3(108, "Mido", "oktopmiht5N", 22000);

	Admin a1(100, "Mido", "PassAttemp3t", 450500);
	Admin a2(104, "Tarek", "eifewfgweg5A", 87900);
	Admin a3(108, "Mido", "oktopmiht5N", 22000);

	f.addClient(c1);
	f.addClient(c2);
	f.addClient(c3);

	f.addEmployee(e1);
	f.addEmployee(e2);
	f.addEmployee(e3);

	f.addAdmin(a1);
	f.addAdmin(a2);
	f.addAdmin(a3);*/

	/*f.getAllClients();
	cout << endl;
	f.getAllEmployees();
	cout << endl;
	f.getAllAdmins();*/

	//f.removeAllClients();
	//f.removeAllEmployees();
	//f.removeAllAdmins();
	
	//..........................................................................
	//FilesHelper & (FileManager with Parser for Admin test)
	/*Admin admin1(500, "Hens", "PasswordTest1", 100000);
	Admin admin2(501, "Soha", "adniafu448A", 80000);
	Admin admin3(502, "Amanda", "rhegoelorV54", 70000);
	FileManager f;
	f.addAdmin(admin1);
	f.addAdmin(admin2);
	f.addAdmin(admin3);
	FilesHelper::getAdmins();
	FilesHelper::clearFile("Clients.txt", "New Clients.txt");*/


	//FilesHelper with Parse Employee test
	/*Employee employee1(500, "Hens", "PasswordTest1", 100000);
	Employee employee2(501, "Soha", "adniafu448A", 80000);
	Employee employee3(502, "Amanda", "rhegoelorV54", 70000);
	FilesHelper::saveEmployee("Employee.txt", "New Employee.txt", employee1);
	FilesHelper::saveEmployee("Employee.txt", "New Employee.txt", employee2);
	FilesHelper::saveEmployee("Employee.txt", "New Employee.txt", employee3);
	FilesHelper::getEmployees();
	FilesHelper::clearFile("Clients.txt", "New Clients.txt");*/


	//FilesHelper with Parse Client test
	/*Client client1(500, "Hens", "PasswordTest1", 100000);
	Client client2(501, "Soha", "adniafu448A", 80000);
	Client client3(502, "Amanda", "rhegoelorV54", 70000);
	FilesHelper::saveClient(client1);
	FilesHelper::saveClient(client2);
	FilesHelper::saveClient(client3);
	FilesHelper::getClients();
	FilesHelper::clearFile("Clients.txt", "New Clients.txt");*/

	//..........................................................................
	//Parser Test
	/*string c = "112$Amigo$PassTest22224$80000";
	string e = "220$Emploo$PassTest22224$10000";
	string a = "330$Adminoo$PassTest22224$15000";

	Client c1 = Parser::parseToClient(c);
	Employee e1 = Parser::parseToEmployee(e);
	Admin a1 = Parser::parseToAdmin(a);

	cout << "\nClient Details: \n";
	cout << "ID: " << c1.getId() << endl;
	cout << "Name: " << c1.getName() << endl;
	cout << "Password: " << c1.getPassword() << endl;
	cout << "Balance: " << c1.getBalance() << endl;

	cout << "\nEmployee Details: \n";
	cout << "ID: " << e1.getId() << endl;
	cout << "Name: " << e1.getName() << endl;
	cout << "Password: " << e1.getPassword() << endl;
	cout << "Balance: " << e1.getSalary() << endl;

	cout << "\nAdmin Details: \n";
	cout << "ID: " << a1.getId() << endl;
	cout << "Name: " << a1.getName() << endl;
	cout << "Password: " << a1.getPassword() << endl;
	cout << "Balance: " << a1.getSalary() << endl;*/

	//..........................................................................
	//Test 1
	/*Client C1(1, "Batman", "Baaat1234", 4000);
	//C1.Display();
	//cout << endl;

	C1.Deposit(1800);
	C1.Withdraw(2700);
	cout << endl;

	Client C2(2, "Superman", "Uranium985", 7000);
	//C2.Display();
	//cout << endl;
	//C1.Transfer_To(900, C2);
	//cout << endl;

	cout << "Client 1 ";
	C1.Check_Balance();

	cout << "Client 2 ";
	C2.Check_Balance();
	cout << "\n===================================\n";

	Client C3(3, "Ronaldo", "Maghawry123", 60000);
	C3.Display();
	cout << "\n===================================\n";

	Employee E1(8, "Spiderman", "Spider12345*$@#", 12000);
	E1.Display(); 
	cout << "\n===================================\n";

	Admin A1(5, "Ironman", "Iron12345", 8000);
	A1.Display();*/

	//Test2
	/*Client g(250, "Ali", "Alibaba2020", 10000);
	g.Display();
	cout << "\n===================================\n";

	Employee E1(100, "Spiderman", "Spider45*$@#", 12000);
	E1.Display();
	cout << "\n===================================\n";*/

	//Test file helper get 

	//Test file helper get 
	/*cout << "get data from test file:" << endl;
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
	cout << "**********************************************\n";
	cout << "clear last id from file:" << endl;
	cout << "contents:" << endl;
	FilesHelperGet::clearFile("TEST.txt", "testid.txt");
	cout << "**********************************************\n";
	cout << "**********************************************\n";
	cout << "save  id to file:" << endl;
	cout << "contents:" << endl;
	FilesHelperGet::saveLast("TEST.txt", 2);
	cout << "**********************************************\n";*/
	


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