#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// print linkedlist
void printList(ListNode *head) {
  ListNode *curr = head;
  while (curr != nullptr) {
    std::cout << curr->val;
    if (curr->next != nullptr) {
      std::cout << " -> ";
    }
    curr = curr->next;
  }
  std::cout << std::endl;
}

// insert node at the front of linkedlist
ListNode *insertAtHead(ListNode *head, int val) {
  ListNode *newhead = new ListNode{val};
  return newhead;
}

// insert node at the tail of linkedlist
ListNode *insertAtTail(ListNode *head, int val) {
  ListNode *curr = head;
  ListNode *newTail = new ListNode{val, nullptr};
  if (curr == nullptr) {
    return newTail;
  }
  while (curr->next != nullptr) {
    curr = curr->next;
  }
  curr->next = newTail;
  return head;
}

// insert at a selected location
ListNode *insertAtPosition(ListNode *head, int val, int position) {
  if (position == 0) {
    return insertAtHead(head, val);
  }
  ListNode *curr = head;
  ListNode *newNode = new ListNode{val};
  for (int i = 0; i < position - 1 && curr != nullptr; ++i) {
    curr = curr->next;
  }
  if (curr != nullptr) {
    newNode->next = curr->next;
    curr->next = newNode;
  }
  return head;
}

// delete the node at the front
ListNode *deleteAtHead(ListNode *head) {
  if (head == nullptr) {
    return head;
  }
  ListNode *newHead = head->next;
  delete head;
  return head->next;
}

// delete the node at the tail
ListNode *deleteAtTail(ListNode *head) {
  ListNode *curr = head;
  if (head == nullptr) {
    return head;
  }
  if (head->next == nullptr) {
    delete head;
    return nullptr;
  }
  while (curr->next->next != nullptr) {
    curr = curr->next; // last second
  }
  delete curr->next;
  curr->next = nullptr;
  return head;
}

// delete the node at the selected location
ListNode *deleteAtPosition(ListNode *head, int position) {
  ListNode *curr = head;
  if (position == 0) {
    return deleteAtHead(head);
  }
  for (int i = 0; i < position - 1 && curr != nullptr; ++i) {
    curr = curr->next;
  }
  if (curr == nullptr || curr->next == nullptr) {
    return head;
  }
  ListNode *nodeToDelete = curr->next;
  curr->next = curr->next->next;
  delete nodeToDelete;
  return head;
}

// delete whole list
void deleteList(ListNode *head) {
  while (head != nullptr) {
    ListNode *next = head->next;
    delete head;
    head = next;
  }
}

// main()
