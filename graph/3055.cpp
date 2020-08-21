#include<iostream>
#include<queue>

using namespace std;

int R, C;
char arr[52][52];
bool visit[52][52];
int Dy, Dx, Sy, Sx;
int cnt;
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };
typedef pair<int, int> pii;
queue<pii> q;
queue<pii> wa;
int ans;

void show() {
	for (int i = 1; i < R + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			printf("%2c", arr[i][j]);
		}
		printf("\n");
	}
	printf("================\n");
}
void water() {
	while (!wa.empty()) {
		int size = wa.size();
		int ny, nx;
		for (int s = 0; s < size; s++) {
			pii now = wa.front();
			wa.pop();

			for (int i = 0; i < 4; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] == '.' && visit[ny][nx] == false) {
					wa.push({ ny,nx });
					visit[ny][nx] = true;
					arr[ny][nx] = '*';
				}
			}
		}
		break;
	}
}

void bfs(int ypos, int xpos) {
	q.push({ ypos,xpos });
	visit[ypos][xpos] = true;
	int cnt = 0;
	int ny, nx;
	while (!q.empty()) {
		water();
		cnt++;
		int size = q.size();

		for (int s = 0; s < size; s++) {
			pii now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] == '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
				if (ny == Dy && nx == Dx) {
					ans = cnt;
					return;
				}
			}
		}
		
	}
}

int main() {
	scanf("%d %d", &R, &C);

	for (int i = 1; i < R + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			scanf(" %1c", &arr[i][j]);
			if (arr[i][j] == 'D') {
				Dy = i;
				Dx = j;
				visit[i][j] = true;
			}
			else if (arr[i][j] == 'S') {
				Sy = i;
				Sx = j;
				visit[i][j] = true;
			}
			else if (arr[i][j] == '*') {
				wa.push({ i,j });
				visit[i][j] = true;
			}
		}
	}
	//show();
	bfs(Sy, Sx);

	if (ans != 0)
		printf("%d\n", ans);
	else
		printf("KAKTUS\n");
	return 0;

}