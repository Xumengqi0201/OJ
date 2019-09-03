class Solution {
public:
    int compress(vector<char>& chars) {
    	const int size = chars.size();
    	int p = 0;
    	for (int i = 1; i <= size; i++){
    		int cnt = 1;
    		while (i < size && chars[i] == chars[i-1]){
    			i++;
    			cnt++;
    		}
    		chars[p++] = chars[i-1];
    		if (cnt == 1)	continue;
    		string str = to_string(cnt);
    		for (char ch : str){
    			chars[p++] = ch;
    		}
    	}
    	return p;
    }
};
/*
这个题一次做对还是不容易的，太多details
*/