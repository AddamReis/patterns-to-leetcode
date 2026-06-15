#include <iostream>
#include <vector>

using namespace std;

// ** Commands ** //
// cout = prints text or values in the terminal.
// << = sends data to cout.
// endl = moves the output to the next line.
// .size() = returns the number of elements in a vector or string.
// .empty() = checks if a vector or string is empty.

// ** Dictionary ** //
//arranged - placed in a specific order.
//sorted - arranged in increasing order (order by). | "Ordenado"
//pointer tracks - a variable that keeps the position of a specific value in the array.
//unique - exclusive, not repeated.

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    // uniqueIndex stores the position of the last unique value found.
    int uniqueIndex = 0;

    for (int current = 1; current < static_cast<int>(nums.size()); ++current) {
        if (nums[current] != nums[uniqueIndex]) {
            ++uniqueIndex;
            // Move the new unique value to the next valid position in the array.
            nums[uniqueIndex] = nums[current];
        }
    }

    return uniqueIndex + 1;
}

/*
                            *Problem Statement*
                ## Remove Duplicates From a Sorted List ##

You work on a system that receives a sorted list of customer IDs.
Because of duplicated imports, the same ID can appear many times.

Your goal is to remove the duplicates in-place, keeping only one occurrence
of each ID and preserving the original order.

The function must return the new valid size of the array. The values after
this size do not matter.

Because the array is sorted, implement the solution using Two Pointers:
one pointer tracks the position of the last unique value and the other scans
the array.

Example:
nums = {1, 1, 2, 2, 3, 4, 4, 5}

After removal:
nums = {1, 2, 3, 4, 5, ...}

Expected answer:
5
*/

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int newLength = removeDuplicates(nums);

    cout << "Remove Duplicates - New length: " << newLength << endl;
    cout << "Array after removal: ";

    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
