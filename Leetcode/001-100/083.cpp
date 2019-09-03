/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        for (ListNode *p = head; p != NULL;){
            ListNode *q = p;
            //p和q开始指向同一个位置，p不动，q走到和p的value值不同的第一个节点的位置
            //重复上面的过程就可以去重了
            for (; q!=NULL && p->val == q->val; q = q->next);
            p->next = q;//p指向q的位置，丢掉了中间相同的节点
            p = q;//p现在在q的位置,重复上面的过程
        }

        return head;
    }
};

/*
  有序链表去重问题
  两个指针p和q移动
*/