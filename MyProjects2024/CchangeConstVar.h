#pragma once
#include <iostream>
class CchangeConstVar
{
public:
	CchangeConstVar()
	{

	}
	virtual ~CchangeConstVar()
	{

	}
	void chageConstVariable_()
	{
		const volatile int  x = 10;
		int* _mPTR = (int*)(&x);
		*_mPTR = 100;
		std::cout << " value of x:" << x << std::endl;
		std::cout << " value of _mPTR" << *_mPTR;

	}
	CchangeConstVar(const CchangeConstVar&) = delete;   // copy constructor
	CchangeConstVar& operator=(const CchangeConstVar&) = delete; // copy assignment
	CchangeConstVar(CchangeConstVar&&) = delete;        // move constructor
	CchangeConstVar& operator=(CchangeConstVar&&) = delete; // move assignment

};

