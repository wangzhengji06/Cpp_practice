#include <unordered_map>

class LRUCache {
public:
  LRUCache(int capacity) : capacity(capacity), size(0) {
    head = new DouLink();
    tail = new DouLink();

    head->next = tail;
    tail->prev = head;
  }

  ~LRUCache() {
    DouLink *current = head;

    while (current != nullptr) {
      DouLink *nextNode = current->next;
      delete current;
      current = nextNode;
    }
  }

  int get(int key) {

    auto it = map.find(key);

    if (it == map.end()) {
      return -1;
    }

    DouLink *node = it->second;

    moveToHead(node);

    return node->value;
  }

  void put(int key, int value) {
    auto it = map.find(key);

    // Case 1:
    // key already exists
    if (it != map.end()) {
      DouLink *node = it->second;

      node->value = value;
      moveToHead(node);

      return;
    }

    // Case 2:
    // key does not exist

    DouLink *newNode = new DouLink(key, value);

    map[key] = newNode;

    addToHead(newNode);

    ++size;

    if (size > capacity) {
      DouLink *removed = removeTail();

      map.erase(removed->key);

      delete removed;

      --size;
    }
  }

private:
  struct DouLink {
    int key;
    int value;

    DouLink *prev;
    DouLink *next;

    DouLink() : key(0), value(0), prev(nullptr), next(nullptr) {}

    DouLink(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
  };

  DouLink *head;
  DouLink *tail;

  int capacity;
  int size;

  std::unordered_map<int, DouLink *> map;

  void addToHead(DouLink *node) {
    node->prev = head;
    node->next = head->next;

    head->next->prev = node;
    head->next = node;
  }

  void removeNode(DouLink *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void moveToHead(DouLink *node) {
    removeNode(node);
    addToHead(node);
  }

  DouLink *removeTail() {
    DouLink *node = tail->prev;

    removeNode(node);

    return node;
  }
};
