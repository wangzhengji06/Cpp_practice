struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head) {
  if (head == nullptr) {
    return true;
  }
  // My intuition here is I need to reach the middle
  ListNode *middle = head;
  ListNode *fast = head;

  // Find the middle point
  while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next;
    middle = middle->next;
  }

  ListNode *prev = middle;
  ListNode *curr = middle->next;
  prev->next = nullptr;
  while (curr != nullptr) {
    ListNode *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }

  ListNode *slow = prev;
  while (head != middle) {
    if (slow->val != head->val) {
      return false;
    }
    head = head->next;
    slow = slow->next;
  }
  return true;
}
