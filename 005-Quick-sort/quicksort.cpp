#include <iostream>
#include <vector>
#include <random>
#include <chrono>

class QuickSort {
    private:
        // Partition function: rearranges array so elements less than pivot are on the left, and elements greater than pivot are on the right.
        static int partition(std::vector<int>& arr, int low, int high) {
            // choose the right most elemnt as the pivot
            int pivot = arr[high];

            // index of the smaller element.
            int i = low - 1;

            // transverse through all elements.
            // compare each element with pivot.
            for (int j = low; j < high; j++) {
                // If current element is smaller than or equal to pivot.
                if (arr[j] <= pivot) {
                    i++;
                    std::swap(arr[i], arr[j]);
                }
            }

            // place pivot in the correct position
            std::swap(arr[i + 1], arr[high]);
            // return i + 1;  return the position of the pivot.
        }

        static void quickSortRecursive(std::vector<int>& arr, int low, int high) {
            if (low < high) {
                int pivotIndex = partition(arr, low, high);

                // Recursively sort elements before and after partitioning.
                quickSortRecursive(arr, low, pivotIndex - 1);
                quickSortRecursive(arr, pivotIndex + 1, high);
            }
        }

    public:
        // public interface for quicksort.
        static void sort(std::vector<int>& arr) {
            if (arr.size() <= 1) return;
            quickSortRecursive(arr, 0, arr.size() - 1);
        }

        // Utility function to print array
        static void printArray(const std::vector<int>& arr) {
            for  (int x : arr) {
                std::cout << x <<  " ";
            }
            std::cout << std::endl;
        }

        // Function to generate random array for testing.
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

int main () {
    std::cout << "========= QuickSort Algorithm Implementation =====\n\n";

    // Test
}