#include <iostream>
#include <vector>

using namespace std;

// ** Commands ** //
// cout = prints text or values in the terminal.
// << = sends data to cout.
// endl = moves the output to the next line.
// .size() = returns the number of elements in a vector or string.

// ** Dictionary ** //
// sorted - arranged in increasing order. | "Ordenado"

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = static_cast<int>(numbers.size()) - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            return {left + 1, right + 1}; // LeetCode uses 1-based indexes.
        }

        // Because the array is sorted, a small sum moves the left pointer.
        if (sum < target) {
            ++left;
        } else {
            // A large sum moves the right pointer.
            --right;
        }
    }

    return {};
}

/*
                            *Problem Statement*
                ## Find Two Purchases With Exact Value ##

You work on a checkout system. The system receives a list of prices sorted in
ascending order and a target value called target.

Your goal is to find two different products where the sum of their prices is
exactly equal to target.

Because the list is already sorted, implement the solution using Two Pointers:
one pointer starts at the beginning of the list and the other starts at the end.

Example:
numbers = {2, 7, 11, 15}
target = 9

Expected answer:
{1, 2}

Note:
In this problem, the returned indexes follow the LeetCode standard, so they
start at 1. Because of that, real indexes 0 and 1 become 1 and 2 in the answer.
*/

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(numbers, target);

    cout << "Two Sum II: ";
    for (int index : result) { // C++ foreach.
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
