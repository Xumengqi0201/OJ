/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* slow = pHead, *fast = pHead;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow){
                fast = pHead;
                while(fast != slow){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};