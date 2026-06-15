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

ListNode* reverseList(ListNode* head) {
    ListNode* previous = nullptr;
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* nextNode = current->next; // Stores the next node before changing the pointer.
        current->next = previous;          // Reverses the pointer of the current node.
        previous = current;                // Moves previous to the current node.
        current = nextNode;                // Continues walking through the original list.
    }

    return previous;
}

void printList(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr) {
        cout << current->value;

        if (current->next != nullptr) {
            cout << " -> ";
        }

        current = current->next;
    }

    cout << endl;
}

void deleteList(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

/*
                            *Problem Statement*
                ## Reverse a Linked List In-Place ##

You work on a system that shows a chain of tasks.
Each task points to the next task.

Given the head of a linked list, reverse the order of the nodes without
creating a new list. The reversal must be done in-place, changing only the
next pointers.

Example:
1 -> 2 -> 3 -> 4 -> 5

Expected answer:
5 -> 4 -> 3 -> 2 -> 1

To solve this, we use three pointers:

previous stores the previous node that is already reversed.
current points to the node we are processing now.
nextNode temporarily stores the next original node.

At each step, we make current->next point to previous.
At the end, previous will be the new head of the list.
*/

int main() {
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout << "Original list: ";
    printList(first);

    ListNode* reversedHead = reverseList(first);

    cout << "Reversed list: ";
    printList(reversedHead);

    deleteList(reversedHead); // Not required here, but it is good practice to free allocated memory.

    return 0;
}
