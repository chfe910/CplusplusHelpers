

#ifndef __QSTATICLINKLIST__
#define __QSTATICLINKLIST__

template<class Type>
class QStaticLinkList
{

private:

	typedef struct 
	{
		Type val;
		int next;
	} QStaticListNode;

	QStaticListNode *list;
	int Capacity;
	int length;

	int  mallocNode();
	void freeNode(int idx);
	int  getIdx(int pos);

public:

	QStaticLinkList();
	QStaticLinkList(int capacity);

	bool empty() { return length == 0; };
	Type get(int pos);
	int  find(Type value);

	bool insert(int pos, Type value);
	bool Delete(int pos);

	~QStaticLinkList() { delete [] list; };
};

#endif
