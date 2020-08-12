#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

int K, V, E;
vector <int> v[20002];
int visit[20002];
bool ans = true;
typedef pair<int, int> pii;
queue<pii> q;

void bfs(int pos, int col) {
	visit[pos] = -col;
	q.push({ pos, -col });

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		int v_size = v[now.first].size();

		for (int i = 0; i < v_size; i++) {
			if (visit[now.first] == visit[v[now.first].at(i)]) {
				ans = false;
				return;
			}
			if (visit[v[now.first].at(i)] == 0) {
				q.push({ v[now.first].at(i), -now.second });
				visit[v[now.first].at(i)] = -now.second;
			}
		}
	}
}

void dfs(int pos, int col) {
	visit[pos] = -col;

	int v_size = v[pos].size();

	for (int i = 0; i < v_size; i++) {
		if (visit[pos] == visit[v[pos].at(i)]) {
			ans = false;
			return;
		}
		if (visit[v[pos].at(i)] == 0) {
			dfs(v[pos].at(i), -col);
		}
	}
}

int main() {

	scanf("%d", &K);

	for (int k = 0; k < K; k++) {
		
		scanf("%d %d", &V, &E);
		int s, e;
		for (int i = 0; i < E; i++) {
			scanf("%d %d", &s, &e);
			v[s].push_back(e);
			v[e].push_back(s);
		}

		memset(visit, 0, sizeof(visit));

		for (int i = 1; i < V + 1; i++) {
			if (visit[i] == 0) {
				bfs(i, -1);
				//dfs(i, -1);
				while (!q.empty()) {
					q.pop();
				}
				if (ans == false)
					break;
			}
		}
		/*
		for (int i = 1; i < V + 1; i++) {
			printf("%d ", visit[i]);
		}
		*/
		if (ans == true)
			printf("YES\n");
		else
			printf("NO\n");

		for (int i = 1; i < V + 1; i++)
			v[i].clear();
		ans = true;
	}



	return 0;
}