#include "CommonHeader.h"

typedef double(*fptr)(double, double);
double sum(double a, double b)
{
	return (a + b);
}

double binary_op(double  a, double b, fptr ptrObj)
{
	return ptrObj(a, b);
}

class CSum
{
public:
	CSum(int x=0, int y=0)
		:a(x)
		,b(y) {}
	int operator()(int x, int y)
	{
		a = x;
		b = y;
		return a + b;
	}
private:
	int a, b;
};
void funcToCreateFuncPTR_N_Functor_()
{
	std::cout << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
	fptr ptrObj = sum;
	std::cout << "\tSum is::" << ptrObj(10.20, 30.50)<<std::endl;
	std::cout << "\tSum using bunary::" << binary_op(10.20, 100, sum) << std::endl;
	CSum sObj;
	std::cout << "\tSum using functor::" << sObj(20, 100) << std::endl;
	int x = 100;
	int* _mPTR = new(&x)int (10);
	std::cout << "\tValue of x::" << x << std::endl;
	std::cout << "end " << __FUNCTION__ << std::endl;
}
