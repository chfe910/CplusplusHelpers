
#include "QStaticLinkList.h"

#define DEFAULT_MAX_SIZE 1000

template <class Type>
QStaticLinkList<Type>::QStaticLinkList()
{
	QStaticLinkList(DEFAULT_MAX_SIZE);
}

/*�½�һ��һά����list�����������и���������һ����������list[0].nextΪͷָ�룬��0����ʾ��ָ��*/
template <class Type>
QStaticLinkList<Type>::QStaticLinkList(int capacity)
{
	Capacity = capacity;
	list = new QStaticListNode [capacity];
	for (int i = 0; i < capacity - 1; i++)
	{
		list[i].next = i + 1;
	}
	list[capacity - 1].next = 0; // Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص�nextΪ0
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
	int idx = Capacity - 1;
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
