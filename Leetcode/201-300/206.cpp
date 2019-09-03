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
    ListNode* reverseList(ListNode* head) {
    	ListNode *pre = NULL, *cur = head;
    	while (cur){
    		ListNode *tmp = cur->next;
    		cur->next = pre;
    		pre = cur;
    		cur = tmp;
    	}
        return pre;
    }
};
//reverse linked list，最后返回的是pre，把pre设置为null