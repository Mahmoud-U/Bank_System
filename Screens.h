//#pragma once
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

	 static void clearScreen()
	 {
		 system("cls"); // Clear the console screen on Windows
	 }
	 static int loginAs() {
		 HANDLE col;
		 col = GetStdHandle(STD_OUTPUT_HANDLE);
		 int choice;
		 /*cin >> choice;*/
		 choice = _getch(); // Wait for user input
		 switch (choice) {
		 case '1':
			 SetConsoleTextAttribute(col, 10);
			 std::cout << "You are an Admin" << std::endl;
			 break;
		 case '2':
			 SetConsoleTextAttribute(col, 11);
			 std::cout << "You are an Employee" << std::endl;
			 break;
		 case '3':
			 SetConsoleTextAttribute(col, 13);
			 std::cout << "You are a client" << std::endl;
			 break;
		 case '0':
			 SetConsoleTextAttribute(col, 14);
			 std::cout << "Exitting" << std::endl;
			 break;
		 default:
			 std::cout << "Invalid choice. Please try again." << std::endl;
			 break;
		 }

		 return choice;
		 cout << "choise: " << choice;
		 system("cls");
		 loginScreen(choice);
	 }

	 static void loginOptions() {
		 HANDLE col;
		 col = GetStdHandle(STD_OUTPUT_HANDLE);

		 system("cls"); // Clear the screen
		 SetConsoleTextAttribute(col, 9);
		 std::cout << "Choose your role" << std::endl;
		 SetConsoleTextAttribute(col, 10);
		 std::cout << "1. Admin" << std::endl;
		 SetConsoleTextAttribute(col, 11);
		 std::cout << "2. Employee" << std::endl;
		 SetConsoleTextAttribute(col, 13);
		 std::cout << "3. Client" << std::endl;
		 SetConsoleTextAttribute(col, 14);
		 std::cout << "0. Exit" << std::endl;
		 SetConsoleTextAttribute(col, 15);
		 std::cout << "Enter your choice: ";
		 loginAs();
	 }


	 static void loginScreen(int c) {


		 switch (c) {
		 case '1':
			 // AdminManager::printClientMenu();

			 break;
		 case '2':
			 EmployeeManager::printEmployeeMenu();

			 break;
		 case '3':

			 break;
		 case '0':

			 std::cout << "Exitting" << std::endl;

			 break;

		 }

		 _getch(); // Wait for user to press a key

		 system("cls");

	 }

	 static void logout() {

		 // Log off the current user
		 if (!ExitWindowsEx(EWX_LOGOFF, 0)) {

		 }
	 }
	 /* static void runApp() {

		  FileManager ff;
		  ff.getAllAdmins();
	  }*/

};


//	 static int loginAs() 
//	 {
//		 int c{};
//		 return c;
//
//	 }
//
//	 static void loginOptions() {
//		 char choice{};
//		 HANDLE col;
//		 col = GetStdHandle(STD_OUTPUT_HANDLE);
//		 int result{};
//
//		 do {
//			 	system("cls"); // Clear the screen
//				SetConsoleTextAttribute(col, 9);
//			 	cout << "Choose your role" << endl;
//				SetConsoleTextAttribute(col, 10);
//			 	cout << "1. Admin" << endl;
//				result = 1;
//				result = loginAs();
//				SetConsoleTextAttribute(col, 11);
//			 	cout << "2. Employee" << endl;
//				result = 2;
//				result = loginAs();
//				SetConsoleTextAttribute(col, 13);
//			 	cout << "3. Client" << endl;
//				result = 3;
//				result = loginAs();
//				SetConsoleTextAttribute(col, 14);
//				cout << "0. Exit" << endl;
//				SetConsoleTextAttribute(col, 15);
//			 	cout << "Enter your choice: ";
//			 	choice = _getch(); // Wait for user input
//			 
//			 	switch (choice) 
//				{
//				case '1':
//				{
//					SetConsoleTextAttribute(col, 10);
//					clearScreen();
//					cout << "You are an Admin" << endl;
//					break;
//				}
//				case '2':
//				{
//					SetConsoleTextAttribute(col, 11);
//					cout << "You are an Employee" << endl;
//					break;
//				}
//				case '3':
//				{
//					SetConsoleTextAttribute(col, 13);
//					cout << "You are a client" << endl;
//					break;
//				}
//				case '0':
//				{
//					SetConsoleTextAttribute(col, 14);
//					cout << "Exitting" << endl;
//					break;
//				}
//			 	default:
//			 		cout << "Invalid choice. Please try again." << endl;
//			 		break;
//			 	}
//			 
//			 	_getch(); // Wait for user to press a key
//
//		 } while (choice != '0');
//				system("cls");
//	 }
//
//	/* static int loginAs()
//	 {
//		 system("cls");
//
//	 }*/
//	
//
//	 static void loginScreen(int n) {
//		 n = loginAs();
//		 do {
//			 switch (loginAs()) {
//			 case 1:
//			 {
//				 AdminManager::printAdminMenu();
//				 break;
//			 }
//			 case 2:
//			 {
//				 EmployeeManager::printEmployeeMenu();
//				 
//				 break;
//			 }
//			 case 3:
//			 {
//				 ClientManger::printClientMenu();
//				 break;
//			 }
//			 default:
//			 {
//				 cout << "Exitting" << endl;
//				 break;
//			 }
//
//			 }
//
//			 _getch(); // Wait for user to press a key
//		 } while (loginAs() != 0);
//	 system("cls");
//
//	 }
//
//	 static void invalid(int c) 
//	 {
//		 cout << "Invalid choice: " << c << ". Please try again." << endl;
//	 }
//
//	 static void logout() 
//	 {
//		 // Log off the current user
//		 if (!ExitWindowsEx(EWX_LOGOFF, 0)) {
//
//		 }
//	 }
//
//	 static void runApp()
//	 {
//		 bool isRunning = true;
//		 while (isRunning) 
//		 {
//			 FileManager f;
//			 f.getAllAdmins();
//			 f.getAllEmployees();
//			 f.getAllClients();
//			 //bankName();
//			 //welcome();
//			 loginOptions();
//			 //loginAs();
//			 logout();
//
//		 }
//	 }
//};
