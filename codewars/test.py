import unittest
from perfect_power import isPP

class TestIsPP(unittest.TestCase):
    def test_perfect_powers(self):
        self.assertEqual(isPP(4), [2, 2])
        
        
    def test_not_perfect_powers(self):
        self.assertIsNone(isPP(5))
        
        
if __name__ == '__main__':
    unittest.main()