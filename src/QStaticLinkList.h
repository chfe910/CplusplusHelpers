

#ifndef __QSTATICLINKLIST__
#define __QSTATICLINKLIST__


typedef struct 
{
	int val;
	int cur; // Cursor
} QStaticListNode;


class QStaticLinkList
{
private:
	QStaticListNode *list;
	unsigned int length;

	int malloc_SLL();
	void free_SSL(int idx);

	int getIdx(int pos);

public:
	QStaticLinkList();
	QStaticLinkList(int capacity);

	//unsigned int length();
	bool empty()			{ return length == 0;	};
	int  getPos(int value);
	int  getVal(int pos);

	bool insert(int pos, int element);
};

#endif
