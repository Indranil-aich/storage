#include "CommonHeader.h"
/*****************************************************************
* vptr (Virtual Table Pointer):
	Points to the vtable.
	Used for dynamic dispatch of virtual functions.
	Present in every object with virtual functions.
	Size: 8 bytes on a 64-bit system.

vtable (Virtual Table):
	An array of function pointers.
	Contains pointers to the virtual functions of a class.
	Used by vptr to resolve function calls at runtime.
	Size depends on the number of virtual functions.

vbptr (Virtual Base Table Pointer):
	Points to the vbtable.
	Used to manage virtual inheritance.
	Ensures a single instance of the virtual base class is shared.
	Present in every object with virtual base classes.
	Size: 8 bytes on a 64-bit system.

************************************************************************
*  In the follwing example class B & class C derived virtuall from class A
*  and class D , derived from class B & class C. It means that all 
* 
*  Single Instance Management: vbptr ensures that there's only one instance of the virtual base class, 
                             even if multiple paths (via different derived classes) lead to it.

   Offset Management: vbptr points to a table known as the Virtual Base Table (vbtable). 
	                   This table contains the necessary offsets to correctly locate the shared virtual 
					   base class within the object's memory layout.
* 
***********************************************************************/

class A
{
public:
	A()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
	virtual void display_()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
	virtual ~A()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
};
class B :virtual public A
{
public:
	//int b;
	B()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
	virtual void display_()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
	virtual ~B()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
};
class C :virtual public A
{
public:
	//int c;
	C()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
	virtual void display_()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
	virtual ~C()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
};

class D :public B, public C
{
public:
	D()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
	virtual void display_()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
	virtual ~D()
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl;
	}
};

void diamondProblem_()
{
	std::cout << __FUNCTION__ << "execute at line no" << __LINE__ << std::endl;
	D* dObj = new D();
	A* aObj = new A();
	B* bObj = new B();
	C* cObj = new C();
	std::cout << "\t sizeOf(A)" << sizeof(A) << std::endl;  // size of A's vPTR = 8 bytes
	std::cout << "\t sizeOf(B)" << sizeof(B) << std::endl;  // size of A's vPTR = 8 bytes +  8 bytes sizeof(vbptr) (size of virtual base pointer).
	std::cout << "\t sizeOf(C)" << sizeof(C)<< std::endl;   // size of A's vPTR = 8 bytes +  8 bytes sizeof(vbptr) (size of virtual base pointer).
	std::cout << "\t sizeOf(D)" << sizeof(D) << std::endl;  // size of B + size of C -  size of A's vPTR =  16 + 16 -8 = 24
	std::cout << "end " << __FUNCTION__ << std::endl;
}