#include <iostream>
bool findSubstring(const std::string value, const std::string substring);
int searchFromGivenPoint(const std::string value, const char firstChar, const int lastIndex);
int main()
{
    std::string value = "i ikno2w  ajsiojapodjapojdpoajdpojaiknownjdopinjasiodfhnbquihbfiuwbhuifhuiwheio iknosw";
    bool result = findSubstring(value, "iknow");
    std::cout << "The result is: " << (result == true ? "true" : "false") << "\n";
}
int searchFromGivenPoint(const std::string value, const char firstChar, const int lastIndex)
{
    for (int i = lastIndex; i < value.size(); i++)
    {
        if (value.at(i) == firstChar)
        {
            return i;
        }
    }
    return -1;
}
bool findSubstring(const std::string value, const std::string substring)
{
    if (substring == "")
    {
        return false;
    }
    int size_main_string = value.size();
    int size_substring = substring.size();
    int index = 0;
    while (index <= size_main_string - size_substring)
    {
        index = searchFromGivenPoint(value, substring.at(0), index);
        if (index == -1)
        {
            return false;
        }
        int max_index_main_string = index + size_substring - 1;
        if (max_index_main_string > size_main_string - 1)
        {
            return false;
        }
        bool isSubstringOk = true;
        for (int i = 0; i < size_substring; i++)
        {
            if (value.at(index + i) != substring.at(i))
            {
                isSubstringOk = false;
                break;
            }
        }
        if (isSubstringOk)
        {
            return true;
        }
        index++;
    }
    return false;
}
