
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

private:


	QListNode *head;
	QListNode *dummyHead;
	QListNode *tail;
	int length;


public:
	

	QLinkList();
	QLinkList(int *values, int length);


	//QListNode *head()		{ return head;				};
	//QListNode *dummyHead()	{ return dummyHead;			};
	//QListNode *tail()		{ return tail;				};
	//int length()	{ return length;			};
	bool empty()			{ return length == 0;	};


	bool get	(int pos, int &value);
	bool insert	(int pos, int  value);
	bool insert	(int pos, int *values, int length);
	bool Delete	(int pos);
	bool Delete	(int start, int end);


	/* Linked List Cycle */
	// Given a linked list, determine if it has a cycle in it.
	// Solve it without using extra space.
    bool hasCycle();
	// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
	// Solve it without using extra space.
	QListNode *detectCycle();


	~QLinkList();


};

#endif
