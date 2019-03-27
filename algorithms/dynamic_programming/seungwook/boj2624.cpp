#include <iostream>
#include <algorithm>

using namespace std;

struct coin{
    int value;
    int amount;
    bool operator < (const coin& c) const {
        return value < c.value;
    }
};

int main(){
    
    int T, K;
    cin >> T >> K ;
    coin coins[101];
    
    for(int i = 1 ; i <= K; i ++){
        cin >> coins[i].value >> coins[i].amount;
    }
    sort(coins + 1, coins + K + 1);
    int dp[101][10001] = {0,};
    dp[0][0] = 1;
    for(int i=1; i<=K; i ++){
        for(int k=0; k<=coins[i].amount; k++){
            for(int j=0; j<=T; j++){
                if(j+coins[i].value*k <= T)
                    dp[i][j+coins[i].value*k] += dp[i-1][j];
                else
                    break;
            }
        }
    }
    cout<< dp[K][T];
}
