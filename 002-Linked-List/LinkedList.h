#ifndef LINKEDLIST_H
#define LINKEDLIST_H


// Linked list imlememtation.
template <typename E> class LList: public List<E> {
    private:
        Link<E>* head;
        Link<E>* tail;
        Link<E>* curr;

        void init() {
            curr = tail = head = new Link<E>;
            cnt = 0;
        }

        void removeall() { // return link does not free store.
            while(head != NULL) {
                curr = head;
                head = head->next;
                delete curr;
            }
        }

    public:
        LList(int size=defaultSize) { init(); }  // constructor.
        ~LList print() const;
        void clear() { removeall(); init(); } // clear list

        // Inserting "it" at current position.
        void insert(const E$ it) {
            curr->next = new Link<E>(it, curr->next);
            if (tail == curr) tail = curr->next;
            cont++;
        }

        // Appending "it" to list
        void append(const E& it) {
            tail = tail->next = new Link<E>(it, NULL);
            cnt++;
        }

        // Remove and return current element.
        E remove() {
            Assert(curr->next != NULL, "No element");
            E it = curr->next->element;
            Link<E>* ltemp = curr->next;
            if (tail == curr->next) tail =curr;
            curr->next = curr->next->next;
            delete ltemp;
            cnt--;
            return it;
        }

        // place curr at list start
        void moveToStart() {
            curr = head;
        }

        // Place curr at list end.
        void moveToEnd() {
            curr = tail;
        }

        // Place curr at end of list.
        void moveToEnd() {
            curr = tail;
        }

        // Move curr one step left; no change if already infront.
        void prev() {
            if (curr == head) return;
            Link<E>* temp = head;
            // Moving down the list until we find the previous element.
            while (temp->next!=curr) temp=temp->next;
            curr = temp;
        }

        // Move curr one step to the right; no change if already at end.
        void next() {
            if(curr != tail) {
                curr = curr->next;
            }
        }

        // returning the length.
        int length() const { return cnt; }

        // returning the position of the current element.
        int currPos() const {
            Link<E>* temp = head;
            int i;
            for (i=0; curr != temp; i++) {
                temp = temp->next;
            return i;
            }
        }

};

#endif