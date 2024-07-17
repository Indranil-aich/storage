#include "commonHeader.h"

template <typename T>
class CSharedPTR
{
private:
	T* _mPTR;
	int *_mRefCount;
public:
	CSharedPTR(T* ptr)
		:_mPTR(ptr)
		,_mRefCount(new int(1))
	{

	}
	int getRefCount_() const
	{
		return *_mRefCount;
	}
	CSharedPTR(const CSharedPTR& Obj)   noexcept                      // move constructor
	{
		std::cout << "\t" << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
		_mPTR = Obj._mPTR;
		_mRefCount = Obj._mRefCount;
		(*_mRefCount)++;
		

	}
	CSharedPTR& operator=(const CSharedPTR& Obj) noexcept            // move assignment
	{
		if (this != &Obj)
		{
			std::cout << "\t" << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
			__clean_up__();
			_mPTR = Obj._mPTR;
			_mRefCount = Obj._mPTR;
			(*_mRefCount)++;
		
		}
		return *this;
	}

	virtual ~CSharedPTR()
	{
		std::cout << "\t" << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
		__clean_up__();
	}
	CSharedPTR(CSharedPTR&& Obj) = delete;
	CSharedPTR& operator=(CSharedPTR&& Obj) = delete;

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
private:
	void __clean_up__()
	{
		(*_mRefCount)--;
		if (_mPTR != nullptr && (*_mRefCount) == 0)
		{
			delete _mPTR;
			_mPTR = nullptr;
	
		}
	;
	}
	
};
void funToCreateSharedPTR_()
{
	std::cout << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
	CSharedPTR<int> obj1(new int(10));
	CSharedPTR<int> obj2 = obj1;
	*obj2 = 100;
	

	std::cout << "\t Ref of shared Obj  "<<obj1.getRefCount_()<<" value of obj1 is " << *obj1 << std::endl;
	std::cout << "end " << __FUNCTION__ << std::endl;
}