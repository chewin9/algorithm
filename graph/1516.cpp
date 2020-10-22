#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>	

using namespace std;
typedef struct Node {
	int level;
	int time;
	vector<int> to_node;
}Node;

Node no[502];
int N;
int ans[502];
queue<int> q;
typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii> > pq;

void solve() {
	for (int i = 1; i < N + 1; i++) {
		if (no[i].level == 0) {
			pq.push({ no[i].time, i });
			//ans[i] = no[i].time;
		}
	}

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();

		ans[now.second] = now.first;
		int size = no[now.second].to_node.size();

		for (int i = 0; i < size; i++) {
			int next = no[now.second].to_node.at(i);

			no[next].level--;
			if (no[next].level == 0) {
				pq.push({ ans[now.second] + no[next].time, next });
			}
		}
	}
}
int main() {

	scanf("%d", &N);

	int a;
	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &a);
		no[i].time = a;
		while (1) {
			scanf("%d", &a);
			if (a == -1)
				break;
			no[i].level++;
			no[a].to_node.push_back(i);
		}
	}

	solve();
	for (int i = 1; i < N + 1; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}