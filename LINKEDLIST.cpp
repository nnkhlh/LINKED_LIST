#include <iostream>
using namespace std;
struct Node{
    int key;
    Node* pNext;
};
struct List{
    Node* pHead;
    Node* pTail;
};
void createList(List &L) {
    L.pHead = L.pTail = nullptr;
}
void insertHead(List &L, int data){
    Node *newNode = new Node();
    newNode->key = data;
    newNode->pNext = nullptr;
    if (L.pHead == nullptr) {
        L.pHead = L.pTail = newNode;
        return;
    }
    newNode->pNext = L.pHead;
    L.pHead = newNode;
}
void insertTail(List &L, int data) {
    Node *newNode = new Node();
    newNode->key = data;
    newNode->pNext = nullptr;
    if (L.pHead == nullptr) {
        L.pHead = L.pTail = newNode;
        return;
    }
    L.pTail->pNext = newNode;
    L.pTail = newNode;
}
void reverseList(List &L) {
    if(L.pHead == nullptr || L.pHead->pNext == nullptr) {
        return;
    }
    Node* prev = nullptr;
    Node* curr = L.pHead;
    Node* next = nullptr;
    while (curr != nullptr) {
        next = curr->pNext;
        curr->pNext = prev;
        prev = curr;
        curr = next;
    }
    L.pTail = L.pHead;
    L.pHead = prev;
}
List reverseList1(List L) {
    List K = {nullptr, nullptr};
    Node* curr = L.pHead;
    while(curr != nullptr) {
        Node *tmp = new Node{curr->key, K.pHead};
        K.pHead = tmp;
        //insertHead(K, curr->key);
        if(K.pTail == nullptr) {
            K.pTail = tmp;
        }
        curr = curr->pNext;
    }
    return K;
}
void removeDuplicate(List &L) {
    if(L.pHead == nullptr){
        return;
    }
    Node* curr =  L.pHead;
    while (curr != nullptr) {
        Node* temp = curr;
        while (temp->pNext != nullptr) {
            if (temp->pNext->key == curr->key){
                Node *del = temp->pNext;
                temp->pNext = temp->pNext->pNext;
                if (del == nullptr) {
                    L.pTail = temp;
                }
                delete del;
            } else {
                temp = temp->pNext;
            }
        }
        curr = curr->pNext;
    }
}

void printList(List L)  {
    if (L.pHead == nullptr) {
        return;
    }
    Node* curr = L.pHead;
    while (curr != nullptr) {
        cout << curr->key << ' ';
        curr = curr->pNext;
    }
}
void skipMdeleteN(List &L, int m, int n) {
    Node* curr = L.pHead;
    while (curr != nullptr) {
        for (int i = 1; i < m && curr != nullptr; i++) {
            curr = curr->pNext;
        }
        if (curr == nullptr) {
            return;
        }
        //cout << curr->keyz << endl;
        Node* t = curr->pNext;
        for (int i = 1; i <= n && t != nullptr; i++) {
            Node* del = t;
            //cout << t->key << endl;
            t = t->pNext;
            delete del;
        }
        curr->pNext = t;
        curr = t;
    }
}
Node* reverseNode(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr != nullptr){
        next = curr->pNext;
        curr->pNext = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindromeList(List &L) {
    if(L.pHead == nullptr || L.pHead->pNext == nullptr) {
        return true;
    }
    Node* fast = L.pHead;
    Node* slow = L.pHead;
    while (fast != nullptr && fast->pNext != nullptr) {
        slow = slow->pNext;
        fast = fast->pNext->pNext;
    }
    Node* half = reverseNode(slow);
    bool check = true;
    Node* curr = L.pHead;
    while (half != nullptr) {
        if(curr->key != half->key) {
            check = false;
            break;
        }
        half = half->pNext;
        curr = curr->pNext;
    }
    return check;
}
int main() {
    List L;
    createList(L);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertTail(L, x);
    }
    if(isPalindromeList(L)) cout << "YES";
    else cout << "NO";
}
