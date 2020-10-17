#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>;

using namespace std;
typedef pair<int, int> pii;

queue<pii> q;
bool visit[52][52];
int N, M, T;
int arr[52][52];
bool change = false;
int ans = 0;

void show() {
	//printf("\n====================================\n");
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void spin(int pos, int dir, int cnt) {
	if (dir == 1) {
		cnt = (M - cnt) % M;
		dir = 0;
	}

	for (int p = pos; p < N + 1; p = p + pos) {
		for (int c = 0; c < cnt; c++) {
			int tmp = arr[p][M];
			for (int i = M; i > 1; i--)
				arr[p][i] = arr[p][i - 1];
			arr[p][1] = tmp;
		}
	}
}
void bfs(int pos, int cnt) {
	memset(visit, false, sizeof(visit));

	visit[pos][cnt] = true;
	q.push({ pos,cnt });
	int n_pos, n_cnt;
	int tmp = arr[pos][cnt];
	int count = 1;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		
		//우 확인
		n_pos = now.first;
		n_cnt = now.second + 1;
		if (n_cnt > M)
			n_cnt = 1;
		if (arr[n_pos][n_cnt] == tmp && visit[n_pos][n_cnt] == false) {
			q.push({ n_pos,n_cnt });
			visit[n_pos][n_cnt] = true;
			count++;
		}
		// 좌 확인
		n_pos = now.first;
		n_cnt = now.second - 1;
		if (n_cnt == 0)
			n_cnt = M;
		if (arr[n_pos][n_cnt] == tmp && visit[n_pos][n_cnt] == false) {
			q.push({ n_pos, n_cnt });
			visit[n_pos][n_cnt] = true;
			count++;
		}
		//위에 원판
		n_pos = now.first + 1;
		n_cnt = now.second;
		if (n_pos > N)
			continue;
		if (arr[n_pos][n_cnt] == tmp && visit[n_pos][n_cnt] == false) {
			q.push({ n_pos,n_cnt });
			visit[n_pos][n_cnt] = true;
			count++;
		}
		//아래 원판
		n_pos = now.first - 1;
		n_cnt = now.second;
		if (n_pos <= 0)
			continue;
		if (arr[n_pos][n_cnt] == tmp && visit[n_pos][n_cnt] == false) {
			q.push({ n_pos,n_cnt });
			visit[n_pos][n_cnt] = true;
			count++;
		}
	}

	if (count!=1) {
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < M + 1; j++) {
				if (visit[i][j] == true)
					arr[i][j] = 0;
			}
		}
		change = true;
	}

}

void get_sum() {
	double sum = 0;
	int cnt = 0;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			if (arr[i][j] != 0) {
				sum += arr[i][j];
				cnt++;
			}
		}
	}
	double aver = sum / cnt;

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			if (arr[i][j] != 0) {
				if (arr[i][j] > aver)
					arr[i][j] -= 1;
				else if (arr[i][j] < aver)
					arr[i][j] += 1;
			}
		}
	}
}
void get_ans() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			if (arr[i][j] != 0)
				ans += arr[i][j];
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &T);

	memset(arr, 0, 0);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	//show();
	int a, b, c;
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &a, &b, &c);
		spin(a, b, c);
		//printf("%d time ========================\n", i);
		//show();
		change = false;
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < M + 1; j++) {
				if (arr[i][j] != 0) {
					bfs(i, j);
				}
			}
		}
		//show();
		if (change == false) {
			get_sum();
		}
	}

	get_ans();
	printf("%d\n", ans);
	return 0;
}