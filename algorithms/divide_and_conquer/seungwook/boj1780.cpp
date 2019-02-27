#include <iostream>
 
using namespace std;
 
int output[3];  // -1 0 1
int arr[2187][2187];
 
void paper(int x, int y, int N){
    int first = arr[x][y];
    bool flag = true;
    
    for(int i = x; i < x + N; i++){
        for(int j = y; j < y + N; j++){
            if(arr[i][j] != first){
                flag = false;
                break;
            }
        }
    }
    
    if(flag) {
        output[first + 1]++;
    }
    else {
        for(int a = x; a < x + N; a += N/3 ){
            for(int b = y; b < y + N; b += N/3){
                paper(a, b, N/3);
            }
        }
    }
}
 
int main(){
    int N;
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    
    paper(0, 0, N);
    
    for(int i = 0; i < 3; i++){
        cout << output[i] << endl;
    }
    
    return 0;
}

