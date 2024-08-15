#include <iostream>
struct answer
{
    int *res;
    int size;
};
int findCorrectIndex(const std::string substringWindow, const int last_index, const char firstChar);
bool contains(const std::string substring, const std::string subStringWindow);
answer *getValidIndexes(const std::string *substrings, const int substrings_size, const std::string fullWindow, const int window);
void addMemberToArray(int *&arr, int &members, int &size, const int newMember);
void returnArrayWithFixedSize(int *&arr, int &size, const int members);
int main()
{
    int size = 3;
    std::string *substrings = new std::string[size]{"foo", "bar", "hugo"};
    int window = 0;
    for (int i = 0; i < size; i++)
    {
        window += substrings[i].size();
    }
    std::string value = "foobarhugojjsljpjaodjaopjdajdjfoobarhugoadnahndoiadoibarfoohugo";
    answer *ans = getValidIndexes(substrings, size, value, window);
    for (int i = 0; i < ans->size; i++)
    {
        std::cout << ans->res[i] << "\n";
    }
    delete[] ans->res;
    delete[] ans;
    delete[] substrings;
}
int findCorrectIndex(const std::string substringWindow, const int last_index, const char firstChar)
{
    for (int i = last_index; i < substringWindow.size(); i++)
    {
        if (firstChar == substringWindow[i])
        {
            return i;
        }
    }
    return -1;
}
bool contains(const std::string substring, const std::string subStringWindow)
{
    int index = 0;
    while (index + substring.size() - 1 < subStringWindow.size() - 1)
    {
        index = findCorrectIndex(subStringWindow, index, substring[0]);
        if (index == -1)
        {
            return false;
        }
        bool contains = true;
        for (int i = 0; i < substring.size(); i++)
        {
            if (substring[i] != subStringWindow[index + i])
            {
                contains = false;
                break;
            }
        }
        if (contains)
        {
            return true;
        }
        index++;
    }
    return false;
}
void addMemberToArray(int *&arr, int &members, int &size, const int newMember)
{
    if (members == size)
    {
        size *= 2;
        int *newArr = new int[size];
        for (int i = 0; i < members; i++)
        {
            newArr[i] = arr[i];
        }
        for (int i = members; i < size; i++)
        {
            newArr[i] = -1;
        }
        delete[] arr;
        arr = newArr;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == -1)
            {
                arr[i] = newMember;
                members++;
                break;
            }
        }
    }
}
void returnArrayWithFixedSize(int *&arr, int &size, const int members)
{
    int *newArray = new int[members];
    for (int i = 0; i < members; i++)
    {
        newArray[i] = arr[i];
    }
    size = members;
    delete[] arr;
    arr = newArray;
}
answer *getValidIndexes(const std::string *substrings, const int substrings_size, const std::string fullWindow, const int window)
{
    int currentSize = 10;
    int membersAdded = 0;
    int *arr = new int[currentSize];
    for (int i = 0; i < currentSize; i++)
    {
        arr[i] = -1;
    }
    std::string substringWindow = "";
    int i = 0;
    while (window + i <= fullWindow.size())
    {
        for (int j = 0; j < window; j++)
        {
            substringWindow.append(std::string{fullWindow.at(j + i)});
        }
        bool containsEverything = true;
        for (int j = 0; j < substrings_size; j++)
        {
            if (!contains(substrings[j], substringWindow))
            {
                containsEverything = false;
                break;
            }
        }
        if (containsEverything)
        {
            addMemberToArray(arr, membersAdded, currentSize, i);
        }
        i++;
        substringWindow = "";
    }
    returnArrayWithFixedSize(arr, currentSize, membersAdded);
    answer *ans = new answer;
    ans->res = arr;
    ans->size = currentSize;
    return ans;
}