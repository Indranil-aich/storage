#include "CommonHeader.h"
#include <iostream>

class CmyBase
{
public:
	template <typename X>
	void display_(X tmp) = delete;
	void display_(int x)
	{
		std::cout << "\tvalue of X is " << x << std::endl;
	}
};

void funcToDeleteSpatialMemberFunc_()
{
	std::cout << std::endl << __FUNCTION__ <<"execute at line no" <<__LINE__ << std::endl;
	CmyBase bObj;
	//bObj.display_(10.20); // error:: attempt to refer a deleted function
	bObj.display_(10);
	std::cout << "end " << __FUNCTION__ << std::endl;


}