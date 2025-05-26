#include <iostream>
#include "ArrayList.h"

int main() {

    ArrayList<int> L(10);
    L.append(1);
    L.append(2);
    L.append(3);
    L.moveToStart();
    L.insert(0);

    for (L.moveToStart(); L.currPos() < L.length(); L.next()) {
        std::cout << L.getValue() << " ";
    }
    std::cout << std::endl;

    return 0;
}