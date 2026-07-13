struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *insert(ListNode *node, ListNode *head) {
  ListNode dummy{0, head};
  ListNode *iter{&dummy};
  while (iter->next != nullptr && iter->next->val <= node->val) {
    iter = iter->next;
  }
  node->next = iter->next;
  iter->next = node;

  return dummy.next;
}

ListNode *insertionSortList(ListNode *head) {
  ListNode *iter{head};
  ListNode *newhead = nullptr;

  while (iter != nullptr) {
    ListNode *temp = iter->next;
    iter->next = nullptr;
    // Now start the insertion logic
    newhead = insert(iter, newhead);
    iter = temp;
  }
  return newhead;
}
