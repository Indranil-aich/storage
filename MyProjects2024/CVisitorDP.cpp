#include "CommonHeader.h"
class IHospital;

class IPatient
{
public:
	virtual void doAccept(IHospital* obj) = 0;
	virtual void getPatient_() = 0;
};

class IHospital
{
public:
	virtual void doVisit_(IPatient* obj) = 0;
};
class CPatient1 :public IPatient
{
public:
	void doAccept(IHospital* obj) override
	{
		obj->doVisit_(this); 
	}
    void getPatient_() override
	{
		std::cout << "CPatient1" << std::endl;
	}
};
class CDoctor :public IHospital
{
public:
	void doVisit_(IPatient * obj) override
	{
		std::cout << "doctor visited to "; obj->getPatient_();
	}
};


void funcToCreateVisitor_()
{
	IPatient* p1 = new CPatient1();
	IHospital* d1 = new CDoctor();
	p1->doAccept(d1);

}