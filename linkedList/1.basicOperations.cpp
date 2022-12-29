#include <iostream>
using namespace std;

class ListNode {
   public:
    int data;
    ListNode* next;

    // constructor
    ListNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int countNode(ListNode* head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }

    return cnt;
}

void insertNode(ListNode*& head, int data, int position) {
    ListNode* newNode = new ListNode(data);

    if (!head) {
        head = newNode;
        return;
    }

    // insert at the beginning of linked list
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // insert at other posiition
    ListNode* currNode = head;
    while (currNode && currNode->next && position > 1) {
        currNode = currNode->next;
        position--;
    }

    // gievn position is greater than linked list length
    if (position > 1) {
        currNode->next = newNode;
        return;
    }

    newNode->next = currNode->next;
    currNode->next = newNode;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    ListNode* head = nullptr;

    insertNode(head, 5, 0);
    insertNode(head, 4, 0);
    insertNode(head, 3, 0);
    insertNode(head, 2, 0);
    insertNode(head, 1, 0);
    insertNode(head, 6, 2);
    insertNode(head, 7, 10);
    insertNode(head, 8, 0);
    insertNode(head, 9, 7);
    insertNode(head, 10, 10);
    insertNode(head, 11, 10);

    printList(head);

    return 0;
}