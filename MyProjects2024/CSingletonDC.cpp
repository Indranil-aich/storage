#include "CommonHeader.h"
#include <thread>
#include <mutex>


class CDCSingleton
{
public:
	static CDCSingleton* getInstance_()
	{
		if (_mObj == nullptr)
		{
			_mMutx.lock();
			if (_mObj == nullptr)
			{
				_mObj = new CDCSingleton();
				atexit(__clean__);

			}
			_mMutx.unlock();
				
		}
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
		return _mObj;
	}
	void addToLogMsg_(const std::string& msg)
	{
		mutx.lock();
		_mMsg += msg + "\n";
		mutx.unlock();
	}
	std::string getLogMsg_() const
	{
		return _mMsg;
	}
	static CDCSingleton* _mObj;
	static std::mutex _mMutx;
private:
	static void __clean__()
	{
		delete _mObj;
	}
	std::string _mMsg;
	std::mutex mutx;
	CDCSingleton()
		:_mMsg() {
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
	~CDCSingleton()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
	CDCSingleton(const CDCSingleton&) = delete;
	CDCSingleton& operator=(const CDCSingleton&) = delete;

};

CDCSingleton*  CDCSingleton::_mObj = nullptr;
std::mutex CDCSingleton::_mMutx ;

void createLogMsgDC1_(int i)
{
	CDCSingleton* obj = CDCSingleton::getInstance_();
	for (int i = 0; i < 5; i++)
	{
		std::string str = "\t\tThis is for th1";
		obj->addToLogMsg_(str);
	}
}

void createLogMsgDC2_(int i)
{
	CDCSingleton* obj = CDCSingleton::getInstance_();
	for (int i = 0; i < 5; i++)
	{
		std::string str = "\t\tThis is for th2";
		obj->addToLogMsg_(str);
	}
}
void funcToCreateDCSingletonObj_()
{
	std::thread th1(createLogMsgDC1_, 1);
	std::thread th2(createLogMsgDC2_, 2);
	th1.join();
	th2.join();
	std::cout << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
	CDCSingleton* obj = CDCSingleton::getInstance_();
	std::cout << "log Msg\n" << obj->getLogMsg_() << std::endl;
	std::cout << "end " << __FUNCTION__ << std::endl;
}