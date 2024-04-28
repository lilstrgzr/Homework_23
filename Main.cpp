#include <ctime>
#include <iostream>


template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}


void swap(int& var, int& var1, int& var2) {
	if (var > var1 && var > var2) {
		var1 = var;
		var2 = var;
		return;
	}
	if (var1 > var && var1 > var2) {
		var = var1;
		var2 = var1;
		return;
	}
	var = var2;
	var1 = var2;
}

template <typename T>
int first_negative(T& arr, const int& lenght, int& var = 0) {
	var = 1;
	for (int i = 0; i < lenght; i++) {
		if (*(arr + i) < 0)
			return var = *(arr + i);
	}
}

template <typename T>
void arrs(T arr2, const int size2, T arr3, const int size3) {
	for (int i = 0; i < size2; i++)
		for (int j = 0; j < size3; j++)
			if (*(arr2 + i) == *(arr3 + j))
				*(arr3 + j) = 0;

}

int main() {
	setlocale(LC_ALL, "Russian");
	int num, num1, num2;

	std::cout << "Задача 1\nВведите три числа -> ";
	std::cin >> num >> num1 >> num2;
	swap(num, num1, num2);
	std::cout  << num << ", " << num1 << ", " << num2 << std::endl;

	std::cout << "Задача 2\n";
	int var;
	const int size1 = 10;
	int arr1[size1];

	fill_arr(arr1, size1, -10, 10);
	print_arr(arr1, size1);
	first_negative(arr1, size1, var);
	std::cout << var << std::endl;


	std::cout << "Задача 3\n";
	const int size2 = 7;
	int arr2[size2]{ 3, 6, 4, 1, 4, 8, 2 };
	const int size3 = 6;
	int arr3[size3]{ 5, 3, 1, 5, 10, 8 };

	std::cout << "Первый Массив: ";
	print_arr(arr2, size2);
	

	std::cout << "Второй Массив: ";
	print_arr(arr3, size3);

	std::cout << "Изменённый массив: ";
	arrs(arr2, size2, arr3, size3);
	print_arr(arr3, size3);


	return 0;
}

