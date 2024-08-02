#include <iostream>
void printArr(int *arr, int size);
int main()
{
    int *arr = new int[9]{1, 2, 45, 6, 3, 4, 5, 6, 1};
    printArr(arr, 9);
    delete[] arr;
}
void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}