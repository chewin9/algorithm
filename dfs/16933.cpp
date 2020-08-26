#include<iostream>
#include<queue>

using namespace std;


int N, M, K;
int arr[1002][1002];
bool visit[1002][1002][12];
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;
queue<ppi> q;
bool sun = false;
int ans = -1;
void bfs(int ypos, int xpos, int bre, int cnt) {
	visit[ypos][xpos][bre] = true;
	q.push({ {ypos,xpos},{bre,cnt} });

	while (!q.empty()) {
		
		int size = q.size();
		sun = !sun;

		for (int s = 0; s < size; s++) {
			ppi now = q.front();
			q.pop();
			int ny, nx, now_bre, now_cnt;

			if (now.first.first == N && now.first.second == M) {
				ans = now.second.second;
				return;
			}

			for (int i = 0; i < 4; i++) {
				ny = now.first.first + dy[i];
				nx = now.first.second + dx[i];
				now_bre = now.second.first;
				now_cnt = now.second.second;

				if (ny <= 0 || ny > N || nx <= 0 || nx > M)
					continue;
				
				if (arr[ny][nx] == 0 && visit[ny][nx][now_bre] == false) {
					q.push({ {ny,nx},{now_bre, now_cnt + 1} }); 
					visit[ny][nx][now_bre] = true;
				}
				if (arr[ny][nx] == 1 && visit[ny][nx][now_bre-1] == false && now_bre != 0) {
					if (sun == true) {
						q.push({ {ny,nx}, {now_bre - 1, now_cnt + 1} });
						visit[ny][nx][now_bre - 1] = true;
					}
					else if (sun == false) {
						q.push({ {now.first.first, now.first.second},{now.second.first, now.second.second + 1} });
					}
				}
			}
		}
	}
}

int main() {

	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	bfs(1, 1, K, 1);

	if (ans != -1)
		printf("%d\n", ans);
	else
		printf("-1\n");

	return 0;
}