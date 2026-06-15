#include <iostream>

using namespace std;

// ** Commands ** //
// cout = prints text or values in the terminal.
// << = sends data to cout.
// endl = moves the output to the next line.

// ** Dictionary ** //
//chain - a sequence of events where each event points to the next one. | "Corrente"
//head - the first node in a linked list.

struct ListNode {
    int value;
    ListNode* next;

    ListNode(int nodeValue) {
        value = nodeValue;
        next = nullptr;
    }
};

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;       // Moves 1 step at a time.
        fast = fast->next->next; // Moves 2 steps at a time.

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

/*
                            *Problem Statement*
                ## Detect a Cycle in a Linked List ##

You work on a system that processes a chain of events.
Each event points to the next event in the queue.

Because of an integration bug, one event can point to a previous event,
creating an infinite cycle.

Given the head of a linked list, check if there is a cycle.

Example with cycle:
1 -> 2 -> 3 -> 4
     ^         |
     |_________|

Expected answer:
true

Because the structure can have a cycle, we cannot only walk until we find
nullptr. We use Fast & Slow Pointers:

slow moves 1 step at a time.
fast moves 2 steps at a time.

If there is a cycle, fast eventually meets slow.
If there is no cycle, fast reaches nullptr.
*/

int main() {
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // Creates a cycle back to node 2.

    bool result = hasCycle(first);

    cout << "Fast & Slow Pointers - List has cycle: ";
    cout << (result ? "true" : "false") << endl;

    fourth->next = nullptr;
    delete first;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
