#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;

int N, M;
vector<int> v[10002];
bool visit[10002];
int hack[100002];
int ans = -1e9;
queue<int> q;

int dfs(int pos) {

	visit[pos] = true;
	int cnt = 1;

	int v_size = v[pos].size();

	for (int i = 0; i < v_size; i++) {
		if (visit[v[pos].at(i)] == false) {
			cnt += dfs(v[pos].at(i));
		}
	}

	return cnt;
}

void bfs(int pos) {
	q.push(pos);
	visit[pos] = true;
	int cnt = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cnt++;

		int v_size = v[now].size();

		for (int i = 0; i < v_size; i++) {
			if (visit[v[now].at(i)] == false) {
				q.push(v[now].at(i));
				visit[v[now].at(i)] = true;
			}
		}
	}
	hack[pos] = cnt;
}

int main() {
	scanf("%d %d", &N, &M);

	int s, e;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		v[e].push_back(s);
	}
	
	for (int i = 1; i < N+1; i++) {
		//hack[i] = dfs(i);
		bfs(i);
		ans = max(ans, hack[i]);
		memset(visit, false, sizeof(visit));
	}

	for (int i = 1; i < N + 1; i++) {
		if (ans == hack[i])
			printf("%d ", i);
		//printf("%2d", hack[i]);
	}

	return 0;
}