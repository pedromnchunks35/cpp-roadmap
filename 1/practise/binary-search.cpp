#include <iostream>
int findMember(int *arr, int size, int num);
void bubbleSort(int *arr, int size);
int main()
{
    int *arr = new int[6]{1, 2, 3, 10, -2, 6};
    bubbleSort(arr, 6);
    int found = findMember(arr, 6, -3);
    std::cout << "Number found at: " << found << std::endl;
}
void bubbleSort(int *arr, int size)
{
    bool sorted = true;
    while (sorted == true)
    {
        sorted = false;
        for (int i = 0; i < size - 1; i++)
        {
            int a = arr[i];
            int b = arr[i + 1];
            if (a > b)
            {
                arr[i + 1] = a;
                arr[i] = b;
                sorted = true;
            }
        }
    }
}
//? Basicly when we think in the interval we must see how much we would walk ((y-x)/2) and we sum to the current medium point
//? Example  0 1 2 3 4 5 6 (found 6)
//? First          l
//? sec     0 1 2 3 [4 5 6] (this is what we wish to observe)
//? third           6-4 = 2/2 = 1
//? fourth     [4 5 6]
//? left was the position for the 4.. we sum the walk which is 1 then it is 5
//? [4 5 6]
//?    l
//? 6>5 => left = 5+1 = 6
//? n = 6 + (6-6)/2 = 6
//? n = 6 = 6 FOUND
//? In case we dont find the value the left should reach the last position of the array + 1 (size), because the last positon is size-1
//? and the right should hit -1
//? This is because every single time we move the range to the left we are decreasing the right side
//? Every time we move the range to the right we are increasing the left
int findMember(int *arr, int size, int num)
{
    int left = 0;
    int right = size - 1;
    while (left != size && right != -1)
    {
        int n = left + (right - left) / 2;
        if (arr[n] == num)
        {
            return n;
        }
        if (arr[n] > num)
        {
            right = n - 1;
        }
        else
        {
            left = n + 1;
        }
    }
    return -1;
}