from list_abc import List

class ArrayList(List):
    """
    List implementation using arrays.
    This is equivalent to the C++ ArrayList class template.
    """
    
    def __init__(self, size=100):
        """Constructor with default size 100"""
        super().__init__()
        self.max_size = size  # Maximum size of the list
        self.list_size = 0    # Number of list items now
        self.curr = 0         # Position of the current element
        self.list_array = [None] * self.max_size  # The array holding list elements
    
    def clear(self):
        """Reinitialize the list"""
        self.list_size = 0
        self.curr = 0
        self.list_array = [None] * self.max_size
    
    def insert(self, item):
        """Insert item at current position"""
        assert self.list_size < self.max_size, "List capacity exceeded"
        
        # Shift elements up to make room
        for i in range(self.list_size, self.curr, -1):
            self.list_array[i] = self.list_array[i-1]
            
        self.list_array[self.curr] = item
        self.list_size += 1
    
    def append(self, item):
        """Append item at the end of the list"""
        assert self.list_size < self.max_size, "List capacity exceeded"
        
        self.list_array[self.list_size] = item
        self.list_size += 1
    
    def remove(self):
        """Remove and return the current element"""
        assert 0 <= self.curr < self.list_size, "No element"
        
        item = self.list_array[self.curr]  # Copy the element
        
        # Shift elements down
        for i in range(self.curr, self.list_size-1):
            self.list_array[i] = self.list_array[i+1]
            
        self.list_size -= 1
        return item
    
    def move_to_start(self):
        """Reset position to the start of the list"""
        self.curr = 0
    
    def move_to_end(self):
        """Set position at the end of the list"""
        self.curr = self.list_size
    
    def prev(self):
        """Back up the current position"""
        if self.curr != 0:
            self.curr -= 1
    
    def next(self):
        """Advance the current position"""
        if self.curr < self.list_size:
            self.curr += 1
    
    def length(self):
        """Return the list size"""
        return self.list_size
    
    def curr_pos(self):
        """Return the current position"""
        return self.curr
    
    def move_to_pos(self, pos):
        """Set current list position to pos"""
        assert 0 <= pos <= self.list_size, "Position out of range"
        self.curr = pos
    
    def get_value(self):
        """Return the current element"""
        assert 0 <= self.curr < self.list_size, "No current element"
        return self.list_array[self.curr]