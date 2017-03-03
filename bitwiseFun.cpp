#include <iostream>
#include <bitset>
using namespace std;

void UpdateBits()
{

	int N = 1024; //10000000000
	cout << "N: "<< bitset<64>(N) << endl;
	int M = 21; // 10101
	cout << "M: "<< bitset<64>(M) << endl;
	int i =2, j = 6;

	int max = ~0;
	cout << "max number: "<< bitset<64>(max) << endl;

	cout << "1<< j: "<< bitset<64>(1<<j) << endl;
	cout << "1<<j - 1: "<< bitset<64>((1<<j) - 1) << endl;
	int left = max - ((1<<j) -1);
	cout << "left: "<< bitset<64>(left) << endl;

	int right = ((1<<i) -1);
	cout << "right: "<< bitset<64>(1 << i) << endl;	
	cout << "right: "<< bitset<64>(right) << endl;

	int mask = left | right;
	cout << "mask: "<< bitset<64>(mask) << endl;



	int result = (N & mask) | ( M << i);
	cout << "N & mask: "<< bitset<64>(N & mask) << endl;
	cout << "M << i: "<< bitset<64>(M << i) << endl;
	cout << "result: "<< bitset<64>(result) << endl;		


}


int main()
{

	UpdateBits();

	// // just random number
	// int a = 5;
	// cout << "pos number: "<< bitset<64>(a) << endl;
	// /*
	// 0000000000000000000000000000000000000000000000000000000000000101
	// */

	// // plain 0
	// int q = 0;
	// // checking ~ operation
	// cout << "~ number: " << bitset<64>(~q) << endl;
	// //1111111111111111111111111111111111111111111111111111111111111111

	// // note that negative numbers are stored as 2's compliment in system
	// a = -5;
	// cout << "neg number: " << bitset<64>(a) << endl;
	
	// 1111111111111111111111111111111111111111111111111111111111111011
	

	// // just random number
	// unsigned int b= 5;
	// cout << "pos number: "<< bitset<64>(b) << endl;
	// /*
	// 0000000000000000000000000000000000000000000000000000000000000101
	// */

	// // note that negative numbers are stored as 2's compliment in system
	// // unsigned int is stored differently
	// b = -5;
	// cout << "neg number: " << bitset<64>(b) << endl;
	// /*
	// 0000000000000000000000000000000011111111111111111111111111111011
	// */	

}



