#include "CommonHeader.h"

class Ccomplex
{
private:
	int r, i;
public:
	Ccomplex(int x=0, int y=0)
		:r(x)
		,i(y) {}
	virtual ~Ccomplex() = default;
	void dump_() {
		std::cout << "\t Complex Number  " << r << " + i" << i << std::endl;
	}

	Ccomplex operator+(Ccomplex const & num)
	{
		Ccomplex tmp;
		tmp.r = r + num.r;
		tmp.i = i + num.i;
		return tmp;
	}

};
void funcToOverloadOperator_()
{
	std::cout << __FUNCTION__ << " execute at line no" << __LINE__ << std::endl;
	Ccomplex C1(5, 10), C2(10, 20);
	Ccomplex C3 = C1 + C2;
	C3.dump_();
	std::cout << "end " << __FUNCTION__ << std::endl;
}
