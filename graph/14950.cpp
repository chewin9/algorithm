#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
vector<ppi> arr;

int N, M, T;
int parent[10002];
int ans = 0;
int cnt = 0;

int Find(int x) {
	if (parent[x] == x)
		return x;
	else {
		int y = Find(parent[x]);
		parent[x] = y;
		return y;
	}
}
bool SameParent(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y)
		return true;
	else
		return false;
}
void Merge(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y)
		return;
	else
		parent[y] = x;
}
int main() {
	scanf("%d %d %d", &N, &M, &T);

	for (int i = 1; i < N + 1; i++) {
		parent[i] = i;
	}

	int from, to, cost;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		arr.push_back({ cost,{from,to} });
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < M; i++) {
		if (SameParent(arr[i].second.first, arr[i].second.second) == false) {
			Merge(arr[i].second.first, arr[i].second.second);
			ans += arr[i].first + cnt * T;
			cnt++;
		}
	}

	printf("%d\n", ans);



	return 0;
}