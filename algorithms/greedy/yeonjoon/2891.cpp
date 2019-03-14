#include <iostream>

using namespace std;

int main()
{
	int N, S, R; // 팀의 수 N, 카약이 손상된 팀의 수 S, 카약을 더 가져온 팀의 수 R

	/* 팀의 상태를 나타내는 배열
	 * 이상 없음 0, 카약 손상 1, 카약 여분 2*/
	int team[12] = { 0, };
	int cnt = 0; // 출전 못하는 팀의 수

	cin >> N >> S >> R;

    //손상과 여분이 동시에 있는 팀도 고려..!!
    
	//카약이 손상된 팀 기록
	for (int i = 0; i < S; i++) {
		int tmp;
		cin >> tmp;
		team[tmp] -= 1;
	}

	//카약을 더 가져온 팀 기록
	for (int i = 0; i < R; i++) {
		int tmp;
		cin >> tmp;
		team[tmp] += 1;
	}

	for (int i = 0; i < N; i++) {
		if (team[i] == 1) {
			if (team[i - 1] == 2) {//앞 팀이 여분 카약 있음
				team[i - 1] = 0;
				team[i] = 0;
			}
			else if (team[i + 1] == 2) {//뒷 팀이 여분 카약 있음
				team[i + 1] = 0;
				team[i] = 0;
			}
			else {
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;

}
