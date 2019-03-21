#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define MAX 10001
#define INF 0x7fffffff/2//infinite

//std::vector<std::pair<int ,int> > v[MAX];//computer number, second
int visit[MAX];//누적시간->최대값이 최종 정답.

int main(){
	int round;
	scanf("%d", &round);

	for(int i=0; i<round; i++){
		int n, d, c;
		std::fill(visit, visit+MAX, INF);
		scanf("%d %d %d", &n, &d, &c);
		std::vector<std::pair<int ,int> > v[n+1];	
		
		for(int j=0; j<d; j++){//의존하는 case 모두 vector에 집어넣기.
			int a, b, s;
			scanf("%d %d %d", &a, &b, &s);
			v[b].push_back(std::make_pair(a,s));
		}
		
		std::queue<std::pair<int, int> > q;//서로 연결되어 있는 vertex 모두 bfs로 확인.
		q.push(std::make_pair(c, 0));//처음 감염된 computer
		visit[c] = 0;

		while(!q.empty()){
			int com_i = q.front().first;
			int com_sec = q.front().second;
			q.pop();

			for(size_t k=0; k<v[com_i].size(); k++){//pop한 com와 의존하고 있는 모든 com
				int n_i = v[com_i][k].first;
				int n_sec = v[com_i][k].second;
				
				if(visit[n_i] > n_sec + com_sec){//시간이 더 단축해서 도착했으면 갱신.
					visit[n_i] = n_sec+com_sec;
					q.push(std::make_pair(n_i, visit[n_i]));//새롭게 시간 단축한 com 주변 확인.
				}
			}
		}
		//최종 답 찾기.
		int num = 0;
		int t = 0;
		for(int j=1; j<=n; j++){
			if(visit[j] != INF){//왜 안됨??
				num++;
				if(t<visit[i]) t=visit[i];
			}
		}
		printf("%d %d\n", num, t);
	}
	return 0;
}
