
#include "QLinkList.h"

bool QLinkList::hasCycle(QListNode *head) {
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
