#include <iostream>
std::string findTheLongestMostCommonString(const std::string value, const std::string *arr, const int size);
int main()
{
    std::string value = "hh kk hhkkhh hkk121231hdhauhdadhh";
    std::string *arr = new std::string[3]{"hh", "kkkk", "hhhh"};
    std::string result = findTheLongestMostCommonString(value, arr, 3);
    std::cout << result << "\n";
    delete[] arr;
}
int findNextFirstChar(const std::string value, const int index, const char firstChar)
{
    for (int i = index; i < value.size(); i++)
    {
        if (value[i] == firstChar)
        {
            return i;
        }
    }
    return -1;
}
std::string findTheLongestMostCommonString(const std::string value, const std::string *arr, const int size)
{
    int index_arr_current_max = 0;
    int index_max_found = 0;
    for (int i = 0; i < size; i++)
    {
        int last_index = 0;
        int number_of_chars_found = 0;
        int number_of_times_found = 0;
        while (arr[i].size() - 1 + last_index <= value.size() - 1)
        {
            last_index = findNextFirstChar(value, last_index, arr[i][0]);
            if (last_index == -1)
            {
                break;
            }
            else
            {
                for (int j = 0; j < arr[i].size(); j++)
                {
                    if (value[last_index + j] == arr[i][j])
                    {
                        number_of_chars_found++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (number_of_chars_found == arr[i].size())
            {
                number_of_times_found++;
            }
            number_of_chars_found = 0;
            last_index++;
        }
        if (number_of_times_found > index_arr_current_max)
        {
            index_max_found = i;
            index_arr_current_max = number_of_times_found;
        }
    }
    return arr[index_max_found];
}