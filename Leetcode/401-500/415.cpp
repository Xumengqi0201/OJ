class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
       	int l1 = num1.size(), l2 = num2.size();
       	while (l1 < l2){
       		num1 = "0" + num1;
       		l1++;
       	}
       	while (l2 < l1){
       		num2 = "0" + num2;
       		l2++;
       	}
       	string res = "";
       	for (int i = num1.size()-1; i >= 0; i--){
       		int digit = num2[i] - '0' + num1[i] - '0'+carry;
       		carry = digit/10;
       		res = to_string(digit % 10) + res;
       	}
       	if (carry == 1)		res = "1" + res;
       	return res;
    }
};