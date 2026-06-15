#include <iostream>
#include <vector>

using namespace std;

// ** Commands ** //
// cout = prints text or values in the terminal.
// << = sends data to cout.
// endl = moves the output to the next line.
// .size() = returns the number of elements in a vector or string.

// ** Dictionary ** //
// accumulated - total sum of values up to a certain point.

vector<int> buildPrefixSum(const vector<int>& expenses) {
    vector<int> prefix(expenses.size() + 1, 0); // Creates a zero-filled vector with one extra position.

    for (int i = 0; i < static_cast<int>(expenses.size()); ++i) { 
        // prefix[i + 1] keeps position zero as 0 and starts the accumulated values at position 1.
        prefix[i + 1] = prefix[i] + expenses[i]; 
    }
    return prefix;
}

int rangeSum(const vector<int>& prefix, int left, int right) {
    // Sum of nums[left..right]:
    // remove from the accumulated value everything that came before left.
    return prefix[right + 1] - prefix[left];
}

/*
                            *Problem Statement*
                ## Expense Analysis by Period ##
You work on a finance system that stores a user's daily expenses.
Each position in the array represents the total spent in one day.

Given an array expenses, where expenses[i] represents the spending on day i,
implement a structure that can quickly answer the total spent between two days:
startDay and endDay, inclusive.

Because the system can receive many queries for the same expense history,
your solution must do one initial pre-processing step and then answer each
query in O(1).
*/

int main() {
    vector<int> expenses = {120, 80, 45, 200, 60, 30, 90};

    vector<int> prefix = buildPrefixSum(expenses); // First, we pre-process the array once.

    // Parameters that indicate the start day (left) and end day (right) of the range we want to sum.
    int left = 1;
    int right = 3;

    // After that, each range query can be answered in O(1).
    int sum = rangeSum(prefix, left, right);

    cout << "Prefix Sum: ";
    for (int value : prefix) {
        cout << value << " ";
    }
    cout << endl;
    cout << "Range sum [" << left << ", " << right << "]: " << sum << endl;
    return 0;
}
