// MyProjects2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CommonHeader.h"

int main()
{
	std::cout << "Hello World!\n";
/*
	funcToChageConstVariable_();
	funcToDeleteSpatialMemberFunc_();
	funcToDiamondProblem_();
	funcToOverloadOperatorNewAndDelete();
	funcToMakeFinalClass_();
	funcToOverloadOperator_();
	funcToCreateVehicleFactory_();
	funToCreateUniquePTR_();
	funToCreateSharedPTR_();
	funcToCreateFuncPTR_N_Functor_();
	funcToCreateExplicitConstructor_();
	funcToCreateSingletonObj_();

	funcToCreateDCSingletonObj_();
	funcToCreate2D_N_3D_dynamicArry_();
	funcToManupulateBit_();
	funcToCreateLinkList_();
	funcToCreateLinkList_();
	funcToManipulateString_();
	funcToCreateABSFactory_();
	funcToCreateVisitor_();

*/

 
 funcToCreateBST_();
	
	return 0;
}



/*
#include <iostream>
#include <memory>
#include <vector>

class IObserver
{
   public:
      IObserver(){
        std::cout << __FUNCTION__ << " execute " << std::endl;
      }
      virtual ~IObserver(){
        std::cout << __FUNCTION__ << " execute " << std::endl;
      }
      virtual void update_(const std::string & Cstr) = 0;
      virtual int getID_() = 0;

};

class CObserver : public IObserver
{
   public:
      CObserver (int id)
      :_mID(id){
        std::cout << __FUNCTION__ << " execute " << std::endl;
      }
      virtual ~CObserver(){
        std::cout << __FUNCTION__ << " execute user::"<<_mID << std::endl;
      }
      void update_(const std::string & Cstr)
      {
           std::cout << __FUNCTION__ << " execute " << std::endl;
           std::cout<<" Observer::"<<_mID<<" get update msg"<<Cstr<<std::endl;
      }
      int getID_()
      {
         return _mID;
      }
  private:
     int _mID;

};
class ISubjects
{
   public:
      ISubjects(){
        std::cout << __FUNCTION__ << " execute " << std::endl;
      }
      virtual ~ISubjects(){
        std::cout << __FUNCTION__ << " execute " << std::endl;
      }
      virtual void stateChange_() = 0;
      virtual void attachObserver_(std::unique_ptr<IObserver>)  = 0;
      virtual void detachObserver_(int _ID)  = 0;
   private:
      virtual void notify_() = 0;
};

class CAmazon : public ISubjects
{
   public:
      CAmazon (){
        std::cout << __FUNCTION__ << " execute " << std::endl;
      }
      virtual ~CAmazon (){
        std::cout << __FUNCTION__ << " execute " << std::endl;
      }
      void stateChange_()
      {
          notify_();
      }
      void attachObserver_(std::unique_ptr<IObserver> vObj)
      {
          vSubj.push_back(std::move(vObj));
      }
      void detachObserver_(int _ID )
      {
         for(int  i = 0 ; vSubj.size(); i++)
         {
              if(_ID == vSubj[i]->getID_())
             {
                 vSubj.erase(vSubj.begin()+i);
                 break;
             }
         }
      }
   private:
      std::vector<std::unique_ptr<IObserver>> vSubj;
      void notify_()
      {
          for(auto &tmp:vSubj)
          {
              tmp->update_("big billion day on 13th Aug");
          }
      }
};

int main()
{
   std::unique_ptr<ISubjects> sObj(new CAmazon ());
   sObj->attachObserver_(std::make_unique<CObserver>(100));
   sObj->attachObserver_(std::make_unique<CObserver>(200));
   sObj->attachObserver_(std::make_unique<CObserver>(300));
   sObj->attachObserver_(std::make_unique<CObserver>(400));
   sObj->attachObserver_(std::make_unique<CObserver>(500));
   sObj->stateChange_();
   sObj->detachObserver_(300);
   sObj->stateChange_();
   return 0;
}
*/

/*
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

class IObserver
{
public:
    virtual void update(const std::string& message) = 0;
    virtual ~IObserver() = default;
};

class Observer : public IObserver
{
public:
    Observer(const std::string& name) : name_(name) {}

    void update(const std::string& message) override {
        std::cout << name_ << " received message: " << message << std::endl;
    }

private:
    std::string name_;
};

class Subject
{
public:
    void attach(std::shared_ptr<IObserver> observer) {
        observers_.push_back(observer);
    }

    void detach(std::shared_ptr<IObserver> observer) {
        auto it = std::remove_if(observers_.begin(), observers_.end(),
            [&observer](const std::weak_ptr<IObserver>& weakObs) {
                if (auto obs = weakObs.lock()) {
                    return obs == observer;
                }
                return false;
            });
        observers_.erase(it, observers_.end());
    }

    void notify(const std::string& message) {
        for (auto& weakObs : observers_) {
            if (auto obs = weakObs.lock()) {
                obs->update(message);
            }
        }
    }

private:
    std::vector<std::weak_ptr<IObserver>> observers_;
};

int main()
{
    Subject subject;

    auto observer1 = std::make_shared<Observer>("Observer1");
    auto observer2 = std::make_shared<Observer>("Observer2");
    auto observer3 = std::make_shared<Observer>("Observer3");

    subject.attach(observer1);
    subject.attach(observer2);
    subject.attach(observer3);

    std::cout << "Notifying observers:" << std::endl;
    subject.notify("Hello, observers!");

    subject.detach(observer2);

    std::cout << "\nNotifying observers after detaching Observer2:" << std::endl;
    subject.notify("Update after detaching Observer2");

    return 0;
}

*/