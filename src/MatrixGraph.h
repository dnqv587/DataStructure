#pragma once
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <type_traits>

//***********************************************
// name      : 邻接矩阵
// brief     :
// attention : None
//***********************************************

/*/
 * 示例：有向图
 * A->B;B->C;C->A;C->D;D->A
 * 在下图中，行代表出，列代表入
 *  _____________________________
 * |_____|__A__|__B__|__C__|__D__|
 * |__A__|__0__|__1__|__0__|__0__|
 * |__B__|__0__|__0__|__1__|__0__|
 * |__C__|__1__|__0__|__0__|__1__|
 * |__D__|__1__|__0__|__0__|__0__|
 */

template <typename T,int MaxVertexCount = 10>
class MatrixGraph
{
public:
    MatrixGraph():_vertexCount(0),_edgeCount(0)
    {
        std::memset(_graph,0x00,MaxVertexCount*MaxVertexCount*sizeof(int));
    }
    ~MatrixGraph()=default;

    /// @brief 添加顶点
	template<typename _T = T>
    auto addVertex(const T& element)->typename std::enable_if_t<!std::is_trivially_copyable_v<_T>,void>
    {
        if(_vertexCount >= MaxVertexCount)
        {
            throw std::length_error("vertex count > MaxVertexCount");
        }
        _data[_vertexCount++]=element;
    }

    template<typename _T = T>
    auto addVertex(T element)->typename std::enable_if_t<std::is_trivially_copyable_v<_T>,void>
    {
        if(_vertexCount >= MaxVertexCount)
        {
            throw std::length_error("vertex count > MaxVertexCount");
        }
        _data[_vertexCount++]=element;
    }

    /// @brief 添加边 -- 有向图，不加权
    /// @param v1 出
    /// @param v2 入
    void addEdge(int v1,int v2)
    {
        if(_graph[v1][v2] == 0)
        {
            _graph[v1][v2] = 1;
            ++_edgeCount;
        }
    }

    void print() const
    {
        for(int i=0;i<MaxVertexCount;++i)
        {
            for(int j =0;j<MaxVertexCount;++j)
            {
                if(_graph[i][j]>0)
                {
                    std::cout<<_data[i]<<"->"<<_data[j]<<std::endl;
                }
            }
        }
    }

private:
    int _vertexCount; //顶点数
    int _edgeCount; //边数
    int  _graph[MaxVertexCount][MaxVertexCount]; //邻接矩阵--各边数据
    T _data[MaxVertexCount]; //各顶点数据
};