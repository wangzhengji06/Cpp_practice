#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T> class LinkedStack {
private:
  struct Node {
    T data;
    Node *next;
    Node(const T &value) : data(value), next(nullptr) {}
  };

  Node *topNode;
  int count;

public:
  LinkedStack() : topNode(nullptr), count(0) {}

  ~LinkedStack() {
    while (!isEmpty()) {
      pop();
    }
  }

  void push(const T &value) {
    Node *tempNode = new Node{value};
    tempNode->next = topNode;
    topNode = tempNode;
    count++;
  }

  T pop() {
    if (isEmpty()) {
      throw runtime_error("Empty stack!");
    }
    Node *temp = topNode;
    T value = temp->data;
    topNode = topNode->next;
    delete temp;
    count--;
    return value;
  }

  T top() const {
    if (isEmpty()) {
      throw runtime_error("Empty stack!");
    }
    return topNode->data;
  }

  bool isEmpty() const { return topNode == nullptr; }

  int size() const { return count; }

  void print() const {
    if (isEmpty()) {
      cout << "Stack is empty" << endl;
      return;
    }
    cout << "Stack (top -> bottom): ";
    Node *current = topNode;
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }
};
