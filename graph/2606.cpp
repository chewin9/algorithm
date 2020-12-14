#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;

int N, M;
vector<int> arr[102];
bool visit[102];
int ans=-1;
queue<int> q;
void bfs(int pos) {
	visit[pos] = true;
	q.push(pos);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		ans++;

		for (int i = 0; i < arr[now].size(); i++) {
			if (visit[arr[now].at(i)] == false) {
				q.push(arr[now].at(i));
				visit[arr[now].at(i)] = true;
			}
		}
	}
}
int main() {
	scanf("%d", &N);
	scanf("%d", &M);

	int to, from;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &from, &to);
		arr[from].push_back(to);
		arr[to].push_back(from);
	}

	memset(visit, false, sizeof(visit));

	bfs(1);
	printf("%d\n", ans);
	return 0;
}