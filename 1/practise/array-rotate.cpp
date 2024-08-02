#include <iostream>
void rotateXPositions(int *&arr, int *size, int rotateXPositions);
int main()
{
    int size = 5;
    int *arr = new int[size]{1, 2, 3, 4, 5};
    rotateXPositions(arr, &size, 7);
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    delete[] arr;
}
void rotateXPositions(int *&arr, int *size, int rotateXPositions)
{
    int oldSize = *size;
    int newSize = *size * 2;
    while (newSize < oldSize + rotateXPositions)
    {
        newSize += oldSize;
    }
    int *newArr = new int[newSize];
    for (int i = 0; i < oldSize; i++)
    {
        newArr[rotateXPositions  + i] = arr[i];
    }
    delete[] arr;
    *size = newSize;
    arr = newArr;
}