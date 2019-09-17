#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"

template <typename T>
class SelfList {
    public: 
        enum Method {
            Move, Count, Transpose
        };

    protected:
        Node<T>* head;
        Method method;

    public:
        SelfList(Method method) : head(nullptr), method{method} {};

        bool insert(T data) {
            Node<T>* temp = new Node<T>(data);
            if ( this->head == nullptr )
                this->head = temp;
            else {
                temp->next = this->head;
                this->head = temp;
            } return true;
        }
             
        bool remove(T data) {
            Node<T> **pointer = &head, *temp = head;
            if (head->data == data) {
                head = head->next;
                delete temp;
                return true;
            } if (size() > 1)
                for (int i = 1; i < size(); ++i, pointer = &(*pointer)->next)
                    if ((*pointer)->data == data) {
                        temp = *pointer;
                        *pointer = temp->next;
                        delete temp;
                        return true;
                    }
            return false;
        }  

        bool find(T data) {
            if (size() == 0) return false;
            Node<T> **pointer = &head, *temp = nullptr;

            if (this->method == Move){
                if (this->head->data ==  data) return true;
                while (*pointer != nullptr) {
                    if ((*pointer)->data == data) {
                        temp = *pointer;
                        *pointer = temp->next;
                        temp->next = this->head;
                        this->head = temp;
                        return true;
                    } pointer = &(*pointer)->next;
                }
            }
            
            if (this->method == Transpose) {
                if (this->head->data ==  data) return true;
                while ((*pointer)->next != nullptr) {
                    if ((*pointer)->next->data == data) {
                        temp = (*pointer)->next;
                        (*pointer)->next = temp->next;
                        temp->next = *pointer;
                        *pointer = temp;
                        return true;
                    } pointer = &(*pointer)->next;
                }
            }
            
            if (this->method == Count) {
                if (size() == 1 && head->data == data) {
                    head->count++; return true;
                }
                while (*pointer != nullptr) {
                    if ((*pointer)->data == data) {
                        temp = *pointer;
                        *pointer = temp->next;
                        temp->count++;
                        pointer = &head;
                        while ((*pointer)->count > temp->count)
                            pointer = &(*pointer)->next;
                        temp->next = *pointer;
                        *pointer = temp;
                        return true;
                    } pointer = &(*pointer)->next;
                }
            }
            
            return false;
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
            } else cout << "Empty List!\n";
        }

        ~SelfList() {
            if (this->head!=nullptr) this->head->killSelf();
        }  
};

#endif