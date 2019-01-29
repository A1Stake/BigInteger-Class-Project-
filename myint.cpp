/*
 * Matthew Wix
 * COP3330 Section 4
 * Project #5
 * Summary: The purpose of this file is to implement the methods for creating a class
 * that can store a number much larger than what can be stored by the integer data type.
 * The methods implemented can store the large number, perform addition, multiplication,
 * and subtraction on it, perform size comparisons, and store input from the stream.
 */

#include <iostream>
#include "myint.h"
#include <cstring>

using namespace std;

//function from Bob Myers to convert characters into integers
int C2I(char c){	// converts character into integer (returns -1 for error)
	if (c < '0' || c > '9'){
		return -1;	//error
	}

	return (c - '0');	// success
}

//function from Bob Myers to convert integers into characters
char I2C(int x){	// converts single digit integer into character (returns '\0' for error)
	if (x < 0 || x > 9){		
		return '\0';	//error
	}

	return (static_cast<char>(x) + '0'); 	// success
}	

MyInt::MyInt(int n){			//conversion constructor for int
	size = 0;
	if(n <= 0){			//if number is negative or zero, array stores zero
		n = 0;
		size = 1;
	}
	int temp = n;

	while(temp > 0){		//obtains the amount of digits in the number
		temp /= 10;
		size++;
	}

	digits = new char[size];	//creates array with size equal to number of digits
	if(n == 0){
		digits[0] = '0';
	}
	for(int i = 0; i < size; i++){		//iterates through loop and stores number backwards
		char ctemp = I2C((n % 10));
		digits[i] = ctemp;
		n /= 10; 
	}
}

MyInt::MyInt(const char* c){
	bool valid = true, hitNumber = false;		//used to check input string for conditions
	int startingIndex = 0;				//removes unimportant zeroes from beginning of number
	for(int i = 0; i < strlen(c); i++){		//loop checks if all the characters in the
		if(isdigit(c[i]) && c[i] != '0'){	//array are digits and removes any zeros at
			hitNumber = true;		//the start of the cstring that are not needed
		}
		if(!isdigit(c[i])){
			valid = false;
		}

		if(!hitNumber){
			startingIndex++;		//stores number of leading zeroes
		}
	}
	if(!hitNumber && valid){			//if input was all digits that were zeroes
		size = 1;				//stores a single zero
		digits = new char[size+1];
		digits[0] = '0';
		digits[size] = '\0';
	}else if(valid){				//if input was all digits and
		size = strlen(c)-startingIndex;		//contained nonzero numbers 
		digits = new char[size+1];	//size of number is size of cstring minus leading zeroes
		for(int i = 0; i < size; i++){
			//stores number in reverse order from how it was entered
			digits[i] = c[size+startingIndex-1-i];
		}
		digits[size] = '\0';
	}else{					//if input was not all digits, stores a zero
		size = 1;
		digits = new char[size+1];
		digits[0] = '0';
		digits[1] = '\0';
	}
}

MyInt::MyInt(const MyInt& x){			//Copy constructor
	size = x.size;
	digits = new char[size];
	for(int i = 0; i < size; i++){
		digits[i] = x.digits[i];
	}
}

MyInt& MyInt::operator=(const MyInt& x){	//Assignmnet operator
	if(this != &x){
		delete [] digits;
	
		size = x.size;
		digits = new char[size];
		for(int i = 0; i < size; i++){
			digits[i] = x.digits[i];
		}
	}
	return *this;
}

MyInt& MyInt::operator++(){			//prefix increment
	*this = *this + 1;
	return *this;
}

MyInt MyInt::operator++(int){			//postfix increment
	MyInt num1 = *this;
	*this = *this + 1;
	return num1;
}

MyInt& MyInt::operator--(){			//prefix decrement
	*this = *this - 1;
	return *this;
}

MyInt MyInt::operator--(int){			//postfix decrement
	MyInt num1 = *this;
	*this = *this - 1;
	return num1;

}

MyInt::~MyInt(){				//deletes dynamically allocated memory
	delete [] digits;
}

MyInt operator+(const MyInt& x, const MyInt& y){
	unsigned int biggerSize = (x.size > y.size) ? x.size : y.size;
	unsigned int smallerSize = (x.size < y.size) ? x.size : y.size;

	bool usingX = (x.size > y.size) ? true : false;	//finds the number with the most digits
	
	char* z = new char[biggerSize+2];		//new number can only be one digit 
							//larger than the biggest number
	z[biggerSize+1] = '\0';
	int carryOver = 0;
	for(int i = 0; i < smallerSize; i++){
		int temp1 = C2I(x.digits[i]);	//converts characters to ints for arithmetic operations
		int temp2 = C2I(y.digits[i]);

		
		int sum = temp1 + temp2 + carryOver;	//if previous digits added to more than ten, 
		carryOver = (sum > 9) ? 1 : 0;		//adds 1 to the sum of the next iteration
		z[biggerSize - i] = I2C(sum % 10);
	}

	for(int i = smallerSize; i < biggerSize; i++){
			int temp;
			temp = (usingX) ?  C2I(x.digits[i]) : temp = C2I(y.digits[i]);

			int sum = temp + carryOver;
			carryOver = (sum > 9) ? 1 : 0;
			z[biggerSize - i] = I2C(sum % 10);
	}

	if(carryOver == 1){
		z[0] = '1';
	}
	else{
		z[0] = '0';		//leading zero will be removed by constructor
	}
	MyInt temporary(z);
	return temporary;
}

