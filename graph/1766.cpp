#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef struct Node {
	int level;
	vector<int> to_node;
}Node;

Node no[32002];
priority_queue<int, vector<int>, greater<> > pq;
vector<int> ans;
int N, M;

void solve() {
	for (int i = 1; i < N + 1; i++) {
		if (no[i].level == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();

		ans.push_back(now);

		int size = no[now].to_node.size();

		for (int i = 0; i < size; i++) {
			int next = no[now].to_node.at(i);

			no[next].level--;

			if (no[next].level == 0)
				pq.push(next);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		no[b].level++;
		no[a].to_node.push_back(b);
	}

	solve();
	for (int i = 0; i < N; i++) {
		printf("%d ", ans.at(i));
	}

	return 0;
}