#include "CommonHeader.h"

/**************************************************************************************
* The Liskov Substitution Principle (LSP) states that objects of a superclass should be 
replaceable with objects of a subclass without affecting the program's behavior.

In your factory design pattern code:

Base Class CVehicle:
===========================
Abstract class with a pure virtual function createVehicle_().

Derived Classes CCar and CBike:
==================================
Both override the createVehicle_() method.
Implement their specific behavior for createVehicle_().

Factory Class CVehicleFactory:
====================================
Creates and returns either a CCar or CBike object as a CVehicle pointer based on input.

LSP Application:

Method Consistency: CCar and CBike provide implementations for createVehicle_(), 
                   allowing them to be used wherever CVehicle is expected.
Behavioral Compatibility: Using CCar or CBike in place of CVehicle does not 
                         alter the program's behavior.
Conclusion:
Your code adheres to LSP because CCar and CBike can replace CVehicle without affecting 
the program's functionality. The factory pattern ensures the correct vehicle type is 
created, and polymorphism ensures the right createVehicle_() method is called.

"Objects of a superclass should be replaceable with objects of a subclass 
without affecting the correctness of the program."
**************************************************************************************/

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

void funcToCreateVehicleFactory_()
{
	std::cout << __FUNCTION__ << " execute at line no" << __LINE__ << std::endl;
	std::unique_ptr<CVehicleFactory> cfObj(new CVehicleFactory());
	cfObj->getVehicle_(1)->createVehicle_();
	std::cout << "end " << __FUNCTION__ << std::endl;

}