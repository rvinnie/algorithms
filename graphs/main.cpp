#include <iostream>
#include <climits>

# define COLOR_GREEN "\e[0;32m"
# define COLOR_BLUE "\e[0;34m"
# define COLOR_WHITE "\e[0;37m"
# define COLOR_CYEN "\e[0;36m"
# define COLOR_YELLOW "\e[0;33m"
# define COLOR_RESET "\e[0m"

using namespace std;

const int size = 8;

void print_info(int begin, int end) {
	cout << COLOR_YELLOW << "Лабораторная работа №1 (Вариант - 5)" << endl
		<< "Задача: поиск кратчайшего пути от " << COLOR_CYEN << begin
		<< COLOR_YELLOW << " до " << COLOR_CYEN << end << COLOR_YELLOW
		<< endl << "вершины в ориентированном взвешенном графе." << COLOR_RESET << endl << endl;
}

int main() {
	int begin_index = 0; // начальный индекс
	int end_index = size - 1; // конечный индекс
	int minindex, min, current;
	int graph[size][size] = { // матрица связей
		{0, 3, 0, 5, 0, 0, 0, 0},
		{0, 0, 0, 2, 0, 0, 7, 0},
		{0, 3, 0, 0, 0, 9, 0, 0},
		{0, 0, 0, 0, 1, 5, 0, 0},
		{0, 0, 0, 0, 0, 8, 6, 0},
		{0, 0, 0, 0, 0, 0, 10, 0},
		{0, 0, 4, 0, 0, 0, 0, 4},
		{0, 0, 0, 0, 0, 12, 0, 0}
	};
	print_info(begin_index + 1, end_index + 1);
	cout << "Матрица связей исходного графа:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			printf("%3d", graph[i][j]);
		cout << endl;
	}
	int d[size]; // массив минимальных длин до каждой вершины
	bool in[size]; // массив посещенных вершин
	for (int i = 0; i < size; i++) {
		d[i] = INT_MAX;
		in[i] = false;
	}
	d[begin_index] = 0;
	do {
		minindex = INT_MAX;
		min = INT_MAX;
		for (int i = 0; i < size; i++) { // находим ребро с наименьшим весом 
			if (in[i] == false && d[i] < min) {
				min = d[i];
				minindex = i;
			}
		}
		if (minindex != INT_MAX) { // если такое ребро найдено то продолжаем
			for (int i = 0; i < size; i++) {
				if (graph[minindex][i] > 0) {
					current = graph[minindex][i] + min; // вес ребра + вес текущей вершины
					if (current < d[i])
						d[i] = current;
				}
			}
			in[minindex] = true; // фиксируем, что посетили вершину
		}
	} while (minindex != INT_MAX);
	cout << endl;
	cout << "Кратчайший путь от 1 до 8 вершины - " << COLOR_GREEN << d[end_index] << COLOR_RESET << endl;
	int path[size]; // путь от begin_index до end_index
	int k = 0;
	path[k++] = end_index + 1;
	int weight = d[end_index]; // текущий вес вершины
	while (end_index != begin_index) {
		for (int i = 0; i < size; i++) {
			if (graph[i][end_index] > 0) {
				current = weight - graph[i][end_index];
				if (current == d[i]) { // если вес вершины совпал с разностью весов прошлой вершины и ребра
					weight = d[i];
					end_index = i;
					path[k++] = end_index + 1;
				}
			}
		}
	}
	cout << "Путь: " << COLOR_GREEN;
	for (int i = k - 1; i >= 0; i--) {
		if (i == k - 1 || i == 0)
			cout << COLOR_CYEN;
		cout << path[i] << COLOR_GREEN << " ";
	}
	cout << COLOR_RESET << endl;
	return (0);
}