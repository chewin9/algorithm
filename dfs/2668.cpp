#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[3][102];
int cycle[102];
int visit[102];
int N;
int ans;
bool aa[102];
vector<int> v;

void dfs(int start, int pos, int cnt) {
	visit[pos] = cnt;
	cycle[pos] = start;

	v.push_back(pos);
	int next = arr[2][pos];

	if (visit[next] == 0)
		dfs(start, next, cnt + 1);
	else if (visit[next] != 0 && start == cycle[next]) {
		int count = cnt - visit[next] + 1;
		ans += count;
		for (int i = v.size() - count; i < v.size(); i++) {
			aa[v.at(i)] = true;
		}
		return;
	}
	else if (visit[next] != 0 && start != cycle[next])
		return;
}

int main() {
	scanf("%d", &N);
	int a;
	for (int i = 1; i < N + 1; i++) {
		arr[1][i] = i;
		scanf("%d", &a);
		arr[2][i] = a;
	}

	for (int i = 1; i < N + 1; i++) {
		if (visit[i] == 0)
			dfs(i, i, 1);
		v.clear();
	}

	printf("%d\n", ans);
	for (int i = 1; i < N + 1; i++) {
		if (aa[i])
			printf("%d\n", i);
	}
	return 0;
}