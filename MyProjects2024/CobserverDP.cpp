#include <iostream>
#include <vector>
#include <memory>



class IObservers
{
public:
    IObservers()
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
    virtual ~IObservers()
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
    virtual void updateObservers_(const std::string& obj) = 0;
    virtual int getID_() const = 0;
};

class ISubjects
{
public:
    ISubjects()
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
    virtual ~ISubjects()
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
    virtual void attachObserver_(std::unique_ptr<IObservers> obj) = 0;
    virtual void detachObserver_(int id) = 0;
    virtual void ntifyObserver_() = 0;

};
class CObservers : public IObservers
{
public:
    CObservers(const std::string& str, int id)
        :_mName(str)
        , _mID(id)
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
    virtual ~CObservers()
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
    void updateObservers_(const std::string& obj)
    {
        std::cout << _mName << " is updated regarding" << obj << std::endl;
    }
    int getID_() const
    {
        return _mID;
    }
private:
    std::string _mName;
    int _mID;
};

class CAmazon : public ISubjects
{
public:
    CAmazon()
        :vObj()
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
    ~CAmazon()
    {
        std::cout << __FUNCTION__ << " executes\n";
    }
    void attachObserver_(std::unique_ptr<IObservers> obj)
    {
        vObj.push_back(std::move(obj));
    }
    void detachObserver_(int id)
    {
        for (auto it = vObj.begin(); it != vObj.end();)
        {
            if ((*it)->getID_() == id)
            {
                vObj.erase(it);
                break;
            }
            else {
                ++it;
            }
        }
    }
    void ntifyObserver_()
    {
        for (auto& tmp : vObj)
        {
            tmp->updateObservers_("Big billion day on 25 Sep");
        }
    }
private:
    std::vector<std::unique_ptr<IObservers>>vObj;
};


void funcToCreateObserverDP_()
{
    std::unique_ptr<CAmazon>aObj(new CAmazon());
    aObj->attachObserver_(std::make_unique<CObservers>("A", 100));
    aObj->attachObserver_(std::make_unique<CObservers>("B", 200));
    aObj->attachObserver_(std::make_unique<CObservers>("C", 300));
    aObj->attachObserver_(std::make_unique<CObservers>("D", 400));
    aObj->attachObserver_(std::make_unique<CObservers>("E", 500));
    aObj->ntifyObserver_();
    aObj->detachObserver_(300);
    aObj->ntifyObserver_();
   


}
/*
#include <iostream>
#include <memory>
#include <vector>
class IObserver;
class ISubject
{
public:
    ISubject()
    {
        std::cout << __FUNCTION__ << "\n";
    }
    virtual ~ISubject()
    {
        std::cout << __FUNCTION__ << "\n";
    }
    virtual void attachObserver_(std::shared_ptr<IObserver> obj) = 0;
    virtual void detachObserver_(std::shared_ptr<IObserver> obj) = 0;
    virtual void notifyObserver_() = 0;

};

class IObserver
{
public:
    IObserver() {
        std::cout << __FUNCTION__ << "\n";
    }
    virtual ~IObserver() {
        std::cout << __FUNCTION__ << "\n";
    }
    virtual void updateInfo_(const std::string& str) = 0;
};

class CAmaozon :public ISubject
{
public:
    CAmaozon()
    {
        std::cout << __FUNCTION__ << "\n";
    }
    virtual ~CAmaozon()
    {
        std::cout << __FUNCTION__ << "\n";
    }
    void attachObserver_(std::shared_ptr<IObserver> obj)
    {
        vObj.push_back(obj);
    }

    void detachObserver_(std::shared_ptr<IObserver> obj)
    {
        for (auto tmp = vObj.begin(); tmp != vObj.end();)
        {
            if (obj == tmp->lock())
            {
                tmp = vObj.erase(tmp);
            }
            else
            {
                tmp++;
            }
        }
         
    }
    void notifyObserver_()
    {
        for (auto& tmpW : vObj)
        {
            if (auto tmp = tmpW.lock())
            {  // Convert weak_ptr to shared_ptr
                tmp->updateInfo_("big billion day\n");
            }
        }
    }
private:
    std::vector<std::weak_ptr<IObserver> > vObj;

};

class CObserver : public IObserver
{
public:
    CObserver(const std::string str)
        :_mSTR(str) {
        std::cout << __FUNCTION__ << "\n";
    }
    virtual ~CObserver() {
        std::cout << __FUNCTION__ << "\n";
    }
    void updateInfo_(const std::string& str)
    {
        std::cout << _mSTR << "update about " << str;
    }
private:
    std::string _mSTR;
};

int main()
{
    std::shared_ptr<IObserver>sObj1(new CObserver("A"));
    std::shared_ptr<IObserver>sObj2(new CObserver("B"));
    std::shared_ptr<IObserver>sObj3(new CObserver("C"));
    std::shared_ptr<IObserver>sObj4(new CObserver("D"));
    std::unique_ptr<ISubject>subj1(new CAmaozon());
    subj1->attachObserver_(sObj1);
    subj1->attachObserver_(sObj2);
    subj1->attachObserver_(sObj3);
    subj1->attachObserver_(sObj4);
    subj1->notifyObserver_();
    subj1->detachObserver_(sObj1);
    subj1->notifyObserver_();
    return 0;
}*/