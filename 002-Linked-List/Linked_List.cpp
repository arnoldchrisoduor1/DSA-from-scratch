#include <iostream>
#include <stdexcept>

template<typename T>
class DoublyLinkedList {
private:
    // Node structure - contains data and pointers to both next and previous nodes
    struct Node {
        T data;           // The actual data stored in the node
        Node* next;       // Pointer to the next node in the list
        Node* prev;       // Pointer to the previous node in the list
        
        // Constructor for creating a new node
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };
    
    Node* head;    // Pointer to the first node in the list
    Node* tail;    // Pointer to the last node in the list
    size_t size;   // Keeps track of the number of nodes in the list

public:
    // Constructor - initializes an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    // Destructor - automatically called when object goes out of scope
    ~DoublyLinkedList() {
        clear();  // Remove all nodes to prevent memory leaks
    }
    
    // Copy constructor - creates a deep copy of another list
    DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr), size(0) {
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }
    
    // Assignment operator - allows list1 = list2
    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this != &other) {  // Avoid self-assignment
            clear();           // Clear current list
            Node* current = other.head;
            while (current != nullptr) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }
    
    // INSERT OPERATIONS
    
    // Insert at the beginning of the list
    void push_front(const T& value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            // List is empty - new node becomes both head and tail
            head = tail = newNode;
        } else {
            // List has elements - update connections
            newNode->next = head;    // New node points to current head
            head->prev = newNode;    // Current head's prev points to new node
            head = newNode;          // Update head to point to new node
        }
        size++;
    }
    
    // Insert at the end of the list
    void push_back(const T& value) {
        Node* newNode = new Node(value);
        
        if (tail == nullptr) {
            // List is empty - new node becomes both head and tail
            head = tail = newNode;
        } else {
            // List has elements - update connections
            tail->next = newNode;    // Current tail points to new node
            newNode->prev = tail;    // New node's prev points to current tail
            tail = newNode;          // Update tail to point to new node
        }
        size++;
    }
    
    // Insert at a specific position (0-indexed)
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
        
        // Navigate to the position
        for (size_t i = 0; i < position; i++) {
            current = current->next;
        }
        
        // Update connections
        newNode->next = current;           // New node points to current node
        newNode->prev = current->prev;     // New node's prev points to current's prev
        current->prev->next = newNode;     // Previous node points to new node
        current->prev = newNode;           // Current node's prev points to new node
        
        size++;
    }
    
    // DELETE OPERATIONS
    
    // Remove the first element
    void pop_front() {
        if (head == nullptr) {
            throw std::runtime_error("Cannot pop from empty list");
        }
        
        Node* nodeToDelete = head;
        
        if (head == tail) {
            // Only one element in the list
            head = tail = nullptr;
        } else {
            // Multiple elements
            head = head->next;     // Move head to next node
            head->prev = nullptr;  // New head has no previous node
        }
        
        delete nodeToDelete;
        size--;
    }
    
    // Remove the last element
    void pop_back() {
        if (tail == nullptr) {
            throw std::runtime_error("Cannot pop from empty list");
        }
        
        Node* nodeToDelete = tail;
        
        if (head == tail) {
            // Only one element in the list
            head = tail = nullptr;
        } else {
            // Multiple elements
            tail = tail->prev;     // Move tail to previous node
            tail->next = nullptr;  // New tail has no next node
        }
        
        delete nodeToDelete;
        size--;
    }
    
    // Remove element at specific position
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
        
        // Navigate to the position
        for (size_t i = 0; i < position; i++) {
            current = current->next;
        }
        
        // Update connections to bypass the node
        current->prev->next = current->next;
        current->next->prev = current->prev;
        
        delete current;
        size--;
    }
    
    // Remove first occurrence of a value
    bool remove(const T& value) {
        Node* current = head;
        
        while (current != nullptr) {
            if (current->data == value) {
                if (current == head && current == tail) {
                    // Only one element
                    head = tail = nullptr;
                } else if (current == head) {
                    // Removing head
                    head = head->next;
                    head->prev = nullptr;
                } else if (current == tail) {
                    // Removing tail
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    // Removing middle element
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                
                delete current;
                size--;
                return true;
            }
            current = current->next;
        }
        return false;  // Value not found
    }
    
    // SEARCH OPERATIONS
    
    // Find the position of a value (returns -1 if not found)
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
        return -1;  // Not found
    }
    
    // Check if the list contains a value
    bool contains(const T& value) const {
        return find(value) != -1;
    }
    
    // ACCESS OPERATIONS
    
    // Get reference to first element
    T& front() {
        if (head == nullptr) {
            throw std::runtime_error("List is empty");
        }
        return head->data;
    }
    
    // Get const reference to first element
    const T& front() const {
        if (head == nullptr) {
            throw std::runtime_error("List is empty");
        }
        return head->data;
    }
    
    // Get reference to last element
    T& back() {
        if (tail == nullptr) {
            throw std::runtime_error("List is empty");
        }
        return tail->data;
    }
    
    // Get const reference to last element
    const T& back() const {
        if (tail == nullptr) {
            throw std::runtime_error("List is empty");
        }
        return tail->data;
    }
    
    // Get element at specific position
    T& at(size_t position) {
        if (position >= size) {
            throw std::out_of_range("Position out of range");
        }
        
        Node* current = head;
        for (size_t i = 0; i < position; i++) {
            current = current->next;
        }
        return current->data;
    }
    
    // Get const element at specific position
    const T& at(size_t position) const {
        if (position >= size) {
            throw std::out_of_range("Position out of range");
        }
        
        Node* current = head;
        for (size_t i = 0; i < position; i++) {
            current = current->next;
        }
        return current->data;
    }
    
    // UTILITY OPERATIONS
    
    // Check if list is empty
    bool empty() const {
        return size == 0;
    }
    
    // Get the number of elements
    size_t getSize() const {
        return size;
    }
    
    // Remove all elements
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }
    
    // Reverse the list
    void reverse() {
        if (size <= 1) return;
        
        Node* current = head;
        Node* temp = nullptr;
        
        // Swap next and prev pointers for all nodes
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;  // Move to next node (which is now prev)
        }
        
        // Swap head and tail
        temp = head;
        head = tail;
        tail = temp;
    }
    
    // DISPLAY OPERATIONS
    
    // Print list from head to tail
    void printForward() const {
        Node* current = head;
        std::cout << "Forward: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    // Print list from tail to head
    void printBackward() const {
        Node* current = tail;
        std::cout << "Backward: ";
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