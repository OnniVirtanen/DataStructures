//
// Created by Onni on 25/08/2023.
//

#pragma once
#include "List.h"

template<typename T>
class ArrayList
{
public:
    void Add(T item);
    void Remove(size_t index);
    [[nodiscard]] size_t Size() const;
    T Get(size_t index) const;
    bool Contains(T item) const;
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
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
T &ArrayList<T>::operator[](size_t index)
{
    if (index >= m_size)
    {
        throw std::out_of_range("index out of bounds");
    }
    return m_array[index];
}

template<typename T>
const T &ArrayList<T>::operator[](size_t index) const
{
    if (index >= m_size)
    {
        throw std::out_of_range("index out of bounds");
    }
    return m_array[index];
}

template<typename T>
ArrayList<T>::ArrayList()
{
    m_size = 0;
    m_capacity = 1;
    m_array = new T[2];
}

template<typename T>
ArrayList<T>::~ArrayList()
{
    delete[] m_array;
}

// checked
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
        for (size_t i = index; i < m_size - 1; i++)
        {
            m_array[i] = m_array[i + 1];
        }
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
    T* newArray = new T[m_capacity];

    for (size_t i = 0; i < m_size; ++i)
    {
        newArray[i] = m_array[i];
    }

    delete[] m_array;
    m_array = newArray;
}

template<typename T>
void ArrayList<T>::Shrink()
{
    m_capacity /= 2;
    T* newArray = new T[m_capacity];

    for (size_t i = 0; i <= m_size; ++i)
    {
        newArray[i] = m_array[i];
    }

    delete[] m_array;
    m_array = newArray;
}
