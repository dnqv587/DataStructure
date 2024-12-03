#pragma once
#include <stdexcept>
#include <iostream>

//***********************************************
// name      : 邻接表
// brief     :
// attention : None
//***********************************************

template <typename T,int MaxVertexCount = 10>
class AdjacencyGraph
{
public:
    AdjacencyGraph()
    :_vertexCount(0),
     _edgeCount(0),
     _vertex{}
    {}

	void addVertex(const T& element)
	{
		if(_vertexCount >= MaxVertexCount)
		{
			throw std::length_error("vertex count > MaxVertexCount");
		}
		_vertex[_vertexCount++].element=element;
	}

    void addEdge(int v1,int v2)
    {
        auto* currNode = _vertex[v1].next;
        if (currNode)
        {
            while(currNode->next)
            {
                if(currNode->next->nextVertex == v2)
                {
                    throw std::logic_error("existed vertex!");
                }
                currNode = currNode->next;
            }
            currNode->next = new Node(v2, nullptr);
            ++_edgeCount;
        }
        else
        {
            _vertex[v1].next = new Node(v2, nullptr);
            ++_edgeCount;
        }
    }

    void print() const
    {
        for(const auto& i:_vertex)
        {
            Node* currNode = i.next;
            while(currNode)
            {
                std::cout<<i.element<<"->"<<_vertex[currNode->nextVertex].element<<std::endl;
                currNode = currNode->next;
            }
        }
    }

private:
    // 节点
    struct Node
    {
        Node()
        :nextVertex(-1),next(nullptr){}
        Node(int vertex,Node* node)
        :nextVertex(vertex),next(node){}
        ~Node()
        {
            Node* n = next;
            while(n)
            {
                Node* temp = n->next;
                delete n;
                n = temp;
            }
        }
        int nextVertex; //边
        Node* next; //下一邻接顶点
    };
    //头节点
    struct HeadNode
    {
        HeadNode()
        :element{},next(nullptr){}
        ~HeadNode()
        {
            delete next;
        }
        T element; //顶点信息
        Node* next; //下一邻接顶点
    };

    int _vertexCount; //顶点数
    int _edgeCount; //边数
    HeadNode _vertex[MaxVertexCount]; //各顶点数据
};