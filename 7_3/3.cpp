struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head) {
  if (head == nullptr) {
    return head;
  }
  ListNode *slow = nullptr;
  ListNode *fast = head;

  while (fast != nullptr) {
    ListNode *next = fast->next;
    fast->next = slow;
    slow = fast;
    fast = next;
  }
  return slow;
}
