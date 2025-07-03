#include <iostream>
#include <string>
#include <vector>
#include <list>  //this will be for linked lists in each bucket (separate chaining)

// Defining the Entry structure.
// This struct will hold a single key-value pair within our hash table.
struct Entry {
    int key;  // this is the integer key.
    std::string value;  // this is the string value associated with our hash table.

    // a constructor for convenience.
    Entry(int k, const std::string& v) : key(k), value(v) {}
};

//  Defining the hash table class.
class HashTable {
    private:
        // the core of the data structure: a vector of lists.
        // Each element in the vector is a 'bucket' and each bucket is a linked list of entry objects.
        // This will be to handle collisions using separate chaining.
        std::vector<std::list<Entry>> table;
        int capacity;   //total number of buckets in the hash table.
        int size; // the curent number of key-value pairs stored in the table.

        // private helper function: Hash function.
        // taking the index and retrning an index within the tables capacity.
        // simple modulo used for integer keys.
        int hashFunction(int key) const {
            return key % capacity; // Modulo operator to map the key to an index [0, capacity-1]
        }
    public:
        // constructor for the hash table.
        // will initialize the table with a given number of buckets (capacity).
        // we'll set the default capacity to 100.
        HashTable(int initialCapacity = 100) : capacity(initialCapacity), size(0) {
            // resizing the vector to hold 'capacity' number of empty lists.
            table.resize(capacity);
        }

        // Building the INSERT function.
        void insert(int key, const std::string& value) {
            // we will calculate the bucket index uding the hash function.
            int index = hashFunction(key);

            // getting a reference to the list at that index.
            std::list<Entry>& bucket = table[index];

            // we will now check if the key already exists in this bucket (update value if it does.)
            for (Entry& entry : bucket) {
                if (entry.key == key) {
                    entry.value = value;
                    std::cout << "Updated key " << key << " with new value: " << value << std::endl;
                    return;
                }
            }

            // if key not found we will add a new entry to the end of the list in the bucket.
            bucket.emplace_back(key, value); //emplace will construct Entry in-place.
            size++;
            std::cout << "Inserted key: " << key << ", value: " << value << std::endl;
        }

        // Building the SEARCH functionality
        std::string get(int key) const {
            // calculating the bucket index.
            int index = hashFunction(key);

            // we will get the constant reference to the list at that index.
            const std::list<Entry>& bucket = table[index];

            // iterate through the list in the bucket to find the key.
            for (const Entry& entry : bucket) {
                if (entry.key == key) {
                    return entry.value; // key found, return its value.
                }
            }

            // incase key was not found.
            return "Key Not Found";
        }

        // Building the DELETE functionality.
        void remove(int key) {
            // calculating the bucket index.
            int index = hashFunction(key);

            // getting the reference to the list at that index.
            std::list<Entry>& bucket = table[index];

            // we will iterate through the list to find and remove the key.
            // we will use the iterator because we might modify the list while iterating.
            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                if (it->key == key) {
                    bucket.erase(it);
                    size--;
                    std::cout << "Removed key: " << key << std::endl;
                    return;
                }
            }
        }

        // Buidling the DISPLAY functionality.
        void display() const {
            std::cout << "\n=== Hash Table Contents ===" << std::endl;
            // we will iterate through all the contents in the list.
            for (int i = 0; i < capacity; ++i) {
                // getting the constant reference to the list (bucket) at the current index.
                const std::list<Entry>& bucket = table[i];
                std::cout << "Bucket " << i << ": ";
                // print the contents if not empty.
                if (!bucket.empty()) {
                    for (const Entry& entry : bucket) {
                        std::cout << "(" << entry.key << ", " << entry.value << ") ";
                    }
                } else {
                    std::cout << "Empty";
                }
                std::cout << "Total elements: " << size << std::endl;
                std::cout << "===========================\n" << std::endl;
            }
        }

        // Get current number of elements.
        int getSize() const {
            return size;
        }

        // Get current capacity  (number of buckets).
        int getCapacity() const {
            return capacity;
        }
};

int main() {
    std::cout << "Building a Hash Table from scratch!\n" << std::endl;

    // Create a hash table with an initial capacity of 10
    HashTable myHashTable(10);

    // Insert some key-value pairs
    std::cout << "--- Inserting values ---" << std::endl;
    myHashTable.insert(10, "Apple");
    myHashTable.insert(20, "Banana");
    myHashTable.insert(5, "Cherry");
    myHashTable.insert(15, "Date"); // This will collide with 5 (15 % 10 = 5)
    myHashTable.insert(25, "Elderberry"); // This will collide with 5 and 15 (25 % 10 = 5)
    myHashTable.insert(30, "Fig");
    myHashTable.insert(1, "Grape");
    myHashTable.insert(11, "Honeydew"); // This will collide with 1 (11 % 10 = 1)
    myHashTable.insert(10, "Apricot"); // Update existing key 10

    myHashTable.display(); // Display current state

    // Test search functionality
    std::cout << "--- Searching for values ---" << std::endl;
    std::cout << "Value for key 20: " << myHashTable.get(20) << std::endl;
    std::cout << "Value for key 15: " << myHashTable.get(15) << std::endl;
    std::cout << "Value for key 25: " << myHashTable.get(25) << std::endl;
    std::cout << "Value for key 99: " << myHashTable.get(99) << std::endl; // Not found
    std::cout << "Value for key 10: " << myHashTable.get(10) << std::endl; // Updated value

    // Test removal functionality
    std::cout << "--- Removing values ---" << std::endl;
    myHashTable.remove(15); // Remove an existing key
    myHashTable.remove(100); // Try to remove a non-existent key
    myHashTable.remove(1);  // Remove a key that caused a collision

    myHashTable.display(); // Display state after removals

    std::cout << "Value for key 15 after removal: " << myHashTable.get(15) << std::endl;
    std::cout << "Value for key 1 after removal: " << myHashTable.get(1) << std::endl;
    std::cout << "Value for key 11 after removal: " << myHashTable.get(11) << std::endl; // Should still be there

    return 0;
}