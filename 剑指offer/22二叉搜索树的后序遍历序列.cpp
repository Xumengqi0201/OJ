class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0)    return false;
        return isBST(sequence, 0, sequence.size()-1);
    }
    bool isBST(vector <int> & sequence, int start, int end){
        if (start > end)    return true;
        int root = sequence[end];
        int pivot= start; //寻找分界点，右子树开始的地方
        for (; sequence[pivot] < root; pivot++);
        //这种寻找分界点的方法保证了左子树中每一个元素都比根元素小
        for (int i = pivot; i <= end; i++){//右子树中每一个元素都应该比根大
            if (sequence[i] < root)    return false;
        }
        return isBST(sequence, start, pivot-1) && isBST(sequence, pivot,end-1);
    }
};
/*
	给定一个数组判定它是不是某一个BST后序遍历的结构

*/