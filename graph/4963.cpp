#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

typedef pair<int, int> pii;
queue<pii> q;
int w, h;
int arr[52][52];
bool visit[52][52];
int ans;
const int dy[] = { 1,1,0,-1,-1,-1,0,1 };
const int dx[] = { 0,1,1,1,0,-1,-1,-1 };
void bfs(int ypos, int xpos) {
	q.push({ ypos,xpos });
	visit[ypos][xpos] = true;

	int nx, ny;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny <= 0 || ny > h || nx <= 0 || nx > w)
				continue;
			if (arr[ny][nx] == 1 && visit[ny][nx] == false) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
	}
}

int main() {
	while (1) {
		memset(arr, 0, sizeof(arr));
		memset(visit, false, sizeof(visit));
		ans = 0;
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			break;


		for (int i = 1; i < h + 1; i++) {
			for (int j = 1; j < w + 1; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		
		for(int i=1; i<h+1; i++)
			for (int j = 1; j < w + 1; j++) {
				if (arr[i][j] != 0 && visit[i][j] == false) {
					bfs(i, j);
					ans++;
				}
			}

		printf("%d\n", ans);
	}



}