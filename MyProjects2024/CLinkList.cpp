#include <iostream>

class CmyLink
{
private:
	int _mData;
public:
	CmyLink* _mNN;
public:
	CmyLink(int data)
		:_mData(data)
		, _mNN(nullptr)
	{}
	CmyLink* createMyList_(CmyLink* nodeObj, int data)
	{
		if (nodeObj == nullptr)
		{
			nodeObj = new CmyLink(data);
		}
		else 
		{
			CmyLink* tmpObj = nodeObj;
			while (tmpObj->_mNN != nullptr)
			{
				tmpObj = tmpObj->_mNN;
			}
			tmpObj->_mNN = new CmyLink(data);
		}
		return nodeObj;
	}
	void display_(CmyLink* nodeObj)
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl<<"\t";
		while (nodeObj != nullptr)
		{
			std::cout << " " << nodeObj->_mData;
			nodeObj = nodeObj->_mNN;
		}
	}
	
	void display3rd_(CmyLink* nodeObj)
	{
		std::cout << "\n\tFunction name" << __FUNCTION__ << std::endl << "\t";
		while (nodeObj->_mNN->_mNN->_mNN != nullptr)
		{
			nodeObj = nodeObj->_mNN;
		}
		std::cout << "display3rd_ from last" << nodeObj->_mData<<"\n";
	}
	//Floyd’s Cycle detection algorithm
	void isLoop_(CmyLink* head)
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl << "\t";
		CmyLink* fastPTR = head;
		CmyLink* slowPTR = head;
		bool  flag = false;
		while (fastPTR != nullptr && fastPTR->_mNN != nullptr)
		{
			fastPTR = fastPTR->_mNN->_mNN;
			slowPTR = slowPTR->_mNN;
			if (fastPTR == slowPTR)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			std::cout << "\n\tloop detected" << std::endl;
		}
		else {
			std::cout << "\n\tloop detected" << std::endl;
		}
	}


	int countNodes(struct Node* n)
	{

	}


	void printMiddleOfList_(CmyLink* head)
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl << "\t";
		CmyLink* fastPTR = head;
		CmyLink* slowPTR = head;
		while (fastPTR != nullptr && fastPTR->_mNN != nullptr)
		{
			fastPTR = fastPTR->_mNN->_mNN;
			slowPTR = slowPTR->_mNN;
		}
		std::cout << "middle of the list" <<slowPTR->_mData << std::endl;



	}
	~CmyLink()
	{
		if (_mNN != nullptr)
		{
			std::cout << " " << _mData;
			CmyLink* tmp = _mNN;

			_mNN = tmp->_mNN;
			delete tmp;
			tmp = nullptr;
		}
	}
	CmyLink* reverseMyLink_(CmyLink* nodeObj)
	{
		std::cout << "\tFunction name" << __FUNCTION__ << std::endl << "\t";
		CmyLink* pre_node = nullptr;
		CmyLink* cur_node = nodeObj;
		CmyLink* next_node = cur_node->_mNN;
		cur_node->_mNN = pre_node;
		while (next_node != nullptr)
		{
			
			pre_node = cur_node;
			cur_node = next_node;
			next_node = cur_node->_mNN;
			cur_node->_mNN = pre_node;
			
		}
		return cur_node;
	}
};


void funcToCreateLinkList_()
{
	CmyLink* nObj = new CmyLink(10);
	CmyLink* tmpObj = nObj->createMyList_(nObj, 20);
	tmpObj = nObj->createMyList_(nObj, 30);
	tmpObj = nObj->createMyList_(nObj, 40);
	tmpObj = nObj->createMyList_(nObj, 50);
	std::cout << "==========display=============" << std::endl;
	nObj->display_(nObj);
	nObj->display3rd_(nObj);
	nObj->printMiddleOfList_(nObj);
	nObj = nObj->reverseMyLink_(nObj);
	nObj->display_(nObj);
	tmpObj->_mNN = nObj;
	nObj->isLoop_(nObj);
		
}

