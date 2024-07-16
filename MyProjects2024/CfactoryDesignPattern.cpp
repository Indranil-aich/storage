#include "CommonHeader.h"

class CVehicle
{
public:
	CVehicle() = default;
	virtual void createVehicle_() = 0;
	virtual ~CVehicle() {}

};

class CCar :public CVehicle
{
public:
	CCar() = default;
	void createVehicle_()
	{
		std::cout << "Ccar" << std::endl;
	}
	~CCar() {
		std::cout << "delete CCar" << std::endl;
	}
};

class CBike :public CVehicle
{
public:
	CBike() = default;
	void createVehicle_()
	{
		std::cout << "CBike" << std::endl;
	}
	~CBike() {
		std::cout << "delete CBike" << std::endl;
	}
};

class CVehicleFactory
{
public:
	CVehicleFactory()
		:fObj(nullptr) {}
	CVehicle* fObj;
	CVehicle *getVehicle_(int i)
	{
		if (i == 1)
		{
			fObj = new CCar();
		}
		else {
			fObj = new CBike();
		}
		return fObj;
	}
	~CVehicleFactory() {
		std::cout << __FUNCTION__ << " execute at line no" << __LINE__ << std::endl;
		delete fObj;
		fObj = nullptr;
	}

};

void createVehicleFactory_()
{
	std::cout << __FUNCTION__ << " execute at line no" << __LINE__ << std::endl;
	std::unique_ptr<CVehicleFactory> cfObj(new CVehicleFactory());
	cfObj->getVehicle_(1)->createVehicle_();
	std::cout << "end " << __FUNCTION__ << std::endl;

}