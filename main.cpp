#include <iostream>
#include "ArrayList.h"
#include "List.h"

#define LOG(msg, x) std::cout << msg << x << std::endl

int main() {
    List<int>* pArrayList = new ArrayList<int>();

    pArrayList->Add(1);
    pArrayList->Add(2);

    LOG("size: ", pArrayList->Size());

    for (int i = 0; i < pArrayList->Size(); i++)
    {
        std::cout << i << " element: " << pArrayList->Get(i) << std::endl;
    }

    delete pArrayList;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
