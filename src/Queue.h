#pragma once
#include "LinkList.h"

template <typename T,class C=LinkList<T>>
class Queue
{
 public:
	void push(const T& val)
	{
		_container.PushBack(val);
	}

	T pop()
	{
		return _container.PopFront();
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