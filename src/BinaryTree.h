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

	virtual void Insert(const T& node) = 0;

    virtual void Delete(const T& node) = 0;

	/// @brief 先序遍历 -- 根左右
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

	/// @brief 中序遍历 -- 左根右
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

	/// @brief 后序遍历 -- 左右根
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

    /// @brief 左子树的高度
    /// @return 高度
    size_t LeftDepth() const
    {
        std::function<size_t (Node*)> depth = [&depth](Node* node)->size_t{
            if(node == nullptr)
            {
                return 0;
            }
            size_t left = depth(node->right);
            size_t right = depth(node->left);
            return std::max(left,right) + 1;
        };

        return depth(_root->left);
    }

    /// @brief 右子树的高度
    /// @return 高度
    size_t RightDepth() const
    {
        std::function<size_t (Node*)> depth = [&depth](Node* node)->size_t{
            if(node == nullptr)
            {
                return 0;
            }
            size_t left = depth(node->right);
            size_t right = depth(node->left);
            return std::max(left,right) + 1;
        };

        return depth(_root->right);
    }

    /// @brief 树的高度
    /// @return 高度
    size_t depth() const
    {
        std::function<size_t (Node*)> depth = [&depth](Node* node)->size_t{
            if(node == nullptr)
            {
                return 0;
            }
            size_t left = depth(node->right);
            size_t right = depth(node->left);
            return std::max(left,right) + 1;
        };

        return std::max(depth(_root->left),depth(_root->right));
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