#include <iostream>
#include "ArrayList.h"

#define LOG(x) std::cout << x << std::endl

int main() {
    List<int>* pArrayList = new ArrayList<int>();
    pArrayList->Add(25);
    pArrayList->Add(32);
    pArrayList->Add(24);
    pArrayList->Add(54);
    LOG(pArrayList->Get(pArrayList->Size() - 1));
    pArrayList->Remove(pArrayList->Size() - 1);

    delete pArrayList;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
