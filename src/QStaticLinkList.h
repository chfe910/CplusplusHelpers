

#ifndef __QSTATICLINKLIST__
#define __QSTATICLINKLIST__


class QStaticLinkList
{

private:

	typedef struct 
	{
		int val;
		int next;
	} QStaticListNode;

	QStaticListNode *list;
	int Capacity;
	int length;

	int  mallocNode();
	void freeNode(int idx);
	int getIdx(int pos);

public:

	QStaticLinkList();
	QStaticLinkList(int capacity);

	bool empty() { return length == 0; };
	int  get(int pos);
	int  find(int value);

	bool insert(int pos, int value);
	bool Delete(int pos);

	~QStaticLinkList();
};

#endif
