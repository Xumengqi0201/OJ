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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if (pListHead == NULL || k == 0)	return NULL;
    	ListNode *p, *q;
    	p = q = pListHead;
    	//双指针，先让一个指针走k-1步停止再和另外一个指针一起走，p走到tail节点的时候，q就在倒数第k个节点
    	
    	for (int i = 1; i < k ; i++){
    		//0节点不算
    		if (p->next)	p = p->next;
    		else  return NULL;
    	}
    	while (p->next){
    		p = p->next;
    		q = q->next;
    	}
    	return q;
    }
};