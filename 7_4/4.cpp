struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *trainingPlan(ListNode *head, int cnt) {
  // after cnt step, I start recording
  int step = 0;
  ListNode *candidate = head;
  for (int i = 0; i < cnt; ++i) {
    head = head->next;
  }
  while (head != nullptr) {
    head = head->next;
    candidate = candidate->next;
  }
  return candidate;
}
