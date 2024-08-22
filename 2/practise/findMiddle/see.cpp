#include <iostream>
#include <string>
class Solution
{
public:
    int pivotInteger(int n)
    {
        int sumEverything = 0;
        for (int i = 0; i < n; i++)
        {
            sumEverything += i + 1;
        }
        int numberToInspect = 1;
        while (numberToInspect != n)
        {
            int leftSum = 0;
            for (int i = 0; i < numberToInspect; i++)
            {
                leftSum += i + 1;
            }
            int rightSum = sumEverything - leftSum;
            if (rightSum == leftSum + numberToInspect + 1)
            {
                return numberToInspect+1;
            }
            numberToInspect++;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    int result = sol.pivotInteger(8);
    std::cout << std::to_string(result) << "\n";
}