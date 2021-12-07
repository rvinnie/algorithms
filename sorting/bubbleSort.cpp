#include "main.hpp"

void	bubbleSortInfo(void)
{
	std::cout << COLOR_YELLOW << "{ "<< COLOR_GREEN << "Bubble Sort" << COLOR_YELLOW << " }" << std::endl;
	std::cout << "is the simplest sorting algorithm that works by repeatedly "
				<< "swapping the adjacent elements if they are in wrong order." << std::endl << std::endl;
	std::cout << "Worst and Average Case Time: O(n*n) - when array is reverse sorted" << std::endl
				<< "Best Case Time: O(n) - when array is already sorted"
				<< COLOR_RESET << std::endl << std::endl;
}	

void	bubbleSort(int *array, size_t &size)
{
	bubbleSortInfo();
	printArray("Source Array", array, size, COLOR_CYEN);
	for (size_t i = 0; i < size - 1; i++)
	{
		bool swapped = false;
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int	tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
	printArray("Sorted Array", array, size, COLOR_GREEN);
}