#include "integerArray.h"

IntegerArray::IntegerArray() = default;

IntegerArray::IntegerArray(int length) : m_length{ length } {
    assert(length >= 0);
    if (length > 0)
        m_data = new int[length] {};
}

IntegerArray::IntegerArray(const IntegerArray& other) {
    reallocate(other.getLength());

    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = other.m_data[index];
}

IntegerArray::~IntegerArray() {
    delete[] m_data;
}

void IntegerArray::erase() {
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

int& IntegerArray::operator[](int index) {
    if (index < 0 || index >= m_length) {
        throw std::out_of_range("Index out of bounds");
    }
    return m_data[index];
}

void IntegerArray::reallocate(int newLength) {
    erase();

    if (newLength <= 0)
        return;

    m_data = new int[newLength];
    m_length = newLength;
}

void IntegerArray::resize(int newLength) {
    if (newLength == m_length)
        return;

    if (newLength <= 0) {
        erase();
        return;
    }

    int* data{ new int[newLength] };
    if (m_length > 0) {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = m_data[index];
    }

    delete[] m_data;
    m_data = data;
    m_length = newLength;
}

IntegerArray& IntegerArray::operator=(const IntegerArray& other) {
    if (&other == this)
        return *this;

    reallocate(other.getLength());

    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = other.m_data[index];

    return *this;
}

void IntegerArray::insertBefore(int value, int index) {
    if (index < 0 || index > m_length) {
        throw std::out_of_range("Index out of bounds");
    }

    int* data{ new int[m_length + 1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

    data[index] = value;

    for (int after{ index }; after < m_length; ++after)
        data[after + 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    ++m_length;
}

void IntegerArray::remove(int index) {
    if (index < 0 || index >= m_length) {
        throw std::out_of_range("Index out of bounds");
    }

    if (m_length == 1) {
        erase();
        return;
    }

    int* data{ new int[m_length - 1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

    for (int after{ index + 1 }; after < m_length; ++after)
        data[after - 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    --m_length;
}

void IntegerArray::insertAtBeginning(int value) 
{
    insertBefore(value, 0);
}

void IntegerArray::insertAtEnd(int value) 
{
    insertBefore(value, m_length);
}

int IntegerArray::getLength() const 
{
    return m_length;
}