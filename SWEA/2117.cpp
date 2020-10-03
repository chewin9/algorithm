#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>

using namespace std;

int N, M, T;
int arr[22][22];
bool visit[22][22];
int ans = -1e9;

const int dy[] = { -1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0,-1,-1,-1,0,1,1,1 };

void show() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("%2d", visit[i][j]);
		}
		printf("\n");
	}
}
void solve(int ypos, int xpos, int k) {
	int home = 0;
	
	int ny, nx;

	for (int i = 0; i < k; i++) {
		for (int j = k - i-1; j >= 0; j--) {
			for (int t = 0; t < 8; t++) {
				ny = ypos + dy[t] * i;
				nx = xpos + dx[t] * j;

				if (ny <= 0 || ny > N || nx <= 0 || nx > N)
					continue;

				if (arr[ny][nx] == 1 && visit[ny][nx] == false) {
					home++;
					visit[ny][nx] = true;
				}
			}
		}
	}

	int cost = 0;
	cost = home * M - ( k * k + (k-1) *(k-1));

	if (cost >= 0) {
		ans = max(ans, home);
	}
}


int main() {

	/*N = 8;
	solve(4, 4, 3);
	show();*/

	freopen("sample_input.txt", "r", stdin);

	scanf("%d",&T);

	for (int t = 1; t < T + 1; t++) {
		ans = -1e9;
		scanf("%d %d", &N, &M);

		for (int i = 1; i < N + 1; i++)
			for (int j = 1; j < N + 1; j++)
				scanf("%d", &arr[i][j]);

		for (int k = 1; k < (N/2) *2 +2; k++) {
			for (int i = 1; i < N + 1; i++) {
				for (int j = 1; j < N + 1; j++) {
					memset(visit, false, sizeof(visit));
					solve(i, j, k);
				}
			}
		}

		printf("#%d %d\n", t, ans);
	}



	return 0;
}