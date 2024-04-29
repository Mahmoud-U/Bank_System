#pragma once
#include <iostream>
#include <conio.h>
#include<iostream>
#include <chrono>//for timing
#include <thread>// for pausing execution
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <conio.h>
#include<fstream>
#include <iostream>
#include <conio.h>
#include<iostream>
#include <chrono>//for timing
#include <thread>// for pausing execution
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <chrono>
#include <thread>
#include "Screens.h"
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
		const auto start = std::chrono::steady_clock::now();

		std::chrono::duration<double> time_left = timer_duration - (std::chrono::steady_clock::now() - start);
		HANDLE col;
		col = GetStdHandle(STD_OUTPUT_HANDLE);

		

			
		
		while (time_left > 0s)
		{
			for (int col_code = 1; col_code < 6; col_code++) {

			SetConsoleTextAttribute(col, col_code|8);
			const auto secs = std::chrono::duration_cast<std::chrono::seconds>(time_left);
			std::cout <<
				std::setfill('0') << std::setw(2) << secs.count() << "\n";

			std::this_thread::sleep_for(1s);

			time_left = timer_duration - (std::chrono::steady_clock::now() - start);
			}
		}
		SetConsoleTextAttribute(col, 12);
		/*system("color 84");*/
		cout << "**Route Bank**";
		std::this_thread::sleep_for(std::chrono::seconds(3));
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
		 std::this_thread::sleep_for(std::chrono::seconds(5));
		 system("cls");
		 Screens::loginOptions();
		/* HWND consoleWindow = GetConsoleWindow();
		 if (consoleWindow != NULL) {
			 SendMessage(consoleWindow, WM_CLOSE, 0, 0);
		 }*/
	 }
	 static int loginAs() {
		
		 return;
	 }

	 static void loginOptions() {
		 char choice;
		 HANDLE col;
		 col = GetStdHandle(STD_OUTPUT_HANDLE);
		 
		 do {
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
			 
			 		_getch(); // Wait for user to press a key
			 	} while (choice != '0');
				system("cls");
	 }
	

	 static void loginScreen(int n) {
		 do{
			 switch (n) {
		 case '1':
			 AdminManager::printClientMenu();
			 AdminManager::AdminOptions( client);
			 AdminManager::login( id,  password);
			 break;
		 case '2':
			 EmployeeManager::printEmployeeMenu();
			 EmployeeManager::employeeOptions( employee);
			 break;
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
