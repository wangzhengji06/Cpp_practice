struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode dummy{};
  ListNode *iter = &dummy;
  int carry = 0;

  while (l1 || l2 || carry) {
    int sum = carry;

    if (l1 != nullptr) {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2 != nullptr) {
      sum += l2->val;
      l2 = l2->next;
    }

    carry = sum / 10;
    int digit = sum % 10;

    iter->next = new ListNode(digit);
    iter = iter->next;
  }
  return dummy.next;
}
