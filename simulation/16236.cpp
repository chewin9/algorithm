#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
int N;
int arr[22][22];
bool visit[22][22];
bool ate[22][22];
int Sy, Sx;
int Ss = 2;
int ans = 0;
int cnt = 0;
const int dy[] = { -1,0,0,1 };
const int dx[] = { 0,-1,1,0 };
typedef pair<int, int> pii;
vector<pii> same;
queue<pii> q;
bool check = false;
priority_queue< pii, vector<pii>, greater<pii> > pq;

void find(int start, int end) {
	for (int i = start; i < end; i++) {
		pii now = q.front();
		q.pop();
		if (arr[now.first][now.second] != 0 && arr[now.first][now.second] < Ss && ate[now.first][now.second] == false) {
			same.push_back({ now.first,now.second });
		}
	}
}
void bfs(int ypos, int xpos) {
	int ny, nx;
	
	visit[ypos][xpos] = true;

	for (int i = 0; i < 4; i++) {
		ny = ypos + dy[i];
		nx = xpos + dx[i];

		if (ny <= 0 || ny > N || nx <= 0 || nx > N)
			continue;
		if (arr[ny][nx] <= Ss && visit[ny][nx] == false) {
			q.push({ ny,nx });
			visit[ny][nx] = true;
		}
	}

	int count = 0;
	while (!q.empty()) {
		count++;
		int size = q.size();

		for (int s = 0; s < size; s++) {
			pii now = q.front();
			q.pop();

			if (arr[now.first][now.second] != 0 && arr[now.first][now.second] < Ss && ate[now.first][now.second] == false) {
				//printf("{%d %d}", now.first, now.second);
				//printf("%d:", Ss);
				same.push_back({ now.first, now.second });

				for (int i = s; i < size-1; i++) {
					now = q.front();
					q.pop();
					if (arr[now.first][now.second] != 0 && arr[now.first][now.second] < Ss && ate[now.first][now.second] == false) {
						same.push_back({ now.first,now.second });
					}
				}

				/*while (!q.empty()) {

					now = q.front();
					q.pop();
					if (arr[now.first][now.second] != 0 && arr[now.first][now.second] < Ss && ate[now.first][now.second] == false) {
						same.push_back({ now.first,now.second });
					}
				}*/
				sort(same.begin(), same.end());

				/*for (int i = 0; i < same.size(); i++) {
					printf(" {%d %d} ", same.at(i).first, same.at(i).second);
				}*/

				cnt++;
				ans += count;
				if (Ss == cnt) {
					Ss += 1;
					cnt = 0;
				}

				//printf("Final %d %d\n", same.at(0).first, same.at(0).second);
				ate[same.at(0).first][same.at(0).second] = true;
				arr[same.at(0).first][same.at(0).second] = 0;
				Sy = same.at(0).first;
				Sx = same.at(0).second;
				check = true;
				same.clear();
				return;
			}

			for (int i = 0; i < 4; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > N || nx <= 0 || nx > N)
					continue;
				if (arr[ny][nx] <= Ss && visit[ny][nx] == false) {
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
			if (arr[i][j] == 9) {
				Sy = i;
				Sx = j;
				arr[i][j] = 0;
			}
		}
	}
	while (1) {
		check = false;
		bfs(Sy, Sx);
		while (!q.empty())
			q.pop();
		memset(visit, false, sizeof(visit));
		if (check == false)
			break;
	}

	printf("%d\n", ans);

	return 0;
}