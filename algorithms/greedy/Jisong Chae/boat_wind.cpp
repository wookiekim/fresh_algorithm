#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

int main(){
	int N, S, R;

	scanf("%d %d %d", &N, &S, &R);
	int arr[N+1];
	for(int i=0; i<=N; i++)
		arr[i] = 0;
	std::vector<int> more_boat;

	for(int i=0; i<S; i++){//손상된 카약
		int index;
		scanf("%d",&index);
		arr[index] = -1;
	}

	for(int i=0; i<R; i++){//여분이 있는 팀
		int index;
		scanf("%d", &index);
		more_boat.push_back(index);
		if(arr[index]==-1){S--;}
		arr[index]++;
	}

	std::sort(more_boat.begin(), more_boat.end());
	
	for(std::vector<int>::size_type i=0; i<more_boat.size(); i++){
		int index = more_boat[i];
		if(arr[index]==1){
			if(index!=1 && arr[index-1]==-1){
				arr[index-1] = 0;
				S--;
				continue;
			}
			if(index!=N && arr[index+1]==-1){
				arr[index+1] = 0;
				S--;
				continue;
			}
		}
	}
	printf("%d\n", S);
	return 0;
}

