#pragma once
#include <memory>

template <typename T>
class CircularQueue
{
 public:
	explicit CircularQueue(size_t capacity):_capacity(capacity),_data(std::make_unique<T[]>(capacity)),_front(0),_rear(0)
	{}

	~CircularQueue()=default;

	void push(const T& val)
	{
		if(isFull())
		{

		}
		_data[_rear] = val;
		++_rear;
	}

	bool isEmpty() const
	{
		return _front == _rear;
	}

	bool isFull() const
	{
		return (_rear+1)%_capacity == _front;
	}

 private:
	size_t _capacity;
	std::unique_ptr<T[]> _data;
	off64_t _front;
	off64_t _rear;
};