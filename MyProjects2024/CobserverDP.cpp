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