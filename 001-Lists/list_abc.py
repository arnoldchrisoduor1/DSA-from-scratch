from abc import ABC, abstractmethod

class List(ABC):
    """
    Abstract base class for List implementations.
    This is equivalent to the C++ abstract List class template.
    """
    
    def __init__(self):
        """Default constructor"""
        pass
    
    @abstractmethod
    def clear(self):
        """Clear contents from the list, to make it empty."""
        pass
    
    @abstractmethod
    def insert(self, item):
        """Insert an element at the current location."""
        pass
    
    @abstractmethod
    def append(self, item):
        """Append an element at the end of the list."""
        pass
    
    @abstractmethod
    def remove(self):
        """Remove and return the current element."""
        pass
    
    @abstractmethod
    def move_to_start(self):
        """Set the current position to the start of the list."""
        pass
    
    @abstractmethod
    def move_to_end(self):
        """Set the current position to the end of the list."""
        pass
    
    @abstractmethod
    def prev(self):
        """Move the current position one step left."""
        pass
    
    @abstractmethod
    def next(self):
        """Move the current position one step right."""
        pass
    
    @abstractmethod
    def length(self):
        """Return the number of elements in the list."""
        pass
    
    @abstractmethod
    def curr_pos(self):
        """Return the position of the current element."""
        pass
    
    @abstractmethod
    def move_to_pos(self, pos):
        """Set the current position."""
        pass
    
    @abstractmethod
    def get_value(self):
        """Return the current element."""
        pass