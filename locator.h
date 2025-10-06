#ifndef LOCATOR_H
#define LOCATOR_H

#include "heap.h"
#include "heapnode.h"
#include "exceptions.h"

template <typename K, typename T> class Heap;

// Locator (GTM 8.4.2)

template<typename K, typename T>
class Locator {

  friend class Heap<K,T>;

  public:
    Locator();
    T &getObject();
    bool isPresent() const;
    void release();
    void setObject(const T &object);

  private:
    HeapNode<K,T> *entry;

}; // Locator class

template<typename K, typename T>
Locator<K,T>::Locator() {
  entry = nullptr;
}

template<typename K, typename T>
T& Locator<K,T>::getObject() {
  if (isPresent()) {
    return entry->getObject();
  }
  throw NoSuchObject("ERROR: in method Locator<K,T>::getObject()");
}

template<typename K, typename T>
void Locator<K,T>::setObject(const T &obj) {
  entry->setObject(obj);
}

template<typename K, typename T>
bool Locator<K,T>::isPresent() const {
  return (entry != nullptr);
}

template<typename K, typename T>
void Locator<K,T>::release() {
  entry = nullptr;
}

#endif // LOCATOR_H
