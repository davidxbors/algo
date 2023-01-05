/*
Good morning! Here's your coding interview problem for today.

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

Author: David Bors <borsdavid@proton.me>
Date: 5 Jan 2023
*/
#include <iostream>
#include <vector>
#include <map>

bool simple_solution (std::vector<int> list, int k) 
{
    for (int i = 0; i < list.size(); i++) {
        for (int j = i+1; j < list.size(); j++)
            if (list[i] + list[j] == k)
                return true;
    }
    return false;
}

bool solution (std::vector<int> list, int k)
{
    std::map<int, bool> needed;
    for (auto element : list) {
        if (needed.contains(element))
            return true;
        needed.insert_or_assign(k - element, true);
    }
    return false;
}

int main(int argc, char const *argv[])
{
    std::vector<int> example1 = {10,15,3,7};
    int k1 = 17;
    bool result1 = true;

    std::vector<int> example2 = {10,15,3,6};
    int k2 = 17;
    bool result2 = false;

    assert(simple_solution(example1, k1) == result1 && "Test1 Failed");
    assert(simple_solution(example2, k2) == result2 && "Test2 Failed");
    assert(solution(example1, k1) == result1 && "Test3 Failed");
    assert(solution(example2, k2) == result2 && "Test4 Failed");
    std::cout << "All tests passed!\n";
    return 0;
}
