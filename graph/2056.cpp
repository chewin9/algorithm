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
}Npde;
typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<> > pq;	//time, index
Node no[10002];
int ans[10002];

int N;

void solve() {
	for (int i = 1; i < N + 1; i++) {
		if (no[i].level == 0) {
			pq.push({ no[i].time, i });
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

	int a, b,c;
	for (int i = 1; i < N + 1; i++) {
		scanf("%d %d", &a, &b);
		no[i].time = a;
		
		for (int j = 0; j < b; j++) {
			scanf("%d", &c);
			no[i].level++;
			no[c].to_node.push_back(i);
		}
	}

	solve();
	int tmp = -1e9;

	for (int i = 1; i < N + 1; i++) {
		tmp = max(tmp, ans[i]);
	}
	
	printf("%d\n", tmp);

	return 0;
}