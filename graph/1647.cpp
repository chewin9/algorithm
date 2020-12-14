#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
int N, M;
int ans = 0;
bool visit[100002];
vector<pii> arr[100002];
int last;
void solve(int pos) {
	visit[pos] = true;
	for (int i = 0; i < arr[pos].size(); i++)
		pq.push(arr[pos].at(i));

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();

		if (visit[now.second] == false) {
			printf("{%d %d} ->", now.first, now.second);
			visit[now.second] = true;
			ans += now.first;
			last = max(last, now.first);

			int size = arr[now.second].size();

			for (int i = 0; i < size; i++) {
				int dest = arr[now.second].at(i).second;

				if (visit[dest] == false) {
					pq.push(arr[now.second].at(i));
				}
			}
		}
	}
}


int main() {
	scanf("%d %d", &N, &M);
	int from, to, cost;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		arr[from].push_back({ cost,to });
		arr[to].push_back({ cost,from });
	}
	memset(visit, false, sizeof(visit));

	solve(1);

	printf("%d\n", ans-last);

	return 0;
}