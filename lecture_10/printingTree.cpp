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
      {

      }
  };

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

  Node* Root;
  
  public:
    BinarySearchTree() {
      Root = nullptr;
    }

    void insert(T Data) {
      if (Root == nullptr)
        Root = new Node(Data);
      else
        insertRecursively(Root, Data);
    }
}

int main() {

}