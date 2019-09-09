class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (popV.size() == 0 || pushV.size() != popV.size())	return false;
        stack <int> s;
        for (int i = 0, j = 0; i < pushV.size(); ){
        	s.push(pushV[i++]);
        	while (j < popV.size() && s.top() == popV[j]){
        		s.pop();
        		j++;
        	}
        }
        return s.empty();
    }
};
/*
	给定栈的压入顺序（不一定是连续压入） 判定给的第二个序列是否可能为栈的弹出顺序
	开始题目没看懂
	直接用一个栈模拟压栈弹出就行了
	




*/