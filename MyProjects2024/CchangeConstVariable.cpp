#pragma once
#include <iostream>
#include "CommonHeader.h"


void funcToChageConstVariable_()
{
	std::cout << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
	const volatile int  x = 10;
	int* _mPTR = (int*)(&x);
	*_mPTR = 100;
	std::cout << "\tvalue of x:" << x << std::endl;
	std::cout << "\tvalue of _mPTR" << *_mPTR<<std::endl;
	std::cout <<"end " << __FUNCTION__ << std::endl;
}

