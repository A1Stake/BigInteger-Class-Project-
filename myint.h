/*
 * Matthew Wix
 * Summary: The purpose of this file is to outline the functions necessary for storing a number bigger
 * than the max storage size of an int and performing some of the basic arithmetic operations.
 */

#include <iostream>

using namespace std;

class MyInt
{
 	friend MyInt operator+(const MyInt& x, const MyInt& y);
  	friend MyInt operator-(const MyInt& x, const MyInt& y);
	friend MyInt operator*(const MyInt& x, const MyInt& y);
   	
	friend bool operator<(const MyInt& x, const MyInt& y);
   	friend bool operator>(const MyInt& x, const MyInt& y);
   	friend bool operator<=(const MyInt& x, const MyInt& y);
   	friend bool operator>=(const MyInt& x, const MyInt& y);
   	friend bool operator==(const MyInt& x, const MyInt& y);
   	friend bool operator!=(const MyInt& x, const MyInt& y);
  	 
	friend ostream& operator<<(ostream& s, const MyInt& x);
	friend istream& operator>>(istream& s, MyInt& x);
   
public:
   	MyInt(int n = 0);
	MyInt(const char* c);
	MyInt(const MyInt&);			//Copy Constructor
	MyInt& operator=(const MyInt&);		//Assignment Constructor
	MyInt& operator++();			//prefix increment
	MyInt operator++(int);			//postfix increment
	MyInt& operator--();			//prefix decrement
	MyInt operator--(int);			//postfix decrement
	~MyInt();

private:
   char *digits;				//stores digits of numbers as charcters
   unsigned long long size;			//stores number of digits in the number
};
