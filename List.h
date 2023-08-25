//
// Created by Onni on 25/08/2023.
//

#pragma once
#include <iostream>

template <typename T>
class List
{
public:
    /**
     * Adds an item to end of the list
     * @param item to add
     */
    virtual void Add(const T& item) = 0;
    /**
     * Removes item from given index
     * @param index of list
     */
    virtual void Remove(size_t index) = 0;
    /**
     * Returns the amount of elements in list
     * @return size_t
     */
    [[nodiscard]] virtual size_t Size() const = 0;
    /**
     * Get an item from the list at given index
     * @param index of list
     * @return an item
     */
    virtual T Get(size_t index) const = 0;
    /**
     * Checks if the list contains an element
     * @param item reference
     * @return boolean
     */
    virtual bool Contains(const T& item) const = 0;

    virtual ~List() = default;
};