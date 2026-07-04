struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  ListNode *odd = head;
  ListNode *even = head->next;
  ListNode *temp = even;

  while (odd->next != nullptr && odd->next->next != nullptr) {
    odd->next = odd -> next -> next;
    even->next = even->next->next;
    odd = odd->next;
    even = even->next;
  }
  odd->next = temp;
  return head;
}
