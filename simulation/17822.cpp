#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> pii;
queue<pii> q;
int N, M, T;
int arr[52][52];
bool visit[52][52];
vector <pii> v;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
bool check = true;
int ans = 0;

void cycle(int pos, int cnt) {
	for (int p = pos; p < N + 1; p += pos) {
		for (int t = 0; t < cnt; t++) {
			int tmp = arr[p][M];
			for (int i = M; i > 1; i--)
				arr[p][i] = arr[p][i - 1];
			arr[p][1] = tmp;
		}
	}
}

void bfs(int ypos, int xpos) {
	int num = arr[ypos][xpos];
	q.push({ ypos,xpos });
	v.push_back({ ypos,xpos });
	visit[ypos][xpos] = true;

	int ny, nx;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (nx % M == 0) {
				nx = M;
			}
			else {
				nx = nx % M;
			}
			if (ny <= 0 || ny > N)
				continue;
			if (arr[ny][nx] == num && visit[ny][nx] == false) {
				q.push({ ny,nx });
				v.push_back({ ny,nx });
				visit[ny][nx] = true;
			}
		}
	}
	if (v.size() != 1) {
		for (int i = 0; i < v.size(); i++) {
			arr[v.at(i).first][v.at(i).second] = 0;
		}
		check = false;
	}
}
void num_aver() {
	int sum = 0;
	int cnt = 0;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			if (arr[i][j] != 0) {
				sum += arr[i][j];
				cnt++;
			}
		}
	}
	if (cnt != 0) {
		double ave = (double)sum / cnt;
		//printf("%f", ave);
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < M + 1; j++) {
				if (arr[i][j] != 0) {
					if (arr[i][j] > ave)
						arr[i][j] -= 1;
					else if (arr[i][j] < ave)
						arr[i][j] += 1;
				}
			}
		}
	}
}
void num_check() {
	check = true;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			if (arr[i][j] != 0) {
				memset(visit, false, sizeof(visit));
				while (!q.empty())
					q.pop();
				v.clear();
				bfs(i, j);
			}
		}
	}
	if (check == true) {
		num_aver();
	}
}

void find_ans() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			ans += arr[i][j];
		}
	}
}
void show() {
	printf("\nShow arr\n");
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}
int main() {
	scanf("%d %d %d", &N, &M, &T);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	for (int t = 0; t < T; t++) {
		int x1, d1, k1;
		scanf("%d %d %d", &x1, &d1, &k1);
		if (d1 == 1) {		//시계방향으로 바꿈
			k1 = M - k1;
		}
		cycle(x1, k1);
		//show();
		num_check();
		//show();
	}

	find_ans();
	printf("%d\n", ans);



	return 0;

}