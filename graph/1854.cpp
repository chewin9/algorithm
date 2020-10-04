#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;
typedef pair<int, int> pii;
vector<pii> bus[1002];
int N, M, K;
priority_queue<pii, vector<pii>, greater<pii> > pq;
priority_queue<int> ans[1002];

void djk(int pos) {
	ans[pos].push(0);
	pq.push({ 0,pos });

	while (!pq.empty()) {
		//pii now = pq.top();
		//pq.pop();

		int here = pq.top().second;
		int cost = pq.top().first;
		//int size = bus[here].size();

		pq.pop();
		for (int i = 0; i < bus[here].size(); i++) {
			int next = bus[here].at(i).second;
			int nextcost = bus[here].at(i).first + cost;

			if (ans[next].size() < K) {
				ans[next].push(nextcost);
				pq.push({ nextcost,next });
			}
			else if (ans[next].top() > nextcost) {
				ans[next].pop();
				ans[next].push(nextcost);
				pq.push({ nextcost,next });
			}
		}

	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	int s, e, c;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &c);
		bus[s].push_back({ c,e });		//cost, end
	}

	djk(1);

	for (int i = 1; i < N + 1; i++) {
		if (ans[i].size() != K)
			printf("-1\n");
		else
			printf("%d\n", ans[i].top());
	}


	return 0;
}