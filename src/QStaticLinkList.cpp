
#include "QStaticLinkList.h"

#define DEFAULT_MAX_SIZE 1000

QStaticLinkList::QStaticLinkList()
{
	QStaticLinkList(DEFAULT_MAX_SIZE);
}

/*�½�һ��һά����list�����������и���������һ����������list[0].nextΪͷָ�룬��0����ʾ��ָ��*/
QStaticLinkList::QStaticLinkList(int capacity)
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
int QStaticLinkList::mallocNode()
{
	int idx = list[0].next;//��ǰ�����һ��Ԫ�ص�next���ֵ������Ҫ���صĵ�һ�����ÿ��е��±ꡣ

	if (idx)
	{
		list[0].next = list[idx].next;//����Ҫ�ó�һ��������ʹ���ˣ��������Ǿ͵ð�������һ���������������á�
	}

	return idx;
}

/*���±�Ϊidx�Ŀ��н����յ���������*/
void QStaticLinkList::freeNode(int idx)
{
	list[idx].next = list[0].next;//�ѵ�һ��Ԫ��nextֵ����Ҫɾ���ķ���next
	list[ 0 ].next = idx;//��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�next
}

int QStaticLinkList::getIdx(int pos)
{
	if (pos > length) return -1;

	int idx = Capacity - 1;
	for (int i = 0; i < pos; ++i)
	{
		idx = list[idx].next;
	}

	return idx;
}

int QStaticLinkList::get(int pos)
{
	if (pos > length) return -1;

	int idx = Capacity - 1;
	for (int i = 0; i < pos; ++i)
	{
		idx = list[idx].next;
	}

	return list[idx].val;
}

int QStaticLinkList::find(int value)
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
bool QStaticLinkList::insert(int pos, int value)
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
bool QStaticLinkList::Delete(int pos)
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

QStaticLinkList::~QStaticLinkList()
{
	delete [] list;
}