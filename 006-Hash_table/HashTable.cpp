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
};