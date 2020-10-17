#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, int> pli;
typedef pair<pli, pii> ppi;
typedef long long ll;

int N, M;
ll arr[102][102];
ll visit[102][102][2];

typedef struct my {
	bool operator()(const ppi &a, const ppi &b)const {
		return a.first.first > b.first.first;
	}
};
priority_queue<ppi, vector<ppi>, my> pq;	//{level, cnt}, {ypos,xpos}

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

void show() {
	printf("\nVISIT 1\n");
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			printf("%3lld", visit[i][j][1]);
		}
		printf("\n");
	}

	printf("\nVISIT 0\n");
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			printf("%3lld", visit[i][j][0]);
		}
		printf("\n");
	}
}
void solve() {
	visit[1][1][1] = arr[1][1];
	pq.push({ {visit[1][1][1],1},{1,1} });

	int ypos, xpos, ny, nx, cnt;
	ll val;
	while (!pq.empty()) {
		ppi now = pq.top();
		pq.pop();

		ypos = now.second.first;
		xpos = now.second.second;
		cnt = now.first.second;
		val = now.first.first;
		//printf("{%d %d} {%d %d}\n", val, cnt, ypos, xpos);
		//show();
		for (int i = 0; i < 4; i++) {
			ny = ypos + dy[i];
			nx = xpos + dx[i];

			if (ny <= 0 || ny > N || nx <= 0 || nx > M)
				continue;
			
			if (visit[ny][nx][cnt] == -1 || visit[ny][nx][cnt] > visit[ypos][xpos][cnt]) {
				if (arr[ny][nx] > visit[ypos][xpos][cnt]) {
					if (cnt == 1) {
						// no chance
						pq.push({ {arr[ny][nx], cnt},{ny,nx} });
						visit[ny][nx][cnt] = arr[ny][nx];
						// chance
						ny = ny + dy[i];
						nx = nx + dx[i];
						pq.push({ {visit[ypos][xpos][cnt],cnt - 1},{ny,nx} });
						//visit[ypos][xpos][cnt - 1] = visit[ypos][xpos][cnt];
						visit[ny][nx][cnt - 1] = visit[ypos][xpos][cnt];
					}
					else {
						pq.push({ {arr[ny][nx], cnt},{ny,nx} });
						visit[ny][nx][cnt] = arr[ny][nx];
					}
				}
				else {
					pq.push({ {visit[ypos][xpos][cnt],cnt},{ny,nx} });
					visit[ny][nx][cnt] = visit[ypos][xpos][cnt];
				}
			}
			/*else if (visit[ny][nx][cnt] > visit[ypos][xpos][cnt]) {
				if (arr[ny][nx] > visit[ypos][xpos][cnt]) {
					if(cnt == 1){}
				}
			}*/
		}
	}
}


int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf("%lld", &arr[i][j]);
		}
	}
	memset(visit, -1, sizeof(visit));

	solve();

	show();

	printf("%lld\n", min(visit[N][M][1], visit[N][M][0]));
	return 0;
}