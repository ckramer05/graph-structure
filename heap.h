#ifndef HEAP_H
#define HEAP_H

#include "locator.h"
#include "heapnode.h"
#include "exceptions.h"

template <typename K, typename T>
class Heap {

  public:
    Heap();
    ~Heap();
    void changeKey( const K &, const Locator<K,T> & );
    void clear();
    bool empty() const;
    // priorities/keys are not unique
    Locator<K,T> insert( const K &, const T & );
    T remove(); // throws NoSuchObject
    void print();

  private:
    // It's better to move around pointers instead of nodes of big objects
    vector< HeapNode<K,T> * > heap;
    int last;

    int getLeftChild(const int position) const;
    int getRightChild(const int position) const;
    int getParent(const int position) const;
    
    void up_heap_bubble(const int position);
    void down_heap_bubble(const int position);
};

template <typename K, typename T>
Heap<K,T>::Heap() {
  last = -1;
}

template <typename K, typename T>
Heap<K,T>::~Heap() {
  clear();
}

template <typename K, typename T>
void Heap<K,T>::changeKey(const K &key, const Locator<K,T> &locator) {
  int position = locator.entry->getLocation();
  K oldKey = heap[position]->getKey();
  heap[position]->setKey(key);
  if (key < oldKey) {
    up_heap_bubble(position);
  }
  else if (key > oldKey) {
    down_heap_bubble(position);
  }
}

template <typename K, typename T>
void Heap<K,T>::clear() {
  while (last > -1) {
    delete heap[last];
    last--;
  }
}

template <typename K, typename T>
bool Heap<K,T>::empty() const {
  return (last == -1);
}

template <typename K, typename T>
Locator<K,T> Heap<K,T>::insert(const K &key, const T &obj) {
  HeapNode<K,T> *node = new HeapNode<K,T>(key, obj, heap.size());
  heap.push_back(node);
  last++;
  
  if ((node->getLocation() != 0) && (node->getKey() < heap[getParent(node->getLocation())]->getKey())) {
    up_heap_bubble(node->getLocation());
  }
  
  Locator<K,T> locator = Locator<K,T>();
  locator.entry = node;
  return locator;
}

template <typename K, typename T>
T Heap<K,T>::remove() {
  T removed;

  if (!empty()) {
    removed = heap[0]->getObject();
    delete heap[0];
    heap[0] = heap[last];
    heap[0]->setLocation(0);
    heap[last] = nullptr;
    last--;
    down_heap_bubble(0);
  } 
  else {
    throw NoSuchObject("ERROR: NoSuchObject in method remove()");
  }
   
  return removed;
}

template <typename K, typename T>
int Heap<K,T>::getLeftChild(const int position) const {
  return ((position+1)*2)-1;
}

template <typename K, typename T>
int Heap<K,T>::getRightChild(const int position) const {
  return ((position+1)*2+1)-1;
}

template <typename K, typename T>
int Heap<K,T>::getParent(const int position) const {
  return ((position+1)/2)-1;
}

template <typename K, typename T>
void Heap<K,T>::up_heap_bubble(const int position) {
  int current = position;
  int parent = getParent(position);

  while ((current > 0) && (heap[parent]->getKey() > heap[current]->getKey())) {
    HeapNode<K,T> *temp = heap[current];
    heap[current] = heap[parent];
    heap[current]->setLocation(current);
    heap[parent] = temp;
    heap[parent]->setLocation(parent);
    
    current = parent;
    parent = getParent(parent);
  }
}

template <typename K, typename T>
void Heap<K,T>::down_heap_bubble(const int position) {
  int minimum = position;
  int leftChild = getLeftChild(position);
  int rightChild = getRightChild(position);

  if ((leftChild <= last) && (heap[minimum]->getKey() > heap[leftChild]->getKey())) {
      minimum = leftChild;
  }
  if ((rightChild <= last) && (heap[minimum]->getKey() > heap[rightChild]->getKey())) {
      minimum = rightChild;
  }
  
  if (minimum != position) {
      HeapNode<K,T> *temp = heap[position];
      heap[position] = heap[minimum];
      heap[position]->setLocation(position);
      heap[minimum] = temp;
      heap[minimum]->setLocation(minimum);
      
      down_heap_bubble(minimum);
  }
}

template <typename K, typename T>
void Heap<K,T>::print() {
  if (empty()) {
    cout << "Heap is empty" << endl;
  }
  else {
    cout << "Heap = [";
    for (int i = 0; i <= last; i++) {
      cout << "(" << heap[i]->getLocation() << ", " << heap[i]->getKey() << ", " << heap[i]->getObject() << "),";
    }
    cout << "]" << endl;
  }
}

#endif // HEAP_H
