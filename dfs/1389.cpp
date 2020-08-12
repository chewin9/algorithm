#include<iostream>
#include<vector>
#include<string.h>
#include<queue>

using namespace std;

int N, M;
vector<int> v[102];
int visit[102];
int kavin[102];
int ans;
typedef pair<int, int> pii;
queue<pii> q;

void bfs(int pos, int cnt) {
	q.push({ pos,cnt });
	visit[pos] = cnt;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		int v_size = v[now.first].size();

		for (int i = 0; i < v_size; i++) {
			if (visit[v[now.first].at(i)] == -1 || visit[v[now.first].at(i)] > now.second) {
				q.push({ v[now.first].at(i) , now.second+1 });
				visit[v[now.first].at(i)] = now.second + 1;
			}
		}
	}
}

void dfs(int pos, int cnt) {
	visit[pos] = cnt;

	int v_size = v[pos].size();

	for (int i = 0; i < v_size; i++) {
		if (visit[v[pos].at(i)] == -1 || visit[v[pos].at(i)] > cnt)
			dfs(v[pos].at(i), cnt + 1);
	}

}

int main() {
	scanf("%d %d", &N, &M);
	int s, e, sum;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		v[s].push_back(e);
		v[e].push_back(s);
	}

	memset(visit, -1, sizeof(visit));
	for (int i = 1; i < N + 1; i++) {
		memset(visit, -1, sizeof(visit));
		sum = 0;
		bfs(i, 0);
		//dfs(i, 0);
		for (int j = 1; j < N + 1; j++) {
			if (i != j)
				sum += visit[j];
		}
		kavin[i] = sum;
	}
	sum = kavin[1];
	ans = 1;
	for (int i = 2; i < N + 1; i++) {
		if (sum > kavin[i]) {
			sum = kavin[i];
			ans = i;
		}
	}

	printf("%d\n", ans);
	/*
	for (int i = 1; i < N + 1; i++)
		printf("%2d", kavin[i]);
		*/
	return 0;
}