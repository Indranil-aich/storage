#include "CommonHeader.h"
class CmyOperator
{
public:
	CmyOperator()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
	~CmyOperator()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
	void* operator new(size_t size)
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
		void* ptr = ::operator new(size);
		return ptr;

	}
	void operator delete(void* ptr)
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
		free( ptr);
		ptr = nullptr;
		int x = 100;
		int* _mPTR = new(&x)int(500);
		std::cout << "x::" << x << std::endl;

	}


};

void funcToOverloadOperatorNewAndDelete()
{
	std::cout << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
	
	CmyOperator* obj = new CmyOperator();
	delete obj;
	std::cout << "end " << __FUNCTION__ << std::endl;
}