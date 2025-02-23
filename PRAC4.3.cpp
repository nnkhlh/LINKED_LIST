#include <iostream>
using namespace std;

// Node structure for the linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Insert node at the end of the linked list
void insert(ListNode*& head, int val) {
    if (!head) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new ListNode(val);
}

// Print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// ----------------- INSERTION SORT -----------------
ListNode* sortedInsert(ListNode* sorted, ListNode* newNode) {
    if (!sorted || newNode->val < sorted->val) {
        newNode->next = sorted;
        return newNode;
    }

    ListNode* current = sorted;
    while (current->next && current->next->val < newNode->val) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return sorted;
}

void insertionSort(ListNode*& head) {
    if (!head || !head->next) return;

    ListNode* sorted = nullptr;
    ListNode* current = head;

    while (current) {
        ListNode* nextNode = current->next; // Store next node
        sorted = sortedInsert(sorted, current);
        current = nextNode;
    }

    head = sorted;
}

// ----------------- MERGE SORT -----------------
ListNode* getMiddle(ListNode* head) {
    if (!head) return head;
    ListNode* slow = head, * fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* sortedMerge(ListNode* left, ListNode* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->val <= right->val) {
        left->next = sortedMerge(left->next, right);
        return left;
    } else {
        right->next = sortedMerge(left, right->next);
        return right;
    }
}

ListNode* mergeSort(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* mid = getMiddle(head);
    ListNode* nextToMid = mid->next;
    mid->next = nullptr;

    ListNode* left = mergeSort(head);
    ListNode* right = mergeSort(nextToMid);

    return sortedMerge(left, right);
}

// ----------------- MAIN FUNCTION -----------------
int main() {
    ListNode* list1 = nullptr;
    insert(list1, 4);
    insert(list1, 2);
    insert(list1, 1);
    insert(list1, 3);

    cout << "Insertion Sort on Linked List:\n";
    cout << "Original List: ";
    printList(list1);

    insertionSort(list1);
    cout << "Sorted List: ";
    printList(list1);

    ListNode* list2 = nullptr;
    insert(list2, 4);
    insert(list2, 2);
    insert(list2, 1);
    insert(list2, 3);

    cout << "\nMerge Sort on Linked List:\n";
    cout << "Original List: ";
    printList(list2);

    list2 = mergeSort(list2);
    cout << "Sorted List: ";
    printList(list2);

    return 0;
}
