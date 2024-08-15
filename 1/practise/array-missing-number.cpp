#include <iostream>
struct answer
{
    int res;
    bool found;
};
answer findMissingNumber(int *arr, int size);
void bubbleSort(int *arr, int size);
int main()
{
    int *arr = new int[6]{1, 2, 3, 5, 5, 6};
    answer res = findMissingNumber(arr, 6);
    if (res.found)
    {
        std::cout << "The missing number is " << res.res << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }
    delete[] arr;
}
answer findMissingNumber(int *arr, const int size)
{
    answer ans;
    bubbleSort(arr, size);
    for (int i = 0; i < size - 1; i++)
    {
        int a = arr[i];
        int b = arr[i + 1];
        if (b != a + 1)
        {

            ans.found = true;
            ans.res = a + 1;
            return ans;
        }
    }
    ans.found = false;
    ans.res = -1;
    return ans;
}
void bubbleSort(int *arr, const int size)
{
    bool sorted = true;
    while (sorted)
    {
        sorted = false;
        for (int i = 0; i < size - 1; i++)
        {
            int a = arr[i];
            int b = arr[i + 1];
            if (a > b)
            {
                arr[i] = b;
                arr[i + 1] = a;
                sorted = true;
            }
        }
    }
}