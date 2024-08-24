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

/*
#include <iostream>
#include <memory>

class IHospital;
class IPatient
{
   public:
     IPatient()
     {
     }
     virtual ~IPatient()
     {
     }
     virtual void doAccept_(std::unique_ptr<IHospital> &&) = 0;
     virtual int getPID_() const = 0;
};
class IHospital
{
   public:
     IHospital()
     {
         std::cout<<__FUNCTION__<<" execute\n";
     }
     virtual ~IHospital()
     {
         std::cout<<__FUNCTION__<<" execute\n";
     }
     virtual void doVisit_(IPatient *) = 0;


};

class CPatient:public IPatient
{
   public:
     CPatient(int id)
     :_mPID(id)
     {
         std::cout<<__FUNCTION__<<" execute\n";
     }
     virtual ~CPatient()
     {
        std::cout<<__FUNCTION__<<" execute\n";
     }
     void doAccept_(std::unique_ptr<IHospital> &&vObj ) override
     {
        vObj->doVisit_(this);
     }
     int getPID_() const override
     {
        return _mPID;
     }
     private:
        int _mPID;
};

class CDoctor: public IHospital
{
   public:
     CDoctor()
     {
         std::cout<<__FUNCTION__<<" execute\n";
     }
     ~CDoctor()
     {
         std::cout<<__FUNCTION__<<" execute\n";
     }
     void doVisit_(IPatient * pObj) override
     {
        std::cout<< " doctore visited to patient having id"<<pObj->getPID_();
     }


};
class CNurse: public IHospital
{
   public:
     CNurse()
     {
         std::cout<<__FUNCTION__<<" execute\n";
     }
     ~CNurse()
     {
         std::cout<<__FUNCTION__<<" execute\n";
     }
     void doVisit_(IPatient * pObj)
     {
        std::cout<< " doctore visited to patient having id"<<pObj->getPID_();
     }


};

int main()
{
   std::unique_ptr<IPatient>pObj(new CPatient(100));
   std::unique_ptr<IHospital>dObj(new CDoctor());
   std::unique_ptr<IHospital>nObj(new CNurse());
   pObj->doAccept_(std::move(dObj));
   pObj->doAccept_(std::move(nObj));
   return 0;
}
*/