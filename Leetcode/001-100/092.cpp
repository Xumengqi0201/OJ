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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	ListNode *pre_m = findKth(head, m-1);
    	ListNode *pm = findKth(head, m);    
    	ListNode *pn = findKth(head, n);
    	ListNode *pn_next = pn->next;

    	ListNode *pre = pm, *cur = pm->next;
    	while (pre != pn){
    		ListNode *tmp = cur->next;
    		cur->next = pre;
    		pre = cur;
    		cur = tmp;
    	}
    	pm->next = pn_next;
    	if (pre_m){
    		pre_m->next = pn;
    		return head;
    	}
    	return pn;


    }

    ListNode* findKth(ListNode *head, int k){
    	ListNode *p = head;
    	for (int i = 1;p && i < k; i++){
    		p = p->next;
    	}
    	return p;
    }
};