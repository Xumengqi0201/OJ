/*
21. Merge Two Sorted List
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	//返回l1,l2非空的一个链表；两者都为空时，第一个if直接返回空链表
    	if(l1==NULL)
    		return l2;
    	if (l2==NULL)
    		return l1;
        ListNode *head,*p;
        
    	if(l1->val<=l2->val){
    		head=new ListNode(l1->val);
    		l1=l1->next;
    	}
    	else{
    		head=new ListNode(l2->val);
    		l2=l2->next;
    	}
    	p=head;

    	while(l1&&l2){
    		if(l1->val<=l2->val){
    			p->next=new ListNode(l1->val);
    			l1=l1->next;
    		}
    		else{
    			p->next=new ListNode(l2->val);
    			l2=l2->next;
    		}
    		p=p->next;
    	}

    	if (l1){
    		p->next=l1;
    	}
    	else{
    		p->next=l2;
    	}

    	return head;
    }
};