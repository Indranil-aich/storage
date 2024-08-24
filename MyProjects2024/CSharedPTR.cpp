#include "commonHeader.h"


template <typename T>
class CSharedPTR
{
private:
	T* _mPTR;
	int *_mRefCount;
public:
	CSharedPTR(T* ptr)
		:_mPTR(ptr)
		,_mRefCount(new int(1))
	{

	}
	int getRefCount_() const
	{
		return *_mRefCount;
	}
	CSharedPTR(const CSharedPTR& Obj)   noexcept                      // move constructor
	{
		std::cout << "\t" << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
		_mPTR = Obj._mPTR;
		_mRefCount = Obj._mRefCount;
		(*_mRefCount)++;
		

	}
	CSharedPTR& operator=(const CSharedPTR& Obj) noexcept            // move assignment
	{
		if (this != &Obj)
		{
			std::cout << "\t" << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
			__clean_up__();
			_mPTR = Obj._mPTR;
			_mRefCount = Obj._mPTR;
			(*_mRefCount)++;
		
		}
		return *this;
	}

	virtual ~CSharedPTR()
	{
		std::cout << "\t" << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
		__clean_up__();
	}
	CSharedPTR(CSharedPTR&& Obj) = delete;
	CSharedPTR& operator=(CSharedPTR&& Obj) = delete;

	T* operator->()
	{
		std::cout << "\t" << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
		return _mPTR;
	}
	T& operator*()
	{
		std::cout << "\t" << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
		return *(_mPTR);
	}
private:
	void __clean_up__()
	{
		(*_mRefCount)--;
		if (_mPTR != nullptr && (*_mRefCount) == 0)
		{
			delete _mPTR;
			_mPTR = nullptr;
	
		}
	;
	}
	
};
void funToCreateSharedPTR_()
{
	std::cout << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
	CSharedPTR<int> obj1(new int(10));
	CSharedPTR<int> obj2 = obj1;
	*obj2 = 100;
	

	std::cout << "\t Ref of shared Obj  "<<obj1.getRefCount_()<<" value of obj1 is " << *obj1 << std::endl;
	std::cout << "end " << __FUNCTION__ << std::endl;
}

/*
#include <iostream>
#include <memory>

class Dog {
public:
	Dog(const std::string& name) : name_(name) {}
	void Bark() const { std::cout << name_ << " says woof!" << std::endl; }
private:
	std::string name_;
};

class Trainer {
public:
	Trainer(const std::string& name) : name_(name) {}
	void TrainDog(const std::shared_ptr<Dog>& dog) {
		dog_ = dog; // Store a shared_ptr to the dog
	}
	void CommandDog() const {
		if (auto dog = dog_.lock()) { // Try to get a shared_ptr from weak_ptr
			dog->Bark(); // Command the dog to bark
		} else {
			std::cout << "The dog is no longer available for training." << std::endl;
		}
	}
private:
	std::weak_ptr<Dog> dog_; // Weak pointer to the dog
	std::string name_;
};

int main() {
	// Create a shared_ptr for a dog
	std::shared_ptr<Dog> dog = std::make_shared<Dog>("Rex");

	// Create a Trainer and train the dog
	Trainer trainer("John");
	trainer.TrainDog(dog);

	// Command the dog to bark
	trainer.CommandDog(); // Output: Rex says woof!

	// Reset the original shared_ptr
	dog.reset();

	// Try to command the dog again
	trainer.CommandDog(); // Output: The dog is no longer available for training.

	return 0;
}


shared_ptr: Manages the Dog object’s lifetime and ensures it stays alive as long as at least one shared_ptr references it.
weak_ptr: Used by Trainer to observe the Dog without affecting its reference count or ownership. It allows the Trainer to check if the Dog still exists.
Object Lifetime: The Dog is destroyed when the last shared_ptr is reset or goes out of scope, which is why after resetting dog, the Trainer cannot access it anymore.
*/