#include <iostream>
#include <stdexcept>

template<typename T>
class DoublyLinkedList {
    private:
        struct Node {
            T data;
            Node* next;
            Node* prev;

            Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
        };

        Node* head;
        Node* tail;
        size_t size;
    
        public:
            DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

            ~DoublyLinkedList() {
                clear();
            }

            // copy constructor, create a deep copy of list.
            DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr), size(0) {
                Node* current = other.head;
                while (current != nullptr) {
                    push_back(current->data);
                    current = current->next;
                }
            }

            // assignment operator.
            DoublyLinkedList& operator=(const DoublyLinkedList& other) {
                if (this != &other) {
                    clear();
                    Node* current = other.head;
                    while (current != nullptr) {
                        push_back(current->data);
                        current = current->next;
                    }
                }
                return *this;
            }
};