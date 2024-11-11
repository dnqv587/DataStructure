#pragma once
#include <memory>
#include <cassert>

//***********************************************
// name      : 单链表
// brief     : 每个节点只包含一个指针域，称为单向链表
// attention : None
//***********************************************


template <typename T>
class LinkList
{
 private:
	struct Node
	{
		Node():next(nullptr){}

		explicit Node(const T& val):data(val),next(nullptr){}

		T data;		//数据域
		Node* next;	//指针域
	};

 public:

	struct iter
	{
		explicit iter(Node* const v):data(v){}

		iter operator++()
		{
			data = data->next;
			return *this;
		}

		iter operator++(int)
		{
			auto temp = *this;
			data = data->next;
			return temp;
		}

		T operator*() const
		{
			return data->data;
		}

		bool operator==(std::default_sentinel_t sen) const
		{
			return !data;
		}

		Node* get() const
		{
			return data;
		}

	 private:
		Node* data;
	};

	iter begin()
	{
		return iter(_head->next);
	}

	std::default_sentinel_t end()
	{
		return {};
	}


	LinkList():_head(new Node, destroy),_size(0)
	{
    }
    /// @brief 拷贝构造
	LinkList(const LinkList& list)
	{
		Node* lNode = _head;
		Node* rNode = list._head;
		for(int i=0;i<list._size;++i)
		{
			lNode->next = new Node(rNode->data);
			lNode = lNode->next;
			rNode = rNode->next;
			assert(lNode && rNode);
		}
        _size = list._size;
	}

	LinkList(LinkList&& list) noexcept = default;

	~LinkList()=default;

	iter insert(iter node,const T& val)
    {
		assert(contain(node.get()));
        if(!node.get())
        {
			throw std::invalid_argument("invalid argument");
        }
		auto* newNode = new Node(val);
		if(node.get()->next != nullptr)
		{
			newNode->next = node.get()->next;
			node.get()->next = newNode;
		}
		else
		{
			node.get()->next = newNode;
			newNode->next = nullptr;
		}
		++_size;
		return iter(newNode);
    }

	iter PushFront(const T& val)
	{
		auto* newNode = new Node(val);
		newNode->next = _head->next;
		_head->next = newNode;
		++_size;
		return iter(newNode);
	}

	iter PushBack(const T& val)
	{
		Node* back = _head.get();
		while(back->next)
		{
			back = back->next;
		}
		auto* newNode = new Node(val);
		back->next = newNode;
		++_size;
		return iter(newNode);
	}

	void EraseAfter(iter node)
	{
		assert(contain(node.get()));
		auto* afterNode = node.get()->next;
		if(afterNode)
		{
			node.get()->next = afterNode->next;
			--_size;
			delete afterNode;
		}
	}

	T PopFront()
	{
		auto* front = _head->next;
		if(!front)
		{
			throw std::out_of_range("container is empty");
		}
		_head->next = front->next;
		auto data = std::move(front->data);
		delete front;
		--_size;
		return data;
	}

	void ForEach(void (*print)(const T&)) const
	{
		auto* currNode = _head->next;
		while(currNode)
		{
			print(currNode->data);
			currNode = currNode->next;
		}
	}

	size_t size() const
	{
		return _size;
	}

 private:
	bool contain(Node* node)
	{
		auto* currNode = _head->next;
		while(currNode)
		{
			if(currNode == node)
			{
				return true;
			}
			currNode = currNode->next;
		}
		return false;
	}


 	static void destroy(Node* head)
	{
		while(head)
		{
			auto* next = head->next;
			delete head;
			head = next;
		}
	}

	std::unique_ptr<Node,void (*)(Node*)> _head;
	size_t _size;
};