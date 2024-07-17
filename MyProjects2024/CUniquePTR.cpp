#include "commonHeader.h"

template <typename T>
class CUniquePTR
{
public:
	T* _mPTR;
	CUniquePTR(T *ptr)
		:_mPTR(ptr)
	{

	}
	CUniquePTR(CUniquePTR&& Obj)   noexcept                      // move constructor
	{
		std::cout << "\t" << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
		_mPTR = std::move(Obj._mPTR);
		Obj._mPTR = nullptr;

	}
	
	CUniquePTR& operator=(CUniquePTR&& Obj)             // move assignment
	{
		if (this != &Obj)
		{
			std::cout << "\t" << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
			__clean_up__();
			_mPTR = std::move(Obj._mPTR);
			Obj._mPTR = nullptr;
		}
		return *this;
	}

	void __clean_up__()
	{

		delete _mPTR;
		_mPTR = nullptr;
	}
	virtual ~CUniquePTR()
	{
		std::cout << "\t" << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
		__clean_up__();
	}
	CUniquePTR(const CUniquePTR& Obj) = delete;
	CUniquePTR& operator=(const CUniquePTR& Obj) = delete;

	T* operator->()
	{
		std::cout << "\t" << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
		return _mPTR;
	}
	T& operator*()
	{
		std::cout << "\t" << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
		return *(_mPTR);
	}
};
void funToCreateUniquePTR_()
{
	std::cout << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
	CUniquePTR<int> obj1(new int(10));
	CUniquePTR<int> obj2 = std::move(obj1);
	*obj2 = 100;
	obj1 = std::move(obj2);
	std::cout << "\t value of obj1 is" << *obj1 << std::endl;
	std::cout << "end " << __FUNCTION__ << std::endl;
}