#pragma once
#include "BinaryTree.h"

//***********************************************
// name      : 二叉排序树
// brief     : 定义：
// 1、左子树小于父节点，右子树大于父节点。
// 2、通过中序遍历，即可获取到从小到大的有序链表			
// attention : None
//***********************************************
template <typename T>
class BST:public BinaryTree<T>
{
	using Node = BinaryTree<T>::Node;
 public:
	explicit BST(const T& val):BinaryTree<T>(val)
	{}

    /// @brief 插入数据
    /// @param val 
    /// @excpetion 若查询已经存在的值，则抛出异常
	void Insert(const T& val) override
	{
		std::function<void (Node*)> ins = [&ins,&val](Node* node){
			if(!node)
			{
				return;
			}
			if(val < node->data)
			{
				if(node->left)
				{
					ins(node->left);
				}
				else
				{
					node->left = new Node (val);
				}
			}
			else if (val > node->data)
			{
				if(node->right)
				{
					ins(node->right);
				}
				else
				{
					node->right = new Node (val);
				}
			}
            if(val == node->data)
            {
                throw std::logic_error("the value already exists");
            }
		};
        try
        {
            ins(this->_root);
        }
        catch (...)
        {
            throw;
        }

        ++this->_nodeNum;
	}

    void Delete(const T& val) override
    {
        /*被删除节点：
         * 1、无左右孩子：直接删除
         * 2、只有一个孩子：替换为左/右孩子节点，并删除
         * 3、存在左右孩子：
         *      （1）、选取其左子树最大节点上位/选取其右子树最小节点上位，（其左子树最大节点，只可能有左子树），（其右子树最小节点，只可能有右子树）
         *      （2）、将上位的节点替换为左/右孩子节点，并删除
         */
        std::function<Node* (Node* node)> del = [&del,&val, this](Node* node)->Node* {
            if(node == nullptr)
            {
                return nullptr;
            }
            if(val > node->data)
            {
                node->right = del(node->right);
            }
            else if(val < node->data)
            {
                node->left = del(node->left);
            }
            else //找到
            {
                if(node->left && node->right) //被删除的节点存在左右孩子
                {
					Node* maxNode = max(node);
					node->data = maxNode->data;
					node->left = maxNode->left;
					delete maxNode;
                }
                else //被删除节点只存在一个孩子或无孩子节点
                {
					Node* tmp = node;
					if(node->left)
					{
						node = node->left;
					}
					else if(node->right)
					{
						node = node->right;
					}
					else
					{
						node = nullptr;
					}
					delete tmp;
                }

            }
			return node;
        };

		del(this->_root);
    }

    const T& max() const
    {
		return max(this->_root)->data;
    }

    const T& min() const
    {
        return min(this->_root)->data;
    }

 private:
	Node* max(Node* node) const
	{
		while(node && node->right)
		{
			node = node->right;
		}
		return node;
	}

	Node* min(Node* node) const
	{
		while(node && node->left)
		{
			node = node->left;
		}
		return node;
	}
};