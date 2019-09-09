class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
    	//题目认为sequence为空就不是遍历结果了，好吧，那应该强调一下树不是空的，否则我认为是不对的
    	if (sequence.size() == 0)	return false;
    	return isPostorder(sequence, 0, sequence.size()-1);
    }
    bool isPostorder(vector <int> & sequence, int left, int right){
    	if (left > right)	return true;

    	int root = sequence[right];
    	int i = left;
    	while (i < right){
    		if (sequence[i] > root){
    			break;
    		}
    		i++;
    	}
    	int tmp = i;
    	while (i < right){
    		if (sequence[i] < root){
    			return false;
    		}
    		i++;
    	}
    	return isPostorder(sequence,left, tmp-1) && isPostorder(sequence,tmp,right-1);


    }
};
/*
	给定一个数组判定它是不是某一个BST后序遍历的结构

*/