// MyProjects2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CommonHeader.h"

int main()
{
	std::cout << "Hello World!\n";
/*
	funcToChageConstVariable_();
	funcToDeleteSpatialMemberFunc_();
	funcToDiamondProblem_();
	funcToOverloadOperatorNewAndDelete();
	funcToMakeFinalClass_();
	funcToOverloadOperator_();
	funcToCreateVehicleFactory_();
	funToCreateUniquePTR_();
	funToCreateSharedPTR_();
	funcToCreateFuncPTR_N_Functor_();
	funcToCreateExplicitConstructor_();
	funcToCreateSingletonObj_();

	funcToCreateDCSingletonObj_();
	funcToCreate2D_N_3D_dynamicArry_();
	funcToManupulateBit_();
	funcToCreateLinkList_();
	funcToCreateLinkList_();
	funcToManipulateString_();
	funcToCreateABSFactory_();
	funcToCreateVisitor_();
    funcToCreateBST_();

*/

 
 
  funcToCreateObserverDP_();
	
	return 0;
}

/*
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	struct stat statbuf;
	const char *path = "F:\\Storage-Domain\\posix_code";

	// Get the status of the file or directory
	if (stat(path, &statbuf) == -1) {
		perror("stat");
		exit(EXIT_FAILURE);
	}

	// Check if the path is a directory
	if (S_ISDIR(statbuf.st_mode)) {
		printf("%s is a directory.\n", path);
	} else {
		printf("%s is not a directory.\n", path);
	}

	return 0;
}

*/



/*
* #include <iostream>
int *f()
{
    int *x = new int[5];
    return x;
}


int main()
{
  int *fp=f();
  std::cout<<"exec"<<*fp<<std::endl;
  return 0;
}

*/

/*
#include <iostream>
using namespace std;

void decimalToBinary(int n) {
	for (int i = 31; i >= 0; i--) {
		int bit = (n >> i) & 1;
		cout << bit;
	}
	cout << endl;
}

int main() {
	int num = 10; // Example decimal number
	cout << "Binary representation of " << num << " is: ";
	decimalToBinary(num);
	return 0;
}

#include <iostream>
using namespace std;

void decimalToHex(int n) {
	char hexDigits[] = "0123456789ABCDEF";
	char hex[8]; // For storing the result (assuming a 32-bit integer)
	int index = 7;

	for (int i = 0; i < 8; ++i) {
		int currentNibble = n & 0xF; // Extract the last 4 bits (1 nibble)
		hex[index--] = hexDigits[currentNibble]; // Convert to hex digit
		n >>= 4; // Right shift by 4 bits to process the next nibble
	}

	cout << "0x";
	for (int i = 0; i < 8; ++i) {
		cout << hex[i];
	}
	cout << endl;
}

int main() {
	int num = 255; // Example decimal number
	cout << "Hexadecimal representation of " << num << " is: ";
	decimalToHex(num);
	return 0;
}

*/

/*
int hexToDecimal(const char* hex) {
	int length = strlen(hex);
	int base = 1; // The base of the hexadecimal number system (16^0 initially)
	int decimalValue = 0;

	// Process each character from right to left
	for (int i = length - 1; i >= 0; i--) {
		if (hex[i] >= '0' && hex[i] <= '9') {
			decimalValue += (hex[i] - '0') * base;
		} else if (hex[i] >= 'A' && hex[i] <= 'F') {
			decimalValue += (hex[i] - 'A' + 10) * base;
			std::cout<<" "<<decimalValue;
		} else if (hex[i] >= 'a' && hex[i] <= 'f') {
			decimalValue += (hex[i] - 'a' + 10) * base;
		}
		base *= 16; // Increase base by power of 16 (16^1, 16^2, ...)
	}

	return decimalValue;
}
*/