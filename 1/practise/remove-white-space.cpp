#include <iostream>
void removeWhiteSpace(std::string &value);
int main()
{
    std::string value = "Hello im pedro ";
    removeWhiteSpace(value);
    std::cout << value << "\n";
}
void removeWhiteSpace(std::string &value)
{
    std::string newValue = "";
    for (int i = 0; i < (value).size(); i++)
    {
        if ((value).at(i) != ' ')
        {
            newValue.append(std::string{(value).at(i)});
        }
    }
    (value) = newValue;
}