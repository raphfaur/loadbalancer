// Copyright 2024 Raphaël Faure

#include <queue>
#include <set>
#include <vector>

template <typename V> struct Marker {
  V *value;
  int key;
  explicit Marker(V *v) {
    value = v;
    key = value->key();
  }
};

template <typename M> struct priority {
  bool operator()(const Marker<M> &m1, const Marker<M> &m2) const {
    return m1.key > m2.key;
  }
};

template <typename V> struct MinHeap {
  std::priority_queue<Marker<V>, std::vector<Marker<V>>, priority<V>> queue;
  std::set<V *> values;
  void push(V *value);
  V *top();
  void pop();
  void update(V *value);
};

template <typename V> void MinHeap<V>::push(V *value) {
  queue.push(Marker<V>(value));
}

template <typename V> void MinHeap<V>::update(V *value) {
  queue.push(Marker<V>(value));
}

template <typename V> V *MinHeap<V>::top() {
  Marker<V> top_marker = queue.top();
  while ((top_marker.key != top_marker.value->key()) &&  !queue.empty()) {
    queue.pop();
    top_marker = queue.top();
  }
  if (!queue.empty()) {
    return top_marker.value;
  }
  return nullptr;
}

template <typename V> void MinHeap<V>::pop() {
  Marker<V> top_marker = queue.top();
  while (top_marker.key != top_marker.value->key()) {
    queue.pop();
    top_marker = queue.top();
  }
  queue.pop();
}
