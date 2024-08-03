#include <iostream>
bool isPalindrome(const std::string value);
int main()
{
    std::string value = "level";
    bool result = isPalindrome(value);
    std::cout << "This is the result: " << (result == true ? "true" : "false") << "\n";
}
bool isPalindrome(const std::string value)
{
    int left = 0;
    int right = value.size() - 1;
    while (left < right)
    {
        if (value.at(left) != value.at(right))
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}