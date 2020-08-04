#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

int N, M;
int u, v;
int ans;
vector<int> vec[1002];
bool visit[1002];
queue<int> q;

void dfs(int pos) {
	visit[pos] = true;

	int v_size = vec[pos].size();

	for (int i = 0; i < v_size; i++) {
		if (visit[vec[pos].at(i)] == false)
			dfs(vec[pos].at(i));
	}
}

void bfs(int pos) {
	q.push(pos);
	visit[pos] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int v_size = vec[now].size();
		for (int i = 0; i < v_size; i++) {
			if (visit[vec[now].at(i)] == false) {
				q.push(vec[now].at(i));
				visit[vec[now].at(i)] = true;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	/*
	memset(visit, false, sizeof(visit));
	//dfs
	for (int i = 1; i < N+1; i++) {
		if (visit[i] == false) {
			dfs(i);
			ans++;
		}
	}
	*/
	memset(visit, false, sizeof(visit));
	//bfs
	for (int i = 1; i < N + 1; i++) {
		if (visit[i] == false) {
			bfs(i);
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}