#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
vector<ppi> arr;

int N;
int ans = 0;
int parent[302];
bool visit[302];
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
	else {
		parent[y] = x;
	}
}

int main() {

	scanf("%d", &N);
	
	vector<int> tmp;
	int from, to, cost;
	for (int i = 1; i < N+1; i++) {
		scanf("%d", &cost);
		arr.push_back({ cost, {0,i} });
		//tmp.push_back(cost);
	}
	parent[0] = 0;
	for (int i = 1; i < N+1; i++) {
		parent[i] = i;
		for (int j = 1; j < N+1; j++) {
			scanf("%d", &cost);
			if (i >= j)
				continue;
			else {
				arr.push_back({ cost, {i,j} });
			}
		}
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		if (SameParent(arr[i].second.first, arr[i].second.second) == false) {
			Merge(arr[i].second.first, arr[i].second.second);
			ans += arr[i].first;
		}
	}

	printf("%d\n", ans);
	return 0;
}