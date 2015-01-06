
#ifndef __DQTREE__
#define __DQTREE__

#include <vector>

template<class Type>
class DQTree
{

private:

	/* Definition for binary tree */
	struct TreeNode {
		Type val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(Type x) : val(x), left(nullptr), right(nullptr) {}
	};
	
	TreeNode *root;

	bool isBalancedHelper(TreeNode *root, int &depth);
	void inorderTraversalByRecursiveHelper(TreeNode *root, vector<int> &result);

public:

	//构造函数
	DQTree();
	//拷贝构造函数...
	//赋值构造函数...

	bool empty() { return root == nullptr; };
	
	/* Balanced Binary Tree */
	//Given a binary tree, determine if it is height-balanced.
	//For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
    bool isBalanced();

	vector<Type> inorderTraversalByIterate();
	vector<Type> inorderTraversalByRecursive();

	~DQTree() { cout << "here!";};
};

template<class Type>
DQTree<Type>::DQTree()
{
}

template<class Type>
bool DQTree<Type>::isBalancedHelper(TreeNode *root, int &depth)
{
    if (!root) return true;
    ++depth;
        
    int leftDepth = depth, rightDepth = depth;
    if (root->left  && !isBalancedHelper(root->left ,  leftDepth)) return false;
    if (root->right && !isBalancedHelper(root->right, rightDepth)) return false;
        
    if (abs(leftDepth - rightDepth) > 1) return false;
        
    if (leftDepth  > depth) depth =  leftDepth;
    if (rightDepth > depth) depth = rightDepth;
    
    return true;
}

template<class Type>
bool DQTree<Type>::isBalanced()
{
    if (empty()) return true;
    int depth = 0;
    return isBalancedHelper(root, depth);
}

template<class Type>
vector<Type> DQTree<Type>::inorderTraversalByIterate()
{
    vector<Type> result;
	stack<TreeNode *> walker;
	TreeNode *pCurNode = root;
	while (!walker.empty() || pCurNode != nullptr)
	{
		if (pCurNode != nullptr)
		{
			walker.push(pCurNode);
			pCurNode = pCurNode->left;
		}
		else
		{
			pCurNode = walker.top();
			walker.pop();
			result.push_back(pCurNode->val);
			pCurNode = pCurNode->right;
		}
	}

	return result;
}

template<class Type>
void DQTree<Type>::inorderTraversalByRecursiveHelper(TreeNode *root, vector<int> &result) {
	if (!root) return;
    if (root->left ) inorderTraversal(root->left,  result);
	result.push_back(root->val);
    if (root->right) inorderTraversal(root->right, result);
}

template<class Type>
vector<Type> DQTree<Type>::inorderTraversalByRecursive()
{
    vector<int> result;
	inorderTraversal(root, result);
	return result;
}
#endif