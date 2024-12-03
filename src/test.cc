#include "SqList.h"
#include "LinkList.h"
#include "Stack.h"
#include "BST.h"
#include "Queue.h"
#include "CircularQueue.h"
#include "AVL.h"
#include "AdjacencyGraph.h"
#include <iostream>

void SqListTest()
{
	SqList<int> list{10};

	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	list.PushBack(6);
	list.PushBack(7);
	list.PushBack(8);
	list.PushBack(9);
	list.forEach([](auto i){
	  std::cout<<i<<std::endl;
	});
	std::cout<<"----"<<std::endl;

	list.Clear();
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.insert(0,0);
	list.forEach([](auto i){
	  std::cout<<i<<std::endl;
	});
	std::cout<<"----"<<std::endl;

	list.remove(2);
	list.forEach([](auto i){
	  std::cout<<i<<std::endl;
	});
	std::cout<<"----"<<std::endl;
	std::cout<<"size:"<<list.size()<<std::endl;

	std::cout<<"1capacity:"<<list.capacity()<<std::endl;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	list.PushBack(6);
	list.PushBack(7);
	list.PushBack(8);
	list.PushBack(9);
	std::cout<<"2capacity:"<<list.capacity()<<std::endl;
}

void LinkListTest()
{
	LinkList<int> list{};

	list.PushFront(1);
	list.PushFront(2);
	auto i3 = list.PushFront(3);
	list.PushFront(4);
	list.PushFront(5);
	auto i6 = list.PushFront(6);
	list.PushFront(7);
	list.PushFront(8);
	list.PushFront(9);

	list.insert(i3,0);

	list.EraseAfter(i6);
    list.PopFront();

	for(auto i:list)
	{
		std::cout<<i<<std::endl;
	}

//	list.forEach([](auto i){
//	  std::cout<<i<<std::endl;
//	});

}

void StackTest()
{
    Stack<int,LinkList<int>> stack;

    stack.push(10);
    stack.push(9);
    stack.push(8);
    stack.push(7);
    stack.push(6);
    stack.push(5);
    stack.push(4);

    while(!stack.empty())
    {
        std::cout<<stack.pop()<<std::endl;
    }
}

void BSTtest()
{
	BST<int> bst(10);
	bst.Insert(55);
	bst.Insert(9);
	bst.Insert(999);
	bst.Insert(888);
    bst.Insert(1);
    bst.Insert(11);
    bst.Insert(2);
    bst.Insert(3);
    bst.Insert(4);
	bst.Insert(555);
	bst.Insert(444);
	bst.Insert(6666);

	bst.inOrder([](auto i){
		std::cout<<i<<std::endl;
	});

    std::cout<<"left depth:"<<bst.LeftDepth()<<std::endl;
    std::cout<<"right depth:"<<bst.RightDepth()<<std::endl;

    std::cout<<"max:"<<bst.max()<<std::endl;
    std::cout<<"min:"<<bst.min()<<std::endl;

	bst.Delete(444);
	bst.inOrder([](auto i){
	  std::cout<<i<<std::endl;
	});
}

void QueueTest()
{
	Queue<int,SqList<int>> que;
	que.push(10);
	que.push(9);
	que.push(8);
	que.push(7);
	que.push(6);
	que.push(5);
	que.push(4);

	while(!que.empty())
	{
		std::cout<<que.pop()<<std::endl;
	}
}

void CircularQueueTest()
{
    CircularQueue<int> que(5);
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);

    while(!que.isEmpty())
    {
        std::cout<<que.pop()<<std::endl;
    }

    que.push(3);
    que.push(4);
    que.push(5);

    while(!que.isEmpty())
    {
        std::cout<<que.pop()<<std::endl;
    }
}

void AdjacencyGraphTest()
{
    AdjacencyGraph<char> graph;
    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');
    graph.addVertex('D');

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(3,0);

    graph.print();
}

int main()
{
	//LinkListTest();
    //StackTest();
	//BSTtest();
	//QueueTest();
    //CircularQueueTest();
    AdjacencyGraphTest();

    return 0;
}