#include <iostream>
int *mergeTwoArrays(const int *arr, const int *arr2, const int size, const int size2);
void printArray(const int *arr, const int size);
void bubbleSort(int *arr, const int size);
int main()
{
    int size = 10;
    int *arr = new int[size]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size2 = 6;
    int *arr2 = new int[size2]{7, 8, 9, 10, 11, 12};
    int *newArr = mergeTwoArrays(arr, arr2, size, size2);
    printArray(newArr, size + size2);
    delete[] newArr;
}
int *mergeTwoArrays(const int *arr, const int *arr2, const int size, const int size2)
{
    int newSize = size + size2;
    int *newArray = new int[newSize];
    if (arr[0] > arr2[size2 - 1])
    {
        for (int i = 0; i < size2; i++)
        {
            newArray[i] = arr2[i];
        }
        for (int i = 0; i < size; i++)
        {
            newArray[size2 + i] = arr[i];
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            newArray[i] = arr[i];
        }
        for (int i = 0; i < size2; i++)
        {
            newArray[size + i] = arr2[i];
        }
        if (!(arr2[0] > arr[size - 1]))
        {
            bubbleSort(newArray, newSize);
        }
    }
    delete[] arr;
    delete[] arr2;
    return newArray;
}
void bubbleSort(int *arr, const int size)
{
    bool ordered = true;
    while (ordered)
    {
        ordered = false;
        for (int i = 0; i < size - 1; i++)
        {
            int a = arr[i];
            int b = arr[i + 1];
            if (a > b)
            {
                arr[i] = b;
                arr[i + 1] = a;
                ordered = true;
            }
        }
    }
}
void printArray(const int *arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}