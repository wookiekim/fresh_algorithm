#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int ary[64][64];
int N;

string quad_tree(int x, int y, int s) {
	if (s > 1) {
		int mid = s / 2;
		string left_up = quad_tree(x, y, mid);
		string right_up = quad_tree(x, y + mid, mid);
		string left_down = quad_tree(x + mid, y, mid);
		string right_down = quad_tree(x + mid, y + mid, mid);
		string result;

		result = "(" + (left_up + right_up + left_down + right_down) + ")";

		if ((left_up.length()==1) && left_up == right_up && right_up == right_down && right_down == left_down && left_down == left_up) {
			result = left_up;
			return result;
		}
		else {
			return result;
		}
	}
	else {
		return to_string(ary[x][y]);
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &ary[i][j]);
		}
	}

		cout << quad_tree(0, 0, N) << "\n\n";
	return 0;
}