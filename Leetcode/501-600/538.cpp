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
    TreeNode* convertBST(TreeNode* root) {
        vector <int> v;
        inorder(root, v);
        for (int i = v.size()-2; i >= 0; i--){
        	v[i] = v[i]+v[i+1];
        }
        rebuild (root, v);
        return root;
    }
    void inorder(TreeNode *root, vector <int> &v){
    	if (root){
    		inorder(root->left, v);
    		v.push_back(root->val);
    		inorder(root->right, v);
    	}
    }
    void rebuild(TreeNode *root, vector <int> &v){
    	if (root){
    		rebuild (root->left, v);
    		root->val = v[0];
    		v.erase(v.begin());
    		rebuild(root->right, v);

    	}
    }
};
/*
	我自己最开始的方法是ac了，但是很慢
	思路：1.中序遍历把结果放到vector中
		  2.从后往前按要求改变节点的值，把右边的数都加到当前的数
		  3.再中序遍历改变对应位置上的值

	后来看solution改进了一下,第一种写的是个啥
	递归就是学不会，唉
	
	思路：看注释
*/
class Solution {
private:
	int sum = 0; //记录一个节点的右子树节点值之和
public:
    TreeNode* convertBST(TreeNode* root) {
       if(root){
       		//不停的向右子树上递归
       		convertBST(root->right);
       		//递归结束的时候，修改sum
       		sum += root->val;
       		//返回上一层的时候sum已经把右子树的所有节点值加上了
       		root->val = sum;
       		convertBST(root->left);
       }
       return root;
    }

};
//来一个非递归版本的，思路一样,faster
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
       TreeNode *p = root;
       stack <TreeNode*> s;
       int sum = 0;
       while(!s.empty() || p){
          while (p){
            s.push(p);
            p = p->right;
          }

          p = s.top();
          sum += p->val;
          p->val = sum;
          s.pop();
          p = p->left;
       }
       return root;
    }

};