/* 判断一个链表是否有环，如果有返回入口 */
/* 设置一个快指针和一个慢指针，快指针每次走两个节点，满指针走一个节点，重复执行，当快指针为NULL的时候，证明该链表没有环，返回NULL，当快指针等于满指针的时候，证明有环，将快指正返回到链表的首部，让其每次走一个节点，当下一次快指针和满指针相遇的时候，即为入口的位置 */
ListNode* EntryNodeOfLoop(ListNode* pHead) {
    if(pHead == NULL || pHead -> next ==NULL){
        return NULL;
    }
    ListNode* fast = pHead;
    ListNode* slow = pHead;
    while(1){
        fast = fast -> next -> next;
        slow = slow -> next;
        if(fast == NULL || fast -> next == NULL){
            return NULL;
        }
        if(fast == slow){
            break;
        }
    }
    fast = pHead;
    while(1){
        if(fast == slow){      //注意本身就是一个环的情况
            return fast;
        }
        fast = fast -> next;
        slow = slow -> next;
    }
}
