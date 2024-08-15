#include <iostream>
void findMin(int *arr, int size);
void findMax(int *arr, int size);
int main()
{
    int *k = new int[5]{-1, 3, 6, 8, 5};
    findMin(k, 5);
    findMax(k, 5);
}
void findMin(int *arr, int size)
{
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    std::cout << "The minimum is: " << min << std::endl;
}

void findMax(int *arr, int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    std::cout << "The maximum is: " << max << std::endl;
}