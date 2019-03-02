#include <cstdio>
#include <iostream>

int main()
{
	int N, C, round;

	scanf("%d %d", &N, &C);
	int color[C];
	int dwarves[N];
	for(int i=0; i<N; i++){scanf("%d", &dwarves[i]);}
	scanf("%d", &round);
	for(int i=0; i<round; i++){
		int start, end, answer=1, k=0;
		scanf("%d %d", &start, &end);
		std::fill_n(color, C, 0);
		for(int j=start-1;j<end;j++){
			k=color[dwarves[j]-1]++;
			if(k>=((end-start+1)/2)){
				printf("yes %d\n", dwarves[j]);
				answer--;
				break;
			}
		}
		if(answer){printf("no\n");}
	}
}
