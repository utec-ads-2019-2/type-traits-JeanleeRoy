#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    int count = 0;
    Node<T>* next;
      
    Node(T data) : data(data) {
        next = nullptr;
    }
      
    void killSelf();
};

template <typename T>
void Node<T>::killSelf() {
    if (next) {
        next->killSelf();
    }
    
    delete this;
}

#endif