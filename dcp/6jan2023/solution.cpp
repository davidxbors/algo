/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?

Author: David Bors <borsdavid@proton.me>
Date: 6 jan 2023
*/
#include <iostream>
#include <vector>

std::vector<int> solve(std::vector<int> list)
{
    std::vector<int> result = std::vector<int>(list.size());
    int aux = 1;
    for (int i = 0; i < list.size(); i++) {
        result[i] = aux;
        aux *= list[i];
    }
    aux = 1;
    for (int i = list.size() - 1; i >= 0; i--) {
        result[i] *= aux;
        aux *= list[i];
    }
    return result;
}

int main(int argc, char const *argv[])
{
    std::vector<int> list1 = {1, 2, 3, 4, 5};
    std::vector<int> result1 = {120, 60, 40, 30, 24};
    
    std::vector<int> list2 = {3, 2, 1};
    std::vector<int> result2 = {2, 3, 6};

    std::vector<int> list3 = {0, 2, 1};
    std::vector<int> result3 = {2, 0, 0};

    std::vector<int> list4 = {3, 2, 0};
    std::vector<int> result4 = {0, 0, 6};

    std::vector<int> list5 = {0, 2, 0};
    std::vector<int> result5 = {0, 0 ,0};

    /* check if the solution is good for all tests */
    assert(solve(list1) == result1 && "Test1 failed!\n");
    assert(solve(list2) == result2 && "Test1 failed!\n");
    assert(solve(list3) == result3 && "Test1 failed!\n");
    assert(solve(list4) == result4 && "Test1 failed!\n");
    assert(solve(list5) == result5 && "Test1 failed!\n");

    std::cout << "All tests passed!\n";
    return 0;
}
