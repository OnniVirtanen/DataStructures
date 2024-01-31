//
// Created by Onni on 25/08/2023.
//

#pragma once
#include "List.h"
#include <stdio.h>

template<typename T>
class ArrayList
{
public:
    void Add(T item);
    void Remove(size_t index);
    [[nodiscard]] size_t Size() const;
    T Get(size_t index) const;
    bool Contains(T item) const;
    ArrayList();
    ~ArrayList();
private:
    T* m_array = nullptr;
    size_t m_size = 0;
    size_t m_capacity = 0;
    void Grow();
    void Shrink();
};

template<typename T>
ArrayList<T>::ArrayList()
{
    m_size = 0;
    m_capacity = 2;
    m_array = new T[m_capacity]{};
}

template<typename T>
ArrayList<T>::~ArrayList()
{
    memset(m_array, 0, sizeof(T) * m_capacity);
    delete[] m_array;
}

template<typename T>
void ArrayList<T>::Add(const T item)
{
    if (m_size == m_capacity) { Grow(); }
    m_array[m_size++] = item;
}

template<typename T>
bool ArrayList<T>::Contains(const T item) const
{
    for (size_t i = 0; i < m_size; i++)
    {
        if (m_array[i] == item) { return true; }
    }
    return false;
}

template<typename T>
T ArrayList<T>::Get(size_t index) const
{
    if (index < m_size) {
        return m_array[index];
    }
    else
    {
        throw std::out_of_range("index out of bounds");
    }
}

template<typename T>
size_t ArrayList<T>::Size() const
{
    return m_size;
}

template<typename T>
void ArrayList<T>::Remove(size_t index)
{
    if (index < m_size)
    {
        memmove(&m_array[index], &m_array[index + 1], sizeof(T) * (m_size - index - 1));
        --m_size;
        if (m_size < m_capacity / 4)
        {
            Shrink();
        }
    }
    else
    {
        throw std::out_of_range("index out of bounds");
    }
}

template<typename T>
void ArrayList<T>::Grow()
{
    m_capacity *= 2;
    T* newArray = new T[m_capacity]{};
    memcpy(newArray, m_array, sizeof(T) * m_size);
    delete[] m_array;
    m_array = newArray;
}

template<typename T>
void ArrayList<T>::Shrink()
{
    m_capacity /= 2;
    T* newArray = new T[m_capacity]{};
    memcpy(newArray, m_array, sizeof(T) * m_size);
    delete[] m_array;
    m_array = newArray;
}
