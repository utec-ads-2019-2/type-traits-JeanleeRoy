#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include <iostream>
#include "node.h"

template <typename Tr>
class TraitsList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;

        bool find(T data, Node<T> **&pointer) {
            pointer = &head;
            while (*pointer != nullptr) {
                if ((*pointer)->data == data)
                    return true;
                if (cmp(data, (*pointer)->data))
                    return false;
                pointer = &(*pointer)->next;
            } return false;
        }
              
    public:
        TraitsList() : head(nullptr) {};
             
        bool insert(T data) {
            Node<T> **pointer=nullptr, *node = new Node<T>(data);
            if (!find(data, pointer)) {
                node->next = (*pointer);
                *pointer = node;
                return true;
            } return false;
        }
             
        bool remove(T data) {
            Node<T> **pointer=nullptr, **temp=nullptr;
            if (find(data, pointer)) {
                // Aquí algo está fallando, no puedes borrar así un doble puntero. Deberías borrar el contenido
                temp = pointer;
                *pointer = (*pointer)->next;
                delete temp;
                return true;
            } return false;
        }  

        bool find(T data) {
            Node<T> **pointer;
            return find(data, pointer);
        }

        T operator [] (int index) {
            if (index < 0 || index >= this->size())
                throw out_of_range("Out of range");
            Node<T>* temp = this->head;
            for (int i = 0; i < index; ++i)
                temp = temp->next;
            return temp->data;
        }
             
        int size() {
            int c = 0;
            Node<T> *temp = this->head;
            while (temp != nullptr) {
                temp = temp->next; c++;
            } return c;
        }

        void print() {
            if (this->head != nullptr) {
                Node<T>* temp = this->head;
                for (int i = 0; i < this->size(); ++i, temp = temp->next){
                    cout << temp->data << " ";
                } cout << endl;
            } else cout << "Empty List!";
        }

        ~TraitsList() {
            if (this->head!=nullptr) this->head->killSelf();
        }         
};

#endif