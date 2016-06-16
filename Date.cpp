
#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;


//*************************************************************************************
//Name:  Date
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to today's date
//Description:  This is the default constructor which will be called automatically when 
//an object is declared.  It will initialize the state of the class
//
//*************************************************************************************
Date::Date()
{
	myMonth = 1; // set all values to default
	myDay = 1;
	myYear = 1;

	cout << "The default constructor has been called: " << endl; //informs the user that the default constructor has been called
	display(); //the default date is shown

}


//*************************************************************************************
//Name:  Date
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state of the object is changed to the user specified date
//Description:  This is the explicit value constructor used to input specific date and times
//from the user. It ensures valid dates are entered and provides whether or not it is a 
//leap year.
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	cout << endl << "The explicit-value constructor has been called:" << endl; //informs user that the explicit value constructor has been called

	setMonth(m); //call setMonth
	setDay(d); //call setDay
	setYear(y); //call setYear

	if (myMonth == m && myDay == d && myYear == y) //if all values are valid, then the date is displayed
	{
		display();
		
		if (y % 4 == 0) //if all values are valid AND the year is divisible by 4, then
		{
			cout << "It's a leap year!" << endl; //a message is provided stating it is a leap year
		}
	}
}

//*************************************************************************************
//Name:  Display
//Precondition: all variables have been initialized and the class was constructed
//Postcondition: the date appears on the screen
//Description:  a small function to display the date for the user and fills leading
// 0's when needed
//
//*************************************************************************************
void Date::display()
{
	cout << setw(2) << setfill('0') << myMonth << "/" //sets width and fills with 0's
		<< setw(2) << setfill('0') << myDay << "/" //to ensure the month and day has
		<< setw(4) << setfill('0') << myYear //at least two values and the year
		<< endl;							//has at least 4
}

//*************************************************************************************
//Name:  getMonth
//Precondition: myMonth is initialized
//Postcondition: myMonth is returned
//Description:  given that myMonth has been initialized for the Date class object,
// myMonth is dispayed on its own  
//
//
//*************************************************************************************	
int Date::getMonth()
{
	return myMonth; //simply returns myMonth
}

//*************************************************************************************
//Name:  getDay
//Precondition: myDay is initialized
//Postcondition: myDay is returned
//Description:  given that myDay has been initialized for the Date class object,
// myDay is dispayed on its own 
//
//
//*************************************************************************************
int Date::getDay()
{
	return myDay; //simply returns myDay
}

//*************************************************************************************
//Name:  getYear
//Precondition: myYear is initialized
//Postcondition: myYear is returned
//Description:  given that myYear has been initialized for the Date class object,
// myYear is dispayed on its own
//
//
//*************************************************************************************
int Date::getYear()
{
	return myYear; //simply returns myYear
}

//*************************************************************************************
//Name: setMonth
//Precondition: myMonth is initialized
//Postcondition: myMonth is mutated by itself
//Description:  given that myMonth has been initialized for the Date class object,
// the value will be changed when called with said value
//
//
//*************************************************************************************
void Date::setMonth(unsigned m)
{
	if (1 <= m && m <= 12) //validates m
	{
		myMonth = m; //stores m in myMonth
	}

	else             //if m is not valid,
	{
		cerr << "Month = " << setw(2) << setfill('0') << m << " is incorrect" << endl; //an error message appears
	}
}

//*************************************************************************************
//Name:  setDay
//Precondition: myDay is initialized
//Postcondition: myDay is mutated by itself
//Description:  given that myDay has been initialized for the Date class object,
// the value will be changed when called with said value
//

//*************************************************************************************
void Date::setDay(unsigned d)
{
	if (maxDays(myMonth, d)) //if the d value is valid,
	{
		myDay = d; //it is stored in myDay
	}

	else                     //if not,
	{
		cerr << "Day = " << setw(2) << setfill('0') << d << " is incorrect" << endl; //an error message appears
	}
}

//*************************************************************************************
//Name:  setYear
//Precondition: myYear is initialized
//Postcondition: myYear is mutated by itself
//Description:  given that myYear has been initialized for the Date class object,
// the value will be changed when called with said value
//
//*************************************************************************************
void Date::setYear(unsigned y)
{
	if (1 <= y && y <= 9999) //checks for valid year
	{
		myYear = y;			//if so stores it in myYear
	}

	else
		cerr << "Year = " << setw(4) << setfill('0') << y << " is incorrect" << endl; //else error message
}

//*************************************************************************************
//Name:  operator <<
//Precondition: myYear is initialized
//Postcondition: myYear is mutated by itself
//Description:  given that myYear has been initialized for the Date class object,
// the value will be changed when called with said value
//
//*************************************************************************************
ostream & operator<<(ostream & out, const Date & dateObj)
{
	out << setw(2) << setfill('0') << dateObj.myMonth << "/" //overloaded operator << to do
		<< setw(2) << setfill('0') << dateObj.myDay << "/" //the functionality of the
		<< setw(4) << setfill('0') << dateObj.myYear << " "; //display function
	return out;
}

//*************************************************************************************
//Name:  maxDays
//Precondition: maxDays function is called with appropriate parameters, m and d
//Postcondition: returns 1 or 0
//Description:  maxDays is called to ensure that the day given is legitimate
// an array of size 13 is used to match amount of days in the month with the months of the year, save for "0"
// an example: length[1] would give 31, the number of days in January
// This function was difficult to finalize, for I had to ensure that
// if a given month was wrong, say 15, that the day itself would not be penalized.
// Also, if a value outside the parameters of the array were used, say 15,
// I had to ensure the compiler did not attempt to run find length[15]
// because an error would occur.
//*************************************************************************************
int Date::maxDays(unsigned m, unsigned d)
{
	int length[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //array of corresponding days to months
	
	if (1 <= m && m <= 12) //ensure that month is legitimate
	{
		if (1 <= d && d <= length[m]) //if so, the day is checked
		{
			return 1;				//returns 1 if day is within its parameters
		}

		else
		{
			return 0;				//returns 0 if not
		}
	}

	else if (1 <= d && d <= 31) //however, if the MONTH is invalid, the day is not penalized, so long as
	{
		return 1;				//it is within 1-31 days, maxDays returns 1
	}

	else 
	{
		return 0;				//if not it returns 0
	}
}


