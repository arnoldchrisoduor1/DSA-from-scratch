#include <iostream>
#include <vector>
#include <random>
#include <chrono>

class QuickSort {
    private:
        // elements greater on the left and smaller on the right.
        static int partition(std::vector<int>& arr, int low, int high) {
            // Choose the right most element as the pivot.
            int pivot = arr[high];

            // Index of smaller element (indicates right most element.)
            int  i = low - 1;

            // Transverse through all elements
            // Compare each element with pivot.
            for(int j = low; j < high; j++) {
                if(arr[j] <= pivot) {
                    i++;
                    std::swap(arr[i], arr[j]);
                }
            }
            // place pivot in its correct positioon.
            std::swap(arr[i + 1], arr[high]);
            return i + 1;
        }

        static void quickSortRecursive(std::vector<int>& arr, int low, int high) {
            if (low < high) {
                // partitioning the array to get the pivot index.
                int pivotIndex = partition(arr, low, high);

                // recursively sort elements before and after partition.
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

        // utility function for print array.
        static void printArray(const std::vector<int>& arr) {
            for (int x : arr) {
                std:: cout << x << " ";
            }
            std::cout << std::endl;
        }

        // function to generate random array for testing.
        static std::vector<int> generateRandomArray(int size, int maxValue=1000) {
            std::vector<int> arr(size);
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, maxValue);

            for (int& x : arr) {
                x = dis(gen);
            }
            return arr;
        }

        // Function to verify if array is sorted.
        static bool isSorted(const std::vector<int>& arr) {
            for (size_t i = 1; i < arr.size(); i++) {
                if (arr[i] < arr[i-1]) return false;
            }
            return true;
        }
};