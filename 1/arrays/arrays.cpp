#include <iostream>
void printArray(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}
void printArray2(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}
void deletePointer(int *&arr)
{
    delete[] arr;
    arr = nullptr;
}
int main()
{
    int arr[] = {1, 2, 3, 8, 7, 6};
    std::cout << arr[4] << std::endl;
    int *k = new int[4];
    k[1] = 2;
    std::cout << k[1] << std::endl;
    printArray(arr, sizeof(arr) / sizeof(arr[0]));
    std::cout << "**********" << std::endl;
    printArray(k, 4);
    std::cout << "**********" << std::endl;
    printArray2(k, 4);
    std::cout << "**********" << std::endl;
    printArray2(arr, sizeof(arr) / sizeof(arr[0]));
    std::cout << "**********" << std::endl;
    deletePointer(k);
    std::cout << k << std::endl;
    if (k == nullptr)
    {
        std::cout << "im null" << std::endl;
    }
}