
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

public:

	//构造函数
	DQTree();
	//拷贝构造函数...
	//赋值构造函数...

	bool empty() { return root == nullptr; };

	~DQTree() { cout << "here!";};
};

#endif