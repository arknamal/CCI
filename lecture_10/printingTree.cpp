// This program is part of the implementation of Lecture 10 of the CCI Course 2024 by Sarfraz Raza
// Problem 6a:
// Print Tree:
// Write a recursive function outputTree to display a binary tree object on the screen. The
// function should output the tree row by row, with the top of the tree at the left of the
// screen and bottom of the tree towards the right of the screen. Each row is output vertically.

#include <iostream>
using namespace std;

template <typename T>
class BinarySearchTree {
  struct Node {
      T Data;
    Node *Left, *Right;
    public:
      Node(T Data, Node* Left = nullptr, Node* Right = nullptr):Data{Data}, Left{Left}, Right{Right}
      {}
  };

  Node* Root;

  // This private function is used by public function `insert`:
  void insertRecursively(Node* Root, T Data) {
    if (Root->Data > Data) {
      if (Root->Left)
        insertRecursively(Root->Left, Data);
      else
        Root->Left = new Node(Data);
    }
    else {
      if (Root->Right)
        insertRecursively(Root->Right, Data);
      else
        Root->Right = new Node(Data);
    }
  }

  // This is the desired function but is private and called by the public function `print`:
  void outputTree(Node* Root, int depth) {
    if (!Root)
      return;
    outputTree(Root->Right, depth + 1);
    for (int i = 0; i < depth; i++)
      cout << "\t";
    cout << Root->Data << endl;
    outputTree(Root->Left, depth + 1);
  }

  public:

    BinarySearchTree() {
      Root = nullptr;
    }

    // This function inserts data in the Binary Search Tree using `insertRecursively` private function:
    void insert(T Data) {
      if (Root == nullptr)
        Root = new Node(Data);
      else
        insertRecursively(Root, Data);
    }

    // This function prints data of the Binary Search Tree from L2R using `outputTree` private function:
    void print() {
      cout << endl;
      outputTree(Root, 0);
      cout << endl;
    }
};

int main() {
  BinarySearchTree<int> MyBST;
  MyBST.insert(49);
  MyBST.insert(28);
  MyBST.insert(83);
  MyBST.insert(18);
  MyBST.insert(40);
  MyBST.insert(71);
  MyBST.insert(97);
  MyBST.insert(11);
  MyBST.insert(19);
  MyBST.insert(32);
  MyBST.insert(44);
  MyBST.insert(69);
  MyBST.insert(72);
  MyBST.insert(92);
  MyBST.insert(99);
  MyBST.print();
}