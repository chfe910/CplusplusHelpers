
#ifndef __QLINKLIST__
#define __QLINKLIST__


/* Definition for singly-linked list */
struct QListNode
{
	int val;
	QListNode *next;
	QListNode(int x) : val(x), next(nullptr) {}
};


template<class Type>
class QLinkList
{

private:

	QListNode *head;
	QListNode *dummyHead;
	QListNode *tail;
	int length;

	QListNode *mergeHelper(QListNode *l1, QListNode *l2)
	{
		if (!l1) return l2;
		if (!l2) return l1;

		if (l1->val <= l2->val)
		{
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
    }

public:
	
	QLinkList() {}
	//QLinkList(int *values, int length);

	//QListNode *head()		{ return head;				};
	//QListNode *dummyHead()	{ return dummyHead;			};
	//QListNode *tail()		{ return tail;				};
	//int length()	{ return length;			};
	bool empty()			{ return length == 0;	};

	/*bool get	(int pos, int &value);
	bool insert	(int pos, int  value);
	bool insert	(int pos, int *values, int length);
	bool Delete	(int pos);
	bool Delete	(int start, int end);*/

	/* Linked List Cycle */
	// Given a linked list, determine if it has a cycle in it.
	// Solve it without using extra space.
    bool hasCycle();
	// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
	// Solve it without using extra space.
	QListNode *detectCycle();

	/* Merge Two Sorted Lists */
	// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
	bool merge(QLinkList anotherList) { mergeHelper(head, anotherList.head) };

	bool clear() {}
	~QLinkList() { clear(); }
};

template<class Type>
bool QLinkList<Type>::hasCycle()
{
    if (!head) return false;
        
    QListNode *slow = head, *fast = head;
    while (slow->next && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
        
    return false;
}

template<class Type>
QListNode *QLinkList<Type>::detectCycle()
{
    if (!head) return false;
    
    QListNode *slow = head, *fast = head;
    while (slow->next && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
			for (slow = head; slow != fast; slow = slow->next, fast = fast->next) ;
			return slow;
		}
    }
    
    return nullptr;
}


#endif
