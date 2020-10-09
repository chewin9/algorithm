#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
typedef pair<int, int> pii;
vector <pii> v[10002];
priority_queue<pii, vector<pii>, greater<> > pq;
int dist[10002];
bool visit[10002];
int T, N, D, C;

void djk(int pos) {
	dist[pos] = 0;
	pq.push({ 0,pos });

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();

		int here = now.second;
		int cost = now.first;
		if (visit[here] == true)
			continue;
		else
			visit[here] = true;

		int size = v[here].size();

		for (int i = 0; i < size; i++) {
			int next = v[here].at(i).second;
			int next_cost = v[here].at(i).first + cost;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ next_cost,next });
			}
		}
	}
}
int main() {
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d %d", &N, &D, &C);
		for (int i = 1; i < N + 1; i++) {
			dist[i] = 1e9;
			v[i].clear();
		}
		memset(visit, false, sizeof(visit));
		int a, b, s;
		for (int i = 0; i < D; i++) {
			scanf("%d %d %d", &a, &b, &s);
			v[b].push_back({ s,a });
		}

		djk(C);

		int ans = 0;;
		int cnt = 0;
		for (int i = 1; i < N + 1; i++) {
			if (dist[i] != 0 && dist[i] != 1e9) {
				ans = max(ans, dist[i]);
			}
			if (dist[i] != 1e9)
				cnt++;
		}
		printf("%d %d\n", cnt, ans);
	}


	return 0;
}