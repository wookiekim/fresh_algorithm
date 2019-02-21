/* 해싱을 사용해 set을 구현한 코드 */

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<string> hash;

    for(int i = 0; i < n; i++) {
        int command;
        string key;
        cin >> command >> key;

        if(command == 1) {
            hash.insert(key);
        } else if(command == 2) {
            hash.erase(key);
        } else {
            if(hash.count(key) == 1) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }

    return 0;
}
	
