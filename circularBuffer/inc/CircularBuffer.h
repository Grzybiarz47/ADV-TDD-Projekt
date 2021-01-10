#pragma once
#include <exception>
#include <vector>

template<typename T>
class CircularBuffer
{
private:
    const int MAX_SIZE;
    int firstElemIndx, lastElemIndx, curSize;
    std::vector<T> buffer;

    void incrementIndex(int& indx)
    {
        indx = (indx + 1) % MAX_SIZE;
    }

public:
    CircularBuffer(int maxSize) : MAX_SIZE{maxSize},
                                  firstElemIndx{0},
                                  lastElemIndx{0},
                                  curSize{0}, 
                                  buffer(maxSize) {}
    void add(T elem)
    {
        if(curSize > 0)
            incrementIndex(lastElemIndx);
            
        buffer.at(lastElemIndx) = elem;

        if(curSize == MAX_SIZE)
            incrementIndex(firstElemIndx);
        else
            ++curSize;
        
    }
    T remove() noexcept(false)
    {
        T tempElem = buffer.at(firstElemIndx);
        if(curSize > 0)
        {
            incrementIndex(firstElemIndx);
            --curSize;
        }
        else
        {
            throw std::out_of_range("Buffer is already empty");
        }
        
        return tempElem;
    } 
    const int getAllocatedSize() const
    {
        return MAX_SIZE;
    }
    int getSize() const
    {
        return curSize;
    }
};