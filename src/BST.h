#pragma once
#include "BinaryTree.h"

//***********************************************
// name      : 二叉排序树
// brief     :
// attention : None
//***********************************************
template <typename T>
class BST:public BinaryTree<T>
{
	using Node = BinaryTree<T>::Node;
 public:
	explicit BST(const T& val):BinaryTree<T>(val)
	{}

	void insert(const T& val) override
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
			else
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

		};

		ins(this->_root);
	}
};