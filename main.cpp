#include <iostream>
#include "myint.h"

using namespace std;

MyInt Fibonnaci(MyInt num);

int main(){
	/*MyInt n1 ="0000450", n2 = "00000000000000000000";
	cout << "n1: " << n1 << " n2: " << n2 << endl;
	cout << "n1 + n2: " << n1 + n2 << endl;
	MyInt num1;
	MyInt num2(4512);
	MyInt numA("25");
	MyInt num3("876543210");
	MyInt num4("999999999");
	cout << num1 << " " << num2 << " " << num3 << " " << num4 << endl;
	MyInt num5(num3+num4);
	cout << "num5: " << num5 << endl;
	MyInt num6(num3+numA);
	cout << num6 << endl;
	
	cout << num6 + numA << endl;
	cout << "num fiasco: " << num6 + numA + numA + numA << endl;
	cout << "adding: " << MyInt(123) + MyInt(12) + MyInt(12) << endl;
	cout << "4,000,000,000,000 + 6,000,000,000,000 = " << MyInt("4000000000000") + MyInt("6000000000000") << endl;

	MyInt test("0");
	cout << "test1: " << test << endl;
	test = test + MyInt(12);
	cout << "test2: " << test << endl;
	
	test = 5;
	cout << "test3: " << test <<endl;

	MyInt num7("123456789012345");
	MyInt num8("100000");
	cout << "123456789012345 * 100000 = " << num7 * num8 << endl;
	cout << "123456789012345678901234567890 + 1: " << MyInt("123456789012345678901234567890") + MyInt(1) << endl;
	
	MyInt num9("400");
	MyInt num10("500");
	cout << "num9: " << num9 << " num10: " << num10 << endl;
	
	if(num9 == num10){
		cout << "N" << endl;
	}else{
		cout << "Yea" << endl;
	}

	if(num10 == num9){
		cout << "N" << endl;
	}else{
		cout << "Yea" << endl;
	}

	MyInt bigNum("123456789012345678901234567890");
	cout << bigNum + bigNum << endl;
	
	MyInt num11("8");
	cout << "num11: " << num11++ << endl;
	cout << "num11: " << ++num11 << endl;*/
	
/*	MyInt num12(1000);
	MyInt num13(100);
	cout << "num12: " << num12 << " num13: " << num13 << endl; 
	cout << num12 - num13 << endl;
	cout << "num12: " << num12-- << endl;
	cout << "num12: " << --num12 << endl;

	MyInt num14;
	cout << "Enter: ";
	cin >> num14;
	cout << num14 << endl;*/

	// demonstrate behavior of the two constructors and the << overload
	//
	MyInt matt("43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875");
	cout << matt << endl;
	MyInt x(12345), y("9876543210123456789"), r1(-1000), r2 = "14H67", r3;
	char answer;
	cout << "Initial values: \nx = " << x << "\ny = " << y
	<< "\nr1 = " << r1 << "\nr2 = " << r2 << "\nr3 = " << r3 << "\n\n";
	
	// demonstrate >> overload
	//
	cout << "Enter first number: ";
	cin >> x;
	cout << "Enter second number: ";
	cin >> y;
	//
	cout << "You entered:\n";
	cout << "  x = " << x << '\n';
	cout << "  y = " << y << '\n';
	//
	//                                // demonstrate assignment =
	cout << "Assigning r1 = y ...\n";
	r1 = y;
	cout << "  r1 = " << r1 << '\n';
	//
	//                                        // demonstrate comparison overloads
	if (x < y)	cout << "(x < y) is TRUE\n";
	if (x > y)	cout << "(x > y) is TRUE\n";
	if (x <= y)	cout << "(x <= y) is TRUE\n";
	if (x >= y)	cout << "(x >= y) is TRUE\n";
	if (x == y)	cout << "(x == y) is TRUE\n";
	if (x != y)	cout << "(x != y) is TRUE\n";
	//
	//                                                      // demonstrating + and * overloads
	r1 = x + y;
	cout << "The sum (x + y) = " << r1 << '\n';
	r2 = x * y;
	cout << "The product (x * y) = " << r2 << "\n\n";
	cout << "The sum (x + 12345) = " << x + 12345 << '\n';
	cout << "The product (y * 98765) = " << y * 98765 << '\n';
	//
	//                                                                    // create Fibonacci numbers (stored as MyInts) using +
	cout << "\nAssuming that the Fibonnaci sequence begins 1,1,2,3,5,8,13..."
	<< "\n\nThe 10th Fibonnaci number   = " << Fibonnaci(10)
	<< "\n\nThe 100th Fibonnaci number  = " << Fibonnaci(100)
	<< "\n\nThe 1000th Fibonnaci number = " << Fibonnaci(1000)
	<< "\n\nThe 2000th Fibonnaci number = " << Fibonnaci(2000)
	<< "\n\n";
	

	return 0;
}

MyInt Fibonnaci(MyInt num)
{
	MyInt n1 = 1, n2 = 1, n3;
	MyInt i = 2;
	while (i < num)
	{
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		i++;
	}
	return n2;
}
