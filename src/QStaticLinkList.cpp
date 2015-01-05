
#include "QStaticLinkList.h"

#define DEFAULT_MAX_SIZE 1000

QStaticLinkList::QStaticLinkList()
{
	QStaticLinkList(DEFAULT_MAX_SIZE);
}

/*�½�һ��һά����list�����������и���������һ����������list[0].curΪͷָ�룬��0����ʾ��ָ��*/
QStaticLinkList::QStaticLinkList(int capacity)
{
	list = new QStaticListNode [capacity];
	for (int i = 0; i < capacity - 1; i++)
	{
		list[i].cur = i + 1;
	}
	list[capacity - 1].cur = 0; // Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص�curΪ0
}

/*�����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻�0*/
int QStaticLinkList::malloc_SLL()
{
	int idx = list[0].cur;//��ǰ�����һ��Ԫ�ص�cur���ֵ������Ҫ���صĵ�һ�����ÿ��е��±ꡣ

	if (idx)
	{
		list[0].cur = list[idx].cur;//����Ҫ�ó�һ��������ʹ���ˣ��������Ǿ͵ð�������һ���������������á�
	}

	return idx;
}

/*���±�Ϊidx�Ŀ��н����յ���������*/
void QStaticLinkList::free_SSL(int idx)
{
	list[idx].cur = list[0].cur;//�ѵ�һ��Ԫ��curֵ����Ҫɾ���ķ���cur
	list[ 0 ].cur = idx;//��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur
}

/*��list��posλ��֮ǰ�����µ�����Ԫ��*/
bool QStaticLinkList::insert(int pos, int element)
{
	if (pos < 1 || pos > length)// + 1?
	{
		return false;
	}

	int newPos = malloc_SLL();
	if (!newPos)
	{
		return false;
	}

	list[newPos].val = element;
	int preIdx = getIdx(pos - 1);
	list[newPos].cur = list[preIdx].cur;
	list[preIdx].cur = newPos;
	++length;

	return true;
}
