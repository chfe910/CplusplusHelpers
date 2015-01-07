
#ifndef __QBinaryTree__
#define __QBinaryTree__

#include <vector>
#include <iterator>

template<class Type>
class QBinaryTree
{

private:

	typedef typename vector<Type>::iterator TypeVecIter;

	/* Definition for binary tree */
	struct TreeNode {
		Type val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(Type x) : val(x), left(nullptr), right(nullptr) {}
	};

	TreeNode *root;

	TreeNode *constructFromPreorderAndInorderTraversalHelper(TypeVecIter preBegin, TypeVecIter preEnd, TypeVecIter inBegin, TypeVecIter inEnd)
	{
		if (preEnd <= preBegin) return nullptr;

		TreeNode *root = new TreeNode(*preBegin);
		int leftNodes  = find(inBegin, inEnd, *preBegin) - inBegin;
		root->left  = constructFromPreorderAndInorderTraversalHelper(preBegin + 1, preBegin + leftNodes + 1, inBegin, inBegin + leftNodes);
		root->right = constructFromPreorderAndInorderTraversalHelper(preBegin + leftNodes + 1, preEnd, inBegin + leftNodes + 1, inEnd);

		return root;
	}

	TreeNode *constructFromInorderAndPostorderTraversalHelper(TypeVecIter inBegin, TypeVecIter inEnd, TypeVecIter postBegin, TypeVecIter postEnd)
	{
		if (postEnd <= postBegin) return nullptr;

        TreeNode *root = new TreeNode(*(postEnd - 1));
		int leftNodes  = find(inBegin, inEnd, *(postEnd - 1)) - inBegin;
		root->left  = constructFromInorderAndPostorderTraversalHelper(inBegin, inBegin + leftNodes, postBegin, postBegin + leftNodes);
		root->right = constructFromInorderAndPostorderTraversalHelper(inBegin + leftNodes + 1, inEnd, postBegin + leftNodes, postEnd - 1);

		return root;
    }

	bool isBalancedHelper(TreeNode *root, int &depth);
	void inorderTraversalByRecursiveHelper(TreeNode *root, vector<Type> &result);

public:
	
	//构造函数
	QBinaryTree();
	//拷贝构造函数...
	//赋值构造函数...

	bool empty() { return root == nullptr; };

	void constructFromPreorderAndInorderTraversal(vector<Type> &preorder, vector<Type> &inorder) { root = constructFromPreorderAndInorderTraversalHelper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end()); };
	void constructFromInorderAndPostorderTraversal(vector<Type> &inorder, vector<Type> &postorder) { root = constructFromInorderAndPostorderTraversalHelper(inorder.begin(), inorder.end(), postorder.begin(), postorder.end()); };
	
	/* Balanced Binary Tree */
	//Given a binary tree, determine if it is height-balanced.
	//For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
    bool isBalanced();

	vector<Type> inorderTraversalByIterate();
	vector<Type> inorderTraversalByRecursive();

	void destroy() {  };
	~QBinaryTree() { destroy(); };
};

template<class Type>
QBinaryTree<Type>::QBinaryTree()
{
}

template<class Type>
bool QBinaryTree<Type>::isBalancedHelper(TreeNode *root, int &depth)
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
bool QBinaryTree<Type>::isBalanced()
{
    if (empty()) return true;
    int depth = 0;
    return isBalancedHelper(root, depth);
}

template<class Type>
vector<Type> QBinaryTree<Type>::inorderTraversalByIterate()
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
void QBinaryTree<Type>::inorderTraversalByRecursiveHelper(TreeNode *root, vector<Type> &result) {
	if (!root) return;
    if (root->left ) inorderTraversal(root->left,  result);
	result.push_back(root->val);
    if (root->right) inorderTraversal(root->right, result);
}

template<class Type>
vector<Type> QBinaryTree<Type>::inorderTraversalByRecursive()
{
    vector<Type> result;
	inorderTraversal(root, result);
	return result;
}

#endif