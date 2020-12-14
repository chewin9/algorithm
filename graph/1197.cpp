#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
vector<pii> arr[10002];
bool visit[10002];
int V, E;
int ans = 0;

void solve(int pos) {
	visit[pos] = true;
	for (int i = 0; i < arr[pos].size(); i++)
		pq.push(arr[pos].at(i));

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();

		if (visit[now.second] == false) {
			visit[now.second] = true;
			ans += now.first;

			int size = arr[now.second].size();

			for (int i = 0; i < size; i++) {
				int dest = arr[now.second].at(i).second;

				if (visit[dest] == false)
					pq.push(arr[now.second].at(i));
			}
		}
	}
}

int main() {
	scanf("%d %d", &V, &E);

	int from, to, cost;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		arr[from].push_back({ cost,to });
		arr[to].push_back({ cost,from });
	}
	memset(visit, false, sizeof(visit));
	solve(1);

	printf("%d\n", ans);

	return 0;
}