#include <iostream>

using namespace std;

void Foo(int* arr, int size, int &min, int &max, int *sum, unsigned long long int* prod);

int main()
{
	srand(time(NULL));
	int size = 10;
	int* array = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << (array[i] = rand() % 99 + 1) << " ";
	}
	int min, max, sum = 0;
	unsigned long long int prod = 1;
	cout << endl << "Foo: " << endl;
	Foo(array, size, min, max, &sum, &prod);
	cout << "min: " << min << "\n";
	cout << "max: " << max << "\n";
	cout << "sum: " << sum << "\n";
	cout << "prod: " << prod << "\n";

	return 0;
}

void Foo(int* arr, int size, int& min, int& max, int* sum, unsigned long long int* prod)
{
	min = arr[0];
	max = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (min < arr[i])
		{
			min = arr[i];
		}
		if (max > arr[i])
		{
			max = arr[i];
		}
		*sum += arr[i];
		*prod *= arr[i];
	}
}