#include <iostream>

int main()
{
    std::byte pBkbndColor = (std::byte)53281;
    std::byte *someRef = &pBkbndColor;
    std::cout << someRef << "\n";
    *someRef = (std::byte)0;
    std::cout << someRef << "\n";
    return 0;
}