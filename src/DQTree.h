
#ifndef __DQTREE__
#define __DQTREE__


template<class Type>
class DQTree
{

private:

	/* Definition for binary tree */
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	
	TreeNode *root;

	bool isBalanced(TreeNode *root, int &depth);

public:

	//构造函数
	DQTree();
	//拷贝构造函数...
	//赋值构造函数...

	bool empty() { return root == nullptr; };
	
    bool isBalanced();

	~DQTree() { cout << "here!";};
};

template<class Type>
bool DQTree<Type>::isBalanced(TreeNode *root, int &depth) {
    if (!root) return true;
    ++depth;
        
    int leftDepth = depth, rightDepth = depth;
    if (root->left  && !isBalanced(root->left ,  leftDepth)) return false;
    if (root->right && !isBalanced(root->right, rightDepth)) return false;
        
    if (abs(leftDepth - rightDepth) > 1) return false;
        
    if (leftDepth  > depth) depth =  leftDepth;
    if (rightDepth > depth) depth = rightDepth;
    
    return true;
}

template<class Type>
bool DQTree<Type>::isBalanced() {
    if (empty()) return true;
    int depth = 0;
    return isBalanced(root, depth);
}

#endif