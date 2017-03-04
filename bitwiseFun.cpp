#include <iostream>
#include <bitset>
using namespace std;

//https://www.quora.com/What-are-some-cool-bit-manipulation-tricks-hacks
//http://www.catonmat.net/blog/low-level-bit-hacks-you-absolutely-must-know/

void UpdateBits()
{

	int N = 1024; //10000000000
	cout << "N: "<< bitset<64>(N) << endl; 
	//0000000000000000000000000000000000000000000000000000010000000000
	int M = 21; // 10101
	cout << "M: "<< bitset<64>(M) << endl;
	//0000000000000000000000000000000000000000000000000000000000010101
	int i =2, j = 6;

	int max = ~0;
	cout << "max number: "<< bitset<64>(max) << endl;
	//1111111111111111111111111111111111111111111111111111111111111111

	cout << "1<< j: "<< bitset<64>(1<<j) << endl;
	//0000000000000000000000000000000000000000000000000000000001000000

	cout << "1<<j - 1: "<< bitset<64>((1<<j) - 1) << endl;
	//0000000000000000000000000000000000000000000000000000000000111111
	
	int left = max - ((1<<j) -1);
	cout << "left: "<< bitset<64>(left) << endl;
	//1111111111111111111111111111111111111111111111111111111111000000

	int right = ((1<<i) -1);
	cout << "right: "<< bitset<64>(1 << i) << endl;	
	//0000000000000000000000000000000000000000000000000000000000000100
	
	cout << "right: "<< bitset<64>(right) << endl;
	//0000000000000000000000000000000000000000000000000000000000000011

	int mask = left | right;
	cout << "mask: "<< bitset<64>(mask) << endl;
	//1111111111111111111111111111111111111111111111111111111111000011



	int result = (N & mask) | (( M << i) | mask);
	cout << "N & mask: "<< bitset<64>(N & mask) << endl;
	//0000000000000000000000000000000000000000000000000000010000000000
	cout << "M << i: "<< bitset<64>(M << i) << endl;
	//0000000000000000000000000000000000000000000000000000000001010100
	cout << "M << i | mask: "<< bitset<64>((M << i) | mask)<< endl;
	cout << "result: "<< bitset<64>(result) << endl;		
	//0000000000000000000000000000000000000000000000000000010001010100


}


void ComputeSignOfInt()
{
	int v = -1;
	int sign;

	cout << "5 "<< bitset<64>(5) << endl;
	cout << "5 < 0 "<< bitset<64>(5 < 0) << endl;

	cout << "-5 "<< bitset<64>(-5) << endl;
	cout << "-5 < 0 "<< bitset<64>(-5 < 0) << endl;

	cout << "0 < 0 "<< bitset<64>(0 < 0) << endl;
	sign = -(v < 0);

	// sign = 0 for  v = 0
	// sign = 0 for  v = 1
	// sign = -1 for  v = -1
	cout << sign << endl;
}

int main()
{

	UpdateBits();
	//ComputeSignOfInt();
	

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
