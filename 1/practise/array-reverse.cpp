#include <iostream>
void reverseArr(int *&arr, int size);
void printArr(int *arr, int size);
int main()
{
    int *arr = new int[5]{1, 2, 3, 4, 6};
    reverseArr(arr, 5);
    printArr(arr, 5);
}
void reverseArr(int *&arr, int size)
{
    int *newArr = new int[size];
    for (int i = size; 0 <= i; i--)
    {
        newArr[size - i] = arr[i - 1];
    }
    delete[] arr;
    arr = newArr;
}
void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}