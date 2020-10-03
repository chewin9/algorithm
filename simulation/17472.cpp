#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;
queue<ppi> qq;			//{ypos,xpos}, {dis,dir}
queue<pii> q;
vector<pii> v;

int arr[12][12];
int N, M;
bool visit[12][12];
int ans = 1e9;
int city = 1;
int brige[8][8];
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

bool link[32];

void show() {
	printf("Show arr\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void label(int ypos, int xpos, int la) {
	q.push({ ypos,xpos });
	visit[ypos][xpos] = true;
	int ny, nx;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		arr[now.first][now.second] = la;

		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (arr[ny][nx] != 0 && visit[ny][nx] == false) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
	}
}

void get_brige(int pos) {
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == pos) {
				qq.push({{ i,j }, { 4,0 }});
			}
		}
	}

	int ny, nx, dir;
	while (!qq.empty()) {
		ppi now = qq.front();
		qq.pop();

		if (arr[now.first.first][now.first.second] != pos && arr[now.first.first][now.first.second] != 0) {			//다른 섬 도착
			int tmp = arr[now.first.first][now.first.second];
			int cnt = now.second.second - 1;

			if (cnt >= 2) {
				brige[pos][tmp] = min(brige[pos][tmp], cnt);
			}
			continue;
		}

		if (now.second.first == 4) {		//초기 방향 설정 전
			for (int i = 0; i < 4; i++) {
				ny = now.first.first + dy[i];
				nx = now.first.second + dx[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;
				if (arr[ny][nx] != pos) {
					qq.push({ {ny,nx},{i,1} });
				}
			}
		}

		else {
			dir = now.second.first;

			ny = now.first.first + dy[dir];
			nx = now.first.second + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (arr[ny][nx] != pos) {
				qq.push({ {ny,nx},{dir, now.second.second + 1} });
			}
		}
	}
}

void check_link() {
	int tmp_bri[8][8];
	memset(tmp_bri, 0, sizeof(tmp_bri));

	for (int i = 0; i < v.size(); i++) {
		if (link[i] == true) {
			tmp_bri[v.at(i).first][v.at(i).second] = brige[v.at(i).first][v.at(i).second];
			tmp_bri[v.at(i).second][v.at(i).first] = brige[v.at(i).first][v.at(i).second];
		}
	}

	bool asd[8];
	memset(asd, false, sizeof(asd));

	for (int i = 1; i < city; i++) {
		if (tmp_bri[1][i] != 0) {
			q.push({ 1,i });
		}
	}
	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		asd[now.first] = true;
		asd[now.second] = true;

		for (int i = 1; i < city; i++) {
			if (tmp_bri[now.second][i] != 0 && asd[i] ==false) {
				q.push({ now.second,i });
			}
		}
	}
	for (int i = 1; i < city; i++) {
		if (asd[i] == false)
			return;
	}

	int answer = 0;
	for (int i = 1; i < city; i++) {
		for (int j = i; j < city; j++) {
			if(tmp_bri[i][j] != 0){
				answer += tmp_bri[i][j];
			}
		}
	}
	ans = min(ans, answer);

}

void dfs(int goal, int pos, int cnt) {
	link[pos] = true;
	if (goal == cnt) {
		/*for (int i = 0; i < v.size(); i++) {
			printf("%2d", link[i]);
		}
		printf("\n");*/
		check_link();

		link[pos] = false;
		return;
	}
	for (int i = pos + 1; i < v.size(); i++) {
		if (link[i] == false) {
			dfs(goal, i, cnt + 1);
		}
	}
	link[pos] = false;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != 0 && visit[i][j] == false) {
				label(i, j, city);
				city++;
			}
		}
	}
	
	for (int i = 1; i < 8; i++) {
		for (int j = 1; j < 8; j++) {
			brige[i][j] = 1e9;
		}
	}

	for (int i = 1; i < city; i++) {
		get_brige(i);
	}

	/*for (int i = 1; i < city; i++) {
		printf("Brige %d: ", i);
		for (int j = 1; j < city; j++) {
			printf("%2d", brige[i][j]);
		}
		printf("\n");
	}*/

	for (int i = 1; i < city; i++) {
		for (int j = i; j < city; j++) {
			if (brige[i][j] != 1e9)
				v.push_back({ i,j });
		}
	}
	
	/*show();
	for (int i = 0; i < v.size(); i++) {
		printf("{%d %d} => ", v.at(i).first, v.at(i).second);
	}
	printf("\n")*/;

	for (int i = 1; i < v.size()+1; i++) {
		for (int j = 0; j < v.size(); j++) {
			//printf("dfs(%d %d %d)", i, j, 1);
			dfs(i, j, 1);
		}
	}
	if (ans == 1e9)
		printf("-1\n");
	else
		printf("%d\n", ans);
	//show();
	return 0;
}