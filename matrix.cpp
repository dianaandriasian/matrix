////////////////////////////////////////
/// 7
/// 


#include <iostream>


void fillMatrix(int (*)[3], int);
void printMainDiagonal(int (*)[3], int);
void printMinorDiagonal(int (*)[3], int);
void mainPlusMinor(int (*)[3], int);
void swapMainMinor(int (*)[3], int);
void printMatrix(int (*)[3], int);
void matrixToArray(int (*)[3], int*, int);
void printArray(int*, int);

int main()
{
	const int size = 3;
	int matrix[size][size] = {};
	int array[size * size];

	std::cout << "Fill the matrix : " << std::endl << std::endl;
	fillMatrix(matrix, size);

	std::cout << "Main diagonal of matrix : " << std::endl << std::endl;
	printMainDiagonal(matrix, size);

	std::cout << "Minor diagonal of matrix : " << std::endl << std::endl;
	printMinorDiagonal(matrix, size);

	std::cout << "Main + Minor : " << std::endl << std::endl;
	mainPlusMinor(matrix, size);

	std::cout << "Swap diagonals : " << std::endl << std::endl;
	swapMainMinor(matrix, size);
	printMatrix(matrix, size);

	std::cout << "Matrix to array : " << std::endl << std::endl;
	matrixToArray(matrix, array, size);
	printArray(array, size * size);

	swapMainMinor(matrix, size);
	matrixToArray(matrix, array, size);
	printArray(array, size * size);

	return 0;
}

void fillMatrix(int(*matrix)[3], int size)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << "matrix[" << i << "][" << j << "] = ";
			std::cin >> matrix[i][j];
		}
		std::cout << std::endl;
	}
}


void printMainDiagonal(int (*matrix)[3], int size)
{
	for (int i = 0; i < size; ++i) {
		std::cout << "matrix[" << i << "][" << i << "] = " << matrix[i][i] << std::endl;
	}

	std::cout << std::endl;
}

void printMinorDiagonal(int (*matrix)[3], int size)
{
	for (int i = 0; i < size; ++i) {
		std::cout << "matrix[" << i << "][" << (size - 1 - i) << "] = " << matrix[i][size - 1 - i] << std::endl;
	}

	std::cout << std::endl;
}

void mainPlusMinor(int(*matrix)[3], int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << "matrix[" << i << "][" << i << "] + matrix[" << i << "][" << (size - 1 - i) << "] = " 
			      <<  matrix[i][i] + matrix[i][size - 1 - i] << std::endl;
	}

	std::cout << std::endl;
}

void swapMainMinor(int(*matrix)[3], int size)
{
	for (int i = 0; i < size; ++i) {
		if (i != (size - i - 1)) {

			matrix[i][i] = matrix[i][i] + matrix[i][size - 1 - i];
			matrix[i][size - 1 - i] = matrix[i][i] - matrix[i][size - 1 - i];
			matrix[i][i] = matrix[i][i] - matrix[i][size - 1 - i];

		}

	}
}

void printMatrix(int(*matrix)[3], int size)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << "matrix[" << i << "][" << j << "] = " << matrix[i][j] << std::endl;
		}

		std::cout << std::endl;
	}
}

void matrixToArray(int(*matrix)[3], int* array, int size)
{
	int k = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			array[k] = matrix[i][j];
			++k;
		}
	}
}

void printArray(int* array, int size)
{
	for (int i = 0; i < size; ++i) {
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}

	std::cout << std::endl;
}










