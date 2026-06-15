#include <iostream>
#include <vector>

using namespace std;

// ** Commands ** //
// cout = prints text or values in the terminal.
// << = sends data to cout.
// endl = moves the output to the next line.


vector<int> maxRevenueInKDays(const vector<int>& revenues, int k) {
    // Validation to make sure k is valid: greater than zero and not bigger than the revenues array.
    if (k <= 0 || k > static_cast<int>(revenues.size())) {
        return {0, 0, 0};
    }

    int windowSum = 0;

    // First, we build the initial window with the first k days.
    for (int i = 0; i < k; ++i) {
        windowSum += revenues[i];
    }

    int maxSum = windowSum;
    int startDay = 1;
    int endDay = k;

    // Now the window slides: the current day enters and the old day leaves.
    for (int right = k; right < static_cast<int>(revenues.size()); ++right) {
        int left = right - k;

        windowSum += revenues[right];
        windowSum -= revenues[left];

        if (windowSum > maxSum) {
            maxSum = windowSum;
            startDay = left + 2; // The current window starts on the day after the one that left.
            endDay = right + 1;  // The current window ends on the day that just entered.
        }
    }

    return {maxSum, startDay, endDay};
}

/*
                            *Problem Statement*
                ## Best Sales Period ##

You work on a sales analysis system. Each position in the revenues array
represents the total sold in one day.

Given an array revenues and a number k, find the highest total revenue in any
period of k consecutive days.

Example:
revenues = {120, 80, 45, 200, 60, 30, 90}
k = 3

Possible windows:
120 + 80 + 45 = 245
80 + 45 + 200 = 325
45 + 200 + 60 = 305
200 + 60 + 30 = 290
60 + 30 + 90 = 180

Expected answer: 325

Because we need to analyze consecutive ranges with a fixed size, we can use
Sliding Window to update the sum in O(1) each time the window moves.
*/

int main() {
    vector<int> revenues = {120, 80, 45, 200, 60, 30, 90};
    int k = 3;

    vector<int> bestRevenue = maxRevenueInKDays(revenues, k);

    cout << "Sliding Window - Highest revenue in " << k << " days: " << bestRevenue[0] << " between days " << bestRevenue[1] << " and " << bestRevenue[2] << endl;

    return 0;
}
