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
    ListNode* removeElements(ListNode* head, int val) {
    	while (head){
    		if (head ->val != val){
    			break;
    		}
    		ListNode *tmp = head;
			head = head->next;
			delete tmp;
    		
    	}
    	ListNode *pre = NULL, *cur = head;
    	while(cur){
    		if (cur->val == val){
    			if (pre){
    				pre->next = cur->next;
    				delete cur;
    				cur = pre->next;
    			}
    			else{
	    			ListNode *tmp = cur;
	    			cur = cur->next;
	    			delete tmp;
    			}
    		}
    		else{
    			pre = cur;
                cur = cur->next;
    		}
    	}
    	return head;
        
    }
};

//linked list去重，主要是head的处理