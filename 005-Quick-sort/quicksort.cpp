#include <iostream>
#include <vector>
#include <random>
#include <chrono>

class QuickSort {
private:
    // Partition function: rearranges array so elements less than pivot
    // are on the left, and elements greater than pivot are on the right
    static int partition(std::vector<int>& arr, int low, int high) {
        // Choose the rightmost element as pivot
        int pivot = arr[high];
        
        // Index of smaller element (indicates right position of pivot)
        int i = low - 1;
        
        // Traverse through all elements
        // Compare each element with pivot
        for (int j = low; j < high; j++) {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++; // increment index of smaller element
                std::swap(arr[i], arr[j]);
            }
        }
        
        // Place pivot in its correct position
        std::swap(arr[i + 1], arr[high]);
        return i + 1; // return position of pivot
    }
    
    // Recursive quicksort function
    static void quickSortRecursive(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            // Partition the array and get the pivot index
            int pivotIndex = partition(arr, low, high);
            
            // Recursively sort elements before and after partition
            quickSortRecursive(arr, low, pivotIndex - 1);
            quickSortRecursive(arr, pivotIndex + 1, high);
        }
    }

public:
    // Public interface for quicksort
    static void sort(std::vector<int>& arr) {
        if (arr.size() <= 1) return;
        quickSortRecursive(arr, 0, arr.size() - 1);
    }
    
    // Utility function to print array
    static void printArray(const std::vector<int>& arr) {
        for (int x : arr) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    
    // Function to generate random array for testing
    static std::vector<int> generateRandomArray(int size, int maxValue = 1000) {
        std::vector<int> arr(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, maxValue);
        
        for (int& x : arr) {
            x = dis(gen);
        }
        return arr;
    }
    
    // Function to verify if array is sorted
    static bool isSorted(const std::vector<int>& arr) {
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i-1]) return false;
        }
        return true;
    }
};

// Demonstration and testing
int main() {
    std::cout << "=== Quicksort Algorithm Implementation ===\n\n";
    
    // Test 1: Small array with known values
    std::cout << "Test 1: Small array\n";
    std::vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Original: ";
    QuickSort::printArray(arr1);
    
    QuickSort::sort(arr1);
    std::cout << "Sorted:   ";
    QuickSort::printArray(arr1);
    std::cout << "Is sorted: " << (QuickSort::isSorted(arr1) ? "Yes" : "No") << "\n\n";
    
    // Test 2: Array with duplicates
    std::cout << "Test 2: Array with duplicates\n";
    std::vector<int> arr2 = {5, 2, 8, 2, 9, 1, 5, 5};
    std::cout << "Original: ";
    QuickSort::printArray(arr2);
    
    QuickSort::sort(arr2);
    std::cout << "Sorted:   ";
    QuickSort::printArray(arr2);
    std::cout << "Is sorted: " << (QuickSort::isSorted(arr2) ? "Yes" : "No") << "\n\n";
    
    // Test 3: Already sorted array
    std::cout << "Test 3: Already sorted array\n";
    std::vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7};
    std::cout << "Original: ";
    QuickSort::printArray(arr3);
    
    QuickSort::sort(arr3);
    std::cout << "Sorted:   ";
    QuickSort::printArray(arr3);
    std::cout << "Is sorted: " << (QuickSort::isSorted(arr3) ? "Yes" : "No") << "\n\n";
    
    // Test 4: Reverse sorted array
    std::cout << "Test 4: Reverse sorted array\n";
    std::vector<int> arr4 = {7, 6, 5, 4, 3, 2, 1};
    std::cout << "Original: ";
    QuickSort::printArray(arr4);
    
    QuickSort::sort(arr4);
    std::cout << "Sorted:   ";
    QuickSort::printArray(arr4);
    std::cout << "Is sorted: " << (QuickSort::isSorted(arr4) ? "Yes" : "No") << "\n\n";
    
    // Test 5: Large random array with timing
    std::cout << "Test 5: Large random array (10,000 elements)\n";
    std::vector<int> arr5 = QuickSort::generateRandomArray(10000);
    
    auto start = std::chrono::high_resolution_clock::now();
    QuickSort::sort(arr5);
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Sorted 10,000 elements in " << duration.count() << " microseconds\n";
    std::cout << "Is sorted: " << (QuickSort::isSorted(arr5) ? "Yes" : "No") << "\n\n";
    
    // Algorithm complexity explanation
    std::cout << "=== Algorithm Analysis ===\n";
    std::cout << "Time Complexity:\n";
    std::cout << "  - Best/Average case: O(n log n)\n";
    std::cout << "  - Worst case: O(n²) - when pivot is always smallest/largest\n";
    std::cout << "Space Complexity: O(log n) - due to recursion stack\n";
    std::cout << "In-place: Yes (sorts within the original array)\n";
    std::cout << "Stable: No (relative order of equal elements may change)\n";
    
    return 0;
}