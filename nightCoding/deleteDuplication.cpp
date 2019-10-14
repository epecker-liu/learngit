ListNode* DeleteDuplication(ListNode* pHead) {/* 给出一个从小到大排序的链表，删除其中有相同数字的全部节点 */
    /* 设置两个指针first 和 second first指向最后一个确定不需要删除的节点，second指向第一个需要判断的节点，当*second和*（second->next）相同的时候，将second向后移动一个节点，并重复判断，直到两个数字不同，结束判断后删除 first 之后到second的所有节点，将second 指向second->next的位置*/
    ListNode* p = new ListNode(-1);
    ListNode* first;
    ListNode* second;
    p -> next = pHead;
    first = p;
    second = pHead;
    while(second != NULL){
        if(second -> next && second -> val == (second -> next) -> val){
            while(second -> next && second -> val == (second -> next) -> val){
                second = second -> next;
            }
            first -> next = second -> next;
        }
        else{
            first = first -> next;
        }  
        second = second -> next;
     }
     return p -> next;
}
