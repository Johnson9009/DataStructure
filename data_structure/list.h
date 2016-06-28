#ifndef DATA_STRUCTURE_AND_ALGORITHM_DATA_STRUCTURE_LIST_H_
#define DATA_STRUCTURE_AND_ALGORITHM_DATA_STRUCTURE_LIST_H_ 

#include <cstddef>

template <class T>
struct Node {
  Node() : value(), next(NULL) {}

  T value;
  Node *next;
};

#endif  // DATA_STRUCTURE_AND_ALGORITHM_DATA_STRUCTURE_LIST_H_
