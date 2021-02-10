#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

void FillRand(int** arr, const int m, const int n);
void Print(int** arr, const int m, const int n);
int** Allocate(const int m, const int n);
void Clear(int** arr, const int m, const int n);
void push_row_back(int**& arr, int& m, int& n);
void push_row_front(int**& arr, int& m, int& n);
void push_by_index(int**& arr, int& m, int& n, const int index);
void push_col_back(int**& arr, int& m, int& n);
void push_col_front(int**& arr, int& m, int& n);
void insert_col(int**& arr, int& m, int& n, int index);
void pop_row_back(int**& arr, int& m, int& n);
void pop_row_front(int**& arr, int& m, int& n);
void pop_col_back(int**& arr, int& m, int& n);
void erase_row(int**& arr, int& m, const int n, int index);
void pop_col_front(int**& arr, int& m, int& n);
void erase_col(int**& arr, int& m, int& n, const int index);

int main()
{
	setlocale(LC_ALL, "Russian");
	system("color 0A");

	int m; // Кол-во строк
	int n; // Кол-во столбцов (элементов строки)

	cout << "Введите кол-во строк: "; cin >> m;
	cout << "Введите кол-во элементов строки: "; cin >> n;

	// 2.Выделяем память для строк двумерного динамического массива
	int** arr = Allocate(m, n);
	//srand(time(NULL));
	FillRand(arr, m, n);
	Print(arr, m, n);

	cout << endl;

	cout << "Добавление строки в конец" << endl;
	push_row_back(arr, m, n);
	Print(arr, m, n);
	cout << "Добавление строки в  начало" << endl;
	push_row_front(arr, m, n);
	Print(arr, m, n);
	int index;
	cout << "Добавление строки в по индексу: "; cin >> index;
	push_by_index(arr, m, n, index);
	Print(arr, m, n);
	cout << "Добавление столбика в конец" << endl;
	push_col_back(arr, m, n);
	Print(arr, m, n);
	cout << "Добавление столбика в начало" << endl;
	push_col_front(arr, m, n);
	Print(arr, m, n);
	cout << "Удаление строки в конце" << endl;
	pop_row_back(arr, m, n);
	Print(arr, m, n);
	cout << "Удаление строки в начале" << endl;
	pop_row_front(arr, m, n);
	Print(arr, m, n);
	cout << "Удаление столбика в конце" << endl;
	pop_col_back(arr, m, n);
	Print(arr, m, n);
	int index2;
	cout << "Удаление строки по индексу: "; cin >> index2;
	erase_row(arr, m, n, index2);
	Print(arr, m, n);
	cout << "Удаление столбика в начале" << endl;
	pop_col_front(arr, m, n);
	Print(arr, m, n);
	int index3;
	cout << "Добавление столбика по индексу: "; cin >> index3;
	insert_col(arr, m, n, index3);
	Print(arr, m, n);
	int index4;
	cout << "Удаление столбика по индексу: "; cin >> index4;
	erase_col(arr, m, n, index4);
	Print(arr, m, n);
}

void erase_col(int**& arr, int& m, int& n, const int index)
{
	--n;
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n];
		for (int j = 0; j <= n; j++)
		{
			if (j == index)
				continue;
			buffer[j > index ? j - 1 : j] = arr[i][j];
		}
		arr[i] = buffer;
	}

}

void insert_col(int**& arr, int& m, int& n, const int index)
{
	++n;
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n];
		for (int j = 0; j < n; j++)
		{
			if (j == index)
			{
				buffer[j] = rand() % 1000;
				continue;
			}

			buffer[j] = arr[i][j > index ? j - 1 : j];
		}
		arr[i] = buffer;
	}
}

void pop_col_front(int**& arr, int& m, int& n)
{
	--n;
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n];
		for (int j = 0; j <= n; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		arr[i] = buffer;
	}
}

void erase_row(int**& arr, int& m, const int n, int index)
{
	if (index > m) return;
	int** buffer = new int*[m - 1];
	for (int i = 0; i <= index; i++)
		buffer[i] = arr[i];
	for (int i = index + 1; i <= m; i++)
		buffer[i - 1] = arr[i];
	//delete[] arr;
	arr = buffer;
	//arr[index] = new int[m - 1];
	m--;
}

void pop_col_back(int**& arr, int& m, int& n)
{
	int** buffer = new int*[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//delete[] arr;
	arr = buffer;
}

void pop_row_front(int**& arr, int& m, int& n)
{
	int** buffer = new int*[--m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i + 1];
	}
	//delete[] arr;
	arr = buffer;
}

void pop_row_back(int**& arr, int& m, int& n)
{
	int** buffer = new int*[--m];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	//delete[] arr;
	arr = buffer;
}

void push_col_front(int**& arr, int& m, int& n)
{
	++n;
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n];
		buffer[0] = rand() % 1000;
		for (int j = 1; j <= n; j++)
		{
			buffer[j] = arr[i][j - 1];
		}
		arr[i] = buffer;
	}
}

void push_col_back(int**& arr, int& m, int& n)
{
	int** buffer = new int*[n+1];
	buffer[m] = new int[n];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = n; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			buffer[j][i] = rand() % 1000;
		}
	}
	delete[] arr;
	arr = buffer;
	n++;
}

void push_by_index(int**& arr, int& m, int& n, const int index)
{
	++m;
	int** buffer = new int*[m];
	for (int i = 0; i < m; i++)
	{
		if (i == index)
		{
			buffer[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				buffer[i][j] = rand() % 1000;
			}
			continue;
		}
		buffer[i] = arr[i > index ? i - 1 : i];
	}
	delete[] arr;
	arr = buffer;
}

void push_row_front(int**& arr, int& m, int& n)
{
	++m;
	int** buffer = new int*[m];
	buffer[0] = new int[n];
	for (int i = 0; i < n; i++)
	{
		buffer[0][i] = rand() % 1000;
	}
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}

void push_row_back(int**& arr, int& m, int& n)
{
	int** buffer = new int*[m + 1];
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[m] = new int[n];

	for (int i = 0; i < n; i++)
	{
		buffer[m][i] = rand() % 1000;
	}
	++m;
	delete[] arr;
	arr = buffer;
}

void Clear(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
		delete[] arr[i];

		}
	}
	delete[] arr;
}

int** Allocate(const int m, const int n)
{
	// 1. Создаём массив указателей
	int** arr = new int*[m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}
	return arr;
}

void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

