#pragma once
#include <iostream>
#include <conio.h>
#include <chrono>//for timing
#include <thread>// for pausing execution
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include<fstream>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include "ClientManger.h"
#include "AdminManager.h"
#include"EmployeeManager.h"
#include"Employee.h"


using namespace std::chrono_literals;
using namespace std;
class Screens
{
public:
	static void bankName() {
		const auto timer_duration = 5s;
		const auto start = chrono::steady_clock::now();

		chrono::duration<double> time_left = timer_duration - (chrono::steady_clock::now() - start);
		HANDLE col;
		col = GetStdHandle(STD_OUTPUT_HANDLE);





		while (time_left > 0s)
		{
			for (int col_code = 1; col_code < 6; col_code++) {

				SetConsoleTextAttribute(col, col_code | 8);
				const auto secs = chrono::duration_cast<chrono::seconds>(time_left);
				cout <<
					setfill('0') << setw(2) << secs.count() << "\n";

				this_thread::sleep_for(1s);

				time_left = timer_duration - (std::chrono::steady_clock::now() - start);
			}
		}
		SetConsoleTextAttribute(col, 12);
		/*system("color 84");*/
		cout << "**Route Bank**";
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");

		//HWND consoleWindow = GetConsoleWindow();
		//if (consoleWindow != NULL) {
		//	SendMessage(consoleWindow, WM_CLOSE, 0, 0);
		//	
		//}
		//AllocConsole();

		Screens::welcome();
	}

	 static void welcome() {
		 HANDLE col;
		 col = GetStdHandle(STD_OUTPUT_HANDLE);
		 SetConsoleTextAttribute(col, 6);
		 cout << "**Welcome**";
		 this_thread::sleep_for(chrono::seconds(5));
		 system("cls");
		 Screens::loginOptions();
		/* HWND consoleWindow = GetConsoleWindow();
		 if (consoleWindow != NULL) {
			 SendMessage(consoleWindow, WM_CLOSE, 0, 0);
		 }*/
	 }

	 static int loginAs() 
	 {
		 int choice;
		 cout << "Enter your choice: ";
		 cin >> choice;
		 return choice;
	 }

	 static void loginOptions() {
		 char choice;
		 HANDLE col;
		 col = GetStdHandle(STD_OUTPUT_HANDLE);
		 
		 do {
			 	system("cls"); // Clear the screen
				SetConsoleTextAttribute(col, 9);
			 	cout << "Choose your role" << endl;
				SetConsoleTextAttribute(col, 10);
			 	cout << "1. Admin" << endl;
					
				SetConsoleTextAttribute(col, 11);
			 	cout << "2. Employee" << endl;
				SetConsoleTextAttribute(col, 13);
			 	cout << "3. Client" << endl;
				SetConsoleTextAttribute(col, 14);
				cout << "0. Exit" << endl;
				SetConsoleTextAttribute(col, 15);
			 	cout << "Enter your choice: ";
			 	choice = _getch(); // Wait for user input
			 
			 	switch (choice) 
				{
			 	case '1':
				{
					SetConsoleTextAttribute(col, 10);
					cout << "You are an Admin" << std::endl;
					break;
				}
			 	case '2':
				{
					SetConsoleTextAttribute(col, 11);
					cout << "You are an Employee" << std::endl;
					break;
				}
			 	case '3':
				{
					SetConsoleTextAttribute(col, 13);
					cout << "You are a client" << std::endl;
					break;
				}
				case '0':
				{
					SetConsoleTextAttribute(col, 14);
					cout << "Exitting" << std::endl;
					break;
				}
			 	default:
			 		cout << "Invalid choice. Please try again." << std::endl;
			 		break;
			 	}
			 
			 	//_getch(); // Wait for user to press a key

			 } while (choice != '0');
				system("cls");
	 }
	

	 static void loginScreen(int n) {
		 do {
			 switch (n) {
			 case '1':
			 {
				 AdminManager::printAdminMenu();
				 Admin* a;
				 AdminManager::adminOptions(a);
				 int id{};
				 string password;
				 AdminManager::adminLogin(id, password);
				 break;
			 }
			 case '2':
			 {
				 EmployeeManager::printEmployeeMenu();
				 Employee* e;
				 EmployeeManager::employeeOptions(e);
				 break;
			 }
			 case '3':

				 break;
			 case '0':

				 std::cout << "Exitting" << std::endl;

				 break;

			 }

			 _getch(); // Wait for user to press a key
		 } while (n != '0');
	 system("cls");

	 }

	 static void invalid(int c) 
	 {
		 cout << "Invalid choice: " << c << ". Please try again." << endl;
	 }

	 static void logout() 
	 {
		 // Log off the current user
		 if (!ExitWindowsEx(EWX_LOGOFF, 0)) {

		 }
	 }

	 static void runApp()
	 {
		 bool isRunning = true;
		 while (isRunning) 
		 {
			 FileManager f;
			 f.getAllAdmins();
			 f.getAllEmployees();
			 f.getAllClients();
			 bankName();
			 welcome();
			 int choice = loginAs();

			 if (choice >= 1 && choice <= 3) {
				 loginScreen(choice);
				 // Add logic for each user type after logging in
				 // For example, call specific methods based on user type
			 }
			 else {
				 invalid(choice);
			 }

			 logout();

			 /*cout << "Do you want to logout? (y/n): ";
			 char logoutChoice;
			 cin >> logoutChoice;
			 if (logoutChoice == 'y' || logoutChoice == 'Y') {
				 logout();
				 isRunning = false;
			 }*/
		 }
	 }
};
