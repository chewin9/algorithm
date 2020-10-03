#include <iostream>
#include <deque>
using namespace std;
int n, result;
int peopleCnt;
int exitCnt;//점심먹으러 간사람
int map[11][11];
deque <int> d0;//계단 안에 있는 사람들
deque <int> d1;
struct Position {
	int x;
	int y;
};
Position people[11];//사람 위치 좌표
Position stair[2];//계단 위치 좌표
int dist[11][2];//사람과 계단 사이거리(시간)
int selectStair[11];//사람마다 배정된 계단
int stairSize[2];
int abs(int x) {
	return x >= 0 ? x : -x;
}
void downStair() {
	int time = 0;
	while (1) {
		time++;//타임++
		for (int i = 0; i < peopleCnt; i++) {
			if (dist[i][selectStair[i]] - time == 0) {//계단 내려가기시작
				if (selectStair[i] == 0)//0번계단
					d0.push_back(stairSize[0]);
				else//1번계단
					d1.push_back(stairSize[1]);
			}
		}

		//계단 내려가자~~~~
		int temp0[3] = { 0, };//계단 안에 있는 사람들
		int temp1[3] = { 0, };//계산하기위해 잠시 씀
		for (int i = 0; i < 3; i++) {
			if (d0.size() > 0) {//데큐에서 빼서 계단 내려가는 중표시
				temp0[i] = d0.front();
				d0.pop_front();
				temp0[i]--;
				if (temp0[i] == 0) exitCnt++;
			}
			if (d1.size() > 0) {
				temp1[i] = d1.front();
				d1.pop_front();
				temp1[i]--;
				if (temp1[i] == 0)exitCnt++;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (temp0[i] > 0) {//0이아니면 계단을 다 내려온 것이 아니므로 다시 집어논다
				d0.push_front(temp0[i]);
			}
			if (temp1[i] > 0) {
				d1.push_front(temp1[i]);
			}
		}
		if (exitCnt == peopleCnt) {//모두 빠져나오면 return
			result = result < time ? result : time;
			break;
		}
	}
}
void dfs(int p, int cnt) {//사람들 어디 계단으로 갈지 배치
	if (cnt == peopleCnt) {
		//계단 위치 배정 끝났으므로 내려보내주자~~
		exitCnt = 0;
		downStair();
		return;
	}
	for (int i = p; i < peopleCnt; i++) {
		for (int j = 0; j < 2; j++) {
			selectStair[i] = j;
			dfs(i + 1, cnt + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		//start
		cin >> n;
		peopleCnt = 0;
		int stairCnt = 0;
		result = 2e9;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {//사람일때 좌표
					people[peopleCnt].x = i;
					people[peopleCnt].y = j;
					peopleCnt++;
				}
				else if (map[i][j] > 1) {//계단일때 좌표
					stair[stairCnt].x = i;
					stair[stairCnt].y = j;
					stairSize[stairCnt] = map[i][j];
					stairCnt++;
				}
			}
		}
		//모든 사람과 계단 사이거리를 미리 구해서 시간 단축
		for (int i = 0; i < peopleCnt; i++) {
			for (int j = 0; j < 2; j++) {
				dist[i][j] = abs(people[i].x - stair[j].x)
					+ abs(people[i].y - stair[j].y) + 1;
			}
		}
		dfs(0, 0);
		//end
		cout << '#' << t << ' ' << result + 1 << '\n';
	}
}