class Stack:
    def  __init__(self):
    # Initialize an emoty list to store the elements in the stack.
      self.items= []

    def is_empty(self):
      # check if the stack is empty.
      return len(self.items) == 0
    
    def push(self, item):
       # Append item at the top of the stack
       self.items.append(item)

    def pop(self):
       # Remove and return the item at the top of the stack.
       if not self.is_empty():
          return self.items.pop()
       
       else:
          # Print a message if the stack is empty and return None.
          print("Stack is None")
          return None
       
    def peek(self):
       # Return the item at the top of the stack without removing it.
       if not self.is_empty():
          return self.items[-1]
       
       else:
          # Print a message if the stack is empty and return None
          print("Stack is Empty")
          return None
       
    def size(self):
       # Return the number of elements in the stack
       return len(self.items)