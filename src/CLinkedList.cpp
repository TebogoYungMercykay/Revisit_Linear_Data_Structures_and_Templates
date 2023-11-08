#include "CLinkedList.h"

template <class T>
CLinkedList<T>::CLinkedList() {
    this->head = NULL;
}

template <class T>
CLinkedList<T>::~CLinkedList() {
    if (this->head != NULL) {
        this->clear();
        this->head = NULL;
    }
}

template <class T>
void CLinkedList<T>::prepend(T data) {
    Node* newNode = new Node(data, this->head);
    if (this->head == NULL) {
        this->head = newNode;
    } else {
        Node* current = this->head;
        while (current->next != this->head) {
            current = current->next;
        }
        current->next = newNode;
        this->head = newNode;
    }
}

template <class T>
void CLinkedList<T>::append(T data) {
    Node* newNode = new Node(data, this->head);
    if (this->head == NULL) {
        this->head = newNode;
    } else {
        Node* current = this->head;
        while (current->next != this->head) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template <class T>
void CLinkedList<T>::remove(int index) {
    int length = this->length();
    if (index < length && index >= 0) {
        Node<T>* nodeToRemove;
        if (index == 0) {
            nodeToRemove = this->head;
            Node<T>* current = this->head;
            while (current->next != this->head) {
                current = current->next;
            }
            current->next = this->head->next;
            this->head = this->head->next;
        } else {
            Node<T>* current = this->head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            nodeToRemove = current->next;
            current->next = current->next->next;
        }
        delete nodeToRemove;
        nodeToRemove = NULL;
    }
}

template <class T>
void CLinkedList<T>::insert(T data, int index) {
    int length = this->length();
    if (index <= length && index >= 0) {
        if (index == 0) {
            this->prepend(data);
        } else if (index == length) {
            this->append(data);
        } else {
            Node* newNode = new Node(data);
            Node* current = this->head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

template <class T>
void CLinkedList<T>::removeElements(T data) {
    Node<T>* current = this->head;
    Node<T>* predecessor = nullptr;
    while (current != nullptr) {
        if (current->data == data) {
            Node<T>* toDelete = current;
            if (predecessor == nullptr) {
                this->head = current->next;
            } else {
                predecessor->next = current->next;
            }
            current = current->next;
            delete toDelete;
        } else {
            predecessor = current;
            current = current->next;
        }

        // Checks to avoid infinite Looping
        if (current == this->head) {
            break;
        }
    }
}

template <class T>
void CLinkedList<T>::print() const {
    if (this->head == NULL) {
        std::cout << "Empty" << std::endl;
    } else {
        Node<T>* current = this->head;
        while (current->next != this->head) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << current->data << std::endl;
    }
}

template <class T>
void CLinkedList<T>::reverse() {
    int length = this->length() - 1;
    for (int k = 1, index = 1; k < length; k++) {
        Node<T>* current = this->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        this->prepend(current->data);
        this->remove(index + 1);
        index += 1;
    }
}

template <class T>
void CLinkedList<T>::clear() {
    while (this->head != NULL) {
        this->remove(0);
    }
}

template <class T>
int CLinkedList<T>::length() const {
    int size = 0;
    if (this->head != NULL) {
        size += 1;
        Node<T>* current = this->head->next;
        while (current != this->head) {
            size += 1;
            current = current->next;
        }
    }
    return size;
}

template <class T>
T CLinkedList<T>::get(int index) const {
	int length = this->length();
	int indexGet = 0;
    if (index >= 0 && index < length && this->head != NULL) {
		Node<T>* current = this->head->next;
		while (current != this->head && indexGet < length) {
			if (indexGet == index) {
				return current;
			}
			current = current->next;
			indexGet += 1;
		}
	}

	return T();
}

template <class T>
T CLinkedList<T>::operator[](int index) const {
    return this->get(index);
}

template <class T>
void CLinkedList<T>::filter(std::string op, T query) {
    // filter implementation goes here
}

template <class T>
void CLinkedList<T>::swap(int index1, int index2) {
    // swap implementation goes here
}

template <class T>
void CLinkedList<T>::slice(int start, int end) {
    // slice implementation goes here
}

template <class T>
void CLinkedList<T>::RRotate(int k) {
    // RRotate implementation goes here
}

template <class T>
void CLinkedList<T>::LRotate(int k) {
    // LRotate implementation goes here
}

template <class T>
void CLinkedList<T>::removeDuplicates() {
    // removeDuplicates implementation goes here
}

template <class T>
CLinkedList<T> &CLinkedList<T>::operator=(const CLinkedList<T> &other) {
    // operator= implementation goes here
}

template <class T>
bool CLinkedList<T>::operator==(const CLinkedList<T> &other) const {
    // operator== implementation goes here
}

template <class T>
void CLinkedList<T>::operator+=(const CLinkedList<T> &other) {
    // operator+= implementation goes here
}

template <class T>
CLinkedList<T>* CLinkedList<T>::operator-(const CLinkedList<T> &other) const {
    // operator- implementation goes here
}

template <class T>
void CLinkedList<T>::consume(CLinkedList<T> &other) {
    // consume implementation goes here
}
