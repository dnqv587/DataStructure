#include "SqList.h"
#include <iostream>

int main()
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

    return 0;
}