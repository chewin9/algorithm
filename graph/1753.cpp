#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;
typedef pair<int, int> pii;

vector<pii> arr[20002];
priority_queue<pii, vector<pii>, greater<> > pq;

int V, E, K;
int ans[20002];
bool visit[20002];
void djk(int pos) {
	ans[pos] = 0;
	pq.push({ 0,pos });
	//visit[pos] = true;
	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();

		int here = now.second;
		int cost = now.first;
		
		if (visit[here] == true)
			continue;
		visit[here] = true;

		int size = arr[here].size();

		for (int i = 0; i < size; i++) {
			int next = arr[here].at(i).second;
			int next_cost = arr[here].at(i).first + cost;

			if (ans[next] > next_cost) {
				ans[next] = next_cost;
				pq.push({ next_cost, next });
			}
		}
	}
}

bool aa(int a, int b) {
	return a > b;
}
int main() {


	scanf("%d %d %d", &V, &E, &K);

	int u, v, w;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		arr[u].push_back({ w,v });			//cost, dest
	}
	for (int i = 1; i < V + 1; i++) {
		ans[i] = 1e9;
	}
	djk(K);

	for (int i = 1; i < V + 1; i++) {
		if (ans[i] == 1e9)
			printf("INF\n");
		else
			printf("%d\n", ans[i]);
	}

	return 0;
}