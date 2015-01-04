
#ifndef __QLINKLIST__
#define __QLINKLIST__


/* Definition for singly-linked list */
struct QListNode
{
	int val;
	QListNode *next;
	QListNode(int x) : val(x), next(nullptr) {}
};


class QLinkList
{
public:

	/* Linked List Cycle */
	// Given a linked list, determine if it has a cycle in it.
	// Solve it without using extra space.
    bool hasCycle(QListNode *head);
	// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
	// Solve it without using extra space.
	QListNode *detectCycle(QListNode *head);
};

#endif
