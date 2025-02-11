/*#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node *makeNote(int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void duyet(Node *head){
    while(head != NULL){
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}

void themdau1(Node **head, int data){
    Node* newNode = makeNote(data);
    newNode->next = (*head); // cho phan next cua con tro new vao node dau cua con tro hien tai
    if(*head != NULL) {
        (*head)->prev = newNode;
    }
    (*head) = newNode;
}

void themdau2(Node *&head, int data){
    Node *newNode = new Node;
    newNode->next = head;
    if(head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}


void themcuoi1(Node **head, int data) {
    Node *newNode = makeNote(data);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void themcuoi2(Node *&head, int data) {
    Node *newNode = makeNote(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
int sz(Node *head) {
    int cnt = 0;
    while (head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}
void themgiua1(Node **head, int data, int k) {
    Node* newNode = makeNote(data);
    int cnt = sz(*head);
    if(k < 1 || k > cnt + 1) {
        return;
    }
    if(k == 1) {
        themdau1(head, data);
        return;
    }
    Node *temp = *head;
    for (int i = 1; i < k - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp;
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    temp->prev = newNode;
}
void themgiua2(Node *&head, int data, int k) {
    Node* newNode = makeNote(data);
    int cnt = sz(head);
    if(k < 1 || k > cnt + 1) {
        return;
    }
    if(k == 1) {
        themdau2(head, data);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < k - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp;
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    temp->prev = newNode;
}

void xoadau(Node *&head) {
    if(head == NULL) return;
    Node* temp = head;
    head = head->next;
    if(head != NULL) {
        head->prev = NULL;
    }
    delete temp;
}

void xoacuoi(Node *&head) {
    if(head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if(temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    delete temp;
}
int main() {
    Node *head = NULL;
    themdau1(&head, 10);
    themdau1(&head, 20);
    themdau1(&head, 30);
    duyet(head);

    themcuoi1(&head, 40);
    themcuoi1(&head, 50);
    duyet(head);

    themgiua1(&head, 25, 3);
    duyet(head);
    cout << 1;
    return 0;
}
*/
#include <iostream>

using namespace std;

// Define Node structure
struct Node {
    int key;
    Node* pNext;
    Node* pPrev;
};

// Define List structure
struct List {
    Node* pHead;
    Node* pTail;
};

// Function to create an empty list
void createList(List &L) {
    L.pHead = L.pTail = nullptr;
}

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->pNext = newNode->pPrev = nullptr;
    return newNode;
}

// Insert at the head of the list
void insertHead(List &L, int key) {
    Node* newNode = createNode(key);
    if (L.pHead == nullptr) {
        L.pHead = L.pTail = newNode;
    } else {
        newNode->pNext = L.pHead;
        L.pHead->pPrev = newNode;
        L.pHead = newNode;
    }
}

// Insert at the tail of the list
void insertTail(List &L, int key) {
    Node* newNode = createNode(key);
    if (L.pTail == nullptr) {
        L.pHead = L.pTail = newNode;
    } else {
        L.pTail->pNext = newNode;
        newNode->pPrev = L.pTail;
        L.pTail = newNode;
    }
}

// Insert at a specific position (1-based index)
void insertAt(List &L, int key, int pos) {
    if (pos <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (pos == 1) {
        insertHead(L, key);
        return;
    }

    Node* temp = L.pHead;
    int count = 1;

    while (temp != nullptr && count < pos - 1) {
        temp = temp->pNext;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    Node* newNode = createNode(key);
    newNode->pNext = temp->pNext;
    newNode->pPrev = temp;

    if (temp->pNext != nullptr) {
        temp->pNext->pPrev = newNode;
    } else {
        L.pTail = newNode;
    }

    temp->pNext = newNode;
}

// Delete the head node
void deleteHead(List &L) {
    if (L.pHead == nullptr) return;

    Node* temp = L.pHead;
    L.pHead = L.pHead->pNext;

    if (L.pHead != nullptr) {
        L.pHead->pPrev = nullptr;
    } else {
        L.pTail = nullptr;
    }

    delete temp;
}

// Delete the tail node
void deleteTail(List &L) {
    if (L.pTail == nullptr) return;

    Node* temp = L.pTail;
    L.pTail = L.pTail->pPrev;

    if (L.pTail != nullptr) {
        L.pTail->pNext = nullptr;
    } else {
        L.pHead = nullptr;
    }

    delete temp;
}

// Delete a node at a specific position
void deleteAt(List &L, int pos) {
    if (L.pHead == nullptr || pos <= 0) return;

    if (pos == 1) {
        deleteHead(L);
        return;
    }

    Node* temp = L.pHead;
    int count = 1;

    while (temp != nullptr && count < pos) {
        temp = temp->pNext;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    if (temp->pNext != nullptr) {
        temp->pNext->pPrev = temp->pPrev;
    } else {
        L.pTail = temp->pPrev;
    }

    if (temp->pPrev != nullptr) {
        temp->pPrev->pNext = temp->pNext;
    }

    delete temp;
}

// Traverse and print the list from head to tail
void printForward(List L) {
    Node* temp = L.pHead;
    while (temp != nullptr) {
        cout << temp->key << " ";
        temp = temp->pNext;
    }
    cout << endl;
}

// Traverse and print the list from tail to head (reverse)
void printBackward(List L) {
    Node* temp = L.pTail;
    while (temp != nullptr) {
        cout << temp->key << " ";
        temp = temp->pPrev;
    }
    cout << endl;
}

// Main function to test the doubly linked list
int main() {
    List myList;
    createList(myList);

    // Insert at head
    insertHead(myList, 10);
    insertHead(myList, 20);
    insertHead(myList, 30);

    cout << "List after insertions at head: ";
    printForward(myList); // Expected Output: 30 20 10

    // Insert at tail
    insertTail(myList, 40);
    insertTail(myList, 50);
    cout << "List after insertions at tail: ";
    printForward(myList); // Expected Output: 30 20 10 40 50

    // Insert at position
    insertAt(myList, 25, 3);
    cout << "List after insertion at position 3: ";
    printForward(myList); // Expected Output: 30 20 25 10 40 50

    // Print in reverse order
    cout << "List in reverse order: ";
    printBackward(myList); // Expected Output: 50 40 10 25 20 30

    // Delete head
    deleteHead(myList);
    cout << "After deleting head: ";
    printForward(myList); // Expected Output: 20 25 10 40 50

    // Delete tail
    deleteTail(myList);
    cout << "After deleting tail: ";
    printForward(myList); // Expected Output: 20 25 10 40

    // Delete at position
    deleteAt(myList, 2);
    cout << "After deleting at position 2: ";
    printForward(myList); // Expected Output: 20 10 40

    return 0;
}






















