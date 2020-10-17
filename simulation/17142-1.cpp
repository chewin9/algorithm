#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int, int>pii;
vector<pii> virus;
queue<pii> q;
int N, M;
int arr[52][52];
int visit[52][52];
bool choose[10];
int ans = 1e9;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

void show() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("%3d", visit[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void find_ans() {
	int tmp = 0;

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j] == 0 && visit[i][j] == -1)
				return;
			else if(arr[i][j] !=2){
				tmp = max(visit[i][j], tmp);
			}
		}
	}
	ans = min(ans, tmp);
}

void spread() {
	memset(visit, -1, sizeof(visit));

	for (int i = 0; i < virus.size(); i++) {
		if (choose[i] == true) {
			visit[virus.at(i).first][virus.at(i).second] = 0;
			q.push({ virus.at(i).first,virus.at(i).second });
		}
	}

	int ny, nx;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];
			if (ny <= 0 || ny > N || nx <= 0 || nx > N)
				continue;

			if (arr[ny][nx] != 1 && visit[ny][nx] == -1) {
				q.push({ ny,nx });
				visit[ny][nx] = visit[now.first][now.second] + 1;
			}
		}
	}
}

void dfs(int pos, int cnt) {
	choose[pos] = true;

	if (cnt == M) {
		/*printf("\n");
		for (int i = 0; i < virus.size(); i++) {
			printf("%2d", choose[i]);
		}*/

		spread();
		//show();
		find_ans();
		choose[pos] = false;
		return;
	}
	for (int i = pos + 1; i < virus.size(); i++) {
		if (choose[i] == false) {
			dfs(i, cnt + 1);
		}
	}
	choose[pos] = false;
}
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
			}

		}
	}
	for (int i = 0; i < virus.size() - M+1; i++) {
		dfs(i, 1);
	}

	if (ans == 1e9)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}