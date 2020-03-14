/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
	solution 1:
	把链表中的数逐个相加

*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *tmp = NULL;
        int carry = 0, num = 0;
        while(l1 || l2){
        	num += carry;
        	if (l1){
        		num += l1->val;
        		l1 = l1->next;
        	}
        	if (l2){
        		num += l2->val;
        		l2 = l2->next;
        	}
        	if (num >= 10){
        		carry = 1;
        	}else{
        		carry = 0;
        	}

        	if (head == NULL){
        		head = new ListNode(num % 10);
        		tmp = head;
        	}else{
        		tmp->next = new ListNode(num%10);
        		tmp = tmp->next;
        	}
        	num = 0;
        }
        //坑，不要忘记最后的进位
        if (carry == 1){
        	tmp->next = new ListNode(1);
        }
        return head;
    }
};

