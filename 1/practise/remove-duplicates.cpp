#include <iostream>
void removeDuplicated(int *&arr, int size);
void mergeSort(int *arr, int size);
void sumArrays(int *left, int *right, int *arr, int leftSize, int rightSize, int size);
bool contains(int *arr, int size, int num);
int main()
{
    int size = 12;
    int *arr = new int[size]{7, 2, 4, -1, 2, 3, 4, 4, 4, 4, 4, 4};
    mergeSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    removeDuplicated(arr, size);
    std::cout << "******************" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}
bool contains(int *arr, int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}
void removeDuplicated(int *&arr, int size)
{
    int added = 0;
    int *newArr = new int[size];
    for (int i = 0; i < size; i++)
    {
        if (!contains(newArr, size, arr[i]))
        {
            newArr[added] = arr[i];
            added++;
        }
    }
    delete[] arr;
    arr = newArr;
}
void mergeSort(int *arr, int size)
{
    if (size < 2)
    {
        return;
    }
    int n = size / 2;
    int *left = new int[n];
    int *right = new int[size - n];
    for (int i = 0; i < n; i++)
    {
        left[i] = arr[i];
    }
    for (int i = 0; i < size - n; i++)
    {
        right[i] = arr[n + i];
    }
    mergeSort(left, n);
    mergeSort(right, size - n);
    sumArrays(left, right, arr, n, size - n, size);
    delete[] left;
    delete[] right;
}
void sumArrays(int *left, int *right, int *arr, int leftSize, int rightSize, int size)
{
    int i = 0, j = 0, z = 0;
    while (i < leftSize && j < rightSize)
    {
        if (left[i] < right[i])
        {
            arr[z++] = left[i++];
        }
        else
        {
            arr[z++] = right[j++];
        }
    }
    while (i < leftSize)
    {
        arr[z++] = left[i++];
    }
    while (j < rightSize)
    {
        arr[z++] = right[j++];
    }
}