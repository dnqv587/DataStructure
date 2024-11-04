#pragma once
#include <functional>

//***********************************************
// name      : 二叉树
// brief     : 
// attention : None
//***********************************************
template <typename T>
class BinaryTree
{
public:

	explicit BinaryTree(const T& val)
	:_root(new Node(val)),_nodeNum(0)
	{
	}

	virtual ~BinaryTree()
	{
		std::function<void (Node*)> del = [&del](Node* node){
			if(!node)
			{
				return;
			}
			auto left = node->left;
			auto right = node->right;
			delete node;
			del(left);
			del(right);
		};

		del(_root);
	}

	virtual void insert(const T& node) = 0;

	/// @brief 先序遍历
	/// @param func
	void preOrder(std::function<void (const T& data)> func)
	{
		std::function<void (Node*)> preorder = [&preorder,&func](Node* node){
			if(!node)
			{
				return;
			}
		  	std::invoke(func,node->data);
		  preorder(node->left);
		  preorder(node->right);
		};

		preorder(_root);
	}

	/// @brief 中序遍历
	/// @param func
	void inOrder(std::function<void (const T& data)> func)
	{
		std::function<void (Node*)> inorder = [&inorder,&func](Node* node){
		  if(!node)
		  {
			  return;
		  }

		  inorder(node->left);
		  std::invoke(func,node->data);
		  inorder(node->right);
		};

		inorder(_root);
	}

	/// @brief 后序遍历
	/// @param func
	void postOrder(std::function<void (const T& data)> func)
	{
		std::function<void (Node*)> postorder = [&postorder,&func](Node* node){
		  if(!node)
		  {
			  return;
		  }

		  postorder(node->left);
		  std::invoke(func,node->data);
		  postorder(node->right);
		};

		postorder(_root);
	}

 protected:
    struct Node
    {
		explicit Node(const T&val)
		:data(val),left(nullptr),right(nullptr){}

        T data;
        Node* left;
        Node* right;
    };

    Node* _root;
	size_t _nodeNum;
};