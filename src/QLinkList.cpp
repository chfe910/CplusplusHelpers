
#include "QLinkList.h"

bool QLinkList::hasCycle()
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

QListNode *QLinkList::detectCycle()
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