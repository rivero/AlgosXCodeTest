//
//  main.cpp
//  test1
//
//  Created by Jaguar Rivero on 2024-09-04.
//

#include <iostream>
#include <vector>
template <typename T>
void printv(const T& v, bool newLine = true, bool printIndex = false)
{
    for (const auto& elem : v)
    {
        std::cout << elem << "\t";
    }
    if (printIndex)
    {
        std::cout << "\n";
        size_t c{};
        for (const auto& elem : v)
        {
            std::cout << "[" << c++ << "]\t";
        }
    }
    
    if (newLine)
    {
        std::cout << "\n";
    }
}

#include "MergedSortedArray.h"

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    MergeSortedArray::process();
    return 0;
}
