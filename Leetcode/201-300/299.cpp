class Solution {
public:
    string getHint(string secret, string guess) {
        string res = "";
        int bulls = 0, cows = 0;
        int table[10] = {0};
        for (int i = 0; i < secret.size(); i++){
        	if (secret[i] == guess[i]){
        		bulls++;
        	}
        	else{
        		table[secret[i]-'0'] ++;
        	}
        }
        for (int i = 0; i < guess.size(); i++){
        	if (guess[i] != secret[i] && table[guess[i]-'0'] > 0){
        		cows++;
        		table[guess[i]-'0']--;
        	}
        }
        
        res = to_string(bulls)+ "A"+to_string(cows)+"B";
        return res;

    }
};

//not easy