from array_list import ArrayList

def main():
    # Create an ArrayList with capacity 10
    L = ArrayList(10)
    
    # Add elements to the list
    L.append(1)
    L.append(2)
    L.append(3)
    
    # Move to start and insert a new element
    L.move_to_start()
    L.insert(0)
    
    # Iterate through the list and print each element
    L.move_to_start()
    while L.curr_pos() < L.length():
        print(L.get_value(), end=" ")
        L.next()
    print()


if __name__ == "__main__":
    main()