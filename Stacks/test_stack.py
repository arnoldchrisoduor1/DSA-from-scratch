import unittest
from stacks import Stack

class TestStack(unittest.TestCase):
    def test_push_pop(self):
        stack = Stack()
        stack.push(1)
        stack.push(2)
        stack.push(3)

        self.assertEqual(stack.pop(), 3)
        self.assertEqual(stack.pop(), 2)
        self.assertEqual(stack.pop(), 1)
        self.assertTrue(stack.is_empty())

    def test_peek(self):
        stack = Stack()
        stack.push(1)
        stack.push(2)

        self.assertEqual(stack.peek(), 2)
        self.assertEqual(stack.size(), 2)

    def test_is_empty(self):
        stack = Stack()

        self.assertTrue(stack.is_empty())
        stack.push(3)
        self.assertFalse(stack.is_empty())

    def test_size(self):
        stack = Stack()

        stack.push(1)
        stack.push(2)

        self.assertEqual(stack.size(), 2)

        stack.pop()

        self.assertEqual(stack.size(), 1)

if __name__ == '__main__':
    unittest.main()