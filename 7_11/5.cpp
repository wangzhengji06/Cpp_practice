struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *partition(ListNode *head, int x) {
  ListNode *iter = head;

  ListNode *iter_1 = nullptr;
  ListNode *iter_2 = nullptr;
  ListNode *front = iter_1;
  ListNode *front_2 = iter_2;

  while (iter != nullptr) {
    if (iter->val < x) {
      if (iter_1 == nullptr) {
        iter_1 = iter;
        front = iter_1;
      } else {
        iter_1->next = iter;
        iter_1 = iter;
      }
    } else {
      if (iter_2 == nullptr) {
        iter_2 = iter;
        front_2 = iter;
      } else {
        iter_2->next = iter;
        iter_2 = iter;
      }
    }
    iter = iter->next;
  }
  if (iter_2 != nullptr) {
    iter_2->next = nullptr;
  }

  if (iter_1 == nullptr) {
    return front_2;
  }
  iter_1->next = front_2;
  return front;
}
