// Copyright 2024 Raphaël Faure
#include <queue>
#include <set>
#include <vector>

template <typename I> struct load {
  int operator()(I *i1, I *i2) const {
    return i1->get_charge() > i2->get_charge();
  }
};

template <typename I> struct Balancer {
  std::set<I *> instances;
  std::priority_queue<I *, std::vector<I *>, load<I>> queue;
  int insert(I *instance);
  I *laziest();
};

template <typename I> int Balancer<I>::insert(I *instance) {
  instances.insert(instance);
  queue.push(instance);
  return instances.size();
}

template <typename I> I *Balancer<I>::laziest() { return queue.top(); };
