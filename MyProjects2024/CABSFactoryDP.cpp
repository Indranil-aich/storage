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

/*
* 
* 
* The code demonstrates the Abstract Factory design pattern combined with the Dependency Injection principle:

High-Level Module and its Dependency on Interfaces (Abstractions)
High-Level Module: The high-level module in this context is the client code or the logic that uses the factory to create products, such as the main function and the CAbsFactory class. These modules are responsible for orchestrating the creation of objects but should not concern themselves with the details of how the objects are created.

Interface/Abstraction Dependency:

The high-level module (CAbsFactory) depends on the IvehicleFactory interface to create cars and bikes.
The main function depends on the CAbsFactory to choose the appropriate factory (e.g., CmarutiFactory or CtataFactory) and then calls methods defined by the IvehicleFactory interface (createCar_(), createBike_()).
Low-Level Module and its Dependency on Interfaces
Low-Level Modules:

The low-level modules are the concrete factories (CmarutiFactory, CtataFactory) and concrete products (CmarutiCar, CtataBike, etc.).
These modules implement the details of how specific cars and bikes are created.
Interface Dependency:

The low-level factories (CmarutiFactory, CtataFactory) implement the IvehicleFactory interface. This means they provide concrete implementations for the methods createCar_() and createBike_() defined by the IvehicleFactory interface.
The concrete product classes (CmarutiCar, CtataBike) implement the ICar and IBike interfaces, respectively. This ensures that all products can be treated uniformly by the high-level module.
Summary
High-Level Modules: CAbsFactory and main function depend on the IvehicleFactory interface to create products. This allows them to work with any concrete factory that implements this interface, promoting flexibility and maintainability.

Low-Level Modules: CmarutiFactory, CtataFactory, and the specific product classes (CmarutiCar, CtataBike) depend on the IvehicleFactory, ICar, and IBike interfaces. This ensures they can be substituted easily without affecting the high-level module, following the Dependency Inversion Principle.
#include <iostream>
#include <memory>

// Product Interfaces
class ICar {
public:
    ICar() {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    virtual ~ICar() {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    virtual void getCar_() = 0;
};

class IBike {
public:
    IBike() {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    virtual ~IBike() {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    virtual void getBike_() = 0;
};

// Concrete Products
class CmarutiCar : public ICar {
public:
    CmarutiCar() {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    ~CmarutiCar() override {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    void getCar_() override {
        std::cout << "Maruti car" << std::endl;
    }
};

class CmarutiBike : public IBike {
public:
    CmarutiBike() {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    ~CmarutiBike() override {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    void getBike_() override {
        std::cout << "Maruti bike" << std::endl;
    }
};

class CtataCar : public ICar {
public:
    CtataCar() {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    ~CtataCar() override {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    void getCar_() override {
        std::cout << "Tata car" << std::endl;
    }
};

class CtataBike : public IBike {
public:
    CtataBike() {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    ~CtataBike() override {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    void getBike_() override {
        std::cout << "Tata bike" << std::endl;
    }
};

// Abstract Factory Interface
class IvehicleFactory {
public:
    IvehicleFactory() {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    virtual ~IvehicleFactory() {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    virtual std::unique_ptr<ICar> createCar_() = 0;
    virtual std::unique_ptr<IBike> createBike_() = 0;
};

// Concrete Factories
class CmarutiFactory : public IvehicleFactory {
public:
    CmarutiFactory() {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    ~CmarutiFactory() override {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    std::unique_ptr<ICar> createCar_() override {
        return std::make_unique<CmarutiCar>();
    }
    std::unique_ptr<IBike> createBike_() override {
        return std::make_unique<CmarutiBike>();
    }
};

class CtataFactory : public IvehicleFactory {
public:
    CtataFactory() {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    ~CtataFactory() override {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
    std::unique_ptr<ICar> createCar_() override {
        return std::make_unique<CtataCar>();
    }
    std::unique_ptr<IBike> createBike_() override {
        return std::make_unique<CtataBike>();
    }
};

// Abstract Factory Creator
class CAbsFactory {
private:
    std::unique_ptr<IvehicleFactory> vObj;

public:
    CAbsFactory() {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }

    std::unique_ptr<IvehicleFactory> createFactory_(int i) {
        if (i == 1) {
            return std::make_unique<CtataFactory>();
        } else {
            return std::make_unique<CmarutiFactory>();
        }
    }

    ~CAbsFactory() {
        std::cout << __FUNCTION__ << " executes" << std::endl;
    }
};

int main() {
    std::unique_ptr<CAbsFactory> fObj = std::make_unique<CAbsFactory>();
    fObj->createFactory_(1)->createBike_()->getBike_();
    return 0;
}

*/