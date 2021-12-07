#include "main.hpp"

void	quickSortInfo(void)
{
	std::cout << COLOR_YELLOW << "{ "<< COLOR_GREEN << "Quick Sort" << COLOR_YELLOW << " }" << std::endl;
	std::cout << "It picks an element as pivot and partitions the given array around the picked pivot." 
				<< std::endl << std::endl;
	std::cout << "Worst and Average Case Time: O(n*n)" << std::endl
					<< "Best Case Time: O(nLogn)"
					<< COLOR_RESET << std::endl << std::endl;
}	

int	partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	
	for (int j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			int tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
		}
	}
	i++;
	array[high] = array[i];
	array[i] = pivot;
	return (i);
}

void	launchSort(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);

		launchSort(array, low, pi - 1);
		launchSort(array, pi + 1, high);
	}
}

void	quickSort(int *array, size_t &size)
{
	quickSortInfo();
	printArray("Source Array", array, size, COLOR_CYEN);
	launchSort(array, 0, size - 1);
	printArray("Sorted Array", array, size, COLOR_GREEN);
}