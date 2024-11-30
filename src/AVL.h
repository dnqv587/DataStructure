#pragma once
#include "BinaryTree.h"

template <typename T>
class AVL:public BinaryTree<T>
{
public:
    AVL()=default;
    ~AVL()=default;

    void Insert(const T& val) override
    {

    }

    /// @brief 平衡因子
    /// @return 左子树-右子树的差
    size_t BalanceFactor() const
    {
        return this->LeftDepth() - this->RightDepth();
    }


private :
    using Node=BinaryTree<T>::Node;
};