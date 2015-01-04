
#ifndef __QLINKLIST__
#define __QLINKLIST__

class QLinkList {
public:


	/************************ Definition for singly-linked list ************************/
	struct QListNode {
		int val;
		QListNode *next;
		QListNode(int x) : val(x), next(nullptr) {}
	};


	/* Linked List Cycle */
	// Given a linked list, determine if it has a cycle in it.
	// Solve it without using extra space.
    bool hasCycle(QListNode *head);


};

#endif
