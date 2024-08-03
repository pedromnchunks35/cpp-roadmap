#include <iostream>
//? Basicly we need to mount a op table and return the last position in it which gives the minimum value of operations
//? required to do the modification of the string
//? This happens because we are recursively getting the minimum number of operations
//? The array is the size of each string + 1 because we are assuming that str1[0]="" and str2[0]="" and arr[0][0]=0 operations (because ""=="")
//? Also we can make 3 operations: replace,delete,insert and we always get the minimum number of operations when we select one of those
//? The filling of laterals is literraly just add numbers to it
//? EX:
//?        ""  T E L E
//?     "" 0  1 2 3 4
//?      T 1
//?      E 2
//?      K 3
//?      A 4
//? After we must compare chars and get the minimum
//? case chars in the current position are equal we get the minimum of the 3 operations down
//? otherwise the minimum of those ops + 1
//? replace = arr[i-1][j-1]
//? delete = arr[i][j-1]
//? insert = arr[i][j-1]
//? Our positon = arr[i][j]
//? minimum is min(min(insert,delete),replace)
//? [replace][delete]
//? [insert][OUR POSITION]
void fillLaterals(int **&arr, const std::string str1, const std::string str2);
void fillTable(int **&arr, const std::string str1, const std::string str2);
int min(int a, int b);
int main()
{
    std::string str1 = "kkka2z";
    std::string str2 = "kkob";
    int **arr = new int *[str1.size() + 1];
    for (int i = 0; i < str1.size() + 1; i++)
    {
        arr[i] = new int[str2.size() + 1];
    }
    arr[0][0] = 0;
    fillLaterals(arr, str1, str2);
    fillTable(arr, str1, str2);
    std::cout << "Min number of ops: " << arr[str1.size()][str2.size()] << "\n";
    for (int i = 0; i < str1.size() + 1; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
int min(int a, int b)
{
    return a < b ? a : b;
}
void fillLaterals(int **&arr, const std::string str1, const std::string str2)
{
    for (int i = 1; i < str2.size() + 1; i++)
    {
        arr[0][i] = i;
    }
    for (int i = 1; i < str1.size() + 1; i++)
    {
        arr[i][0] = i;
    }
}
void fillTable(int **&arr, const std::string str1, const std::string str2)
{
    for (int i = 1; i < str1.size() + 1; i++)
    {
        for (int j = 1; j < str2.size() + 1; j++)
        {
            arr[i][j] = (str1[i - 1] == str2[j - 1] ? (min(min(arr[i][j - 1], arr[i - 1][j]), arr[i - 1][j - 1]))
                                                    : (min(min(arr[i][j - 1], arr[i - 1][j]), arr[i - 1][j - 1]) + 1));
        }
    }
}