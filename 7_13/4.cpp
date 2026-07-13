#include <unordered_set>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  std::unordered_set<ListNode *> inventory;

  while (headA != nullptr && headB != nullptr) {
    if (inventory.count(headA)) {
      return headA;
    }
    if (inventory.count(headB)) {
      return headB;
    }
    inventory.insert(headA);
    inventory.insert(headB);
    headA = headA->next;
    headB = headB->next;
  }

  while (headA != nullptr) {
    if (inventory.count(headA)) {
      return headA;
    }
    inventory.insert(headA);
    headA = headA->next;
  }

  while (headB != nullptr) {
    if (inventory.count(headB)) {
      return headB;
    }
    inventory.insert(headB);
    headB = headB->next;
  }

  return nullptr;
}
