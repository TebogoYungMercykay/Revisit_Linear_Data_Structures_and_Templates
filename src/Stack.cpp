// #include "Stack.h"

template <class T>
Stack<T>::Stack() {
    this->top = NULL;
}

template <class T>
Stack<T>::Stack(const Stack<T>& other) {
    this->top = NULL;

    Stack<T> temporaryStack;
    Node<T>* insertNode = other.top;
    while (insertNode != NULL) {
        temporaryStack.push(insertNode->data);
        insertNode = insertNode->next;
    }

    while (temporaryStack.isEmpty() == false) {
        this->push(temporaryStack.pop());
    }
}

template <class T>
Stack<T>::~Stack() {
    while (this->top != NULL) {
        Node<T>* tempDelete = this->top->next;
        this->top->next = NULL;
        delete this->top;
        this->top = tempDelete;
    }
}

template <class T>
void Stack<T>::push(T data) {
    if (this->top == NULL) {
        Node<T>* insertNode = new Node<T>(data);
        this->top = insertNode;
    } else {
        Node<T>* insertNode = new Node<T>(data, this->top);
        this->top = insertNode;
    }
}

template <class T>
T Stack<T>::pop() {
    if (this->isEmpty() == false) {
        T data = this->top->data;
        Node<T>* removedNode = this->top;
        this->top = this->top->next;
        removedNode->next = NULL;
        delete removedNode;
        removedNode = NULL;

        return data;
    }

    return T();
}

template <class T>
const T Stack<T>::peek() const {
    if (this->isEmpty() == false) {
        return this->top->data;
    } else {
        return T();
    }
}

template <class T>
bool Stack<T>::isEmpty() const {
    return (this->top == NULL);
}
