#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>	
#include<string.h>

using namespace std;
typedef pair<int, int> pii;
int N, M;
int arr[52][52];
int visit[52][52];
vector <pii> v;
bool virus[12];
queue<pii> q;
int ans = 1e9;
int blank = 0;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

void show() {
	printf("\n\nShow visit\n");
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (visit[i][j] == -1)
				printf("  -");
			else
				printf("%3d", visit[i][j]);
		}
		printf("\n");
	}

}

void find_ans() {
	int tmp = 0;

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j] == 0 && visit[i][j] == -1)
				return;
			else if (arr[i][j] != 2)
				tmp = max(tmp, visit[i][j]);
		}
	}
	ans = min(tmp, ans);
	//show();
}
void spread() {
	for (int i = 0; i < v.size(); i++) {
		if (virus[i] == true) {
			q.push({ v.at(i).first, v.at(i).second });
			visit[v.at(i).first][v.at(i).second] = 0;
		}
	}

	int ny, nx;
	while (!q.empty()) {

		pii now = q.front();
		q.pop();
		//printf("{%d %d} ->", now.first, now.second);


		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny <= 0 || ny > N || nx <= 0 || nx > N)
				continue;

			if (arr[ny][nx] != 1 && visit[ny][nx] == -1){
				q.push({ ny,nx });
				visit[ny][nx] = visit[now.first][now.second] + 1;
			}
		}
	}

	find_ans();
}

void dfs(int pos, int cnt) {
	virus[pos] = true;

	if (cnt == M) {

		memset(visit, -1, sizeof(visit));
		spread();
		virus[pos] = false;
		return;

	}
	for (int i = 1; i < v.size(); i++) {
		int next = pos + i;
		if (next+1 > v.size())
			break;
		else {
			dfs(next, cnt + 1);
		}
	}
	virus[pos] = false;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) {
				v.push_back({ i,j });
			}
			if (arr[i][j] == 0)
				blank++;
		}
	}

	if (v.size() < M)
		M = v.size();

	for (int i = 0; i < v.size() - M + 1; i++) {
		//printf("dfs %d", i);
		dfs(i, 1);
	}

	if (ans == 1e9)
		printf("-1\n");
	else
		printf("%d", ans);

	return 0;
}