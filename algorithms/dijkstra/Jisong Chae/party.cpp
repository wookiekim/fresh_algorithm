#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

#define INF 1000000
#define MAX 1001

int dist[MAX];
int dist2[MAX];

int main(){
	int N, M, X;
	scanf("%d %d %d", &N, &M, &X);//students num, road num, destination

	std::vector<std::pair<int, int> > v[N+1];//connection

	for(int i=0; i<M; i++){//upload vector v
		int start, end, time;
		scanf("%d %d %d", &start, &end, &time);
		v[start].push_back(std::make_pair(end, time));
	}

	std::fill(dist+1, dist+N+1, INF);
	std::priority_queue<std::pair<int, int> > pq;//find shortest way
	pq.push(std::make_pair(0, X));
	dist[X] = 0;

	while(!pq.empty()){//destination->every students
		int index = pq.top().second;
		int cost = -pq.top().first;//make small num to big num because of priority
		pq.pop();
		if(cost > dist[index]) continue;//예외처리..?
		for( int i=0; i<v[index].size(); i++){
			int n_index = v[index][i].first;
			int n_dist = cost+v[index][i].second;
			if(n_dist<dist[n_index]){
				dist[n_index] = n_dist;
				pq.push(std::make_pair(-n_dist, n_index));
			}
		}
	}

	for(int i=1; i<=N; i++){//every students->destination
		if(i==X) continue; //할필요 없음!
		int start = i;
		std::fill(dist2+1, dist2+N+1, INF);//init
		dist2[start] = 0;
		pq.push(std::make_pair(0, start));
		while(!pq.empty()){
			int index = pq.top().second;
			int cost = -pq.top().first;//make small num to big num because of priority
          	pq.pop();
          	if(cost > dist2[index]) continue;//예외처리
          	for( int i=0; i<v[index].size(); i++){
				int n_index = v[index][i].first;
              	int n_dist = cost+v[index][i].second;
              	if(n_dist<dist2[n_index]){
					dist2[n_index] = n_dist;
					pq.push(std::make_pair(-n_dist, n_index));
				}
			}
		}
		dist[start] += dist2[X];
	}
	int answer = 0;
	for(int i=1; i<=N; i++){
		if(dist[i] > answer) answer = dist[i];
	}
	printf("%d\n", answer);
	
	return 0;
}
