
#include <iostream>
#include "CommonHeader.h"

class Cbase
{
public:
	int _mx;
	Cbase(int x)
		:_mx(x)
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
	
	void display()
	{
		std::cout << "\tFunction:" << __FUNCTION__<<"value of x "<< _mx<< std::endl;
	}
	
	virtual ~Cbase() {}

};

void display(Cbase obj)
{
	obj.display();
}
void funcToCreateExplicitConstructor_()
{
	display(10);
	std::cout << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
	
	std::cout << "end " << __FUNCTION__ << std::endl;
}