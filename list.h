
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdlib>

template<class T>
class Node{
    private:
        T element;
        Node *leftElement;
        Node *rightElement;
    public:
        void setElement(T newElement) {element = newElement;}
        T & getElement(){ return element;}
        void setLeft (Node * left){leftElement = left; }
        Node * getLeft() {return leftElement;}
        void setRight(Node * right){rightElement = right;}
        Node * getRight(){return rightElement;}
        Node(){}
        ~Node() = default;

};

template<class T>
class List{
    private:
        Node<T> *head;
        Node<T> *tail;
        int size = 0;

    public:
        List(){
            head = nullptr;
            tail = nullptr;
        }

        ~List(){
                Node<T>* aux;
                while (head != nullptr){
                    aux = head;
                    head = head->getLeft();
                    delete aux;
                }
        }

        void insert(T newElement){
                Node<T>* newNode = new Node<T>();
                newNode->setElement(newElement);
                newNode->setRight(nullptr);

                if (head == nullptr){
                    newNode->setLeft(nullptr);
                    head = newNode;
                    tail = newNode;
                    size++;
                }
                else {
                    newNode->setLeft(tail);
                    tail->setRight(newNode);
                    tail= newNode;
                    size++;
                }
        }

        void remove (T byebyeElement){
            // @todo debugging version
            
            Node<T>* aux = head;
            bool done = false;
            
            while (!done && aux != nullptr){
                if (aux->getElement() == byebyeElement){
                    if (size > 1){
                        // remove TAIL
                        if (byebyeElement == tail->getElement()){
                            tail = tail->getLeft();
                            tail->setRight(nullptr);

                        // remove HEAD
                        } else if (byebyeElement == head->getElement()) {
                            head = head->getRight();
                            head->setLeft(nullptr);

                        // remove random element
                        } else {   
                            Node<T> * right = aux->getRight();
                            Node<T> * left = aux->getLeft();
                            if (right != nullptr)
                                right->setLeft(left);
                            if (left != nullptr)
                                left->setRight(right); 
                        }
                    }
                    done = true;
                    size--;
                    delete aux;
                } else {
                    aux = aux->getRight();
                }
            }
        }

        Node<T>* getHead(){
            return head;
        }

        int getSize(){
            return size;
        }

        void moveHeadToEnd(){
            Node<T>* aux = head;
            head = aux->getRight();
            head->setLeft(nullptr);
            tail->setRight(aux);
            aux->setLeft(tail);
            aux->setRight(nullptr);
            tail = aux;
        }

};

#endif /* LIST_H */

