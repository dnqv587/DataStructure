#include "SqList.h"
#include "LinkList.h"
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
	std::cout<<"size:"<<list.Length()<<std::endl;

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

	list.pushFront(1);
	list.pushFront(2);
	auto i3 = list.pushFront(3);
	list.pushFront(4);
	list.pushFront(5);
	auto i6 = list.pushFront(6);
	list.pushFront(7);
	list.pushFront(8);
	list.pushFront(9);

	list.insert(i3,0);

	list.eraseAfter(i6);
	list.popFront();

	for(auto i:list)
	{
		std::cout<<i<<std::endl;
	}

//	list.forEach([](auto i){
//	  std::cout<<i<<std::endl;
//	});

}

int main()
{
	LinkListTest();

    return 0;
}