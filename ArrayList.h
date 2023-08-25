//
// Created by Onni on 25/08/2023.
//

#pragma once
#include "List.h"

static const int START_CAPACITY = 4;
static const int MULTIPLY_CAPACITY = 2;

template<typename T>
class ArrayList : public List<T>
{
public:
    void Add(const T& item) override;
    void Remove(size_t index) override;
    [[nodiscard]] size_t Size() const override;
    T Get(size_t index) const override;
    bool Contains(const T& item) const override;
    ArrayList();
    ~ArrayList();
private:
    T* m_array;
    int m_index;
    size_t m_capacity;
    void Grow();
    void Shrink();
};

template<typename T>
ArrayList<T>::ArrayList()
{
    m_index = -1;
    m_capacity = START_CAPACITY;
    m_array = new T[START_CAPACITY];
}

template<typename T>
ArrayList<T>::~ArrayList()
{
    delete[] m_array;
}

template<typename T>
void ArrayList<T>::Add(const T &item)
{
    // check if there is room to add
    if (m_index + 1 == m_capacity) { Grow(); }
    m_array[++m_index] = item;
}

template<typename T>
bool ArrayList<T>::Contains(const T &item) const
{
    for (size_t i = 0; i <= m_index; i++)
    {
        if (m_array[i] == item) { return true; }
    }

    return false;
}

template<typename T>
T ArrayList<T>::Get(size_t index) const
{
    if (index <= m_index)
    {
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
    return m_index + 1;
}

template<typename T>
void ArrayList<T>::Remove(size_t index)
{
    if (index <= m_index)
    {
        for (size_t i = index; i < m_index; ++i)
        {
            m_array[i] = m_array[i + 1];
        }
        --m_index;

        if (m_index < m_capacity / 4)
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
    if (m_index + 1 != m_capacity) { return; }

    m_capacity *= MULTIPLY_CAPACITY;
    T* newArray = new T[m_capacity];

    for (size_t i = 0; i <= m_index; ++i)
    {
        newArray[i] = m_array[i];
    }

    delete[] m_array;
    m_array = newArray;
}

template<typename T>
void ArrayList<T>::Shrink()
{
    if (m_index >= m_capacity / 4) { return; }

    m_capacity /= 2;
    T* newArray = new T[m_capacity];

    for (size_t i = 0; i <= m_index; ++i)
    {
        newArray[i] = m_array[i];
    }

    delete[] m_array;
    m_array = newArray;
}
