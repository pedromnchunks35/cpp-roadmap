#include <iostream>
void invertString(std::string *value);
int main()
{
    std::string value = "hello world";
    invertString(&value);
    std::cout << value << std::endl;
}
void invertString(std::string *value)
{
    std::string copy = *value;
    for (int i = (*value).size() - 1; i >= 0; i--)
    {
        (*value)[(*value).size() - i - 1] = copy.at(i);
    }
}