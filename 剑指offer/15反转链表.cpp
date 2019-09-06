/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
    	ListNode *pre, *now, *next;
    	pre = NULL, now = pHead, next = pHead->next;
    	while (now){
    		now->next = pre;
    		if (next == NULL) break;
    		pre = now;
    		now = next;
    		next = now->next;
    	}
    	return now;
    }
};
//