#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;

void bfs(int start, vector<int> graph[], bool check[]){
	queue<int> q;
	int num, answer=0;

	q.push(start);
	check[start]=true;

	num = 1+graph[start].size();

	for(int j=0; j<num; j++){//1번 : 상근이의 친구, graph[tmp].size() : 친구의 친구
		int tmp = q.front();
		q.pop();
		for(int i=0; i<graph[tmp].size();i++){
			if(check[graph[tmp][i]] == false){
				q.push(graph[tmp][i]);
				answer++;
				check[graph[tmp][i]] = true;
			}
		}
	}
	printf("%d", answer);
}




int main(){
	int n, m;
	cin >>n>>m;
	
	vector<int> graph[n+1];
	bool check[n+1];
	fill(check, check+n+1, false);

	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i=1;i<=n;i++)
		sort(graph[i].begin(), graph[i].end());//역할을 모르겠다..

	bfs(1,graph,check);

	return 0;
}
