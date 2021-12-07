#include "main.hpp"

void	insertionSortInfo(void)
{
	std::cout << COLOR_YELLOW << "{ "<< COLOR_GREEN << "Insertion Sort" << COLOR_YELLOW << " }" << std::endl;
	std::cout << "is a simple sorting algorithm that works "
				<< "similar to the way you sort playing cards in your hands."
				<< "The array is virtually split into a sorted and an unsorted part. "
				<< "Values from the unsorted part are picked and placed at the correct position in the sorted part."
				<< std::endl << std::endl;
	std::cout << "Worst and Average Case Time: O(n*n) - when array is reverse sorted" << std::endl
					<< "Best Case Time: O(n) - when array is already sorted"
					<< COLOR_RESET << std::endl << std::endl;
}	

void	insertionSort(int *array, size_t &size)
{
	insertionSortInfo();
	printArray("Source Array", array, size, COLOR_CYEN);
	for (size_t i = 1; i < size; i++)
	{
		int current = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > current)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = current;
	}
	printArray("Sorted Array", array, size, COLOR_GREEN);
}