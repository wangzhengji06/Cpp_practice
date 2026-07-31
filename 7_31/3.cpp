class MyHashMap {
public:
  MyHashMap() {
    for (int i = 0; i < SIZE; ++i) {
      table[i] = nullptr;
    }
  }

  void put(int key, int value) {
    int index = hash(key);
    Node *curr = table[index];

    while (curr != nullptr) {
      if (curr->m_key == key) {
        curr->m_val = value;
        return;
      }
      curr = curr->m_next;
    }
    Node *new_node = new Node(key, value, table[index]);
    table[index] = new_node;
  }

  int get(int key) {
    int index = hash(key);
    Node *curr = table[index];

    while (curr != nullptr) {
      if (curr->m_key == key) {
        return curr->m_val;
      }
      curr = curr->m_next;
    }
    return -1;
  }

  void remove(int key) {
    int index = hash(key);
    Node *prev = nullptr;
    Node *curr = table[index];

    while (curr != nullptr) {
      if (curr->m_key == key) {
        if (prev == nullptr) {
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

  ~MyHashMap() {
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
    int m_val;
    Node *m_next;
    Node(int key, int val, Node *next) : m_key{key}, m_val{val}, m_next{next} {}
    Node(int key, int val) : m_key{key}, m_val{val}, m_next{nullptr} {}
  };
  Node *table[SIZE];

  int hash(int key) { return key % SIZE; }
};
