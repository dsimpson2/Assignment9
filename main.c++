#include <iostream>
#include "GenericArray.h"

using namespace std;

int main()
{
    // Create a GenericArray of integers
    GenericArray<int> intArray; 

    // Add values to the array
    for(int i = 0; i < 15; i++)
    {
        intArray.addElement(i * 2);
    }

    // Display size of array
    cout << "Size of array is "
         << intArray.size() << endl;

    // Display sum of all elements
    cout << "Sum of array is "
         << intArray.sum() << endl;

    // Display maximum and minimum values
    cout << "Maximum value is "
         << intArray.max() << endl;

    cout << "Minimum value is "
         << intArray.min() << endl;

    cout << endl;

    // Test the at() function
    cout << "Element at index 4: "
         << intArray.at(4) << endl;

    cout << endl;

    // Create a slice from index 5 through index 10
    int begin = 5;
    int end = 10;

    int* slicedArray = intArray.slice(begin, end);

    cout << "Sliced array:" << endl;

    // Print sliced array if valid
    if(slicedArray != nullptr)
    {
        for(int i = 0; i < (end - begin + 1); i++)
        {
            cout << slicedArray[i] << " ";
        }

        cout << endl;

        // Free the dynamically allocated slice
        delete[] slicedArray;
    }

    return 0; 
}