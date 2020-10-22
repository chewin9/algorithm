#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>	

using namespace std;
typedef struct Node {
	int level;
	vector<int> to_node;
}Node;
vector<int> ans;
queue<int> q;

Node no[1002];
int N, M;

void solve() {
	for (int i = 1; i < N + 1; i++) {
		if (no[i].level == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		ans.push_back(now);

		int size = no[now].to_node.size();

		for (int i = 0; i < size; i++) {
			int next = no[now].to_node.at(i);

			no[next].level--;
			if (no[next].level == 0) {
				q.push(next);
			}
		}
	}
}

int main() {

	scanf("%d %d", &N, &M);

	int a,b,c;
	for (int i = 0; i < M; i++) {
		scanf("%d", &c);
		a = b = 0;

		for (int j = 0; j < c; j++) {
			scanf("%d", &a);
			if(b!=0)
			{
				no[a].level++;
				no[b].to_node.push_back(a);
			}
			b = a;
		}
	}

	solve();

	if (ans.size() != N)
		printf("0\n");
	else {
		for (int i = 0; i < N; i++) {
			printf("%d\n", ans.at(i));
		}
	}

	return 0;
}