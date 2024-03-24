#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Bank_System.h"
using namespace std;
int main()
{
	//testing
	Person p(123, "m12", "a555");
	Client p1, p2;
	cout << "name" << " " << p.getName() << endl;
	cout << "id: " << p.getId() << endl;
	cout << "pwd: " << p.getPassword() << endl;
	p2.transferTo(1000.00, p1);
	cout << p2.deposite(5000) << endl;
	cout << p2.withdraw(1000) << endl;
	cout << p2.transferTo(3000, p1) << endl;


}