#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
vector<ppi> arr;
int N;
long long ans;
int parent[1002];

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

	scanf("%d ", &N);

	int cost;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		for (int j = 0; j < N; j++) {
			scanf("%d", &cost);
			if (i == j)
				continue;
			arr.push_back({ cost, {i,j} });
		}
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		if (sameparent(arr[i].second.first, arr[i].second.second) == false) {
			merge(arr[i].second.first, arr[i].second.second);
			ans += arr[i].first;
		}
	}

	printf("%lld\n", ans);

	return 0;
}