#include <iostream>
void bubbleSort(int *arr, int size);
void printArr(int *arr, int size);
int main()
{
    int *arr = new int[6]{-100, 2, 3, -1000, 20, 10};
    bubbleSort(arr, 6);
    printArr(arr, 6);
}
void bubbleSort(int *arr, int size)
{
    bool ordered = true;
    while (ordered == true)
    {
        ordered = false;
        for (int i = 0; i < size; i++)
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
void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}
