struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  ListNode dummy{};
  ListNode *iter = &dummy;
  while (list1 || list2) {
    if (list1 != nullptr && list2 != nullptr) {
      if (list1->val <= list2->val) {
        iter->next = list1;
        list1 = list1->next;
      } else {
        iter->next = list2;
        list2 = list2->next;
      }
    } else if (list2 == nullptr) {
      iter->next = list1;
      list1 = list1->next;
    } else {
      iter->next = list2;
      list2 = list2->next;
    }
    iter = iter->next;
  }
  return dummy.next;
}
