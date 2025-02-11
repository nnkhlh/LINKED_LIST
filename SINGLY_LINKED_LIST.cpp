#include <iostream>
using namespace std;

// Define Node structure
struct Node {
    int data;
    Node* next;
};

// Define List structure
struct List {
    Node* head;
};

// Function to create an empty list
void createList(List &L) {
    L.head = nullptr;
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Insert a node in sorted order (ascending)
void insertSorted(List &L, int data) {
    Node* newNode = createNode(data);
    if (L.head == nullptr || L.head->data >= data) {
        newNode->next = L.head;
        L.head = newNode;
        return;
    }

    Node* temp = L.head;
    while (temp->next != nullptr && temp->next->data < data) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Reverse the linked list
void reverseList(List &L) {
    Node* prev = nullptr;
    Node* current = L.head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    L.head = prev;
}

// Remove duplicate nodes (keep one node)
void removeDuplicates(List &L) {
    if (L.head == nullptr) return;

    Node* temp = L.head;
    while (temp != nullptr && temp->next != nullptr) {
        if (temp->data == temp->next->data) {
            Node* duplicate = temp->next;
            temp->next = temp->next->next;
            delete duplicate;
        } else {
            temp = temp->next;
        }
    }
}

// Remove the k-th node from the beginning
void removeKthFromStart(List &L, int k) {
    if (L.head == nullptr || k <= 0) return;

    if (k == 1) {
        Node* temp = L.head;
        L.head = L.head->next;
        delete temp;
        return;
    }

    Node* temp = L.head;
    for (int i = 1; temp != nullptr && i < k - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) return;

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Remove the k-th node from the end
void removeKthFromEnd(List &L, int k) {
    if (L.head == nullptr || k <= 0) return;

    Node* first = L.head;
    Node* second = L.head;

    for (int i = 0; i < k; i++) {
        if (first == nullptr) return;
        first = first->next;
    }

    if (first == nullptr) {  // If k == list size, remove head
        Node* temp = L.head;
        L.head = L.head->next;
        delete temp;
        return;
    }

    while (first->next != nullptr) {
        first = first->next;
        second = second->next;
    }

    Node* nodeToDelete = second->next;
    second->next = second->next->next;
    delete nodeToDelete;
}

// Check if the list is symmetric (palindromic)
bool isSymmetric(List L) {
    Node* slow = L.head;
    Node* fast = L.head;
    Node* prev = nullptr;
    Node* next = nullptr;

    // Find middle and reverse first half
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    if (fast != nullptr) { // Odd number of elements, move slow to skip middle
        slow = slow->next;
    }

    // Compare reversed first half with second half
    while (prev != nullptr && slow != nullptr) {
        if (prev->data != slow->data) return false;
        prev = prev->next;
        slow = slow->next;
    }

    return true;
}

// Function to print the list
void printList(List L) {
    Node* temp = L.head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver function to test the linked list functions
int main() {
    List myList;
    createList(myList);

    // Insert in sorted order
    insertSorted(myList, 5);
    insertSorted(myList, 1);
    insertSorted(myList, 3);
    insertSorted(myList, 3);
    insertSorted(myList, 2);
    insertSorted(myList, 5);
    cout << "List after insertions: ";
    printList(myList); // Expected Output: 1 2 3 3 5 5

    // Remove duplicates
    removeDuplicates(myList);
    cout << "After removing duplicates: ";
    printList(myList); // Expected Output: 1 2 3 5

    // Reverse the list
    reverseList(myList);
    cout << "After reversing: ";
    printList(myList); // Expected Output: 5 3 2 1

    // Remove 2nd node from start
    removeKthFromStart(myList, 2);
    cout << "After removing 2nd node from start: ";
    printList(myList); // Expected Output: 5 2 1

    // Remove 2nd node from end
    removeKthFromEnd(myList, 2);
    cout << "After removing 2nd node from end: ";
    printList(myList); // Expected Output: 5 1

    // Check if list is symmetric
    cout << "Is the list symmetric? " << (isSymmetric(myList) ? "Yes" : "No") << endl; // Expected Output: No

    // Insert to create a symmetric list
    insertSorted(myList, 1);
    insertSorted(myList, 5);
    cout << "New List: ";
    printList(myList); // Expected Output: 1 5 5 1
    cout << "Is the new list symmetric? " << (isSymmetric(myList) ? "Yes" : "No") << endl; // Expected Output: Yes

    return 0;
}
