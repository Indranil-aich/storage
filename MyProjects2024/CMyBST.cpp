#include <iostream>
#include <vector>

// #1 createBST
// #2 InOrderR
// #3 InOrderI
// #4 preOrderR
// #5 postOrderR
// #6 findMin
// #7 mirrorTree
// #8 mirrorTree
// #9 BST2DLL



class CmyBST
{
private:
    int _mdata;
    CmyBST* left_node;
    CmyBST* right_node;
public:
    CmyBST(int data)
        :_mdata(data)
        , left_node(nullptr)
        , right_node(nullptr) {}
    CmyBST* createBST_(CmyBST* rootBST, int info);
    void inOrderR_(CmyBST* rootBST);
    void inOrderI_(CmyBST* rootBST, CmyBST** head );
    void inOrderI_(CmyBST* rootBST);
    void preOrderR_(CmyBST* rootBST);
    void postOrderR_(CmyBST* rootBST);
    CmyBST* covertToMirror(CmyBST* rootBST);
    void findMin_(CmyBST* rootBST)
    {
        int min1, min2;
        while (rootBST->left_node != nullptr)
        {
            min2 = rootBST->_mdata;
            rootBST = rootBST->left_node;
            min1 = rootBST->_mdata;
            if (rootBST->left_node == nullptr && rootBST->right_node != nullptr)
            {
                min2 = rootBST->right_node->_mdata;
            }
        }
        std::cout << "\n min1:: " << min1 << " min2:: " << min2 << std::endl;
    }
    void displayDLL(CmyBST* headDLL)
    {
       
    }

};

CmyBST* CmyBST::covertToMirror(CmyBST* bstRoot)
{
    if (bstRoot != nullptr)
    {
        CmyBST* tmp = bstRoot->left_node;
        bstRoot->left_node = bstRoot->right_node;
        bstRoot->right_node = tmp;
        covertToMirror(bstRoot->left_node);
        covertToMirror(bstRoot->right_node);
    }
    return bstRoot;
}

CmyBST* CmyBST::createBST_(CmyBST* rootBST, int data)
{
    if (rootBST == nullptr)
    {
        rootBST = new CmyBST(data);
     }
    else if (data < rootBST->_mdata)
    {
        rootBST->left_node = createBST_(rootBST->left_node, data);
    }
    else if (data > rootBST->_mdata)
    {
        rootBST->right_node = createBST_(rootBST->right_node, data);
    }
    else {      
    }
    return rootBST;
}

void CmyBST::inOrderI_(CmyBST* rootBST)
{
    CmyBST* cur = rootBST;
    CmyBST* pre = nullptr;
    std::vector<CmyBST*>queue;
    while (cur != nullptr || !queue.empty())
    {
        while (cur != nullptr)
        {
            queue.push_back(cur);
            cur = cur->left_node;
        }
        cur = queue.back();
        queue.pop_back();
        std::cout << " " << cur->_mdata;
        cur = cur->right_node;
    }

}
void CmyBST::inOrderR_(CmyBST* rootBST)
{
    if (rootBST != nullptr)
    {
        inOrderR_(rootBST->left_node);
        std::cout << " " << rootBST->_mdata;
        inOrderR_(rootBST->right_node);

    }
}

void CmyBST::inOrderI_(CmyBST* rootBST, CmyBST** head)
{
   
}


void CmyBST::preOrderR_(CmyBST* rootBST)
{
    if (rootBST != nullptr)
    {
        std::cout << " " << rootBST->_mdata;
        preOrderR_(rootBST->left_node);
        preOrderR_(rootBST->right_node);

    }
}


void CmyBST::postOrderR_(CmyBST* rootBST)
{
    if (rootBST != nullptr)
    {
        
        postOrderR_(rootBST->left_node);
        postOrderR_(rootBST->right_node);
        std::cout << " " << rootBST->_mdata;

    }
}


void funcToCreateBST_()
{
    CmyBST* bstRoot = new CmyBST(60);
    CmyBST* head = nullptr;
    bstRoot->createBST_(bstRoot, 50);
    bstRoot->createBST_(bstRoot, 70);
    bstRoot->createBST_(bstRoot, 45);
    bstRoot->createBST_(bstRoot, 55);
    bstRoot->createBST_(bstRoot, 65);
    bstRoot->createBST_(bstRoot, 75);
    bstRoot->findMin_(bstRoot);
    std::cout << "=== inOrderI=====\n";
    bstRoot->inOrderI_(bstRoot);
    bstRoot = bstRoot->covertToMirror(bstRoot);
    std::cout << "=== inOrderR=====\n";
    bstRoot->inOrderR_(bstRoot);
    std::cout << "\n=== preOrderR=====\n";
    bstRoot->preOrderR_(bstRoot);
    std::cout << "\n=== postOrderR=====\n";
    bstRoot->postOrderR_(bstRoot);
    std::cout << "\n=== inOrderI=====\n";
    //bstRoot->inOrderI_(bstRoot, &head);
    //std::cout << "\n DLL\n";
    //bstRoot->displayDLL(head);*/
    //return 0;
}

