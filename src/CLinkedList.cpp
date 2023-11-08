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
    // prepend implementation goes here
}

template <class T>
void CLinkedList<T>::append(T data) {
    // append implementation goes here
}

template <class T>
void CLinkedList<T>::remove(int index) {
    // remove implementation goes here
}

template <class T>
void CLinkedList<T>::insert(T data, int index) {
    // insert implementation goes here
}

template <class T>
void CLinkedList<T>::removeElements(T data) {
    // removeElements implementation goes here
}

template <class T>
void CLinkedList<T>::print() const {
    // print implementation goes here
}

template <class T>
void CLinkedList<T>::reverse() {
    // reverse implementation goes here
}

template <class T>
void CLinkedList<T>::clear() {
    // clear implementation goes here
}

template <class T>
int CLinkedList<T>::length() const {
    // length implementation goes here
}

template <class T>
T CLinkedList<T>::get(int index) const {
    // get implementation goes here
}

template <class T>
T CLinkedList<T>::operator[](int index) const {
    // operator[] implementation goes here
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
CLinkedList<T> *CLinkedList<T>::operator-(const CLinkedList<T> &other) const {
    // operator- implementation goes here
}

template <class T>
void CLinkedList<T>::consume(CLinkedList<T> &other) {
    // consume implementation goes here
}
