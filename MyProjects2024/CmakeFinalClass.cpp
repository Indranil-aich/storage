#include "CommonHeader.h"
class CmyFinal;
class CmkFinal
{
private:
	friend class CmyFinal;
	CmkFinal() = default;
};

class CmyFinal:public virtual CmkFinal
{
public:
	CmyFinal() = default;
};

class CmyClass :public CmyFinal
{
public:
	CmyClass() = default;
};
void funcToMakeFinalClass_()
{
	std::cout << __FUNCTION__ << " execute at line no" << __LINE__ << std::endl;
	//CmyClass* obj = new CmyClass();
	std::cout << "end " << __FUNCTION__ << std::endl;
} 

