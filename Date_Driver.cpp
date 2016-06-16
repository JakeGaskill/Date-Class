/********************************************************************************************

Name: Jacob Gaskill                    Z#: 23236263
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  1/26/2016           Due Time: 8:00 PM
Total Points: 100
Assignment 3: Date program

Description: This assignment provides proof of a working class, Date, that can
take specific values, default values, change values, overload outputs, etc. 
These values include the month, day, and year. This program takes into account
maximum and minimum days of each month, leap years, etc.


*********************************************************************************************/

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

int main()
{

	Date myDate;
	Date yourDate(12, 31, 1957);
	Date test1Date(15, 1, 1962); //should generate error message that bad month
	Date test2Date(2, 29, 1956); //ok, should say leep year
	Date test3Date(2, 30, 1956); //should generate error message that bad day
	Date test4Date(12,31,0000); //should generate error message that bad year
	Date test5Date(80,40,0000); //should generate error message that bad month, day and year

	yourDate.display();
	cout<<yourDate.getMonth()<<endl;
	cout<<yourDate.getDay()<<endl;
	cout<<yourDate.getYear()<<endl;
	myDate.setMonth(11); 
	myDate.setDay(12);
	myDate.setYear(2015);
	cout<<"myDate: "<<myDate<<" test2Date: "<<test2Date<<" yourDate: "<<yourDate<<endl;

	return 0;

}

