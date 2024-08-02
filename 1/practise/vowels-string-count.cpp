#include <iostream>
int countVowels(const std::string value);
int main()
{
    std::string value = "aedcfg";
    int result = countVowels(value);
    std::cout << result << std::endl;
}
int countVowels(const std::string value)
{
    int number_of_vogals = 0;
    for (int i = 0; i < value.size(); i++)
    {
        char a = value.at(i);
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        {
            number_of_vogals++;
        }
    }
    return number_of_vogals;
}
