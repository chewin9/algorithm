#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;

priority_queue<ppi> q;

int N, M, T, K;
int arr[700][700];
int table[700][700];
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
int ans = 0;
void show();

void find_able(int time) {
	for (int i = 1; i < N + K + time; i++) {
		for (int j = 1; j < M + K + time; j++) {
			if (arr[i][j] == 0)
				continue;
			else if (time - table[i][j] >= 0 && time - table[i][j] < arr[i][j]) {
				q.push({ arr[i][j], {i,j} });
			}
		}
	}
}
void area(int time) {
	int ny, nx;
	//printf("\nTIME = %d", time);
	while (!q.empty()) {
		ppi now = q.top();
		q.pop();
		//printf("{%d %d} => ", now.second.first, now.second.second);

		for (int i = 0; i < 4; i++) {
			ny = now.second.first + dy[i];
			nx = now.second.second + dx[i];

			if (arr[ny][nx] == 0) {
				arr[ny][nx] = now.first;
				table[ny][nx] = time + now.first + 1;
			}
		}
	}
	//printf("\n");
}
void solve() {
	int time = 0;
	int a = K;
	while (a--) {
		//printf("%d===============\n", time);
		find_able(time);
		area(time);
		//if(time ==10)
		//show();
		time++;
	}
}

void find_ans() {
	for (int i = 0; i < N + K + K; i++) {
		for (int j = 0; j < M + K + K; j++) {
			if (arr[i][j] != 0 && table[i][j] >= K)
				ans++;
			else if (arr[i][j] + table[i][j] > K)
				ans++;
		}
	}
}
void show() {
	printf("\nShow arr\n");
	for (int i = 0; i < N + K + K; i++) {
		for (int j = 0; j < M + K + K; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\nShow table\n");
	for (int i = 0; i < N + K + K; i++) {
		for (int j = 0; j < M + K + K; j++) {
			printf("%3d", table[i][j]);
		}
		printf("\n");
	}
}
int main() {

	/*priority_queue<ppi> pq;

	pq.push({ 1,{1,1 } });
	pq.push({ 3,{3,3 }});
	pq.push({ 5,{5,5 }});

	while (!pq.empty()) {
		printf("%d", pq.top());
		pq.pop();
	}*/

	freopen("sample_input.txt", "r", stdin);

	scanf("%d", &T);
	for (int t = 1; t < T + 1; t++) {
		memset(arr, 0, sizeof(arr));
		memset(table, 0, sizeof(table));
		ans = 0;
		scanf("%d %d %d", &N, &M, &K);

		for (int i = 0; i < N; i++) {			//(0,0) - > (310,310)
			for (int j = 0; j < M; j++) {
				scanf("%d", &arr[i + K][j + K]);
				table[i + K][j + K] = arr[i + K][j + K];
			}
		}

		solve();
		find_ans();
		//show();
		printf("#%d %d\n", t, ans);
	}



	return 0;
}