#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

int N, T;
int arr[13][13];
bool visit[13][13];
bool core_dir[13][5];
vector<pii> v;
queue<pii> q;
const int dy[] = { -1,0,1,0,0 };
const int dx[] = { 0,-1,0,1,0 };
int choose[13];
int max_core = -1e9;
int ans = 1e9;
int all = 0;
int qqqq = 0;
void check_dir(int ypos, int xpos) {
	bool check = true;
	int cnt = v.size();
	int a = 0;
	int ny, nx;
	ny = ypos;
	nx = xpos;
	for (int i = 0; i < 4; i++) {
		check = true;
		ny = ypos;
		nx = xpos;
		while (1) {
			ny = ny + dy[i];
			nx = nx + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				break;
			if (arr[ny][nx] == 1) {
				check = false;
				break;
			}
		}
		core_dir[cnt][i] = check;
		if (check == true)
			a = 1;
	}
	if (a == 1) {
		v.push_back({ ypos,xpos });
		core_dir[cnt][4] = true;
	}
}

void get_ans() {
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < v.size(); i++) {
		q.push({ v.at(i).first, v.at(i).second });
		visit[v.at(i).first][v.at(i).second] = true;
	}

	int tmp = 0;
	int sum = 0;
	int tmp_core = 0;
	int aa;
	int cnt = 0;
	int dir;
	while (!q.empty()) {
		tmp = 0;
		aa = tmp_core + q.size();

		if (aa < max_core) {
			while (!q.empty())
				q.pop();
			return;
		}

		pii now = q.front();
		q.pop();
		dir = choose[cnt++];
		if (dir == 5)
			continue;

		int ny = now.first;
		int nx = now.second;
		bool check = true;
		while (1) {
			ny = ny + dy[dir];
			nx = nx + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				break;
			if (visit[ny][nx] == true) {
				check = false;
				break;
			}
		}
		if (check == true) {
			ny = now.first;
			nx = now.second;
			while (1) {
				ny = ny + dy[dir];
				nx = nx + dx[dir];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					break;
				visit[ny][nx] = true;
				tmp++;
			}
			sum += tmp;
			tmp_core++;
		}
	}
	if (tmp_core > max_core) {
		ans = -1e9;
		max_core = tmp_core;
		ans = sum;
	}
	else if (tmp_core == max_core) {
		ans = min(ans, sum);
	}
}

void dfs(int pos, int dir, int cnt) {
	choose[pos] = dir;

	if (cnt == v.size()) {
		/*printf("\n");
		for (int i = 0; i < v.size(); i++) {
			printf("%2d", choose[i]);
		}*/
		all++;
		int aa = 0;
		for (int i = 0; i < v.size(); i++) {
			if (choose[i] != 4)
				aa++;
		}
		if (aa >= max_core) {
			qqqq++;
			get_ans();
		}

		return;
	}
	for (int i = pos + 1; i < v.size(); i++) {
		for (int j = 0; j < 5; j++) {
			if (core_dir[i][j] == true) {
				dfs(i, j, cnt + 1);
			}
		}
	}
}

int main() {

	//freopen("sample_input.txt", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t < T + 1; t++) {
		//init
		memset(core_dir, false, sizeof(core_dir));
		memset(choose, 0, sizeof(choose));
		v.clear();
		max_core = -1e9;
		ans = 1e9;
		all = 0;
		qqqq = 0;
		//========================================
		scanf("%d", &N);
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++)
				scanf("%d", &arr[i][j]);
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1) {
					if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
						continue;
					check_dir(i, j);
				}
			}
		}
		
		/*for (int i = 0; i < v.size(); i++) {
			printf("core {%d %d} =", v.at(i).first, v.at(i).second);
			for (int j = 0; j < 5; j++) {
				printf("%2d", core_dir[i][j]);
			}
			printf("\n");
		}*/

		for (int i = 0; i < 5; i++) {
			if (core_dir[0][i] == true) {
				dfs(0, i, 1);
			}
		}
		if (ans == 1e9)
			printf("#%d %d\n", t, 0);
		else
			printf("#%d %d %d %d\n", t, ans, all, qqqq);
	}

	return 0;
}