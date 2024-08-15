#include <iostream>
void comprenseString(std::string &value);
int main()
{
    std::string value = "000000213131212ffgghh";
    comprenseString(value);
    std::cout << value << "\n";
}
void comprenseString(std::string &value)
{
    if (value.size() == 0)
    {
        return;
    }
    int numberOfTimes = 0;
    char currentChar = value.at(0);
    std::string newString = "";
    for (int i = 0; i < value.size(); i++)
    {
        if (currentChar != value.at(i))
        {
            newString.append(std::to_string(numberOfTimes));
            numberOfTimes = 1;
            currentChar = value.at(i);
        }
        else
        {
            numberOfTimes++;
        }
        if (numberOfTimes == 1)
        {
            newString.append(std::string{value.at(i)});
        }
    }
    newString.append(std::to_string(numberOfTimes));
    value = newString;
}