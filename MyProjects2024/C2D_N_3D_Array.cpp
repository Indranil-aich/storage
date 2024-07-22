#include "CommonHeader.h"


#define X1 2
#define Y1 3
#define Z1 2

void funcToCreate2D_N_3D_dynamicArry_()
{

	int** array2D = new int* [X1];
	for (int i = 0; i < X1; i++)
	{
		array2D[i] = new int[Y1];
		for (int j = 0; j < Y1; j++)
		{
			array2D[i][j] = (i * Y1 + j + 1);
		}
	}

	for (int i = 0; i < X1; i++)
	{

		for (int j = 0; j < Y1; j++)
		{
			std::cout << array2D[i][j] << " ";
		}
		std::cout << "\n";
	}

	for (int i = 0; i < X1; i++)
	{
		delete[] array2D[i];
	}

	int* array1D = new int[X1 * Y1];
	for (int i = 0; i < X1; i++)
	{
		for (int j = 0; j < Y1; j++)
		{
			array1D[i * Y1 + j] = (i * Y1 + j + 1);
		}
	}

	for (int i = 0; i < X1; i++)
	{
		for (int j = 0; j < Y1; j++)
		{
			std::cout << array1D[i * Y1 + j] << " ";
		}
		std::cout << "\n";
	}

	delete[] array1D;
	std::cout << __FUNCTION__ << " execute at line no" << __LINE__ << std::endl;

	std::cout << "end " << __FUNCTION__ << std::endl;

}

