#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;

int arr[30][30];
int N, T;

const int dy[] = { -1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int main() {

	/*freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t < T + 1; t++) {
		scanf("%d", &N);
		memset(arr, 0, sizeof(arr));

		solve(N);
		printf("#%d\n", t);
		show();
	}*/

	int N = 10;
	int ypos = 1;
	int xpos = 1;
	int K = 3;
	int ny, nx;
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < K; i++) {
		for (int j = K - 1 - i; j >= 0; j--) {
			for (int t = 0; t < 8; t++) {
				ny = ypos + dy[t] * i;
				nx = xpos + dx[t] * j;
				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue;
				else {
					arr[ny][nx] = 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}