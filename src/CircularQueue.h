#pragma once
#include <memory>

template <typename T>
class CircularQueue
{
 public:
	explicit CircularQueue(size_t capacity):_capacity(capacity+1),_data(std::make_unique<T[]>(capacity)),_front(0),_rear(0)
	{}

	~CircularQueue()=default;

	void push(const T& val)
	{
		if(isFull())
		{
            throw std::out_of_range("container is full");
		}
		_data[_rear] = val;
        _rear = (_rear+1)%_capacity;
	}

    T pop()
    {
        if(isEmpty())
        {
            throw std::out_of_range("container is empty");
        }
        T data = std::move(_data[_front]);
        _front = (_front+1)%_capacity;
        return data;
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