# Creating the node
class Node:
    def __init__(self, data):
        self.data = data
        # initializing references to the previous and next nodes.
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        # Initializing the head of the doubly linked list.
        self.head = None

    def append(self, data):
        # Adding data to the linked list.
        new_node = Node(data)

        # Creating new head if absent
        if self.head is None:
            self.head = new_node

        # Appending the node to the end of the linked list.
        current_node = self.head
        while current_node.next:
            current_node = current_node.next
        current_node.next = new_node

        new_node.prev = current_node

    def prepend(self, data):
        new_node = Node(data)

        # Creating head node if absent
        if self.head is None:
            self.head = new_node

        # Prepending the new node.
        new_node.next = self.head
        self.head.prev = new_node

        new_node = self.head

    def delete(self, data):
        # Start from the head of the list.
        current = self.head
        # Transverse the list.
        while current:
            # If the data matches the data of the current node.
            if current.data == data:
                # Adjust the previous and next reference to skip the current node.
                if current.prev:
                    current.prev.next = current.next
                else:
                    # If the current node is the heaed, update the head to the next node.
                    self.head = current.next
                if current.next:
                    current.next.prev = current.prev
                # Exit the loop after deleting the node
                return
            # Move to the head of the list.
            current = current.next
    
    def display(self):
        # Start from the head of the list.
        current = self.head
        # Transverse the list and print each node's data
        while current:
            print(current.data, end=" ")
            current  =current.next
        print()

# Application of the linked list.
dll = DoublyLinkedList()
dll.append(1)
dll.append(2)
dll.append(3)
dll.append(4)
dll.append(5)
dll.prepend(6)
dll.display()
dll.delete(2)
dll.display()