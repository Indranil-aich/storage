#include <iostream>
#include <memory>

class CDogs
{
public:
    CDogs(const std::string& str)
        :_mStr(str) {
        std::cout << __FUNCTION__ << " execute\n";
    }
    virtual ~CDogs()
    {
        std::cout << __FUNCTION__ << " execute\n";
    }
    void bark_()
    {
        std::cout << __FUNCTION__ << " execute\n";
    }
private:
    std::string _mStr;
};

class CTrainer
{
public:
    CTrainer(const std::string& str)
        :_mStr(str)
    {
        std::cout << __FUNCTION__ << " execute\n";
    }
    virtual ~CTrainer()
    {
        std::cout << __FUNCTION__ << " execute\n";
    }
    void trainDogs_(const std::shared_ptr<CDogs>& dogs)
    {
        std::cout << __FUNCTION__ << " execute\n";
        _wDogs = dogs;
    }
    void commandDogs_()
    {
        if (auto dog = _wDogs.lock())
        {
            dog->bark_();
        }
        else {
            std::cout << "dog not available";
        }
    }
private:
    std::weak_ptr<CDogs>_wDogs;
    std::string _mStr;
};

void functionToWeakPTR()
{
    std::shared_ptr<CDogs> dogs = std::make_shared<CDogs>("D");
    CTrainer tObj("A");
    tObj.trainDogs_(dogs);
    tObj.commandDogs_();
    dogs.reset();
    tObj.commandDogs_();
   
}