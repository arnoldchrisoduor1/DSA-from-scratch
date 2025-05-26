#ifndef LIST_H
#define LIST_H

// Abstract List Class.
template <typename E>

class List {

    private:
        // Prevent copying.
        void operator=(const List&) {}
        List(const List&) {}

    public:
        List() {}  //This is the default constructor.
        virtual ~List() {}    // Base destructor.

        // clear contents from the list, to make it empty.
        virtual void clear() = 0;

        // inserting an element at the current location.
        virtual void insert(const E& item) = 0;

        // Apppend an element at the end of teh list
        virtual void append(const E& item) = 0;

        // Remove and return the current element.
        virtual E remove() = 0;

        // Set the current position to the start of the list.
        virtual void moveToStart() = 0;

        // Set the current position to the end of the list.
        virtual void moveToEnd() = 0;

        // Move the current position one step left (no change if at the begining of the list)
        virtual void prev() = 0;

        // Move the current position one step right (no change if at the end of the list)
        virtual void next() = 0;

        // Return the number of elements in the list
        virtual int length() const = 0;

        // Return the position of the current element.
        virtual int currPos() const = 0;

        //  setting the current position.
        virtual void moveToPos(int pos) = 0;

        // Return the current element
        virtual const E& getValue() const = 0;
};

#endif // LIST_H