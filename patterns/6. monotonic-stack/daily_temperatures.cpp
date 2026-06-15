#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// ** Commands ** //
// cout = prints text or values in the terminal.
// << = sends data to cout.
// endl = moves the output to the next line.
// .empty() = checks if the stack is empty.

// .push() = adds an element to the top of the stack.
// .top() = returns the top element of the stack without removing it.
// .pop() = removes the top element of the stack.

// vector<int> = dynamic array.
// stack<int> = stack data structure. | "Pilha"

// ** Dictionary ** //
// Monotonic Stack - a stack that maintains its elements in a specific order (increasing or decreasing).

vector<int> dailyTemperatures(const vector<int>& temperatures) {
    vector<int> answer(temperatures.size(), 0);
    stack<int> pendingDays;

    for (int currentDay = 0; currentDay < static_cast<int>(temperatures.size()); ++currentDay) {
        // While the stack is not empty and the current temperature is higher than the temperature on top of the stack, we found the answer for that previous day.
        while (!pendingDays.empty() && temperatures[currentDay] > temperatures[pendingDays.top()]) { 
            int previousDay = pendingDays.top(); // Gets the index of the previous day that was still waiting for a warmer day.
            pendingDays.pop();                   // Removes this day from the stack because we found its answer.

            // Calculates how many days passed between the previous day and the current day.
            answer[previousDay] = currentDay - previousDay; 
        }

        // Stores the current day index while we still do not have a warmer future day.
        pendingDays.push(currentDay);
    }

    return answer;
}

void printVector(const vector<int>& values) {
    for (int value : values) {
        cout << value << " ";
    }

    cout << endl;
}

/*
                            *Problem Statement*
                ## Next Warmer Temperature ##

You work on a weather forecast system. Each position in the temperatures array
represents the forecast temperature for one day.

Given an array temperatures, return a new array answer where answer[i] shows
how many days you need to wait after day i to find a higher temperature.

If there is no future day with a higher temperature, answer[i] must be 0.

Example:
temperatures = {73, 74, 75, 71, 69, 72, 76, 73}

Expected answer:
{1, 1, 4, 2, 1, 1, 0, 0}

To solve this, we use a Monotonic Stack.

The stack stores indexes of days that still did not find a warmer day.
While the current temperature is higher than the temperature on top of the
stack, we found the answer for that previous day.

Each index enters and leaves the stack at most once, so the solution is O(n).
*/

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> answer = dailyTemperatures(temperatures);

    cout << "Temperatures: ";
    printVector(temperatures);

    cout << "Days until a warmer temperature: ";
    printVector(answer);

    return 0;
}
