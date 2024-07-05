/*
707. Design Linked List:
Medium

Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:
    MyLinkedList() Initializes the MyLinkedList object.
    int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
    void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
    void addAtTail(int val) Append a node of value val as the last element of the linked list.
    void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
    void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.

Example 1:
Input:
    ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
    [[], [1], [3], [1, 2], [1], [1], [1]]
Output:
    [null, null, null, null, 2, null, 3]

Example 2:
Input:
    ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
    [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
Output:
    [null,null,null,null,null,null,null,null,4,null,null,null]

Example 3:
Input:
    ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","get","get","get","get","addAtHead","addAtIndex","addAtHead","get","get","get","get","get","deleteAtIndex","get","get","get","get","deleteAtIndex","get","get","get","deleteAtIndex","get","get","deleteAtIndex","get","deleteAtIndex","get","deleteAtIndex","get"]
    [[],[7],[2],[1],[3,0],[2],[6],[4],[0],[1],[2],[3],[4],[4],[5,0],[6],[0],[1],[2],[3],[4],[1],[0],[1],[2],[3],[0],[0],[1],[2],[2],[0],[1],[0],[4],[1],[1],[0],[0]]
Output:
    [null,null,null,null,null,null,null,null,6,1,2,0,4,null,null,null,6,4,6,1,2,null,6,6,1,2,null,6,1,2,null,6,1,null,-1,null,0,null,0]

Explanation:
    MyLinkedList myLinkedList = new MyLinkedList();
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
    myLinkedList.get(1);              // return 2
    myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
    myLinkedList.get(1);              // return 3

Constraints:
    0 <= index, val <= 1000
    Please do not use the built-in LinkedList library.
    At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.

 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
*/

#include <iostream>

class MyLinkedList {
    class Node {
        public:
        int val;
        Node* next;

        Node(int v, Node* n) {
            val = v;
            next = n;
        }
    };
    Node* head;
public:
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        if (index < 0) {
            return -1;
        }
        Node* A = head;
        while (index-- && A != nullptr) {
            A = A->next;
        }
        if (A == nullptr) {
            return -1;
        } else {
            return A->val;
        }
    }
    
    void addAtHead(int val) {
        head = new Node(val, head);
    }
    
    void addAtTail(int val) {
        if (head == nullptr) {
            addAtHead(val);
            return;
        }
        Node* A = head;
        while (A->next != nullptr) {
            A = A->next;
        }
        A->next = new Node(val, nullptr);
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* A = head;
        Node* B =  nullptr; // keeping track of previous entry
        while(index && A != nullptr) {
            index--;
            B = A;
            A = A->next;
        }
        if (A == nullptr) {
            if (index == 0) {
                B->next = new Node(val, nullptr);
            }
            return;
        }
        B->next = new Node(val, A);
    }
    
    void deleteAtIndex(int index) {
        if (index < 0) {
            return;
        }
        if (index == 0) {
            head = head->next;
            return;
        }
        Node* A = head;
        while(--index && A != nullptr) {
            A = A->next;
        }
        if (A != nullptr && A->next != nullptr) {
            A->next = A->next->next;
        }
    }
};

int main() {
    // tested on leetcode successfully
    // implement linked list testing here, if needed
    return 0;
}