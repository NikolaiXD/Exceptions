#ifndef INTEGERARRAY_H
#define INTEGERARRAY_H
#include <cassert>
#include <stdexcept>
using namespace std;
class IntegerArray {
private:
    int m_length{};
    int* m_data{};

public:
    IntegerArray();
    explicit IntegerArray(int length);
    IntegerArray(const IntegerArray& other);
    ~IntegerArray();

    void erase();

    int& operator[](int index);

    void reallocate(int newLength);

    void resize(int newLength);

    IntegerArray& operator=(const IntegerArray& other);

    void insertBefore(int value, int index);

    void remove(int index);

    void insertAtBeginning(int value);

    void insertAtEnd(int value);

    int getLength() const;
};

#endif