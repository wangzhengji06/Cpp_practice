struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head) {
  ListNode dummy{0, head};
  ListNode *iter = &dummy;
  auto slow = iter;
  auto fast = head;
  while (fast != nullptr) {
    if (fast->next && fast->val == fast->next->val) {
      int x = fast->val;
      while (fast && fast->val == x) {
        fast = fast->next;
      }
    } else {
      slow->next = fast;
      slow = fast;
      fast = fast->next;
    }
  }
  slow->next = nullptr;
  return iter->next;
}
