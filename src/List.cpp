// #include "List.h"

template <class T>
List<T>& List<T>::operator=(const List<T>& other) {
    if (this != &other) {
        this->clear();
        // Copying elements from the 'other' list to 'this' list
        for (int i = 0; i < other.length(); i++) {
            this->append(other.get(i));
        }
    }

    return *this;
}
