#pragma once
#include "SqList.h"

template <typename T,class C=SqList<T>>
class Stack
{
public:


    void push(const T& val)
    {
        _container.PushBack(val);
    }

    T pop()
    {
        return _container.PopBack();
    }

    size_t size() const
    {
        return _container.size();
    }

    bool empty() const
    {
        return _container.size() <= 0;
    }

private:
    C _container;
};