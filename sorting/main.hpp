#ifndef MAIN_HPP
# define MAIN_HPP

# define COLOR_RED "\e[0;31m"
# define COLOR_GREEN "\e[0;32m"
# define COLOR_BLUE "\e[0;34m"
# define COLOR_WHITE "\e[0;37m"
# define COLOR_CYEN "\e[0;36m"
# define COLOR_YELLOW "\e[0;33m"
# define COLOR_RESET "\e[0m"

# include <iostream>
# include <cstdlib>

void	printArray(std::string name, int *array, size_t &size, std::string color);
void	bubbleSort(int *array, size_t &size);
void	insertionSort(int *array, size_t &size);
void	selectionSort(int *array, size_t &size);
void	quickSort(int *array, size_t &size);

#endif