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

using namespace std;

/*
 * 
 */
int addBin(int);
int size;

int main()
{




	int encArry[8] = {6, 7, 5, 'a', 6, 9, 6, 7};


	for (int i = 0; i < 8; i++) {
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


	int tmp=0;
	int O[4]; //The output array

	while (tmp != 8) {

		
		bitset<4> A = encArry[tmp]; //A will hold the binary representation of N 
		for (int i = 0, j = 3; i < 4; i++, j--) {
			//Assigning the bits one by one.
			O[i] = A[j];
		}
		tmp++;
	}
	for (int i = 0; i < 64; i++) {
		cout << O[i];

	}


	//	int val;
	//
	//	for (int i = 0; i < 8; i++) {
	//		val = encArry[i];
	//		addBin(val);
	//
	//	}
	//
	//
	//
	//	return 0;
}

int addBin(int val)
{
	//	int msg[64]; //The output array
	//	bitset<4> A = val; //A will hold the binary representation of val
	//	int tmp = size + 1;
	//
	//
	//	for (int i = 0; i < 4; i++) {
	//		for (int j = 3; j >= 0; j--) {
	//			//Assigning the bits one by one.
	//			//cout << A[j];
	//
	//
	//
	//		}
	//		//cout << endl;
	//
	//
	//	}
	//	size++;


}




