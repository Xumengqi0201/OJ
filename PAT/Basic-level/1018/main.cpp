# include <iostream>
# include <string>
using namespace std;

struct Game {
	int win = 0;
	int tie = 0;
	int lose = 0;
	int win_gesture[3] = { 0,0,0 }; //分别对应'B','C','J',记录获胜手势的次数
	void count(char gest) {
		if (gest == 'B')
			win_gesture[0]++;
		else if (gest == 'C')
			win_gesture[1]++;
		else
			win_gesture[2]++;
	};

	char choose_gest() {
		int max_id = 0;
		for (int i = 1; i < 3; i++) {
			if (win_gesture[max_id] < win_gesture[i]) //次数相同的时候，按照字母顺序最小的解，
				//win_gesture[]已经保证了字母是按照从小到大排序。仅在字母序大的次数比字母序小的次数大时，才更新id。
				//即次数相同的时候不更新id，这样就保证了次数相同的情形下，字母序小的输出
				max_id = i;
		}
		if (max_id == 0)
			return 'B';
		else if (max_id == 1)
			return 'C';
		else
			return 'J';
	}
};


string rule(char gest_jia, char gest_yi) {
	string res;//if jia win yi,win=true;else win=false;
	if ((gest_jia == 'C' && gest_yi == 'J') || (gest_jia == 'J' && gest_yi == 'B') || (gest_jia == 'B' && gest_yi == 'C'))
		res = "win";
	else if ((gest_jia == 'J' && gest_yi == 'C') || (gest_jia == 'B' && gest_yi == 'J') || (gest_jia == 'C' && gest_yi == 'B'))
		res = "lose";
	else
		res = "tie";
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	char gest_jia, gest_yi;
	Game jia, yi;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> gest_jia >> gest_yi;
		if (rule(gest_jia, gest_yi) == "win") {
			jia.win++;
			jia.count(gest_jia);
			yi.lose++;
		}
		else if (rule(gest_jia, gest_yi) == "tie") {
			jia.tie++;
			yi.tie++;
		}
		else {
			jia.lose++;
			yi.win++;
			yi.count(gest_yi);
		}
	}

	cout << jia.win << ' ' << jia.tie << ' ' << jia.lose << endl;
	cout << yi.win << ' ' << yi.tie << ' ' << yi.lose << endl;
	cout << jia.choose_gest() << ' ' << yi.choose_gest();


	return 0;
}