#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

int N;
int arr[102][102];
bool visit[102][102];
typedef pair<int, int> pii;
queue<pii> q;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
int ans = 1e9;

void number(int ypos, int xpos, int num) {
	visit[ypos][xpos] = true;
	q.push({ ypos,xpos });
	arr[ypos][xpos] = num;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		int ny, nx;
		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny <= 0 || ny > N || nx <= 0 || nx > N)
				continue;
			if (arr[ny][nx] == 1 && visit[ny][nx] == false) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
				arr[ny][nx] = num;
			}
		}
	}
}

void show() {
	printf("Show arr\n");
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

void find(int pos) {
	int aa = 0;
	//printf("%d\n", pos);

	while (!q.empty()) {
		int size = q.size();
		aa++;
		//printf("\n\n%d\n\n", size);
		int ny, nx;
		for (int s = 0; s < size; s++) {
			pii now = q.front();
			q.pop();
			//printf("{%d %d} => ", now.first, now.second);

			if (arr[now.first][now.second] != 0 && arr[now.first][now.second] != pos) {
				//printf("{%d %d}, %d \n", now.first, now.second,aa);
				ans = min(ans, aa);
				break;
				
			}

			for (int i = 0; i < 4; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > N || nx <= 0 || nx > N)
					continue;
				if (arr[ny][nx] != pos && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
		}
	}
}
int main() {
	scanf("%d", &N);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int cnt = 1;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j] == 1 && visit[i][j] == false) {
				number(i, j, cnt++);
			}
		}
	}
	//show();
	
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
		find(k);
		memset(visit, false, sizeof(visit));
		while (!q.empty())
			q.pop();
	}

	printf("%d\n", ans-2);


	return 0;
}