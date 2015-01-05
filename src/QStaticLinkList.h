

#ifndef __QSTATICLINKLIST__
#define __QSTATICLINKLIST__

#include <iostream>
using namespace std;

template<class Type>
class QStaticLinkList
{

private:
	
	#define DEFAULT_MAX_SIZE 1000

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

	//���캯��
	QStaticLinkList();
	QStaticLinkList(int capacity);
	//�������캯��...
	//��ֵ���캯��...

	bool empty() { return length == 0; };
	Type get(int pos);
	int  find(Type value);

	bool insert(int pos, Type value);
	bool Delete(int pos);

	~QStaticLinkList() { delete [] list; cout << "here!";};
};

template <class Type>
QStaticLinkList<Type>::QStaticLinkList()
{
	Capacity = DEFAULT_MAX_SIZE;
	length = 0;

	list = new QStaticListNode [Capacity];
	for (int i = 0; i < Capacity - 1; i++)
	{
		list[i].next = i + 1;
	}
	list[Capacity - 1].next = 0; // Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص�nextΪ0
}

/*�½�һ��һά����list�����������и���������һ����������list[0].nextΪͷָ�룬��0����ʾ��ָ��*/
template <class Type>
QStaticLinkList<Type>::QStaticLinkList(int capacity = DEFAULT_MAX_SIZE)
{
	Capacity = capacity;
	length = 0;

	list = new QStaticListNode [Capacity];
	for (int i = 0; i < Capacity - 1; i++)
	{
		list[i].next = i + 1;
	}
	list[Capacity - 1].next = 0; // Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص�nextΪ0
}

/*�����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻�0*/
template <class Type>
int QStaticLinkList<Type>::mallocNode()
{
	int idx = list[0].next;//��ǰ�����һ��Ԫ�ص�next���ֵ������Ҫ���صĵ�һ�����ÿ��е��±ꡣ

	if (idx)
	{
		list[0].next = list[idx].next;//����Ҫ�ó�һ��������ʹ���ˣ��������Ǿ͵ð�������һ���������������á�
	}

	return idx;
}

/*���±�Ϊidx�Ŀ��н����յ���������*/
template <class Type>
void QStaticLinkList<Type>::freeNode(int idx)
{
	list[idx].next = list[0].next;//�ѵ�һ��Ԫ��nextֵ����Ҫɾ���ķ���next
	list[ 0 ].next = idx;//��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�next
}

template <class Type>
int QStaticLinkList<Type>::getIdx(int pos)
{
	if (pos > length) return -1;

	int idx = Capacity - 1;
	for (int i = 0; i < pos; ++i)
	{
		idx = list[idx].next;
	}

	return idx;
}

template <class Type>
Type QStaticLinkList<Type>::get(int pos)
{
	if (pos > length) return -1;

	int idx = Capacity - 1;
	for (int i = 0; i < pos; ++i)
	{
		idx = list[idx].next;
	}

	return list[idx].val;
}

template <class Type>
int QStaticLinkList<Type>::find(Type value)
{
	int idx = list[Capacity - 1].next;
	for (int i = 1; i <= length; ++i)
	{
		if (list[idx].val == value) return i;
		idx = list[idx].next;
	}

	return -1;
}

/*��������posλ��֮ǰ�����µ�����Ԫ��*/
template <class Type>
bool QStaticLinkList<Type>::insert(int pos, Type value)
{
	if (pos < 1 || pos > length + 1)
	{
		return false;
	}

	int newPos = mallocNode();
	if (!newPos)
	{
		return false;
	}

	list[newPos].val = value;
	int preIdx = getIdx(pos - 1);
	list[newPos].next = list[preIdx].next;
	list[preIdx].next = newPos;
	++length;

	return true;
}

/*ɾ��������posλ�õ�����Ԫ��*/
template <class Type>
bool QStaticLinkList<Type>::Delete(int pos)
{
	if (pos < 1 || pos > length)
	{
		return false;
	}
	
	int preIdx = getIdx(pos - 1);
	int delIdx = list[preIdx].next;
	list[preIdx].next = list[delIdx].next;
	freeNode(delIdx);
	--length;

	return true;
}

#endif
