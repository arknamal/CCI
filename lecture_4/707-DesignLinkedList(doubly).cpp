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

//Implementation using doubly-linked list:

#include <iostream>
using namespace std;

class MyLinkedList {
    class Node {
        public:
        int val;
        Node* next;
        Node* prev;

        Node(int v, Node* n, Node* p): val(v), next(n), prev(p) 
        {
        }
    };
    Node* head;
    Node* tail;
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    
    void printList() {
        Node* A = head;
        if (!head) {
            cout << "Empty";
        }
        while(A) {
            cout << A->val << " ";
            A = A->next;
        }
        cout << endl;
    }
    
    
    int get(int index) {
        if (index < 0) {
            return -1;
        }
        Node* A = head;
        while (index && A) {
            index--;
            A = A->next;
        }
        if (A == nullptr) {
            return -1;
        } else {
            return A->val;
        }
    }
    
    void addAtHead(int val) {
        head = new Node(val, head, nullptr);
        if (tail == nullptr) {
            tail = head;
        } else if (head->next){
            head->next->prev = head;
        }
    }
    
    void addAtTail(int val) {
        if (head == nullptr) {
            addAtHead(val);
            return;
        } else {
            Node* N = new Node(val, nullptr, tail);
            tail->next = N;
            tail = N;
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* A = head;
        while (index && A) {
            index--;
            A = A->next;
        }
        if (A){ // UBSan requirement
            Node* N = new Node(val, A, A->prev);
            A->prev->next = N;
            A->prev = N;
        } else {
            if (index) {
                return;
            } else {
                addAtTail(val);
            }
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0) {
            return;
        }
        if (index == 0) {
            if (head) { // UBSan requirement
                head = head->next;
                if (head) {
                    head->prev = nullptr;
                } else {
                    tail = nullptr;
                }
            }
            return;
        }
        Node* A = head;
        while(index && A) {
            index--;
            A = A->next;
        }
        if (A == tail && index == 0) {
            if (A->prev) { // UBSan requirement
                A->prev->next = nullptr;
                tail = A->prev;
            }
        } else if (A && A->next) { // UBSan requirement
            Node* P = A->prev;
            P->next = A->next;
            A->next->prev = P;
        }
    }
};

int main() {
    MyLinkedList L;

    int i = 0;
    L.addAtHead(38);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(66);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(61);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(76);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(26);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(37);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(8);
    cout << ++i << " -- "; L.printList();
    L.deleteAtIndex(5);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(4);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(45);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(85);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(37);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(93);
    cout << ++i << " -- "; L.printList();
    L.addAtIndex(10, 23);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(21);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(52);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(15);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(47);
    cout << ++i << " -- "; L.printList();
    L.addAtIndex(6, 24);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(64);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(31);
    cout << ++i << " -- "; L.printList();
    L.deleteAtIndex(6);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(40);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(17);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(15);
    cout << ++i << " -- "; L.printList();
    L.addAtIndex(19, 2);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(11);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(86);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(55);
    cout << ++i << " -- "; L.printList();
    L.deleteAtIndex(15);
    cout << ++i << " -- "; L.printList();
    L.addAtIndex(14, 95);
    cout << ++i << " -- "; L.printList();
    L.deleteAtIndex(22);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(66);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(95);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(8);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(47);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(23);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(39);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(0);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(99);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(45);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(4);
    cout << ++i << " -- "; L.printList();
    L.addAtIndex(9, 11);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(81);
    cout << ++i << " -- "; L.printList();
    L.addAtIndex(18, 32);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(20);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(13);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(42);
    cout << ++i << " -- "; L.printList();
    L.addAtIndex(37, 91);
    cout << ++i << " -- "; L.printList();
    L.deleteAtIndex(36);
    cout << ++i << " -- "; L.printList();
    L.addAtIndex(10, 37);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(96);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(57);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(20);
    cout << ++i << " -- "; L.printList();
    L.deleteAtIndex(89);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(18);
    cout << ++i << " -- "; L.printList();
    L.addAtIndex(41, 5);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(23);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(75);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(7);
    cout << ++i << " -- "; L.printList();
    L.addAtIndex(25, 51);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(48);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(46);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(29);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(85);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(82);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(6);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(38);
    cout << ++i << " -- "; L.printList();
    L.deleteAtIndex(14);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(42);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(83);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(13);
    cout << ++i << " -- "; L.printList();
    L.addAtIndex(14, 20);
    cout << ++i << " -- "; L.printList();
    L.addAtIndex(17, 34);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(36);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(58);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(2);
    cout << ++i << " -- "; L.printList();
    L.addAtIndex(33, 59);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(37);
    cout << ++i << " -- "; L.printList();
    L.deleteAtIndex(15);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(64);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(0);
    cout << ++i << " -- "; L.printList();
    L.addAtHead(92);
    cout << ++i << " -- "; L.printList();
    L.deleteAtIndex(63);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(62);
    cout << ++i << " -- "; L.printList();
    L.addAtTail(32);
    cout << ++i << " -- "; L.printList();

    return 0;
}