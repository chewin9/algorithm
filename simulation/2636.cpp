#include<algorithm>
#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

typedef pair<int, int> pii;
queue<pii> q;

int N, M;
int arr[102][102];
bool visit[102][102];
int day = 0;
int ans = 0;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

void show() {
	printf("Show Arr \n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Show visit \n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%2d", visit[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool check_chease() {
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1)
				tmp++;
		}
	}
	if (tmp == 0)
		return false;
	else {
		ans = tmp;
		return true;
	}
}

void get_time() {
	day++;
	memset(visit, false, sizeof(visit));
	
	int ny, nx;

	q.push({0,0 });
	visit[0][0] = true;


	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (arr[ny][nx] == 0 && visit[ny][nx] == false) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1)
				q.push({ i,j });
		}
	}
	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (visit[ny][nx] == true) {
				arr[now.first][now.second] = 0;
				break;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	while (1) {
		
		if (check_chease() == false) {
			break;
		}
		get_time();
		//show();
	}
	printf("%d\n%d\n", day, ans);
	return 0;
}