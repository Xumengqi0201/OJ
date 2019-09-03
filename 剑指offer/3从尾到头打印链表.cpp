/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector <int> ans;
        for (ListNode *p = head; p; p = p->next){
        	ans.push_back(p->val);
        }
        for (int i = 0, j = ans.size()-1; i < j; i++, j--){
        	int tmp = ans[i];
        	ans[i] = ans[j];
        	ans[j] = tmp;
        }
        return ans;
    }
};
/*
	要求：输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
	最简单的方法当然是遍历链表，依次插入，最后再把vector逆转,复杂度：O(n)
	
*/