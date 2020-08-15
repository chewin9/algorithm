#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;
int N, M;
vector<int> v[20002];
int visit[20002];
typedef pair<int, int> pii;
queue<pii> q;
int ans = -1e9;
vector<int> vans;
void bfs(int pos, int cnt) {
	visit[pos] = cnt;
	q.push({ pos, cnt });

	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		ans = max(ans, now.second);

		int v_size = v[now.first].size();

		for (int i = 0; i < v_size; i++) {
			int nx = v[now.first].at(i);
			if (visit[nx] == -1) {
				q.push({ nx, now.second + 1 });
				visit[nx] = now.second + 1;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	memset(visit, -1, sizeof(visit));
	int s, e;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		v[s].push_back(e);
		v[e].push_back(s);
	}

	bfs(1, 0);
	//printf("%d\n", ans);

	for (int i = 1; i < N + 1; i++) {
		if (visit[i] == ans) {
			vans.push_back(i);
		}
	}
	/*for (int i = 1; i < N + 1; i++) {
		printf("%d ", visit[i]);
	}
	printf("\n");*/
	printf("%d %d %d", vans.at(0), ans, vans.size());

	return 0;
}