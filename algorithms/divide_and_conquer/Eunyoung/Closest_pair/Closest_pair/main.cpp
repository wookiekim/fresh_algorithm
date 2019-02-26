#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

using namespace std;

struct Point {
	int x, y;
};

int dist(Point &p, Point &q) {
	return (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y);
}

bool compX(Point a, Point b) {
	if (a.x < b.x) {
		return true;
	}
	else if (a.x == b.x) {
		return a.y < b.y;
	}
	else {
		return false;
	}
}
bool compY(Point a, Point b) {
	if (a.y < b.y) {
		return true;
	}
	else if (a.y == b.y) {
		return a.x < b.x;
	}
	else {
		return false;
	}
}

int closest_pair(vector<Point>::iterator it, int n) {
	if (n == 2) 
		return dist(it[0], it[1]);
	else if (n == 3) 
		return min({ dist(it[0], it[1]), dist(it[0], it[2]), dist(it[1], it[2]) });
	else {
		int line = (it[n / 2 - 1].x + it[n / 2].x) / 2;
		int result = min(closest_pair(it, n / 2), closest_pair(it + n / 2, n - n / 2));

		vector<Point> temp;
		temp.reserve(n);
		
		for (int i = 0; i < n; i++) {
			int gap = it[i].x - line;
			if (gap*gap < result) {
				temp.push_back(it[i]);
			}
		}

		sort(temp.begin(), temp.end(), compY);

		int m = temp.size();

		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m && temp[j].y - temp[i].y < result; j++) {
				result = min(result, dist(temp[i], temp[j]));
			}
		}
		return result;
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<Point> points(n);
	for (auto it = points.begin(); it != points.end(); it++)
		cin >> it->x >> it->y;

	sort(points.begin(), points.end(), compX);

	cout << closest_pair(points.begin(), n);
	
	system("PAUSE");
	return 0;
}