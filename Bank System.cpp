#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Bank_System.h"
using namespace std;
int main()
{
	//testing
	Person p(123, "Ali_BaBa", "any_thinghere");

	cout << "Name : " << p.getName() << endl;
	cout << "Id : " << p.getId() << endl;
	cout << "Password : " << p.getPassword() << endl;
}