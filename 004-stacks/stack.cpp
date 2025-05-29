#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* top;
    size_t size;

public:
    // Constructor
    Stack() : top(nullptr), size(0) {}
    
    // Destructor
    ~Stack() {
        clear();
    }
    
    // Copy Constructor
    Stack(const Stack& other) : top(nullptr), size(0) {
        *this = other;
    }
    
    // Assignment Operator
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            clear();
            if (other.top) {
                copyFrom(other);
            }
        }
        return *this;
    }
    
    // CREATE: Push element onto stack
    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }
    
    // READ: Peek at top element without removing
    T peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty - cannot peek");
        }
        return top->data;
    }
    
    // READ: Get element at specific position (0 = top)
    T at(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        
        Node* current = top;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
    
    // UPDATE: Modify element at top
    void updateTop(const T& newValue) {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty - cannot update");
        }
        top->data = newValue;
    }
    
    // UPDATE: Modify element at specific position (0 = top)
    void updateAt(size_t index, const T& newValue) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        
        Node* current = top;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = newValue;
    }
    
    // DELETE: Pop element from top
    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty - cannot pop");
        }
        
        Node* nodeToDelete = top;
        T value = top->data;
        top = top->next;
        delete nodeToDelete;
        size--;
        return value;
    }
    
    // DELETE: Clear all elements
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    // Utility functions
    bool isEmpty() const {
        return top == nullptr;
    }
    
    size_t getSize() const {
        return size;
    }
    
    // Display stack contents
    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        
        std::cout << "Stack (top to bottom): ";
        Node* current = top;
        while (current) {
            std::cout << current->data;
            if (current->next) std::cout << " -> ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    // Search for an element and return its position (0 = top, -1 = not found)
    int search(const T& value) const {
        Node* current = top;
        int position = 0;
        
        while (current) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1; // Not found
    }

private:
    // Helper function for copy constructor and assignment operator
    void copyFrom(const Stack& other) {
        if (other.isEmpty()) return;
        
        // Create temporary array to reverse the order
        T* tempArray = new T[other.size];
        Node* current = other.top;
        int index = 0;
        
        // Store elements in reverse order
        while (current) {
            tempArray[index++] = current->data;
            current = current->next;
        }
        
        // Push elements to maintain original order
        for (int i = index - 1; i >= 0; i--) {
            push(tempArray[i]);
        }
        
        delete[] tempArray;
    }
};

// Demo function to showcase CRUD operations
void demonstrateStackOperations() {
    std::cout << "=== Stack CRUD Operations Demo ===" << std::endl;
    
    Stack<int> stack;
    
    // CREATE operations
    std::cout << "\n--- CREATE Operations ---" << std::endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    std::cout << "Pushed: 10, 20, 30, 40" << std::endl;
    stack.display();
    std::cout << "Stack size: " << stack.getSize() << std::endl;
    
    // READ operations
    std::cout << "\n--- READ Operations ---" << std::endl;
    std::cout << "Top element (peek): " << stack.peek() << std::endl;
    std::cout << "Element at position 0: " << stack.at(0) << std::endl;
    std::cout << "Element at position 2: " << stack.at(2) << std::endl;
    std::cout << "Search for 20: position " << stack.search(20) << std::endl;
    std::cout << "Search for 99: position " << stack.search(99) << std::endl;
    
    // UPDATE operations
    std::cout << "\n--- UPDATE Operations ---" << std::endl;
    std::cout << "Before update:" << std::endl;
    stack.display();
    
    stack.updateTop(45);
    std::cout << "Updated top element to 45:" << std::endl;
    stack.display();
    
    stack.updateAt(2, 25);
    std::cout << "Updated element at position 2 to 25:" << std::endl;
    stack.display();
    
    // DELETE operations
    std::cout << "\n--- DELETE Operations ---" << std::endl;
    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "After pop:" << std::endl;
    stack.display();
    
    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "After another pop:" << std::endl;
    stack.display();
    
    // Test copy constructor
    std::cout << "\n--- Copy Operations ---" << std::endl;
    Stack<int> stackCopy = stack;
    std::cout << "Original stack:" << std::endl;
    stack.display();
    std::cout << "Copied stack:" << std::endl;
    stackCopy.display();
    
    // Clear operation
    std::cout << "\n--- Clear Operation ---" << std::endl;
    stack.clear();
    std::cout << "After clearing:" << std::endl;
    stack.display();
    std::cout << "Is empty: " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
}

int main() {
    try {
        demonstrateStackOperations();
        
        // Test error handling
        std::cout << "\n--- Error Handling ---" << std::endl;
        Stack<int> emptyStack;
        
        try {
            emptyStack.peek();
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        
        try {
            emptyStack.pop();
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}