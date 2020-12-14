#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
int parent[100002];
int N, M;
vector<ppi> arr;
int ans = 0;
int last = -1e9;
int find(int x) {
	if (parent[x] == x)
		return x;
	else {
		int y = find(parent[x]);
		parent[x] = y;
		return y;
	}
}

bool sameparent(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)
		return true;
	else
		return false;
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)
		return;
	else
		parent[y] = x;
}
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++)
		parent[i] = i;

	int from, to, cost;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		arr.push_back({ cost, {from,to} });
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < M; i++) {
		if (sameparent(arr[i].second.first, arr[i].second.second) == false) {
			merge(arr[i].second.first, arr[i].second.second);
			ans += arr[i].first;
			last = max(last, arr[i].first);
		}
	}

	printf("%d\n", ans-last);


	return 0;
}