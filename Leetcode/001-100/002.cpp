/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*思路：
同时遍历两个链表，两个数相加大于10的时候，该节点数值为两数和对10取余，并在下一个节点的数+1
*/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *head=NULL,*p=NULL;
        int plus=0;
        while(l1||l2){
            int value=0;
            if(l1){
                value +=  l1->val;
                l1=l1->next;
            }
            if(l2){
                value += l2->val;
                l2=l2->next;
            }

            if (head==NULL) 
                p=head=new ListNode((value+plus)%10);
            else{
                p->next=new ListNode((value+plus)%10);
                p=p->next;
            }

            if ((value+plus)>=10)
                plus=1;
            else
                plus=0;

        }
        if (plus==1){
            p->next=new ListNode(1);
        }
             
        return head;
        
    }
};