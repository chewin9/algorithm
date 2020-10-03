#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>	
#include<queue>

using namespace std;

int arr[102][102];
int Sx, Sy;
const int dy[] = { 0,0,-1 };
const int dx[] = { -1,1,0 };
typedef pair<int, int > pii;
bool visit[102][102];
queue<pii> q;
int ans;
void solve(int ypos, int xpos) {
	q.push({ ypos,xpos });
	visit[ypos][xpos] = true;
	int ny, nx;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		if (now.first == 0) {
			ans = now.second;
			while (!q.empty())
				q.pop();
			return;
		}

		for (int i = 0; i < 3; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny < 0 || ny >= 100 || nx < 0 || nx >= 100)
				continue;
			if (arr[ny][nx] == 1 && visit[ny][nx] == false) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
				break;
			}
		}

	}
}
int main() {

	freopen("input.txt", "r", stdin);

	int t;
	while (1) {
		memset(visit, false, sizeof(visit));
		scanf("%d", &t);

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf("%d", &arr[i][j]);
				if (arr[i][j] == 2) {
					Sy = i;
					Sx = j;
				}
			}
		}
		solve(Sy, Sx);
		printf("#%d %d\n", t, ans);
		if (t == 10)
			break;
	}



	return 0;
}