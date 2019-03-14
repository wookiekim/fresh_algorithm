#include <iostream>
#include <algorithm>

using namespace std;

int p[50003], e[50003];
bool u[50003] = {true,};

int main(){

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> e[i];
        p[e[i]] = i;
    }

    for(int i=1; i<=n; i++){
        if(u[e[i]] || u[e[p[e[i]-1]]])u[e[i]] = true;
        else{
            u[e[i]] = u[e[p[e[i]-1]]] = true;
            swap(e[i], e[p[e[i]-1]]);
        }

        cout << e[i] <<' ';
    }

}
