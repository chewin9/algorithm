#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int N;
char arr[52][52];
bool visit[52];
int ans = -1e9;
void show() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("%2c", arr[i][j]);
		}
		printf("\n");
	}
	printf("========================\n");
}

int find(int ypos, int xpos) {
	for (int i = 1; i < N + 1; i++) {
		if (arr[xpos][i] == 'Y' && arr[ypos][i] == 'Y')
			return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			scanf(" %1c", &arr[i][j]);

	//show();

	
	for (int i = 1; i < N+1; i++) {
		int cnt = 0;
		for (int j = 1; j < N + 1; j++) {
			if (i == j)
				continue;
			else if (arr[i][j] == 'Y')
				cnt++;
			else if (arr[i][j] == 'N') {
				cnt += find(i, j);
			}
		}
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}