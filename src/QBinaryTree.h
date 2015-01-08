
#ifndef __QBinaryTree__
#define __QBinaryTree__

#include <vector>
#include <stack>
#include <queue>
#include <iterator>

template<class Type>
class QBinaryTree
{

private:

	typedef typename vector<Type>::iterator TypeVecIter;

	/* Definition for binary tree */
	struct TreeNode
	{
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

	TreeNode *convertSortedArrayToBSTHelper(vector<int> &num, int start, int end)
	{
		int mid = (start + end) >> 1;
        TreeNode *root = new TreeNode(num[mid]);
		
		if (start < mid) root->left  = sortedArrayToBST(num, start, mid - 1);
		if (mid   < end) root->right = sortedArrayToBST(num, mid + 1, end);

		return root;
    }

	bool isSameTreeHelper(TreeNode *p, TreeNode *q)
	{
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTreeHelper(p->left, q->left) && isSameTreeHelper(p->right, q->right);
    }

	bool isSymmetricHelper(TreeNode *left, TreeNode *right)
	{
        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }

	bool isBalancedHelper(TreeNode *root, int &depth);
	int  maxDepthHelper(TreeNode *root) { root == nullptr ? 0 : max(maxDepthHelper(root->left) + 1, maxDepthHelper(root->right) + 1); }
	//int  minDepthHelper(TreeNode *root) { root == nullptr ? 0 : min(minDepthHelper(root->left) + 1, minDepthHelper(root->right) + 1); }
	void inorderTraversalByRecursiveHelper(TreeNode *root, vector<Type> &result);

public:
	
	//构造函数
	QBinaryTree();
	//拷贝构造函数...
	//赋值构造函数...

	bool empty() { return root == nullptr; }

	void constructFromPreorderAndInorderTraversal (vector<Type> &preorder, vector<Type> &inorder)   { root = constructFromPreorderAndInorderTraversalHelper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end()); }
	void constructFromInorderAndPostorderTraversal(vector<Type> &inorder,  vector<Type> &postorder) { root = constructFromInorderAndPostorderTraversalHelper(inorder.begin(), inorder.end(), postorder.begin(), postorder.end()); }

	// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
	void convertSortedArrayToBST(vector<int> &num) { root = num.empty() ? nullptr : convertSortedArrayToBSTHelper(num, 0, num.size() - 1); } // What if root is not nullptr? 
	
	/* Same Tree */
	// Given two binary trees, check if they are equal or not.
	// Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
	bool isSameTree(QBinaryTree &anotherTree) { return isSameTreeHelper(root, anotherTree.root); } // root is a private member, can get it? -> friend?

	/* Symmetric Tree */
	// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
	bool isSymmetric() { return root == nullptr ? true : isSymmetricHelper(root->left, root->right); }

	/* Balanced Binary Tree */
	// Given a binary tree, determine if it is height-balanced.
	// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
    bool isBalanced();

	/* Maximum Depth of Binary Tree */
	// Given a binary tree, find its maximum depth.
	// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
	int maxDepth() { return maxDepthHelper(root); }

	/* Minimum Depth of Binary Tree */
	// Given a binary tree, find its minimum depth.
	// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
	// int minDepth() { return minDepthHelper(root); } // Recursive is not a good idea?
	int minDepth();

	/* Traversal Methods */
	vector<Type>					 preorderTraversalByIterate  (); // Given a binary tree, return the preorder traversal of its nodes' values. Do it by iterate.
	vector<Type>					  inorderTraversalByIterate  (); // Given a binary tree, return the inorder traversal of its nodes' values. Do it by iterate.
	vector<Type>					  inorderTraversalByRecursive(); // Given a binary tree, return the inorder traversal of its nodes' values. Do it by recursive.
	vector<Type>					postorderTraversalByIterate  (); // Given a binary tree, return the postorder traversal of its nodes' values. Do it by iterate.
	vector<vector<Type> >		   levelOrderTraversalByIterate  (); // Given a binary tree, return the levelorder traversal of its nodes' values. Do it by iterate. (ie, from left to right, level by level).
	vector<vector<Type> >  bottomUpLevelOrderTraversalByIterate  (); // Given a binary tree, return the bottom-up levelorder traversal of its nodes' values. Do it by iterate. (ie, from left to right, level by level from leaf to root).
	vector<vector<Type> >	 zigzagLevelOrderTraversalByIterate  (); // Given a binary tree, return the zigzag level order traversal of its nodes' values. Do it by iterate. (ie, from left to right, then right to left for the next level and alternate between).

