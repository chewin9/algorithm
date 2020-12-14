#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;

vector<ppi> arr;
int parent[200002];
int N, M;
int ans;
int total;
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
	while (1) {
		//--------------------
		ans = 0;
		total = 0;
		memset(parent, 0, sizeof(parent));
		arr.clear();
		//--------------------
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0)
			break;

		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}
		int from, to, cost;
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &from, &to, &cost);
			arr.push_back({ cost,{from,to} });
			total += cost;
		}
		sort(arr.begin(), arr.end());

		for (int i = 0; i < M; i++) {
			if (sameparent(arr[i].second.first, arr[i].second.second) == false)	{
				merge(arr[i].second.first, arr[i].second.second);
				ans += arr[i].first;
			}
		}
		printf("%d\n", total-ans);
	}



	return 0;
}