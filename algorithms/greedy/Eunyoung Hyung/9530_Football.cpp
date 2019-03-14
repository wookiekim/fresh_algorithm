#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

enum Result {
	Draw,
	Lose,
	Win
};

class Record {
public:
	int score;
	int receive;
	int gap;
	Result result;

	Record(int s, int r) {
		score = s;
		receive = r;
		gap = r - s;
		if (s == r) result = Draw;
		else if (s > r) result = Win;
		else result = Lose;
	}
	bool operator < (const Record &a) const {
		return (this->gap < a.gap);
	}
};


int main(void) {
	int n, g;
	vector<Record> draw;
	vector<Record> lose;

	int total = 0;
	scanf("%d %d", &n, &g);
	for (int i = 0; i < n; i++) {

		int s, r;
		scanf("%d %d", &s, &r);
		Record newRec = Record(s,r);
		switch (newRec.result)
		{
		case Draw:
			total += 1;
			draw.push_back(newRec);
			break;
		case Lose:
			lose.push_back(newRec);
			break;
		case Win:
			total += 3;
		default:
			break;
		}

	}

	int dsize = draw.size();
	for (int i = 0; i < dsize; i++) {
		if (g > 0) {
			g--;
			total += 2;
		}
		else break;
	}

	sort(lose.begin(), lose.end());
	int lsize = lose.size();
	for (int i = 0; i < lsize; i++) {
		int gap = lose[i].gap;
		int buy = gap + 1;
		if (g >= buy) {
			g -= buy;
			total += 3;
		}
		else if (g >= gap) {
			g -= gap;
			total += 1;
		}
		else break;
	}

	printf("%d\n", total);
	return 0;
}