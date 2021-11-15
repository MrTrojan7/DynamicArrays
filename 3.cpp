#include <iostream>
#include <vector>

using namespace std;

void InitRandNum(int* arr, int size);
void CopyToArrTmp(int* array1, int* array2, vector<int> &arr, int size1, int size2);
void DrawArray(int* arr, int size);
void DrawArray(vector<int> arr);

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	unsigned int size1;
	unsigned int size2;
	cout << "Введите размер массива #1: ";
	cin >> size1;
	cout << "Введите размер массива #2: ";
	cin >> size2;
	int* arr1 = new int[size1];
	int* arr2 = new int[size2];
	InitRandNum(arr1, size1);
	InitRandNum(arr2, size2);
	cout << "Массив #1: \n";
	DrawArray(arr1, size1);
	cout << "Массив #2: \n";
	DrawArray(arr2, size2);
	vector<int> arr3;
	CopyToArrTmp(arr1, arr2, arr3, size1, size2);
	cout << "Копирующий массив: \n";
	DrawArray(arr3);
	cout << "Размер массива: \n";
	cout << arr3.size() <<"\n";
	delete[] arr1;
	delete[] arr2;

	return 0;
}

void InitRandNum(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 30;
	}
	cout << endl;
}

void CopyToArrTmp(int* array1, int* array2, vector<int> &arr, int size1, int size2)
{
	for (size_t i = 0; i < size1; i++)
	{
		for (size_t j = 0; j < size2; j++)
		{
			if (array1[i] == array2[j])
			{
				bool flag = false;
				for (size_t k = 0; k < arr.size(); k++)
				{
					if (array1[i] == arr[k])
					{
						flag = true;
					}
				}
				if (!flag)
				{
					arr.push_back(array1[i]);
					break;
				}
			
			}
		}
	}
}

void DrawArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
		if ((i + 1) % 5 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

void DrawArray(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\t";
		if ((i + 1) % 5 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}