#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> party[54],truth,people[54];
queue<int> q;
int check[54];
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<k;i++){
        int x;
        scanf("%d",&x);
        truth.push_back(x);
    }
    for(int i=0;i<m;i++){
        int hm;
        scanf("%d",&hm);
        for(int j=0;j<hm;j++){
            scanf("%d",&k);
            party[i].push_back(k);
            people[k].push_back(i);
        }
    }
    for(int i=0;i<truth.size();i++){
        for(int j=0;j<people[truth[i]].size();j++){
            if(!check[people[truth[i]][j]]){
                q.push(people[truth[i]][j]);
                check[people[truth[i]][j]]=1;
            }
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<party[x].size();i++){
            for(int j=0;j<people[party[x][i]].size();j++){
                if(!check[people[party[x][i]][j]]){
                    check[people[party[x][i]][j]]=1;
                    q.push(people[party[x][i]][j]);
                }
            }
        }
    }
    int cnt=0;
    for(int i=0;i<m;i++)
        cnt+=!check[i];
    printf("%d",cnt);
    return 0;
}
