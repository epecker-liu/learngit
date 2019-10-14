/* 给出两个链表，寻找它们相同的第一个节点 */
/* 1.用第一个链表中的节点依次与第二个链表中的节点进行比较（遍历）。2.创建两个栈，stack1和stack2 将两个链表push进栈中，后比较两个栈的top 如果相同，则同时出栈，若不相同，则返回该top的next节点。 3.比较两个链表的长度，设长度分别为m，n ，m>=n将链表1移动m-n个节点，使两个链表长度相同，后比较两个链表的头节点，相同则为首个相同的节点。*/
/* 分析：当存在一个节点相同时，其后的节点必然相同 */
/* 方法一 时间复杂度 n*n 空间复杂度 0， 方法二 时间复杂度 m+n 空间复杂度 m+n 方法三 时间复杂度 m+n  空间复杂度 0*/

int GetListLength(ListNode* head){
    int length = 0;
    ListNode* node = head;
    while(node){
        length++;
        node = node  -> next;
    }
    return length;
}

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
    ListNode* LongList  = pHead1;
    ListNode* ShortList  = pHead2;
    int m = 0,n = 0,dif = 0;
    m = GetListLength(pHead1);
    n = GetListLength(pHead2);
    dif = m - n;
    if(dif < 0){
        dif = -dif;
        LongList = pHead2;
        ShortList = pHead1;
    }
    for(int i = 0; i < dif; i++){
        LongList = LongList -> next;
    }
    while(LongList != ShortList){
        LongList = LongList -> next;
        ShortList = ShortList -> next;
    }
    return LongList;
}
