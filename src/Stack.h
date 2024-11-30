#pragma once
#include "SqList.h"

template <typename T,class C=SqList<T>>
class Stack
{
public:

	/// @brief 入栈
    void push(const T& val)
    {
        if constexpr (std::is_same_v<C,SqList<T>>)
        {
            _container.PushBack(val);
        }
        else if constexpr (std::is_same_v<C,LinkList<T>>)
        {
            _container.PushFront(val);
        }

    }

	/// @brief 出栈
	/// @return 栈顶对象（copy）
    T pop()
    {
        if constexpr (std::is_same_v<C,SqList<T>>)
        {
            return _container.PopBack();
        }
        else if constexpr (std::is_same_v<C,LinkList<T>>)
        {
            return _container.PopFront();
        }

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