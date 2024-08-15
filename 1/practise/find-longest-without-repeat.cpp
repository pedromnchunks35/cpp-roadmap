#include <iostream>
#include <unordered_set>
int lengthLongestSubstring(const std::string &s);
bool contains(const char givenChar, const std::string value);
int main()
{
    std::string value = "abbabcdefgdabcefghi              j";
    int result = lengthLongestSubstring(value);
    std::cout << result << "\n";
}
bool contains(const char givenChar, const std::string value)
{
    for (int i = 0; i < value.size(); i++)
    {
        if (givenChar == value.at(i))
        {
            return true;
        }
    }
    return false;
}
int lengthLongestSubstring(const std::string &s)
{
    int max_length = 0;
    int temp_length = 1;
    char current_char = s.at(0);
    std::string foundChars = std::string{s.at(0)};
    for (int i = 0; i < s.size(); i++)
    {
        if (current_char != s.at(i))
        {
            if (!contains(s.at(i), foundChars))
            {
                foundChars.append(std::string{s.at(i)});
                temp_length++;
            }
            else
            {
                if (temp_length > max_length)
                {
                    max_length = temp_length;
                }
                foundChars = "";
                foundChars.append(std::string{s.at(i)});
                temp_length = 1;
            }
            current_char = s.at(i);
        }
    }
    if (temp_length > max_length)
    {
        max_length = temp_length;
    }
    return max_length;
}
