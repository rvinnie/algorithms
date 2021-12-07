#include "main.hpp"

using namespace std;

void	printArray(string name, int *array, size_t &size, string color)
{
	if (!array)
	{ 
		cout << COLOR_RED << "Empty array to print" << COLOR_RESET << endl;
		return ;
	}
	cout << name << ":	";
	for (size_t i = 0; i < size; i++)
		cout << color << array[i] << " ";
	cout << COLOR_RESET << endl;
}

void	stopProgram()
{
	cout << "press any button..." << endl;
	getchar();
}

int main(int argc, char *argv[])
{
	int		array[10] = {1, 4, 0, 16, -7, 8, 9, 2, 24, 5};
	size_t	size = sizeof(array) / sizeof(int);
	short	param;

	if (argc == 2)
		param = atoi(argv[1]);
	if (argc != 2 || (*argv[1] != 'A' && (param < 1 || param > 5)))
	{
		cout << COLOR_RED << "Wrong argument" << endl;
		cout << "./sorting [parameter]" << endl
			<< "1 - Bubble Sort" << endl
			<< "2 - Insertion Sort" << endl
			<< "3 - Selection Sort" << endl
			<< "4 - Merge Sort" << endl
			<< "5 - Quick Sort" << endl
			<< "A - All" << COLOR_RESET << endl;
		return (1);
	}
	switch (param)
	{
	case 1:
		bubbleSort(array, size);
		break;
	case 2:
		insertionSort(array, size);
		break;
	case 3:
		selectionSort(array, size);
		break;
	case 4:
		cout << "Merge Sort" << endl;
		break;
	case 5:
		quickSort(array, size);
		break;
	default:
		bubbleSort(array, size);
		stopProgram();
		insertionSort(array, size);
		stopProgram();
		selectionSort(array, size);
		stopProgram();
		quickSort(array, size);
		break;
	}

	return (0);
}