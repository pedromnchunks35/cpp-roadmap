#include <iostream>
int sumAll(int *arr, int size);
int main()
{
    int size = 10;
    int *k = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result = sumAll(k, size);
    std::cout << result << std::endl;
    delete[] k;
}
int sumAll(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}