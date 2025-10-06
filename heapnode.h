#ifndef HEAPNODE_H
#define HEAPNODE_H

template<typename K, typename T>
class HeapNode {

  public:
    HeapNode(const K & = K(), const T & = T(), const size_t location = 0);
    void setLocation(const size_t);
    size_t getLocation();
    void setObject(const T &);
    T& getObject();
    void setKey(const K &);
    K& getKey();

  private:
    K key;
    T object;
    size_t location;

}; // HeapNode class

template <typename K, typename T>
HeapNode<K,T>::HeapNode(const K &key, const T &obj, const size_t loc) {
  setKey(key);
  setObject(obj);
  setLocation(loc);
}

template <typename K, typename T>
void HeapNode<K,T>::setLocation(const size_t location) {
  this->location = location;
}

template <typename K, typename T>
size_t HeapNode<K,T>::getLocation() {
  return location;
}

template <typename K, typename T>
void HeapNode<K,T>::setObject(const T &object) {
  this->object = object;
}

template <typename K, typename T>
T& HeapNode<K,T>::getObject() {
  return object;
}

template <typename K, typename T>
void HeapNode<K,T>::setKey(const K &key) {
  this->key = key;
}

template <typename K, typename T>
K& HeapNode<K,T>::getKey() {
  return key;
}


#endif // HEAPNODE_H
