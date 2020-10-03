#include <iostream>
#include <deque>
using namespace std;
int n, result;
int peopleCnt;
int exitCnt;//���ɸ����� �����
int map[11][11];
deque <int> d0;//��� �ȿ� �ִ� �����
deque <int> d1;
struct Position {
	int x;
	int y;
};
Position people[11];//��� ��ġ ��ǥ
Position stair[2];//��� ��ġ ��ǥ
int dist[11][2];//����� ��� ���̰Ÿ�(�ð�)
int selectStair[11];//������� ������ ���
int stairSize[2];
int abs(int x) {
	return x >= 0 ? x : -x;
}
void downStair() {
	int time = 0;
	while (1) {
		time++;//Ÿ��++
		for (int i = 0; i < peopleCnt; i++) {
			if (dist[i][selectStair[i]] - time == 0) {//��� �����������
				if (selectStair[i] == 0)//0�����
					d0.push_back(stairSize[0]);
				else//1�����
					d1.push_back(stairSize[1]);
			}
		}

		//��� ��������~~~~
		int temp0[3] = { 0, };//��� �ȿ� �ִ� �����
		int temp1[3] = { 0, };//����ϱ����� ��� ��
		for (int i = 0; i < 3; i++) {
			if (d0.size() > 0) {//��ť���� ���� ��� �������� ��ǥ��
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
			if (temp0[i] > 0) {//0�̾ƴϸ� ����� �� ������ ���� �ƴϹǷ� �ٽ� ������
				d0.push_front(temp0[i]);
			}
			if (temp1[i] > 0) {
				d1.push_front(temp1[i]);
			}
		}
		if (exitCnt == peopleCnt) {//��� ���������� return
			result = result < time ? result : time;
			break;
		}
	}
}
void dfs(int p, int cnt) {//����� ��� ������� ���� ��ġ
	if (cnt == peopleCnt) {
		//��� ��ġ ���� �������Ƿ� ������������~~
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
				if (map[i][j] == 1) {//����϶� ��ǥ
					people[peopleCnt].x = i;
					people[peopleCnt].y = j;
					peopleCnt++;
				}
				else if (map[i][j] > 1) {//����϶� ��ǥ
					stair[stairCnt].x = i;
					stair[stairCnt].y = j;
					stairSize[stairCnt] = map[i][j];
					stairCnt++;
				}
			}
		}
		//��� ����� ��� ���̰Ÿ��� �̸� ���ؼ� �ð� ����
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