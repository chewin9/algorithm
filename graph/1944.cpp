#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>	

using namespace std;
typedef pair<int, int > pii;
typedef pair<int, pii> ppi;
vector<ppi> point;
int N, M;
vector<pii> keys;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
queue<pii> q;
int arr[52][52];
int Sy, Sx;
int visit[52][52];
int parent[252];

int Find(int x) {
	if (parent[x] == x)
		return x;
	else {
		int y = Find(parent[x]);
		parent[x] = y;
		return y;
	}
}
bool SameParent(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y)
		return true;
	else
		return false;
}
void Merge(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y)
		return;
	else
		parent[y] = x;
}

void solve(int ypos, int xpos) {
	visit[ypos][xpos] = 0;
	q.push({ ypos,xpos });

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		int ny, nx;
		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny >= N || ny < 0 || nx >= N || nx < 0)
				continue;

			if (visit[ny][nx] == -1 && arr[ny][nx] == 0) {
				q.push({ ny, nx });
				visit[ny][nx] = visit[now.first][now.second] + 1;
			}
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);

	//getchar();
	char a;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &a);
			if (a == 'S') {
				Sy = i;
				Sx = j;
				arr[i][j] = 0;
			}
			else if (a == 'K') {
				keys.push_back({ i,j });
				arr[i][j] = 0;
			}
			else
				arr[i][j] = a - '0';
		}
	}
	memset(visit, -1, sizeof(visit));
	solve(Sy, Sx);

	int ans = 0;

	for (int i = 0; i < M; i++) {
		if (visit[keys[i].first][keys[i].second] == -1) {
			printf("-1\n");
			return 0;
		}
	}

	keys.push_back({ Sy, Sx });

	/*printf("KEYS\n");
	for (int i = 0; i < keys.size(); i++) {
		printf("%d = {%d %d}\n",i, keys[i].first, keys[i].second);
	}*/
	for (int i = 0; i < keys.size()-1; i++) {
		memset(visit, -1, sizeof(visit));
		solve(keys[i].first, keys[i].second);

		for (int j = i + 1; j < keys.size(); j++) {
			point.push_back({ visit[keys[j].first][keys[j].second], {i,j} });
		}
	}

	/*for (int i = 0; i < point.size(); i++) {
		printf("%d {%d %d}\n", point[i].first, point[i].second.first, point[i].second.second);
	}*/
	for (int i = 0; i < M + 1; i++)
		parent[i] = i;
	sort(point.begin(), point.end());
	for (int i = 0; i < point.size(); i++) {
		if (SameParent(point[i].second.first, point[i].second.second) == false) {
			Merge(point[i].second.first, point[i].second.second);
			ans += point[i].first;
		}
	}

	printf("%d\n", ans);
	return 0;
}