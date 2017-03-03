#include <iostream>
#include <bitset>
using namespace std;

int main()
{

	// just random number
	int a = 5;
	cout << "pos number: "<< bitset<64>(a) << endl;
	/*
	0000000000000000000000000000000000000000000000000000000000000101
	*/

	// plain 0
	int q = 0;
	// checking ~ operation
	cout << "~ number: " << bitset<64>(~q) << endl;

	// note that negative numbers are stored as 2's compliment in system
	a = -5;
	cout << "neg number: " << bitset<64>(a) << endl;
	/*
	1111111111111111111111111111111111111111111111111111111111111011
	*/

	// just random number
	unsigned int b= 5;
	cout << "pos number: "<< bitset<64>(b) << endl;
	/*
	0000000000000000000000000000000000000000000000000000000000000101
	*/

	// note that negative numbers are stored as 2's compliment in system
	// unsigned int is stored differently
	b = -5;
	cout << "neg number: " << bitset<64>(b) << endl;
	/*
	0000000000000000000000000000000011111111111111111111111111111011
	*/	

}



