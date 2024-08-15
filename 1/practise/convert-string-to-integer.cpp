#include <iostream>
#include <climits>
int convertToNumber(const std::string value);
int main()
{
    std::string value = "+111234";
    int result = convertToNumber(value);
    std::cout << result << "\n";
}
int convertToNumber(const std::string value)
{
    int result = 0;
    int i = 0;
    int sign = 1;
    if (value.at(0) == '-' || value.at(0) == '+')
    {
        sign = value.at(0) == '-' ? -1 : 1;
        i++;
    }
    while (value.size() != i)
    {
        result = (result * 10) + (value.at(i) - '0');
        i++;
    }
    return result * sign;
}