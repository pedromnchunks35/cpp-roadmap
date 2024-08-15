#include <iostream>
int max(const int a, const int b);
int maximumContinuous(const int *arr, const int size);
int main()
{
    int *arr = new int[6]{0, 2, -2, 1, 0, 10};
    int result = maximumContinuous(arr, 6);
    std::cout << result << std::endl;
}
int max(const int a, const int b)
{
    return a > b ? a : b;
}
//? SUPPOSE WE HAVE [0,2,-2,1,0,10]
//? mh = max(0,0+0)=0, msf = max(0,0)=0
//? -> mh = max(2,0+2)=2,msf = max(0,2)=2
//? -> mh = max(2,2-2) = 2, msf = max(2,2)=2
//? -> mh = max(1,2+1) = 3, msf = max(2,3)=3
//? -> mh = max(0,3+0) = 3, msf = max(3,3)=3
//? -> mh = max(10,3)=10,msf = max(3,10)=10
int maximumContinuous(const int *arr, const int size)
{
    int maximumSoFar = arr[0];
    int maximumHere = arr[0];
    for (int i = 0; i < size; i++)
    {
        maximumHere = max(arr[i], maximumHere + arr[i]);
        maximumSoFar = max(maximumSoFar, maximumHere);
    }
    return maximumSoFar;
}