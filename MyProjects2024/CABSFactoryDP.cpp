#include "CommonHeader.h"
class IBike
{
public:
	virtual void getBike_() = 0;
};
class ICar
{
public:
	virtual void getCar_() = 0;
};
class IFactory
{
public:
	virtual IBike* createBike_() = 0;
	virtual ICar* createCar_() = 0;
};

class CTataBike:public IBike
{
public:
	void getBike_() override
	{
		std::cout << "tata bike" << std::endl;
	}
};
class CTataCar :public ICar
{
public:
	void getCar_() override
	{
		std::cout << "tata car" << std::endl;
	}
};

class CMarutiBike :public IBike
{
public:
	void getBike_() override
	{
		std::cout << "maruti bike" << std::endl;
	}
};
class CMarutiCar :public ICar
{
public:
	void getCar_() override
	{
		std::cout << "maruti car" << std::endl;
	}
};
class CTataFactory:public IFactory
{
public:
	IBike* createBike_() override
	{
		return new CTataBike();
	}
	ICar* createCar_() override
	{
		return new CTataCar();
	}
};
class CMarutiFactory :public IFactory
{
public:
	IBike* createBike_() override
	{
		return new CMarutiBike();
	}
	ICar* createCar_() override
	{
		return new CMarutiCar();
	}
};

class CABSFactory
{
public:
	IFactory* createFactory_(int i)
	{
		if (i == 1)
		{
			return new CTataFactory();
		}
		else {
			return new CMarutiFactory();
		}
	}
};

void funcToCreateABSFactory_()
{
	CABSFactory* obj = new CABSFactory();
	obj->createFactory_(1)->createBike_()->getBike_();
	delete obj;
}