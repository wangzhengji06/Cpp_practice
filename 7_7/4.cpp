struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
  // define slow and fast
  // keep moving until fast hit nullptr or they point to the same
  // if fast is nullptr then false else true

  ListNode *slow = head;
  ListNode *fast = head;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      return true;
    }
  }

  return false;
}
