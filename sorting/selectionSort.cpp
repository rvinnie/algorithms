#include "main.hpp"

void	selectionSortInfo(void)
{
	std::cout << COLOR_YELLOW << "{ "<< COLOR_GREEN << "Selection Sort" << COLOR_YELLOW << " }" << std::endl;
	std::cout << "sorts an array by repeatedly finding the minimum element " 
				<< "from unsorted part and putting it at the beginning."
				<< std::endl << std::endl;
	std::cout << "Time Complexity: O(n*n)" << std::endl
					<< "The good thing about selection sort is it never makes more than O(n) swaps"
					<< COLOR_RESET << std::endl << std::endl;
}	

void	selectionSort(int *array, size_t &size)
{
	selectionSortInfo();
	printArray("Source Array", array, size, COLOR_CYEN);
	for (size_t i = 0; i < size - 1; i++)
	{
		int min_idx = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		int tmp = array[i];
		array[i] = array[min_idx];
		array[min_idx] = tmp;
	}
	printArray("Sorted Array", array, size, COLOR_GREEN);
}