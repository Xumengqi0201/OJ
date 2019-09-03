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
    bool hasCycle(ListNode *head) {
    	if (head == NULL || head->next == NULL)	return false;
    	ListNode * slow = head;
    	ListNode * fast = head->next;
    	while(slow != fast){
    		if (fast == NULL || fast->next ==  NULL){
    			return false;
    		}
    		slow = slow->next;
    		fast = fast->next->next;
    	}
        return true;
    }
};

/*
快慢双指针法判断链表中有没有环，注意，慢指针和快指针一定会相遇如果存在环的话
因为，他们之间的距离最后总会到达差一步的情况，因为一个一次走一步，一个一次走两步
最后一个一步一个两步，相遇了
*/