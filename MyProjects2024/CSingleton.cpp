#include "CommonHeader.h"
#include <thread>
#include <mutex>

std::mutex mutx;
class CSingleton
{
public:
	static CSingleton& getInstance_()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
		static CSingleton _mObj;
		return _mObj;
	}
	void addToLogMsg_(const std::string& msg)
	{
		mutx.lock();
		_mMsg +=  msg +"\n";
		mutx.unlock();
	}
	std::string getLogMsg_() const
	{
		return _mMsg;
	}
private:
	std::string _mMsg;
	CSingleton()
		:_mMsg() {
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
	~CSingleton()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
	CSingleton(const CSingleton&) = delete;
	CSingleton& operator=(const CSingleton&) = delete;

};

void createLogMsg1_(int i)
{
	CSingleton& obj = CSingleton::getInstance_();
	for (int i = 0; i < 5; i++)
	{
		std::string str = "\t\tThis is for th1";
		obj.addToLogMsg_(str);
	}
}

void createLogMsg2_(int i)
{
	CSingleton& obj = CSingleton::getInstance_();
	for (int i = 0; i < 5; i++)
	{
		std::string str = "\t\tThis is for th2";
		obj.addToLogMsg_(str);
	}
}
void funcToSingletonObj_()
{
	std::thread th1(createLogMsg1_, 1);
	std::thread th2(createLogMsg2_, 2);
	th1.join();
	th2.join();
	std::cout << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
	CSingleton& obj = CSingleton::getInstance_();
	std::cout << "log Msg\n" << obj.getLogMsg_() << std::endl;
	std::cout << "end " << __FUNCTION__ << std::endl;
}