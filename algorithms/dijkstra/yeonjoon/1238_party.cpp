#include <iostream>

using namespace std;

int main()
{
	int N, M, X; //N개의 마을, M개의 단 방향 도로, X에서 열리는 파티
	int **arr1, **arr2; //도시 간의 연결 관계
	int *dist_depart, *dist_arrive, * visit;

	cin >> N >> M >> X;

	arr1 = new int*[N + 1];
	arr2 = new int*[N + 1];
	for (int i = 0; i <= N; i++) {
		arr1[i] = new int[N + 1];
		arr2[i] = new int[N + 1];
		for (int j = 0; j <= N; j++) {
			arr1[i][j] = 99999;
			arr2[i][j] = 99999;
		}
	}
	
	dist_depart = new int[N + 1];
	dist_arrive = new int[N + 1];
	visit = new int[N + 1];
	for (int i = 1; i <= N; i++) {
		dist_depart[i] = 99999;
		dist_arrive[i] = 99999;
		visit[i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr1[from][to] = cost;
		arr2[to][from] = cost;
	}

	dist_depart[X] = 0; 

	for (int i = 1; i <= N; i++) {
		int min = 99999;
		int nearest = 0;
		for (int j = 1; j <= N; j++) {
			if (visit[j] == 0 && min > dist_depart[j]) {
				min = dist_depart[j];
				nearest = j;
			}
		}
		
		visit[nearest] = 1;

		for (int j = 1; j <= N; j++) {
			if (dist_depart[j] > (dist_depart[nearest] + arr1[nearest][j])) {
				dist_depart[j] = dist_depart[nearest] + arr1[nearest][j];
			}
		}

	}

	
	dist_arrive[X] = 0;

	for (int i = 1; i <= N; i++) {
		int min = 99999;
		int nearest = 0;
		for (int j = 1; j <= N; j++) {
			if (visit[j] == 1 && min > dist_arrive[j]) {
				min = dist_arrive[j];
				nearest = j;
			}
		}

		visit[nearest] = 2;

		for (int j = 1; j <= N; j++) {
			if (dist_arrive[j] > (dist_arrive[nearest] + arr2[nearest][j])) {
				dist_arrive[j] = dist_arrive[nearest] + arr2[nearest][j];
			}
		}
	}

	int max = 0;
	int farthest = 0;
	for (int i = 1; i <= N; i++) {
		if (max < (dist_depart[i] + dist_arrive[i])) {
			max = dist_depart[i] + dist_arrive[i];
			farthest = i;
		}
	}

	delete[] arr1;
	delete[] arr2;

	delete[] dist_depart;
	delete[] dist_arrive;
	delete[] visit;
	

	cout << max;

	return 0;

}

