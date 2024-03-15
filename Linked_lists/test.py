# Creating a singly linked list.

# Creating the node
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Creating the linked list class:
class LinkedList:
    def __init__(self):
        self.head = None

# Displaying all the contents of the linked list.
    def display(self):
        if self.head is None:
            return # Return nothing if the list is null
        
        # Looping through the entire linked list.
        current_node = self.head
        while current_node.next:
            print(current_node.next.data, end=" -> ")
            current_node = current_node.next
        return None
    

# Appending nodes to the linked list.
    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node # Creating a new node if no node is found
            return
        
        # Appending nodes to the last node.
        current_node = self.head
        while current_node.next:
            current_node = current_node.next
        current_node.next = new_node

# Putting node before the head node.
    def prepend(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        
        new_node.next = self.head
        self.head = new_node

# Deleting the linked list nodes.
    def delete(self, data):
        # Ignore if the head is Null
        if self.head is None:
            return
        
        # Handling if the head is the one supposed to be deleted.
        if self.head.data == data:
            self.head = self.head.next
            return
        
        # Geeting the node before the node to be deleted.
        current_node = self.head
        while current_node.next:
            if current_node.next.data == data:
                current_node.next = current_node.next.next
            current_node = current_node.next

if __name__ == "__main__":
    linked_list = LinkedList()

    print("Printing an empty linked list: ")
    print()
    linked_list.display()
    print("Adding content to the linked list" )
    linked_list.append(78)
    linked_list.append(46578)
    linked_list.append(64849)
    linked_list.append(00000)
    linked_list.append(8383)
    print("The current state of the linked list: ")
    linked_list.display()
    print()
    print("Deleting 64849 from the linked list ")
    linked_list.delete(64849)
    print()
    print("The current state of the linked list: ")
    linked_list.display()
    print()
    