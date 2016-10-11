/* 
 * File:   main.cpp
 * Author: Collin Stolpa
 * Description: 
 * Encrypt with DES 
 * (1)3a456b73 e24d2537
 * (2)624b3a2d 92345f3d
 * 
 * Encrypted:
 * 
 * 
 */

#include <cstdlib>
#include <bitset>
#include <iostream>
#include <string> 
#include<cstdlib>
#include <algorithm>
#include <iterator>

using namespace std;

/*
 * 
 */
int addBin(int);
int convBinDec(long);

int msg[64]; //The message that has to be encrypted msg[] stores the binary values, each element is 1 bit
int size;
const int ENCARYSIZE = 16;

int main()
{


	int IniPerm[64] = {58, 50, 42, 34, 26, 18, 10, 2,
		60, 52, 44, 36, 28, 20, 12, 4,
		62, 54, 46, 38, 30, 22, 14, 6,
		64, 56, 48, 40, 32, 24, 16, 8,
		57, 49, 41, 33, 25, 17, 9, 1,
		59, 51, 43, 35, 27, 19, 11, 3,
		61, 53, 45, 37, 29, 21, 13, 5,
		63, 55, 47, 39, 31, 23, 15, 7};

	int encArry[ENCARYSIZE] = {6, 7, 5, 'a', 6, 9, 6, 7, 5, 'e', 5, 'a', 6, 'b', 5, 'a'};
	for (int i = 0; i < ENCARYSIZE; i++) {
		if (encArry[i] == 'a') {
			encArry[i] = 10;
		} else if (encArry[i] == 'b') {
			encArry[i] = 11;
		} else if (encArry[i] == 'c') {
			encArry[i] = 12;
		} else if (encArry[i] == 'd') {
			encArry[i] = 13;
		} else if (encArry[i] == 'e') {
			encArry[i] = 14;
		} else if (encArry[i] == 'f') {
			encArry[i] = 15;
		}
	}

	int encryptedBinMsg[64];
	for (int i = 0; i < 64; i++) {
		// initialize all elements to 0
		msg[i] = 0;
		encryptedBinMsg[i] = 0;

	}




	int a[4] = {1, 0, 1, 1};
	int k = 0;
	for (int i = 0; i < 4; i++) {
		k = 10 * k + a[i];
	}




	int val;
	convBinDec(k);
	size = 0;
	//sends each element of encArry[] to get its binary value 
	for (int i = 0; i < ENCARYSIZE; i++) {
		val = encArry[i];
		addBin(val);

	}



	//do the encryption here
	//the first bit of the output is taken from the 58th bit from the input, the second bit of the
	//output is the 50th bit if the input, and so on.
	for (int i = 0; i < 64; i++) {
		encryptedBinMsg[i] = msg[IniPerm[i]];


	}
	//print encrypted binary  message	//this dosent print correctly
	for (int i = 1; i < 65; i++) {
		//	cout << encryptedBinMsg[i-1];
		if (i % 8 == 0) {
			//	cout << endl;
		}
	}

	//print encArry binary elements //this prints correctly
	for (int i = 1; i < 65; i++) {
		cout << msg[i - 1];
		if (i % 8 == 0) {
			cout << endl;
		}
	}

	return 0;
}

// addBin takes the encArry and converts the elements into their 4 bit bites and stores them into msg[]

int addBin(int val)
{

	bitset<4> A = val; //A will hold the binary representation of val
	// bitset reads right to left this loop makes bitset store from left to right into msg for example
	// 1110 for 7 it is now correctly put in as 0111
	for (int i = 3; i >= 0; i--) {
		msg[size++] = A[i];
	}

}

// this takes a 4 bit var and converts it into its corresponding decimal value

int convBinDec(long binNum)
{
	long bin, dec = 0, rem, num, base = 1;

	num = binNum;
	bin = num;
	while (num > 0) {
		rem = num % 10;
		dec = dec + rem * base;
		base = base * 2;
		num = num / 10;
	}
	//cout << "The decimal equivalent of " << bin << " : " << dec << endl;
	return 0;
}


