
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

	//���캯��
	DQTree();
	//�������캯��...
	//��ֵ���캯��...

	bool empty() { return root == nullptr; };

	~DQTree() { cout << "here!";};
};

#endif