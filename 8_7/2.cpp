class MyHashSet {
public:
  MyHashSet() {
    for (int i = 0; i < SIZE; ++i) {
      table[i] = nullptr;
    }
  }

  void add(int key) {
    int index = hash(key);
    Node *curr = table[index];

    // Already exists -> do nothing
    while (curr != nullptr) {
      if (curr->m_key == key) {
        return;
      }

      curr = curr->m_next;
    }

    // Insert at the head of the linked list
    Node *new_node = new Node(key, table[index]);
    table[index] = new_node;
  }

  void remove(int key) {
    int index = hash(key);

    Node *prev = nullptr;
    Node *curr = table[index];

    while (curr != nullptr) {
      if (curr->m_key == key) {
        if (prev == nullptr) {
          // Removing the head
          table[index] = curr->m_next;
        } else {
          prev->m_next = curr->m_next;
        }

        delete curr;
        return;
      }

      prev = curr;
      curr = curr->m_next;
    }
  }

  bool contains(int key) {
    int index = hash(key);
    Node *curr = table[index];

    while (curr != nullptr) {
      if (curr->m_key == key) {
        return true;
      }

      curr = curr->m_next;
    }

    return false;
  }

  ~MyHashSet() {
    for (int i = 0; i < SIZE; ++i) {
      Node *curr = table[i];

      while (curr != nullptr) {
        Node *temp = curr;
        curr = curr->m_next;
        delete temp;
      }
    }
  }

private:
  static const int SIZE = 1009;

  struct Node {
    int m_key;
    Node *m_next;

    Node(int key, Node *next) : m_key{key}, m_next{next} {}
  };

  Node *table[SIZE];

  int hash(int key) { return key % SIZE; }
};
