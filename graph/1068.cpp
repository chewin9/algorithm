#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

int N;
int parent[52];
vector<int> v[52];
bool visit[52];
queue<int> q;
int ans;
vector<int> root;

void getLeaf(int pos) {
	q.push(pos);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		bool flag = true;
		int v_size = v[now].size();
		for (int i = 0; i < v_size; i++) {
			if (visit[v[now].at(i)] == true) {
				q.push(v[now].at(i));
				flag = false;
			}
		}
		if (flag)
			ans++;
	}
}

void bfs(int pos) {
	visit[pos] = false;
	q.push(pos);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int v_size = v[now].size();
		for (int i = 0; i < v_size; i++) {
			q.push(v[now].at(i));
			visit[v[now].at(i)] = false;
		}
	}
}

int main() {
	memset(visit, true, sizeof(visit));

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &parent[i]);
	}

	for (int i = 0; i < N; i++) {
		int a = parent[i];

		if (a == -1) {
			root.push_back(i);
			//root = i;
			continue;
		}

		v[a].push_back(i);
	}

	/*for (int i = 0; i < N; i++) {
		int v_size = v[i].size();
		printf("%d's child: ", i);
		for (int j = 0; j < v_size; j++) {
			printf("%2d", v[i].at(j));
		}
		printf("\n");
	}*/

	/*for (int i = 0; i < N; i++) {
		printf("%2d", visit[i]);
	}
	printf("\n");*/

	int del;
	scanf("%d", &del);

	bfs(del);

	/*for (int i = 0; i < N; i++) {
		printf("%2d", visit[i]);
	}
	printf("\n");*/

	for (int i = 0; i < root.size(); i++) {
		if (visit[root.at(i)] == true) {
			getLeaf(root.at(i));
		}
	}
	printf("%d\n", ans);
	return 0;
}