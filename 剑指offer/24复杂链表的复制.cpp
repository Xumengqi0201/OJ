/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
       if (pHead == NULL)	return NULL;
       unordered_map <RandomListNode*, RandomListNode*> m;
       for (RandomListNode *p = pHead; p; p = p->next){
       	   m[p] = new RandomListNode(p->label);
       }
       for (RandomListNode *p = pHead; p; p = p->next){
       		m[p]->next = m[p->next];
       		m[p]->random = m[p->random];
       }
       return m[pHead];  

    }
};
/*
	输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
	返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
	
	哈希表法
	建立一个hash表实现原链表和复制后的链表的一一对应
	再设置新链表的next和random

*/