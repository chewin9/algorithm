#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

int N;
int arr[102];
int visit[102];		//시작점
int deep[102];		//방문 했는지 and 몇단계를 거쳤는지.
int ans = 0;
vector<int> ans_v;
void dfs(int start, int pos, int cnt, vector<int> v) {
	visit[pos] = start;
	deep[pos] = cnt;
	v.push_back(pos);

	int next = arr[pos];

	if (deep[next] == 0) {
		dfs(start, next, cnt + 1, v);
	}
	if (deep[next] != 0 && visit[next] == start) {
		int tmp = cnt - deep[next] + 1;
		ans += tmp;
		for (int i = v.size() - tmp; i < v.size(); i++) {
			ans_v.push_back(v.at(i));
		}
		v.clear();
	}
	if (deep[next] != 0 && visit[next] != start)
		return;
}

int main() {
	scanf("%d", &N);

	vector<int> tmp;
	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &arr[i]);
	}

	memset(visit, 0, sizeof(visit));
	memset(deep, 0, sizeof(deep));

	for (int i = 1; i < N + 1; i++) {
		if (deep[i] == 0) {
			vector<int> v;
			dfs(i, i, 1, v);
		}
	}
	;
	sort(ans_v.begin(), ans_v.end());
	printf("%d\n", ans);
	for (int i = 0; i < ans_v.size(); i++) {
		printf("%d\n", ans_v.at(i));
	}
	return 0;
}