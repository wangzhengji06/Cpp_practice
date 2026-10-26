#include <cstddef>
#include <print>

using namespace std;

struct Node {
  int m_val;
  Node *m_next;
  Node *m_prev;

  Node(int val) : m_val(val), m_next(nullptr), m_prev(nullptr) {}
  Node(int val, Node *next, Node *prev)
      : m_val(val), m_next(next), m_prev(prev) {}
};

struct LinkedList {
  size_t length;
  Node *head;
  Node *tail;

  LinkedList() : length(0), head(nullptr), tail(nullptr) {}
  // destructor is better defined after you can think about what kind of
  // insertion logic you have

  ~LinkedList() {
    Node *node{head};
    while (length != 0) {
      pop_back();
    }
  }

  // Copy Consturctor
  // head -> val create a Node node_x with it.
  //
  LinkedList(const LinkedList &other) : length(0) {
    Node *node = other.head;
    if (node == nullptr) {
      head = nullptr;
      tail = nullptr;
    }
    while (node != nullptr) {
      push_back(node->m_val);
      node = node->m_next;
    }
  }

  // Copy Assignment

  // Move Constructor

  // Move Assignment

  // size

  size_t size() const { return length; }

  void push_front(int val) {
    // if list is empty, then head and tail assigned to be new node
    // else, head -> m_prev = Node(val) and Node(val) -> next = head then head =
    // Node(val)
    // ++length
    Node *new_node = new Node(val);
    if (length == 0) {
      head = new_node;
      tail = new_node;
    } else {
      head->m_prev = new_node;
      new_node->m_next = head;
      head = new_node;
    }
    ++length;
  }

  void pop_front() {
    // if list has only one node, then head == tail == nullptr
    // if list is empty, do nothing
    // else tail = tail -> prev  tail -> next = nullptr
    if (length == 0) {
      return;
    } else if (length == 1) {
      delete head;
      head = nullptr;
      tail = nullptr;
    } else {
      head = head->m_next;
      delete head->m_prev;
      head->m_prev = nullptr;
    }
    --length;
  }

  void push_back(int val) {
    // if list is empty, then head and tail assigned to be new node
    // else, tail -> m_next = Node(val)  and tail = Node(val) I forgot the prev
    // ++length
    Node *new_node = new Node(val);
    if (length == 0) {
      head = new_node;
      tail = new_node;
    } else {
      tail->m_next = new_node;
      new_node->m_prev = tail;
      tail = new_node;
    }
    ++length;
  }

  void pop_back() {
    // if list has only one node, then head == tail == nullptr
    // if list is empty, do nothing
    // else tail = tail -> prev  tail -> next = nullptr
    if (length == 0) {
      return;
    } else if (length == 1) {
      delete head;
      head = nullptr;
      tail = nullptr;
    } else {
      tail = tail->m_prev;
      delete tail->m_next;
      tail->m_next = nullptr;
    }
    --length;
  }

  bool find(int val) {
    // iterate through the linkedlist
    Node *node{head};
    while (node != nullptr) {
      if (node->m_val == val) {
        return true;
      }
      node = node->m_next;
    }
    return false;
  }

  // Node is unlikely to be there independently, so insert should take val as
  // its target
  void insert(size_t location, int val) {
    // 1. if location == 0, then pushfront
    if (location == 0) {
      push_front(val);
    }
    // if locaiton >= length - 1, then pushback
    else if (location >= length - 1) {
      push_back(val);
    }
    // if location is  0 < location < length - 1, we need to find the node at
    // location i nodex.
    else {
      Node *node = head;
      for (int i = 0; i < location - 1; ++i) {
        node = node->m_next;
      }
      Node *node_y = node->m_next;
      Node *new_node = new Node{val, node, node_y};
      node->m_next = new_node;
      node_y->m_prev = new_node;
      ++length;
    }
  }

  void remove(size_t location, int val) {
    // 1. if location == 0, then pushfront
    if (location == 0) {
      push_front(val);
    }
    // if locaiton >= length - 1, then pushback
    else if (location >= length - 1) {
      push_back(val);
    }
    // if location is  0 < location < length - 1, we need to find the node at
    // location i nodex.
    else {
      Node *node = head;
      for (int i = 0; i < location - 1; ++i) {
        node = node->m_next;
      }
      Node *node_y = node->m_next;
      Node *new_node = new Node{val, node, node_y};
      node->m_next = new_node;
      node_y->m_prev = new_node;
      ++length;
    }
  }
};

int main() {
  LinkedList my_list{};
  my_list.push_back(1);

  println("{} == 1", my_list.size());
  my_list.push_back(2);
  my_list.push_back(3);
  println("{} == 3", my_list.size());
  my_list.pop_back();
  println("{} == 2", my_list.size());
}
