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

            // INSERT OPERATIONS.

            // Insert at the begining of the list.
            void push_front(const T& value) {
                Node* newNode = new Node(value);

                if (head == nullptr) {
                    head = tail = newNode;
                } else {
                    newNode -> next = head;
                    head->prev = newNode;
                    head = newNode;
                }
                size++;
            }

            // Insert at the end of the list
            void push_back(const T& value) {
                Node* newNode = new Node(value);

                if (tail == nullptr) {
                    head = tail = newNode;
                } else {
                    tail->next = newNode;
                    newNode->prev = tail;
                    tail = newNode;
                }
                size++;
            }

            // Inserting at specific position.
            void insert(size_t position, const T& value) {
                if (position > size) {
                    throw std::out_of_range("Position out of range");
                }

                if (position == 0) {
                    push_front(value);
                    return;
                }

                if (position == size) {
                    push_back(value);
                    return;
                }

                Node* newNode = new Node(value);
                Node* current = head;

                for (size_t i = 0; i < position; i++) {
                    current = current->next;
                }

                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev= newNode;

                size++;
            }

            // DELETE OPERATIONS.
            // Remove from the first element.
            void pop_front() {
                if (head == nullptr) {
                    throw std::runtime_error("Cannot pop from empty list");
                }

                Node* nodeToDelete = head;

                if (head == tail) {
                    head = tail = nullptr;
                } else {
                    head = head->next;
                    head->prev = nullptr;
                }
                delete nodeToDelete;
                size--;
            }

            // remove the last element.
            void pop_back() {
                if (tail == nullptr) {
                    throw std::runtime_error("Cannot pop from empty list");
                }

                Node* nodeToDelete = tail;

                if (head == tail) {
                    head = tail = nullptr;
                } else {
                    tail = tail->prev;
                    tail->next = nullptr;
                }
                delete nodeToDelete;
                size--;
            }

            // removing element at specific position.
            void erase(size_t position) {
                if (position >= size) {
                    throw std::out_of_range("Position out of range");
                }

                if (position == 0) {
                    pop_front();
                    return;
                }

                if (position == size - 1) {
                    pop_back();
                    return;
                }

                Node* current = head;

                // navigate to the position.
                for (size_t i = 0; i < position; i++) {
                    current = current->next;
                }

                // updating the connections
                current->prev->next = current->next;
                current->next->prev = current->prev;

                delete current;
                size--;
            }

            // remove first occurence of a value.
            bool remove(const T& value) {
                Node* current = head;

                while (current != nullptr) {
                    if (current->data == value) {
                        if (current == head && current ==  tail) {
                            head = tail = nullptr;
                        } else if (current == head) {
                            head = head->next;
                            head->prev = nullptr;
                        } else if (current == tail) {
                            tail = tail->prev;
                            tail->prev = nullptr;
                        } else {
                            current->prev->next = current->next;
                            current->next->prev = current->prev;
                        }
                        delete current;
                        size--;
                        return true;
                    }
                    current = current->next;
                }
                return false;
            }

            // SEARCH OPERATIONS.

            // find position of a value.
            int find(const T& value) const {
                Node* current = head;
                int position = 0;

                while (current != nullptr) {
                    if (current->data == value) {
                        return position;
                    }
                    current = current->next;
                    position++;
                }
                return -1;
            }

            // checking if the list contains a value.
            bool contains(const T& value) const {
                return find(value) != -1;
            }

            // ACCESS OPERATIONS.
            // get reference to first element.
            T& front() {
                if (head == nullptr) {
                    throw std::runtime_error("List is empty");
                }
                return head->data;
            }

            // get const reference to first element.
            const T& front() const {
                if (head == nullptr) {
                    throw std::runtime_error("List is empty");
                }
                return head->data;
            }

            // get reference to the last element.
            T& back() {
                if (tail == nullptr) {
                    throw std::runtime_error("List is empty");
                }
                return tail->data;
            }

            // get const reference to the last element.
            const T& back() const {
                if (tail == nullptr) {
                    throw std::runtime_error("List is empty");
                }
                return tail->data;
            }

            // Get element at specific position.
            T& at(size_t position) {
                if (position >= size) {
                    throw std:::out_of_range("Position out of range");
                }

                Node* current = head;
                for (size_t = 0; i < position; i++) {
                    current = current->next;
                }
                return current->data;
            }

            // get const element at specific position.
            const T& at(size_t position) const {
                if (position >= size) {
                    throw std::out_of_range("Position out of range");
                }
                Node* current = head;
                for (size_t = 0; i < position; i++) {
                    current = current->next;
                }
                return current->data;
            }

            // UTILITY OPERATIONS.

            // checking if the list is empty.
            bool empty() const {
                return size == 0;
            }

            // getting the number of elements.
            size_t getSize() const {
                return size;
            }

            // remove all elements.
            void clear() {
                while (head != nullptr) {
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                }
                tail = nullptr;
                size = 0;
            }

            // reversing a doubly linked list.
            void reverse() {
                if (size <= 1) return;

                Node* current = head;
                Node* temp = nullptr;

                // swap the next and prev pointees for all nodes.
                while (current != nullptr) {
                    temp = current->prev;
                    current->prev = current->next;
                    current->next = temp;
                    current = current->prev;
                }
                temp = head;
                head = tail;
                tail = temp;
            }

            // DISPLAY OPERATIONS.
            void printForward() const {
                Node* current = head;
                std::cout << "Forward: ";
                while (current != nullptr) {
                    std::cout << current-data << " ";
                    current = current->next;
                }
                std::cout << std::endl;
            }

            // print list from tail to head.
            void printBackward() cont {
                Node* current = tail;
                std::cout<< "Backward: ";
                while (current != nullptr) {
                    std::cout << current->data << " ";
                    current = current->prev;
                }
                std::cout << std::endl;
            }
};

// Example usage and testing
int main() {
    // Create a doubly linked list of integers
    DoublyLinkedList<int> list;
    
    std::cout << "=== Testing Doubly Linked List ===" << std::endl;
    
    // Test insertions
    std::cout << "\n1. Testing insertions:" << std::endl;
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.insert(2, 15);
    
    std::cout << "After insertions (5, 10, 15, 20):" << std::endl;
    list.printForward();
    list.printBackward();
    std::cout << "Size: " << list.getSize() << std::endl;
    
    // Test access operations
    std::cout << "\n2. Testing access operations:" << std::endl;
    std::cout << "Front element: " << list.front() << std::endl;
    std::cout << "Back element: " << list.back() << std::endl;
    std::cout << "Element at position 2: " << list.at(2) << std::endl;
    
    // Test search operations
    std::cout << "\n3. Testing search operations:" << std::endl;
    std::cout << "Position of 15: " << list.find(15) << std::endl;
    std::cout << "Contains 25: " << (list.contains(25) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 10: " << (list.contains(10) ? "Yes" : "No") << std::endl;
    
    // Test deletions
    std::cout << "\n4. Testing deletions:" << std::endl;
    list.pop_front();
    std::cout << "After pop_front:" << std::endl;
    list.printForward();
    
    list.pop_back();
    std::cout << "After pop_back:" << std::endl;
    list.printForward();
    
    list.remove(15);
    std::cout << "After removing 15:" << std::endl;
    list.printForward();
    
    // Test reverse
    std::cout << "\n5. Testing reverse:" << std::endl;
    list.push_back(30);
    list.push_back(40);
    std::cout << "Before reverse:" << std::endl;
    list.printForward();
    
    list.reverse();
    std::cout << "After reverse:" << std::endl;
    list.printForward();
    
    return 0;
}