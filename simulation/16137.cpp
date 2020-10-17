#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

int N, M;
int ori_arr[12][12];
int arr[12][12];
typedef pair<int, int> pii;
vector<pii> v;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
int visit[12][12];
int ans = 1e9;
queue<pii> q;

void get_cliff() {
	int ny, nx;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) {
				int tmp = 0;;
				for (int k = 0; k < 4; k++) {
					ny = i + dy[k];
					nx = j + dx[k];
					if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
						tmp = 0;
						continue;
					}

					if (arr[ny][nx] == 0) {
						tmp++;
					}
					else
						tmp = 0;
					
					if (tmp == 2)
						break;

				}
				if (tmp == 0 || tmp == 1)
					v.push_back({ i,j });
			}
		}
	}
}

void show() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%3d", visit[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void bfs(int pos) {
	int t_ypos;
	int t_xpos;
	t_ypos = v.at(pos).first;
	t_xpos = v.at(pos).second;

	memset(visit, -1, sizeof(visit));

	q.push({ 0,0 });
	visit[0][0] = 0;

	int ny, nx;
	bool check;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		//printf("{%d %d}, %d->   ", now.first, now.second, visit[now.first][now.second]);

		check = true;
		if (arr[now.first][now.second] != 1)
			check = false;

		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			if (arr[ny][nx] != 0) {
				if (arr[ny][nx] == 1) {
					if (visit[ny][nx] == -1) {
						q.push({ ny,nx });
						visit[ny][nx] = visit[now.first][now.second] + 1;
					}
					else if (visit[ny][nx] > visit[now.first][now.second] + 1) {
						q.push({ ny,nx });
						visit[ny][nx] = visit[now.first][now.second] + 1;
					}
				}
				else if (arr[ny][nx] != -1 && check == true) {
					int tmp = visit[now.first][now.second];
					if (tmp % arr[ny][nx] == 0)
						tmp = tmp + arr[ny][nx];
					else
						tmp = tmp + (arr[ny][nx] - tmp % arr[ny][nx]);

					if (visit[ny][nx] == -1) {
						q.push({ ny,nx });
						visit[ny][nx] = tmp;
					}

					/*q.push({ ny,nx });
					visit[ny][nx] = tmp;*/
				}
			}
		}
	}
	/*printf("TIME = %d\n", pos);
	show();*/
	if(visit[N-1][N-1] != -1)
		ans = min(ans, visit[N - 1][N - 1]);

}

int main() {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	get_cliff();

	/*for (int i = 0; i < v.size(); i++) {
		printf("{%d %d} ->", v.at(i).first, v.at(i).second);
	}
	printf("\n");*/

	for (int i = 0; i < v.size(); i++) {
		arr[v.at(i).first][v.at(i).second] = M;
		bfs(i);
		arr[v.at(i).first][v.at(i).second] = 0;
	}
	printf("%d\n", ans);
	return 0;
}