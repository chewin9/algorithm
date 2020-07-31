#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>


using namespace std;

queue <int> q;
vector<int> v[1002];
bool visit[1002];
int N, M, V;

void dfs(int pos) {
	if (visit[pos] == true)
		return;

	if (visit[pos] == false) {
		printf("%d ", pos);
		visit[pos] = true;
	}

	int cnt = v[pos].size();
	for (int i = 0; i < cnt; i++) {
		dfs(v[pos].at(i));
	}
}

void bfs(int pos) {
	visit[pos] = true;
	q.push(pos);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		printf("%d ", now);

		int cnt = v[now].size();
		for (int i = 0; i < cnt; i++) {
			if (visit[v[now].at(i)] == false) {
				q.push(v[now].at(i));
				visit[v[now].at(i)] = true;
			}
		}
	}
}
int main() {
	int s, e;
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		v[s].push_back(e);
		v[e].push_back(s);
	}
	for (int i = 0; i < N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	memset(visit, false, sizeof(visit));

	dfs(V);
	printf("\n");
	memset(visit, false, sizeof(visit));
	bfs(V);
	printf("\n");

	return 0;
}