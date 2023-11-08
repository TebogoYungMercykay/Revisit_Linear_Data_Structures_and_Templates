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
int CLinkedList<T>::length() const {
    int size = 0;
    if (this->head != NULL) {
        size += 1;
        Node<T>* current = this->head->next;
        while (current != NULL && current != this->head) {
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
			Node<T>* current = this->head;
            do {
				if (indexGet == index) {
					return current->data;
				}
				current = current->next;
				indexGet += 1;
            } while (current != NULL && current != this->head);
		}
	}

	return T();
}

template <class T>
void CLinkedList<T>::prepend(T data) {
    Node<T>* newNode = new Node<T>(data, this->head);
    if (this->head == NULL) {
        this->head = newNode;
        this->head->next = newNode;
    } else {
        Node<T>* current = this->head;
        while (current->next != NULL && current->next != this->head) {
            current = current->next;
        }
        current->next = newNode;
        this->head = newNode;
    }
}

template <class T>
void CLinkedList<T>::append(T data) {
    Node<T>* newNode = new Node<T>(data, this->head);
    if (this->head == NULL) {
        this->head = newNode;
        this->head->next = newNode;
    } else {
        Node<T>* current = this->head;
        while (current->next != NULL && current->next != this->head) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template <class T>
void CLinkedList<T>::remove(int index) {
    int length = this->length();
    if (index < length && index >= 0 && this->head != NULL && length > 0) {
        Node<T>* nodeToRemove;
        if (index == 0 && length == 1) {
            this->head->next = NULL;
            delete this->head;
            this->head = NULL;
        } else if (index == 0 && length != 1) {
            Node<T>* current = this->head;
            while (current->next != NULL && current->next != this->head) {
                current = current->next;
            }
            current->next = this->head->next;
            nodeToRemove = this->head;
            this->head = this->head->next;
            nodeToRemove->next = NULL;
            delete nodeToRemove;
            nodeToRemove = NULL;
        } else if (index == 1 && length == 2) {
            nodeToRemove = this->head->next;
            this->head->next = this->head;
            nodeToRemove->next = NULL;
            delete nodeToRemove;
            nodeToRemove = NULL;
        } else {
            Node<T>* current = this->head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            nodeToRemove = current->next;
            current->next = current->next->next;
            nodeToRemove->next = NULL;
            delete nodeToRemove;
            nodeToRemove = NULL;
        }
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
            Node<T>* newNode = new Node<T>(data);
            Node<T>* current = this->head;
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
    if (this->head != NULL) {
        for (int k = 0; k < this->length(); k++) {
            if (k < this->length()) {
                if (this->get(k) == data) {
                    this->remove(k);
                    k--;
                }
            }
        }
    }
}

template <class T>
void CLinkedList<T>::print() const {
    if (this->head == NULL) {
        std::cout << "Empty" << std::endl;
    } else {
        Node<T>* current = this->head;
        while (current->next != NULL && current->next != this->head) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << current->data << std::endl;
    }
}

template <class T>
void CLinkedList<T>::reverse() {
    int length = this->length();
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
    if (this->head != NULL) {
        Node<T>* current = this->head;
        while (current != NULL && current->next != this->head) {
            Node<T>* nodeToDelete = current->next;
            current->next = current->next->next;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
            nodeToDelete = NULL;
        }
        this->head->next = NULL;
        delete this->head;
        this->head = NULL;
    }
}

template <class T>
T CLinkedList<T>::operator[](int index) const {
    return this->get(index);
}

// Here

template <class T>
void CLinkedList<T>::filter(std::string op, T query) {
    if (this->head != NULL) {
        if (op == ">") {
            for (int k = 0; k < this->length(); k++) {
                if (k < this->length()) {
                    if (!(this->get(k) > query)) {
                        this->remove(k);
                        k--;
                    }
                }
            }
        } else if (op == "<") {
			for (int k = 0; k < this->length(); k++) {
                if (k < this->length()) {
                    if (!(this->get(k) < query)) {
                        this->remove(k);
                        k--;
                    }
                }
            }
		} else if (op == ">=") {
			for (int k = 0; k < this->length(); k++) {
                if (k < this->length()) {
                    if (!(this->get(k) >= query)) {
                        this->remove(k);
                        k--;
                    }
                }
            }
		} else if (op == "<=") {
			for (int k = 0; k < this->length(); k++) {
                if (k < this->length()) {
                    if (!(this->get(k) <= query)) {
                        this->remove(k);
                        k--;
                    }
                }
            }
		} else if (op == "==") {
			for (int k = 0; k < this->length(); k++) {
                if (k < this->length()) {
                    if (!(this->get(k) == query)) {
                        this->remove(k);
                        k--;
                    }
                }
            }
		} else if (op == "!=") {
			for (int k = 0; k < this->length(); k++) {
                if (k < this->length()) {
                    if (!(this->get(k) != query)) {
                        this->remove(k);
                        k--;
                    }
                }
            }
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
	if (start >= 0 && start < length && end >= 0 && end < length && start <= end) {
		for (int i = 0; i < start; i++) {
			this->remove(0);
		}
		for (int i = 0; i <= (end - start) + 1; i++) {
			this->remove((end - start) + 1);
		}
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

    for (int i = 0; i < k; i++) {
        tail->next = this->head;
        this->head = this->head->next;
        tail = tail->next;
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
    if (this != &other) {
        int firstLength = this->length();
        int secondLength = other.length();
        CLinkedList<T> secondList;
        CLinkedList<T> firstList;
        if (firstLength == secondLength) {
            for (int i = 0; i < firstLength; i++) {
                firstList.append(this->get(i));
            }
            for (int i = 0; i < secondLength; i++) {
                secondList.append(other.get(i));
            }
            for (int i = 0; i < firstList.length(); ) {
                bool found = false;
                for (int j = 0; j < secondList.length(); j++) {
                    if (firstList.get(i) == secondList.get(j)) {
                        firstList.remove(i);
                        secondList.remove(j);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    i++;
                }
            }

            return firstList.length() == 0 && secondList.length() == 0;
        }
        return false;
    } else {
        return true;
    }
}

template <class T>
void CLinkedList<T>::operator+=(const CLinkedList<T> &other) {
    if (!(*this == other)) {
        Node<T>* current = other.head;
        do {
            this->append(current->data);
            current = current->next;
        } while (current != other.head);
    }
}

template <class T>
CLinkedList<T>* CLinkedList<T>::operator-(const CLinkedList<T> &other) const {
    CLinkedList<T>* result = new CLinkedList<T>();
    *result = *this;
    Node<T>* current = other.head;
    do {
        result->removeElements(current->data);
        current = current->next;
    } while (current != other.head);
    return result;
}

template <class T>
void CLinkedList<T>::consume(CLinkedList<T> &other) {
    if (this != &other && other.head != NULL) {
        if (this->head == NULL) {
            this->head = other.head;
        } else {
            Node<T>* current = this->head;
            while (current->next != this->head) {
                current = current->next;
            }
            current->next = other.head;
            Node<T>* otherCurrent = other.head;
            while (otherCurrent->next != other.head) {
                otherCurrent = otherCurrent->next;
            }
            otherCurrent->next = this->head;
        }
        other.head = NULL;
    }
}
