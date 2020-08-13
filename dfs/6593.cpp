#include<iostream>	
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

int L, R, C;
char arr[32][32][32];
bool visit[32][32][32];
int ans = 1e9;
int sl, si, sj;
int el, ei, ej;

typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;
queue<ppi> q;
const int dy[] = { 1,0,-1,0,0,0 };
const int dx[] = { 0,1,0,-1,0,0 };
const int dz[] = { 0,0,0,0,1,-1 };
void dfs(int level, int ypos, int xpos, int cnt) {
	visit[level][ypos][xpos] = true;

	//printf("{%d %d %d}==>", level, ypos, xpos);

	if (level == el && ypos == ei && xpos == ej) {
		ans = min(ans, cnt);
		visit[level][ypos][xpos] = false;
		return;
	}

	for (int i = 0; i < 6; i++) {
		int ny = ypos + dy[i];
		int nx = xpos + dx[i];
		int nz = level + dz[i];

		if (ny <= 0 || ny > R || nx <= 0 || nx > C || nz <= 0 || nz > L)
			continue;
		if (visit[nz][ny][nx] == false && arr[nz][ny][nx] == '.') {
			dfs(nz, ny, nx, cnt + 1);
			//visit[nz][ny][nx] = false;
		}
		
	}

	visit[level][ypos][xpos] = false;
}

void bfs(int level, int ypos, int xpos, int cnt) {
	q.push({{ level,ypos }, { xpos,cnt }});
	visit[level][ypos][xpos] = true;

	int nz, ny, nx;

	while (!q.empty()) {
		ppi now = q.front();
		q.pop();
		//printf("{%d %d %d %d}==>", now.first.first, now.first.second, now.second.first, now.second.second);
		
		if (now.first.first == el && now.first.second == ei && now.second.first == ej) {
			ans = min(ans, now.second.second);
			break;
		}

		for (int i = 0; i < 6; i++) {

			nz = now.first.first  + dz[i];
			ny = now.first.second + dy[i];
			nx = now.second.first + dx[i];

			//printf("%d", now.first.first);
			//printf("{%d %d %d}%d  ", nz,ny,nx,now.second.second);

			if (nz <= 0 || nz > L || ny <= 0 || ny > R || nx <= 0 || nx > C)
				continue;
			if (visit[nz][ny][nx] == false && arr[nz][ny][nx] == '.') {
				q.push({ {nz,ny},{nx,now.second.second + 1} });
				visit[nz][ny][nx] = true;
			}
		}
	}
}
int main() {
	while (1) {
		scanf("%d %d %d", &L, &R, &C);
		if (L == 0 && R == 0 && C == 0)
			break;
		
		for (int l = 1; l < L + 1; l++) {
			for (int i = 1; i < R + 1; i++) {
				for (int j = 1; j < C + 1; j++) {
					scanf(" %1c", &arr[l][i][j]);
					if (arr[l][i][j] == 'S') {
						sl = l;
						si = i;
						sj = j;
					}
					if (arr[l][i][j] == 'E') {
						el = l;
						ei = i;
						ej = j;
						arr[l][i][j] = '.';
					}
				}
			}
		}

		bfs(sl, si, sj,0);
		while (!q.empty())
			q.pop();

		if (ans != 1e9) {
			printf("Escaped in %d minute(s).\n", ans);
		}
		else {
			printf("Trapped!\n");
		}
		memset(visit, false, sizeof(visit));
		memset(arr, 0, sizeof(arr));
		ans = 1e9;
	}



	return 0;
}