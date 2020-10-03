#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;
typedef pair<int, int> pii;
vector<pii> v[1002];		//가중치, 목적지
priority_queue<pii> pq;
int N, M;
int S, E;
int ans[1002];
void djk(int pos) {
	for (int i = 0; i < N + 1; i++) {
		ans[i] = 1e9;
	}
	ans[pos] = 0;


	pq.push({ 0,pos });

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();

		int size = v[now.second].size();

		for (int i = 0; i < size; i++) {
			int dest = v[now.second].at(i).second;
			int cost = ans[now.second] + v[now.second].at(i).first;
			if (ans[dest] > cost) {
				ans[dest] = cost;
				pq.push({ cost, dest });
			}
		}
	}

}

int main() {
	scanf("%d %d", &N, &M);

	int s, d, c;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &d, &c);
		v[s].push_back({ c,d });
	}
	scanf("%d %d", &S, &E);

	djk(S);

	printf("%d\n", ans[E]);
	return 0;
}