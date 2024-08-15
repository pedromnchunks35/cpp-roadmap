#include <iostream>
void mergeSort(std::string &arr);
void sumArrays(const std::string left, const std::string right, std::string &arr, const int leftSize, const int rightSize);
bool checkAnagram(const std::string str1, const std::string str2);
void removeSpaces(std::string &value);
int main()
{
    std::string str1 = "aaa bbb ccc ddd";
    std::string str2 = "ddd ccc bbb aa                                  a";
    mergeSort(str1);
    mergeSort(str2);
    removeSpaces(str1);
    removeSpaces(str2);
    std::cout << str1 << "\n";
    std::cout << str2 << "\n";
    bool response = checkAnagram(str1, str2);
    std::cout << (response == true ? "true" : "false") << "\n";
}
void removeSpaces(std::string &value)
{
    std::string new_string = "";
    for (int i = 0; i < value.size(); i++)
    {
        if (value.at(i) != ' ')
        {
            new_string.append(std::string{value.at(i)});
        }
    }
    value = new_string;
}
bool checkAnagram(const std::string str1, const std::string str2)
{
    if (str1.size() != str2.size())
    {
        return false;
    }
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1.at(i) != str2.at(i))
        {
            return false;
        }
    }
    return true;
}
void mergeSort(std::string &arr)
{
    if (arr.size() < 2)
    {
        return;
    }
    int n = arr.size() / 2;
    std::string left = "";
    std::string right = "";
    for (int i = 0; i < n; i++)
    {
        left.append(std::string{arr.at(i)});
    }
    for (int i = 0; i < arr.size() - n; i++)
    {
        right.append(std::string{arr.at(n + i)});
    }
    mergeSort(left);
    mergeSort(right);
    sumArrays(left, right, arr, left.size(), right.size());
}
void sumArrays(const std::string left, const std::string right, std::string &arr, const int leftSize, const int rightSize)
{
    int i = 0, j = 0, z = 0;
    while (i < leftSize && j < rightSize)
    {
        if (left[i] < right[j])
        {
            arr[z++] = left[i++];
        }
        else
        {
            arr[z++] = right[j++];
        }
    }
    while (i < leftSize)
    {
        arr[z++] = left[i++];
    }
    while (j < rightSize)
    {
        arr[z++] = right[j++];
    }
}