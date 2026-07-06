struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right) {
  ListNode dummy{0, head};
  ListNode *beforeReverse = &dummy;

  int i = 1;
  while (i < left) {
    beforeReverse = beforeReverse->next;
    ++i;
  }

  // prev now points to the beggining
  ListNode *reverseTail = beforeReverse->next;
  ListNode *prev = nullptr;
  ListNode *curr = reverseTail;

  while (i <= right) {
    ListNode *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
    ++i;
  }
  beforeReverse->next = prev;
  reverseTail->next = curr;

  return dummy.next;
}
