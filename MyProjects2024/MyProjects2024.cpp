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
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define IS_DIR_VALID(st) (((st).st_mode & S_IFDIR) == S_IFDIR)

int main() {
    struct stat statbuf;
    const char *path ="F:\\Storage-Domain\\posix_code";

    // Get the status of the file or directory
    if (stat(path, &statbuf) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    // Check if the path is a directory
    if (IS_DIR_VALID(statbuf)) {
        printf("%s is a directory.\n", path);
    } else {
        printf("%s is not a directory.\n", path);
    }

    return 0;
}
*/


/*
void detachObsever_(int _mID)
{
    for (auto it = vObj.begin(); it != vObj.end();)
    {
        if ((*it)->getID_() == _mID)
        {
            vObj.erase(it);
        }
        else {
            it++;
        }
    }
}*/

/*
* #include <iostream>
int *f()
{
    int *x = new int[5];
    return x;
}


int main()
{
  int *fp=f();
  std::cout<<"exec"<<*fp<<std::endl;
  return 0;
}

*/