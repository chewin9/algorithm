#include<iostream>
#include<vector>
#include<string.h>	
#include<queue>

using namespace std;

int N;
int arr[102][102];
bool visit[102][102];
queue<int> q;

void bfs(int pos) {
	for (int i = 1; i < N + 1; i++) {
		if (arr[pos][i] == 1) {
			q.push(i);
			visit[pos][i] = true;
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i < N + 1; i++) {
			if (arr[now][i] == 1 && visit[pos][i] == false) {
				q.push(i);
				visit[pos][i] = true;
				//visit[pos][i] = true;
			}
		}
	}
}


int main() {
	scanf("%d", &N);

	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 1; i < N + 1; i++)
		bfs(i);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++)
			printf("%d ", visit[i][j]);
		printf("\n");
	}

	return 0;

}