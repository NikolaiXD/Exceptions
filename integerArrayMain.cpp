#include <iostream>
#include "integerArray.h"

int main() {
    try {
        IntegerArray array(10);

        for (int i{ 0 }; i < 10; ++i)
            array[i] = i + 1;

        array.resize(8);

        array.insertBefore(20, 5);

        array.remove(3);

        array.insertAtEnd(30);
        array.insertAtBeginning(40);

        {
            IntegerArray b{ array };
            b = array;
            b = b;
            array = array;
        }

        for (int i{ 0 }; i < array.getLength(); ++i)
            cout << array[i] << ' ';

        cout << '\n';
    }
    catch (const exception& e) 
    {
        cout << "Exception: " << e.what() << '\n';
    }

    return 0;
}