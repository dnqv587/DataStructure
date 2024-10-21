#pragma once
#include <memory>
#include <cassert>

template <typename T>
class LinkList
{
 public:
	LinkList():_head(new Node,destroy),_size(0)
	{}

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
	}

	LinkList(LinkList&& list) noexcept = default;

	~LinkList()=default;

	

 private:
	struct Node
	{
		explicit  Node(const T& val):data(val){}

	 	T data;		//数据域
		Node* next;	//指针域
	};

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