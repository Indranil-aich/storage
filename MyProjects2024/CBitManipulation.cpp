#include "CommonHeader.h"
void powerof2_()
{
	std::cout << "\t" << __FUNCTION__ << " execute at line no" << __LINE__ << std::endl;
	int x = 16;
	bool flag = (x - 1) & x;
	if (!flag)
	{
		std::cout << x << "\t is power of 2" << std::endl;
	}
}
void setSpecificBits_()
{
	std::cout << "\t" << __FUNCTION__ << " execute at line no" << __LINE__ << std::endl;
	int x = 16;
	int pos = 3;
	int y = x;
	x |= (1 << pos);
	std::cout << "\tvalue of x was " << y << " now become " << x << std::endl;
}
int a()
{
	std::cout << "a";
	return 0;
}
int b()
{
	std::cout << "b";
	return 0;
}
void clearSpecificBits_()
{
	std::cout << "\t" << __FUNCTION__ << " execute at line no" << __LINE__ << std::endl;
	int x = 15;
	int pos = 3;
	int y = x;
	x &= ~(1 << pos);
	std::cout << "\tvalue of x was " << y << " now become " << x << std::endl;
}
void reverseOfBits_()
{
	std::cout <<"\t" << __FUNCTION__ << " execute at line no" << __LINE__ << std::endl;
	int x = 7;
	int size = 32;
	int tmp = 0;
	for (int i = 0; i < size; i++)
	{
		tmp |= ((x >> i) & 0x01) << (size - i-1);
	}
	std::cout << "\tvalue of " << x << "becomes " << tmp<<std::endl;
}


void flipTheBits_()
{
	std::cout << "\t" << __FUNCTION__ << " execute at line no" << __LINE__ << std::endl;
	int n = 12;
	int bitC = 2;
	std::cout << "\tNew number is" << (n ^ (1 << bitC))<< std::endl;
}

void alternetBits01_()
{
	std::cout << "\t" << __FUNCTION__ << " execute at line no" << __LINE__ << std::endl;
	int x = 11;
	int mask = x >> 1;
	mask = x ^ mask;
	bool flag = mask & (mask + 1);
	if (!flag)
	{
		std::cout << "\talternate bit of " << x << "0,1" << std::endl;
	}
	else {
		std::cout << "\talternate bit not 0, 1" << std::endl;
	}

}
void SubstractWithotNegativeSign()
{
	std::cout << "\t" << __FUNCTION__ << " execute at line no" << __LINE__ << std::endl;
	int x = 27;
	int y = 100;
	int sub = x+(~y + 1);
	std::cout << "Substract of " << y << " from " << x << " is " << sub<<" and" <<~y<< std::endl;

	
}
void funcToManupulateBit_()
{
	std::cout << __FUNCTION__ << " execute at line no" << __LINE__ << std::endl;
	powerof2_();
	setSpecificBits_();
	clearSpecificBits_();
	reverseOfBits_();
	flipTheBits_();
	SubstractWithotNegativeSign();
	alternetBits01_();
	if (a() ^ b())
	{
		std::cout << "main";
	}
	std::cout << "end " << __FUNCTION__ << std::endl;
}