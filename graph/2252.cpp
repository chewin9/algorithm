#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>

using namespace std;

typedef struct Node {
	int level;
	vector<int> to_node;
};
Node n[32002];
int N, M;
queue<int> q;
queue<int> ans;
bool visit[32002];
void solve() {
	int next;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		ans.push(now);

		int size = n[now].to_node.size();

		for (int i = 0; i < size; i++) {
			next = n[now].to_node.at(i);

			n[next].level--;
			if (n[next].level == 0) {
				q.push(next);
			}
		}
	}

}

int main() {
	
	memset(visit, false, sizeof(visit));
	scanf("%d %d", &N, &M);
	
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		n[b].level++;
		n[a].to_node.push_back(b);
	}

	for (int i = 1; i < N + 1; i++) {
		if (n[i].level == 0) {
			q.push(i);
			visit[i] = true;
		}
	}
	solve();

	while (!ans.empty()) {
		printf("%d ", ans.front());
		ans.pop();
	}
	printf("\n");

	return 0;
}