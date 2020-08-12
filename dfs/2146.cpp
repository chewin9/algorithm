#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int arr[102][102];
int ori_arr[102][102];
bool visit[102][102];
typedef pair<int, int> pii;
queue<pii> q;
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };
int ans = 1e9;
bool check = true;

void numbering(int ypos, int xpos, int val) {
	q.push({ ypos,xpos });
	visit[ypos][xpos] = true;
	arr[ypos][xpos] = val;
	int nx, ny;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny <= 0 || ny > N || nx <= 0 || nx > N)
				continue;
			if (arr[ny][nx] == 1 && visit[ny][nx] == false) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
				arr[ny][nx] = val;
			}
		}
	}
}

void show() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++)
			printf("%2d", arr[i][j]);
		printf("\n");
	}
}

void getAns(int val) {
	int cnt = 1;
	while (!q.empty() && check) {
		int q_size = q.size();
		cnt++;

		for (int t = 0; t < q_size; t++) {
			pii now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = now.first + dy[i];
				int nx = now.second + dx[i];

				if (ny <= 0 || ny > N || nx <= 0 || nx > N)
					continue;

				if (arr[ny][nx] == 0 && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
					arr[ny][nx] = val;
				}
				if (arr[ny][nx] != 0 && arr[ny][nx] != val) {
					ans = min(ans, cnt);
					check = false;
					break;
				}
			}
			if (check == false)
				break;
		}
	}
}
void getOri() {
	for (int i = 1; i < N + 1; i++) 
		for (int j = 1; j < N + 1; j++)
			ori_arr[i][j] = arr[i][j];
}
void getArr() {
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			arr[i][j] = ori_arr[i][j];
}
int main() {
	int cnt = 1;
	scanf("%d", &N);

	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			scanf("%d", &arr[i][j]);

	memset(visit, false, sizeof(visit));

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j] == 1 && visit[i][j] == false) {
				numbering(i, j, cnt++);
			}
		}
	}
	getOri();
	show();
	memset(visit, false, sizeof(visit));

	for (int k = 1; k < cnt; k++) {
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (arr[i][j] == k && visit[i][j] == false) {
					q.push({ i,j });
					visit[i][j] = true;
				}
			}
		}
		getAns(k);
		getArr();
	}

	printf("%d", ans);
	return 0;
}