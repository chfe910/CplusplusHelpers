
#include "QStaticLinkList.h"

#define DEFAULT_MAX_SIZE 1000

QStaticLinkList::QStaticLinkList()
{
	QStaticLinkList(DEFAULT_MAX_SIZE);
}

/*新建一个一维数组list，将该数组中各分量链成一条备用链表，list[0].cur为头指针，“0”表示空指针*/
QStaticLinkList::QStaticLinkList(int capacity)
{
	list = new QStaticListNode [capacity];
	for (int i = 0; i < capacity - 1; i++)
	{
		list[i].cur = i + 1;
	}
	list[capacity - 1].cur = 0; // 目前静态链表为空，最后一个元素的cur为0
}

/*若备用空间链表非空，则返回分配的结点下标，否则返回0*/
int QStaticLinkList::malloc_SLL()
{
	int idx = list[0].cur;//当前数组第一个元素的cur存的值，就是要返回的第一个备用空闲的下标。

	if (idx)
	{
		list[0].cur = list[idx].cur;//由于要拿出一个分量来使用了，所以我们就得把它的下一个分量用来做备用。
	}

	return idx;
}

/*将下标为idx的空闲结点回收到备用链表*/
void QStaticLinkList::free_SSL(int idx)
{
	list[idx].cur = list[0].cur;//把第一个元素cur值赋给要删除的分量cur
	list[ 0 ].cur = idx;//把要删除的分量下标赋值给第一个元素的cur
}

/*在list中pos位置之前插入新的数据元素*/
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