MyInt operator-(const MyInt& x, const MyInt& y){
	unsigned int biggerSize = (x.size > y.size) ? x.size : y.size;
	unsigned int smallerSize = (x.size < y.size) ? x.size : y.size;

	bool usingX = (x.size > y.size) ? true : false;
	
	//if the second number is bigger than the first, operation always results in negative number
	if(!usingX && !(biggerSize == smallerSize)){
		return MyInt("0");
	}

	char* theArray = new char[biggerSize];
	int carryOver = 0;

	for(int i = 0; i < smallerSize; i++){
		int temp1 = C2I(x.digits[i]) - carryOver;
		int temp2 = C2I(y.digits[i]);
		
		carryOver = (temp2 > temp1) ? 10 : 0;

		int diff = temp1 + carryOver - temp2;
		
		carryOver = (carryOver == 10) ? 1 : 0; 

		theArray[biggerSize - 1 - i] = I2C(diff);
	}

	int helper = 10;
	for(int i = smallerSize; i < biggerSize; i++){
		int temp1 = C2I(x.digits[i]);
		helper = (temp1 ==  0 && helper == 10 && carryOver == 1) ? 10 : 0;
		int diff = temp1 + helper - carryOver;
		carryOver = (helper == 10) ? 1 : 0; 

		theArray[biggerSize - 1 - i] = I2C(diff);
	}

	//if last digit operation leaves a carry with no digit to take from, number is negative
	if(carryOver == 1){
		return MyInt("0");
	}
	
	MyInt temporary(theArray);
	delete [] theArray;
	return temporary;
}

MyInt operator*(const MyInt& x, const MyInt& y){
	unsigned int biggerSize = (x.size > y.size) ? x.size : y.size;
	unsigned int smallerSize = (x.size < y.size) ? x.size : y.size;

	bool usingX = (x.size > y.size) ? true : false;
	
	MyInt temporary = "0";	//stores the result of additions greater than what an int can hold
	for(int i = 0; i < biggerSize; i++){
		int temp1 = (usingX) ? C2I(x.digits[i]) : C2I(y.digits[i]);
		for(int j = 0; j < smallerSize; j++){
			int temp2 = (usingX) ?  C2I(y.digits[j]) : C2I(x.digits[j]);
			int temp3 = temp1 * temp2;
			
			//temp array the size of the current number of digits added together
			char* tempArray = new char[(i+j+3)];
			int temp4 = temp3 % 10;
			
			//multiplication of the value in the digits is at most 2 digits
			tempArray[0] = I2C((temp3 / 10));
			tempArray[1] = I2C(temp4);

			//adds the necessary amount of zeroes after the result of multiplying the digits
			for(int k = 2; k < i+j+2; k++){
				tempArray[k] = '0';
			}
			tempArray[(i+j+2)] = '\0';

			temporary = temporary + MyInt(tempArray);
			
		}
	}
	
	return temporary;
}

bool operator<(const MyInt& x, const MyInt& y){
	int xSize = x.size;
	int ySize = y.size;

	//if x has less digits, it cannnot be greater than y and vice versa
	if(xSize < ySize){
		return true;
	}else if(xSize > ySize){
		return false;
	}else{
		for(int i = xSize-1; i > 0; i--){
			if(C2I(x.digits[i]) < C2I(y.digits[i])){
				return true;
			}
		
		}
		return false;
	}
}

bool operator>(const MyInt& x, const MyInt& y){
	return (y < x);
}

bool operator<=(const MyInt& x, const MyInt& y){
	return !(x > y);
}

bool operator>=(const MyInt& x, const MyInt& y){
	return !(x < y);
}

bool operator==(const MyInt& x, const MyInt& y){
	return !(x < y) && !(x > y);
}

bool operator!=(const MyInt& x, const MyInt& y){
	return !(x == y);
}

ostream& operator<<(ostream& s, const MyInt& x){
	for(int i = x.size-1; i >= 0; i--){
		s << x.digits[i];
	}
	return s;
}

istream& operator>>(istream& s, MyInt& x){
	int counter = 0;
	char* theArray = new char[1];
	while(isspace(s.peek())){			//any white space before the number is ignored
		s.get();
	}
	while(isdigit(s.peek())){			//executes as long as next charcter is a number
		theArray[counter] = s.get();
		counter++;
		char* temp = new char[counter+1];
		for(int i = 0; i < counter+1; i++){	//copies array into temp array so it can hold
			temp[i] = theArray[i];		//its values as it is allocated to the new size
		}
		
		delete [] theArray;
		theArray = new char[counter + 2];
			
		for(int i = 0; i < counter+1; i++){
			theArray[i] = temp[i];
		}

		theArray[counter+1] = '\0';
		delete [] temp;
	}
	
	x = MyInt(theArray);
	return s;
}