	void destroy() {  }
	~QBinaryTree() { destroy(); }
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
int QBinaryTree<Type>::minDepth()
{
	if (!root) return 0;

	struct TreeNodeWithDepth
	{
		TreeNode *node;
		int depth;
		TreeNodeWithDepth(TreeNode *n, int d) : node(n), depth(d) {}
	};

	int min = INT_MAX;
	stack<TreeNodeWithDepth> nodeStack;

	nodeStack.push(TreeNodeWithDepth(root, 1));
	while (!nodeStack.empty())
	{
		TreeNodeWithDepth curNode = nodeStack.top();
		nodeStack.pop();

		if (curNode.node->left ) nodeStack.push(TreeNodeWithDepth(curNode.node->left , curNode.depth + 1));
		if (curNode.node->right) nodeStack.push(TreeNodeWithDepth(curNode.node->right, curNode.depth + 1));
		if (!curNode.node->left && !curNode.node->right) min = curNode.depth < min ? curNode.depth : min;
	}

	return min;
}

template<class Type>
vector<Type> QBinaryTree<Type>::preorderTraversalByIterate()
{
    vector<Type> orderVal;

	if (!root) return orderVal;

	stack<TreeNode *> nodeStack;
	nodeStack.push(root);
	while (!nodeStack.empty())
	{
		TreeNode *curNode = nodeStack.top();
		nodeStack.pop();
		orderVal.push_back(curNode->val);

		if (curNode->right) nodeStack.push(curNode->right);
		if (curNode->left ) nodeStack.push(curNode->left );
	}

	return orderVal;
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
void QBinaryTree<Type>::inorderTraversalByRecursiveHelper(TreeNode *root, vector<Type> &result)
{
	if (!root) return;
    if (root->left ) inorderTraversalByRecursiveHelper(root->left,  result);
	result.push_back(root->val);
    if (root->right) inorderTraversalByRecursiveHelper(root->right, result);
}

template<class Type>
vector<Type> QBinaryTree<Type>::inorderTraversalByRecursive()
{
    vector<Type> result;
	inorderTraversalByRecursiveHelper(root, result);
	return result;
}

template<class Type>
vector<Type> QBinaryTree<Type>::postorderTraversalByIterate()
{
    vector<Type> orderVal;

	if (!root) return orderVal;

	stack<TreeNode *> nodeStack;
	nodeStack.push(root);
	while (!nodeStack.empty())
	{
		TreeNode *curNode = nodeStack.top();
		nodeStack.pop();
		orderVal.push_back(curNode->val);

		if (curNode->left ) nodeStack.push(curNode->left );
		if (curNode->right) nodeStack.push(curNode->right);
	}

	reverse(orderVal.begin(), orderVal.end());

	return orderVal;
}

template<class Type>
vector<vector<Type> > QBinaryTree<Type>::levelOrderTraversalByIterate()
{
    vector<vector<Type> > result;
	vector<Type> level;

	queue<TreeNode *> levelQ;
	if (root) levelQ.push(root);		
	while (!levelQ.empty())
	{
		level.clear();
		int size = levelQ.size();
		for (int i = 0; i < size; ++i)
		{
			TreeNode *node = levelQ.front();
			levelQ.pop();

			level.push_back(node->val);

			if (node->left ) levelQ.push(node->left );
			if (node->right) levelQ.push(node->right);
		}

		result.push_back(level);
	}

	return result;
}

template<class Type>
vector<vector<Type> > QBinaryTree<Type>::bottomUpLevelOrderTraversalByIterate()
{
    vector<vector<Type> > result;
	vector<Type> level;

	queue<TreeNode *> levelQ;
	if (root) levelQ.push(root);		
	while (!levelQ.empty())
	{
		level.clear();
		int size = levelQ.size();
		for (int i = 0; i < size; ++i)
		{
			TreeNode *node = levelQ.front();
			levelQ.pop();

			level.push_back(node->val);

			if (node->left ) levelQ.push(node->left );
			if (node->right) levelQ.push(node->right);
		}

		result.insert(result.begin(), level);
	}

	return result;
}

template<class Type>
vector<vector<Type> > QBinaryTree<Type>::zigzagLevelOrderTraversalByIterate()
{
    vector<vector<Type> > res;
        
    vector<TreeNode *> iter;
    if (root) iter.push_back(root);
        
    int isForward = 1;
    while (!iter.empty())
	{
        int size = iter.size();
        vector<Type> level;
            
        for (int i = 0; i < size; ++i)
		{
            level.push_back(iter[i]->val);
            if (iter[i]->left) iter.push_back(iter[i]->left);
            if (iter[i]->right) iter.push_back(iter[i]->right);
        }
            
        if (!isForward) reverse(level.begin(), level.end());
        res.push_back(level);
        iter.erase(iter.begin(), iter.begin() + size);
        isForward ^= 0x01;
    }
        
    return res;
}

#endif