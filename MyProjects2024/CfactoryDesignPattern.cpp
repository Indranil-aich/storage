#include "CommonHeader.h"

#include <iostream>
#include <memory>

/*
*Liskov Substitution Principle (LSP)
Principle:

Subtypes must be substitutable for their base types without altering the correctness of the program.
Analysis:

CCar and CBike both inherit from IVehicle and provide implementations for the pure virtual function getVehicle_().
Since both CCar and CBike override the getVehicle_() method of IVehicle, they can be used interchangeably where IVehicle is expected.
Both CCar and CBike are derived classes that can be used in place of IVehicle, satisfying the Liskov Substitution Principle. The factory class (Cfactory) creates and returns instances of these derived classes correctly, and the main function uses the created IVehicle without any issues.
Conclusion: The code adheres to the Liskov Substitution Principle.

Dependency Inversion Principle (DIP)
Principle:

High-level modules should not depend on low-level modules. Both should depend on abstractions.
Abstractions should not depend on details. Details should depend on abstractions.
Analysis:

The Cfactory class depends on the IVehicle abstraction rather than on concrete implementations like CCar or CBike. This allows for flexibility in creating different types of IVehicle implementations.
The high-level module (the factory class) does not directly depend on the low-level modules (CCar and CBike), but rather on the abstraction (IVehicle).
Conclusion: The code adheres to the Dependency Inversion Principle because the factory class depends on the IVehicle interface rather than directly on CCar or CBike.
*/

class Ivehicle
{
public:
    Ivehicle()
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
    virtual ~Ivehicle()
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
    virtual void getVehicle_() = 0;
};

class Ccar :public Ivehicle
{
public:
    Ccar()
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
    virtual ~Ccar()
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
    void getVehicle_()
    {
        std::cout << __FUNCTION__ << " executes getCar\n";
    }
};

class Cbike :public Ivehicle
{
public:
    Cbike()
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
    virtual ~Cbike()
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
    void getVehicle_()
    {
        std::cout << __FUNCTION__ << " executes getBike\n";
    }
};


class CvehicleFactory
{
public:
    std::unique_ptr<Ivehicle> createVehicle_(int i = 0)
    {
        if (i == 1)
        {
            return std::make_unique<Ccar>();
        }
        else
        {
            return std::make_unique<Cbike>();
        }
    }
    CvehicleFactory()
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
    virtual ~CvehicleFactory()
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
};

void funcToCreateVehicleFactory_()
{
    std::unique_ptr<CvehicleFactory>vObj(new CvehicleFactory());
    vObj->createVehicle_()->getVehicle_();
    
}



