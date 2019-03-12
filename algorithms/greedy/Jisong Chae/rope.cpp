#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

int main(){
	int num;

	scanf("%d", &num);
	std::vector<int> ropes;
	for(int i=0; i<num; i++){
		int a;
		scanf("%d", &a);
		ropes.push_back(a);
	}
	std::sort(ropes.begin(), ropes.end());
	
	int answer = 0;
	for(std::vector<int>::iterator it = ropes.begin();it!=ropes.end(); it++){
		int temp = *it*num;
		if(temp>answer){answer = temp;}
		num--;
	}
	printf("%d\n",answer);

	return 0;
}
