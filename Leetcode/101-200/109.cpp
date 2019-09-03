/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
    	for (ListNode *p = head; p ; p = p->next){
    		v.push_back(p->val);
    	}

    	return buildBST(v, 0, v.size()-1);

    }
    
    TreeNode *buildBST(vector <int> &array, int left, int right){
    	if (left > right)	return NULL;
    	int mid = (left+right)/2;
    	TreeNode * root = new TreeNode(array[mid]);
    	root->left = buildBST(array, left, mid-1);
    	root->right = buildBST(array, mid+1, right);
    	return root;
    }
};

//给定一个有序的链表，简历BST；先把链表转化成有序数组