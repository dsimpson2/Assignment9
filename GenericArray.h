#ifndef GENERICARRAY_H
#define GENERICARRAY_H

#include <iostream>

template <typename T>
class GenericArray
{
private:
    // Pointer to dynamically allocated array
    T* data;

    // Keeps track of the current size of the array
    int currentSize;

public:

    // Default constructor
    GenericArray()
    {
        data = nullptr;
        currentSize = 0;
    }

    // Destructor frees allocated memory
    ~GenericArray()
    {
        delete[] data;
    }

    // Adds a new element to the end of the array
    void addElement(T value)
    {
        // Allocate a new array one element larger
        T* temp = new T[currentSize + 1];

        // Copy existing elements
        for(int i = 0; i < currentSize; i++)
        {
            temp[i] = data[i];
        }

        // Add new value at the end
        temp[currentSize] = value;

        // Free old memory
        delete[] data;

        // Point to new array
        data = temp;

        // Increase size count
        currentSize++;
    }

    // Returns the value stored at a specific index
    T at(int index)
    {
        // Check bounds
        if(index < 0 || index >= currentSize)
        {
            std::cout << "Index out of bounds" << std::endl;
            return T();
        }

        return data[index];
    }

    // Returns the number of elements in the array
    int size()
    {
        return currentSize;
    }

    // Returns the sum of all elements
    T sum()
    {
        T total = 0;

        for(int i = 0; i < currentSize; i++)
        {
            total += data[i];
        }

        return total;
    }

    // Finds the largest value in the array
    T max()
{
    // Check for empty array
    if(currentSize == 0)
    {
        return T();
    }

    T maximum = data[0];

    for(int i = 1; i < currentSize; i++)
    {
        if(data[i] > maximum)
        {
            maximum = data[i];
        }
    }

    return maximum;
}

    // Finds the smallest value in the array
    T min()
{
    // Check for empty array
    if(currentSize == 0)
    {
        return T();
    }

    T minimum = data[0];

    for(int i = 1; i < currentSize; i++)
    {
        if(data[i] < minimum)
        {
            minimum = data[i];
        }
    }

    return minimum;
}

    // Returns a new array containing elements
    // from begin to end (inclusive)
    T* slice(int begin, int end)
    {
        // Verify requested slice is valid
        if(begin < 0 || end >= currentSize || begin > end)
        {
            return nullptr;
        }

        int sliceSize = end - begin + 1;

        // Allocate memory for sliced array
        T* slicedArray = new T[sliceSize];

        // Copy requested elements 
        for(int i = 0; i < sliceSize; i++) 
        {
            slicedArray[i] = data[begin + i];
        }

        return slicedArray;
    }
};

#endif