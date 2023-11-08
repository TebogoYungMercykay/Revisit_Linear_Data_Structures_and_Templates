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
            Node<T>* nodeToRemove = current;
            if (predecessor == nullptr) {
                this->head = current->next;
            } else {
                predecessor->next = current->next;
            }
            current = current->next;
            delete nodeToRemove;
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
	if (this->head != NULL) {
		if (index == 0) {
			return this->head->data;
		} else if (index > 0 && index < length) {
			Node<T>* current = this->head->next;
			while (current != this->head && indexGet < length) {
				if (indexGet == index) {
					return current;
				}
				current = current->next;
				indexGet += 1;
			}
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
    if (this->head != NULL) {
        if (op == ">") {
            Node<T>* current = this->head;
            Node<T>* predecessor = NULL;
            do {
                if (!(current->data > query)) {
                    Node<T>* nodeToRemove = current;
                    if (predecessor == NULL) {
                        this->head = current->next;
                    } else {
                        predecessor->next = current->next;
                    }
                    current = current->next;
                    delete nodeToRemove;
                } else {
                    predecessor = current;
                    current = current->next;
                }
            } while (current != this->head);
        } else if (op == "<") {
			Node<T>* current = this->head;
            Node<T>* predecessor = NULL;
            do {
                if (!(current->data < query)) {
                    Node<T>* nodeToRemove = current;
                    if (predecessor == NULL) {
                        this->head = current->next;
                    } else {
                        predecessor->next = current->next;
                    }
                    current = current->next;
                    delete nodeToRemove;
                } else {
                    predecessor = current;
                    current = current->next;
                }
            } while (current != this->head);
		} else if (op == ">=") {
			Node<T>* current = this->head;
            Node<T>* predecessor = NULL;
            do {
                if (!(current->data >= query)) {
                    Node<T>* nodeToRemove = current;
                    if (predecessor == NULL) {
                        this->head = current->next;
                    } else {
                        predecessor->next = current->next;
                    }
                    current = current->next;
                    delete nodeToRemove;
                } else {
                    predecessor = current;
                    current = current->next;
                }
            } while (current != this->head);
		} else if (op == "<=") {
			Node<T>* current = this->head;
            Node<T>* predecessor = NULL;
            do {
                if (!(current->data <= query)) {
                    Node<T>* nodeToRemove = current;
                    if (predecessor == NULL) {
                        this->head = current->next;
                    } else {
                        predecessor->next = current->next;
                    }
                    current = current->next;
                    delete nodeToRemove;
                } else {
                    predecessor = current;
                    current = current->next;
                }
            } while (current != this->head);
		} else if (op == "==") {
			Node<T>* current = this->head;
            Node<T>* predecessor = NULL;
            do {
                if (!(current->data == query)) {
                    Node<T>* nodeToRemove = current;
                    if (predecessor == NULL) {
                        this->head = current->next;
                    } else {
                        predecessor->next = current->next;
                    }
                    current = current->next;
                    delete nodeToRemove;
                } else {
                    predecessor = current;
                    current = current->next;
                }
            } while (current != this->head);
		} else if (op == "!=") {
			Node<T>* current = this->head;
            Node<T>* predecessor = NULL;
            do {
                if (!(current->data != query)) {
                    Node<T>* nodeToRemove = current;
                    if (predecessor == NULL) {
                        this->head = current->next;
                    } else {
                        predecessor->next = current->next;
                    }
                    current = current->next;
                    delete nodeToRemove;
                } else {
                    predecessor = current;
                    current = current->next;
                }
            } while (current != this->head);
		}
    }
}

template <class T>
void CLinkedList<T>::swap(int index1, int index2) {
	int length = this->length();
	if (index1 >= 0 && index1 < length && index2 >= 0 && index2 < length && index1 != index2) {
		Node<T>* node1 = this->head;
		Node<T>* node2 = this->head;
		for (int i = 0; i < index1; i++) {
			node1 = node1->next;
		}
		for (int i = 0; i < index2; i++) {
			node2 = node2->next;
		}
		T temp = node1->data;
		node1->data = node2->data;
		node2->data = temp;
	}
}

template <class T>
void CLinkedList<T>::slice(int start, int end) {
	int length = this->length();
	if (start >= 0 && start < length && end >= 0 && end < length && start < end) {
		for (int i = 0; i < start; i++) {
			this->remove(0);
		}
		for (int i = end - start + 1; i < this->length() - 1; i++) {
			this->remove(end - start + 1);
		}
	}
}

template <class T>
void CLinkedList<T>::RRotate(int k) {
    int length = this->length();
    if (length == 0 || k < 0) {
        return;
    }

    k = k % length;
    Node<T>* tail = this->head;
    while(tail->next != this->head) {
        tail = tail->next;
    }

    for (int i = 0; i < k; i++) {
        tail->next = this->head;
        this->head = this->head->next;
        tail = tail->next;
    }
}

template <class T>
void CLinkedList<T>::LRotate(int k) {
    int length = this->length();
    if (length == 0 || k < 0) {
        return;
    }

    k = k % length;
    Node<T>* tail = this->head;
    while(tail->next != this->head) {
        tail = tail->next;
    }

    for (int i = 0; i < length - k; i++) {
        tail->next = this->head;
        this->head = this->head->next;
        tail = tail->next;
    }
}

template <class T>
void CLinkedList<T>::removeDuplicates() {
	if (this->head != NULL) {
		Node<T>* current = this->head;
		do {
			Node<T>* check = current;
			while (check->next != this->head) {
				if (check->next->data == current->data) {
					Node<T>* temp = check->next;
					check->next = check->next->next;
					temp->next = NULL;
					delete temp;
					temp = NULL;
				} else {
					check = check->next;
				}
			}
			current = current->next;
		} while (current != this->head);
	}
}

template <class T>
CLinkedList<T>& CLinkedList<T>::operator=(const CLinkedList<T>& other) {
	if (this != &other) {
		this->clear();
		Node<T>* current = other.head;
		do {
			this->append(current->data);
			current = current->next;
		} while (current != other.head);
	}

	return *this;
}

template <class T>
bool CLinkedList<T>::operator==(const CLinkedList<T> &other) const {
    if (this->length() != other.length()) {
        return false;
    }

    CLinkedList<T> list1 = *this;
    CLinkedList<T> list2 = other;

    Node<T>* current1 = list1.head;
    do {
        Node<T>* current2 = list2.head;
        Node<T>* predecessor2 = nullptr;
        while (current2 != nullptr && current2->data != current1->data) {
            predecessor2 = current2;
            current2 = current2->next;
        }
        if (current2 == nullptr) {
            return false;
        }
        if (predecessor2 == nullptr) {
            list2.head = current2->next;
        } else {
            predecessor2->next = current2->next;
        }
        delete current2;
        current1 = current1->next;
    } while (current1 != list1.head);

    if (list2.head != nullptr) {
        return false;
    }

    list2 = *this;
    current1 = other.head;
    do {
        Node<T>* current2 = list2.head;
        Node<T>* predecessor2 = nullptr;
        while (current2 != nullptr && current2->data != current1->data) {
            predecessor2 = current2;
            current2 = current2->next;
        }
        if (current2 == nullptr) {
            return false;
        }
        if (predecessor2 == nullptr) {
            list2.head = current2->next;
        } else {
            predecessor2->next = current2->next;
        }
        delete current2;
        current1 = current1->next;
    } while (current1 != other.head);

    return list2.head == nullptr;
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
