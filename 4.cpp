#include <iostream>
#include <Windows.h>

using namespace std;

void InitArray(int** const arr, const int rows, const int cols);
void DrawArray(const int* const* arr, const int rows, const int cols);
void AddRow(int **&arr, int& rows, int& cols, const int value, const int rownum);
void AddCol(int **&arr, int& rows, int& cols, const int value, const int colnum);
void DeleteRow(int**& arr, int& rows, int& cols, const int rownum);
void DeleteCol(int**& arr, int& rows, int& cols, const int colnum);

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int rows = 10;
    int cols = 5;
    int** arr = new int*[rows];
    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    InitArray(arr, rows, cols);
    while (true)
    {
        system("cls");
        cout << "Добавление/удаление строки/столбца в динамический двумерный массив.\n";
        DrawArray(arr, rows, cols);
        cout << "Удаляем или добавляем?\n1 - добавить, 0 - удалить\n";
        bool iswork;
        cin >> iswork;
        cout << "Строку (1) или столбец(0)?\n";
        bool isRowOrCol;
        cin >> isRowOrCol;
        switch (iswork)
        {
        case 1:
        {
            switch (isRowOrCol)
            {
            case 0:
            {
                int value;
                int num;
                cout << "Номер столбца:\n";
                cin >> num;
                while (num < 0 || num >= cols)
                {
                    cout << "Диапазон от 0 до " << cols << " (включительно)\n";
                    cin >> num;
                }
                cout << "Что добавляем?\n";
                cin >> value;
                AddCol(arr, rows, cols, value, num);
                DrawArray(arr, rows, cols);
                Sleep(3000);
                break;
            }
            case 1:
            {
                int value;
                int num;
                cout << "Номер строки:\n";
                cin >> num;
                while (num < 0 || num >= rows)
                {
                    cout << "Диапазон от 0 до " << rows << " (включительно)\n";
                    cin >> num;
                }
                cout << "Что добавляем?\n";
                cin >> value;
                AddRow(arr, rows, cols, value, num);
                DrawArray(arr, rows, cols);
                Sleep(3000);
                break;
            }
            default:
                break;
            }
        }
        break;
        case 0:
        {
            switch (isRowOrCol)
            {
            case 0:
            {
                int num;
                cout << "Номер столбца:\n";
                cin >> num;
                while (num < 0 || num >= cols)
                {
                    cout << "Диапазон от 0 до " << cols << " (включительно)\n";
                    cin >> num;
                }
                DeleteCol(arr, rows, cols, num);
                DrawArray(arr, rows, cols);
                Sleep(3000);
                break;
            }
            case 1:
            {
                int value;
                int num;
                cout << "Номер строки:\n";
                cin >> num;
                while (num < 0 || num >= rows)
                {
                    cout << "Диапазон от 0 до " << rows << " (включительно)\n";
                    cin >> num;
                }
                DeleteRow(arr, rows, cols, num);
                DrawArray(arr, rows, cols);
                Sleep(3000);
                break;
            }
            default:
                break;
            }
        }
        default:
            break;
        }
    }
    for (size_t i = 0; i < rows; i++)
    {
        delete arr[i];
    }
    delete[] arr;
    
    return 0;
}

void InitArray(int** const arr, const int rows, const int cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 40 + (-20);
        }
    }
}

void DrawArray(const int* const* arr, const int rows, const int cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void AddRow(int **&arr, int& rows, int& cols, const int value, const int rownum)
{
    int** newArray = new int* [rows + 1];
    for (size_t i = 0; i < rows + 1; i++)
    {
        newArray[i] = new int[cols];
    }
    int flag = 0;
    for (size_t i = 0; i <= rows; i++)
    {
        if (i == rownum)
        {
            for (size_t i = 0; i < cols; i++)
            {
                newArray[rownum][i] = value;
            }
            flag++;
            continue;
        }
        for (size_t j = 0; j < cols; j++)
        {
            newArray[i][j] = arr[i - flag][j];
        }
    }
    rows++;
    for (size_t i = 0; i < cols; i++)
    {
        delete arr[i];
    }
    delete[] arr;
    arr = newArray;
}

void AddCol(int**& arr, int& rows, int& cols, const int value, const int colnum)
{
    int** newArray = new int* [rows];
  
    for (size_t i = 0; i < rows; i++)
    {
        newArray[i] = new int[cols + 1];
    }
   
    
    for (size_t i = 0; i < rows; i++)
    {
        int flag = 0;
        for (size_t j = 0; j < cols + 1; j++)
        {
            if (j == colnum)
            {
                flag++;
                newArray[i][j] = value;
            }
            newArray[i][j + flag] = arr[i][j];
        }
    }
    ++cols;

    for (size_t i = 0; i < cols - 1; i++)
    {
        delete arr[i];
    }
    delete[] arr;
    arr = newArray;
}

void DeleteRow(int**& arr, int& rows, int& cols, const int rownum)
{
    int** newArray = new int* [rows - 1];
    for (size_t i = 0; i < rows - 1; i++)
    {
        newArray[i] = new int[cols];
    }
    int flag = 0;
    for (size_t i = 0; i < rows - 1; i++)
    {
        if (i == rownum)
        {
            flag++;
        }
        for (size_t j = 0; j < cols; j++)
        {
            newArray[i][j] = arr[i + flag][j];
        }
    }
    --rows;
    for (size_t i = 0; i < rows + 1; i++)
    {
        delete arr[i];
    }
    delete[] arr;
    arr = newArray;
}

void DeleteCol(int**& arr, int& rows, int& cols, const int colnum)
{
    int** newArray = new int* [rows];

    for (size_t i = 0; i < rows; i++)
    {
        newArray[i] = new int[cols - 1];
    }


    for (size_t i = 0; i < rows; i++)
    {
        int flag = 0;
        for (size_t j = 0; j < cols - 1; j++)
        {
            if (j == colnum)
            {
                flag++;
            }
            newArray[i][j] = arr[i][j + flag];
        }
    }
    --cols;

    for (size_t i = 0; i < rows; i++)
    {
        delete arr[i];
    }
    delete[] arr;
    arr = newArray;
}
