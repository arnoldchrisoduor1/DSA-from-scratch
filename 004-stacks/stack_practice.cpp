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
        // constructor
        Stack() : top(nullptr), size(0) {}

        // Desctructor.
        ~Stack() {
            clear();
        }

        // copy constructor
        Stack(const Stack& other) {
            if (this != other) {
                clear();
                if (other.top) {
                    copyFrom(other);
                }
            }
            return *this;
        }

        // CREATE: push element onto stack.
        void push(const T& value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            size++;
        }

        // READ: peak at top element without removing.
        T peek() const {
            if (isEmpty()) {
                throw std::runtime_error("Stack is empty - cannot peek.");
            }
            return top->data;
        }

        // READ: get element at specific position (0 = top)
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

        // UPDATE: Modify element at specific position (0 = top)
        void updateAt(size_t index, const T& newValue) {
            if (index >= size) {
                throw std::out_of_range("Index out of bounds");
            }
            Node* current = top;
            for(size_t i = 0; i< index; i++) {
                current = current->next;
            }
            current->data = newValue;
        }

        // DELETE: clear all elements.
        void clear() {
            while(!isEmpty()) {
                pop();
            }
        }

        // utility functions
        bool isEmpty() const {
            return top == nullptr;
        }
        size_t getSize() const {
            return size;
        }

        // Display stack contents.
        void display() const {
            if (isEmpty()) {
                std::cout << "Stack is empty" << std::endl;
                return;
            }
            std::cout << "Stack (top to bottom): ";
            Node* current = top;
            while (current) {
                std::cout << current->data;
                if(current->next) std::cout << " -> ";
                current = current->next;
            }
            std::cout << std::endl;
        }

        // search for an element and return its position (0 = top, -1 = not found)
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
            // return -1; not found.
        }

    private:
        // helper function for copy constructor and assignment operator.
        void copyFrom(const Stack& other) {
            if (other.isEmpty()) return;

            // create temporary array to reverse the order.
            T* tempArray = new T[other.size];
            Node* current = other.top;
            int index = 0;

            // store elements in reverse order.
            while (current) {
                tempArray[index++] = current->data;
                current = current->next;
            }

            // push elements to maintain oroginal order
            for (int i = index - 1; i >= 0; i--) {
                push(tempArray[i]);
            }
            delete[] tempArray;
        }
};

// demo function to showcase CRUD operations.
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

        // test error handling.
        std::cout << "\n---Error Handling---" << std::endl;
        Stack<int> emptyStack;

        try {
            emptyStack.peek();
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        try {
            emptyStack.pop();
        } catch (const std::exception& e) {
            std::cout << "Caught exception"<< e.what() << std::endl;
        }
    }

    return 0;
}