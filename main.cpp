#include <iostream>
#include "ArrayList.h"

#define LOG(x) std::cout << x << std::endl

int main() {
    auto* pIntegers = new ArrayList<int>();
    pIntegers->Add(25);
    pIntegers->Add(32);
    pIntegers->Add(24);
    pIntegers->Add(54);

    while (pIntegers->Size() > 0) {
        LOG(pIntegers->Get(pIntegers->Size() - 1));
        pIntegers->Remove(pIntegers->Size() - 1);
    }

    delete pIntegers;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
