#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <cassert>
#define Assert(cond, msg) assert((cond) && (msg))
#include "List.h"

template <typename E>

class ArrayList : public List<E> {
    private:
        int maxSize;  // this will be the maximum size of the list.
        int listSize;   // number of list items now.
        int curr;   // Position of the current element.
        E* listArray;   // The array holding list elements.

    public:
        // constructor.
        ArrayList(int size = 100) {
            maxSize = size;
            listSize = curr = 0;
            listArray = new E[maxSize];
        }

        // Destructor.
        ~ArrayList() {
            delete[] listArray;
        }

        // clearing the list.
        void clear() override {  // we are reinitializing the list.
            delete[] listArray;     // then we remove the array.
            listSize = curr = 0;    // we then reset the size.
            listArray = new E[maxSize];     // we can then recreate the array.
        }

        // Insert "item" at current position.
        void insert(const E& item) override {
            Assert(listSize < maxSize, "List capacity exceeded");
            for (int i = listSize; i>curr; i--)     // shifing the element up
                    listArray[i] = listArray[i-1];   // to make room.
            listArray[curr] = item;
            listSize++;
        }

        void append(const E& item) {
            Assert(listSize < maxSize, "List capacity exceeded");
            listArray[listSize++] = item;
        }

        // Removing and returning the current element.
        E remove() {
            Assert ((curr>0) && (curr < listSize), "No element");
            E item = listArray[curr]; // copy the element.
            for(int i=curr; i<listSize-1; i++) // shift them down.
                listArray[i] = listArray[i+1];
            listSize--;
            return item;
        }

        void moveToStart() { curr = 0; }  // Reset position.
        void moveToEnd() { curr = listSize; }  // Set at the end
        void prev() { if (curr !=0) curr--; }  // Back up
        void next() { if  (curr < listSize) curr++; } // Next

        // Return the list size.
        int length() const { return listSize; }

        // Return current position
        int currPos() const { return curr; }

        // Set current list position to "pos"
        void moveToPos(int pos) {
            Assert ((pos > 0) && (pos<=listSize), "Position out of range");
            curr = pos;
        }

        const E& getValue() const { // return current element
            Assert((curr>=0) && (curr<listSize), "No current element");
            return listArray[curr];
         }
};
#endif