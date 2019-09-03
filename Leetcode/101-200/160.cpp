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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        while(pa != pb){
        	pa == NULL ? pa = headB : pa = pa->next;
        	pb == NULL ? pb = headA : pb = pb->next;
        }
        return pa;
    }
};
/*
	不太懂这个双指针法，一定会在公共节点开始的地方相遇？？？
	Hash方法比较好懂，适合我这种蠢人
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       unordered_map < ListNode*, bool> Hash;
       for (ListNode *pa = headA; pa ; pa = pa->next){
       		Hash[pa] = true;
       }
       for (ListNode *pb = headB; pb; pb = pb->next){
       		if (Hash[pb] == true)	return pb;
       }
       return NULL;
    }
};