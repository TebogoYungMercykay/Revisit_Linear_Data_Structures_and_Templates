#include "Queue.h"

template <class T>
Queue<T>::Queue() {
    this->head = NULL;
    this->tail = NULL;
}

template <class T>
Queue<T>::Queue(const Queue<T>& other) {
    this->head = this->tail = NULL;
    if (other.isEmpty() == false) {
        Node<T>* insertNode = other.head;
        while (insertNode != NULL) {
            this->enqueue(insertNode->data);
            insertNode = insertNode->next;
        }
    }
}

template <class T>
Queue<T>* Queue<T>::clone() const {
    return new Queue(*this);
}

template <class T>
Queue<T>::~Queue() {
    if (this->isEmpty() == false) {
        while (this->head != NULL) {
            Node<T>* tempDelete = this->head;
            this->head = this->head->next;
            delete tempDelete;
        }
        this->tail = NULL;
    }
}

template <class T>
void Queue<T>::enqueue(T data) {
    Node<T>* insertNode = new Node<T>(data);
    if (this->tail == NULL && this->head == NULL) {
        this->head = this->tail = insertNode;
    } else {
        this->tail->next = insertNode;
        this->tail = insertNode;
    }
}

template <class T>
T Queue<T>::dequeue() {
    if (this->isEmpty() == false) {
        Node<T>* removedNode = this->head;
        T removedData = removedNode->data;
        this->head = this->head->next;
        if (this->head == NULL) {
            this->tail = NULL;
        }
        delete removedNode;
        return removedData;
    }

    return T();
}

template <class T>
const T Queue<T>::peek() const {
    if (this->isEmpty() == false) {
        return this->head->data;
    } else {
        return T();
    }
}

template <class T>
bool Queue<T>::isEmpty() const {
    return (this->head == NULL && this->tail == NULL);
}
