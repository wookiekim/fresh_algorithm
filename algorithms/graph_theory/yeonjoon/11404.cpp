#include <iostream>

using namespace std;

int main()
{
	int n, m;

	cin >> n; // 도시 개수
	cin >> m; // 버스 개수

	int arr[101][101];

	//arr 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = 9999;
			}
		}
	}

	//버스 정보 입력
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		if (arr[from][to] > cost) {
			arr[from][to] = cost;
		}
	}

	//플로이드 와샬 알고리즘
	for (int k = 1; k <= n; k++) { // path에 node k가 포함되는 경우
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	//출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 9999) {
				arr[i][j] = 0;
			}
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;

}
