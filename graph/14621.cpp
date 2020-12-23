#include<algorithm>
#include<string.h>
#include<vector>
#include<iostream>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ppi;

vector<ppi> arr;
int parent[1002];
char sex[1002];
int N, M;
int ans;

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
	if (sex[x] == sex[y])
		return true;

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
	scanf("%d %d", &N, &M);
	char a;
	for (int i = 1; i < N + 1; i++) {
		parent[i] = i;
		cin >> a;
		sex[i] = a;
	}
	
	int from, to, cost;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		arr.push_back({ cost,{from,to} });
	}
	sort(arr.begin(), arr.end());
	//for (int i = 0; i < M; i++)
	//	printf("%d {%d %d} -> ", arr[i].first, arr[i].second.first, arr[i].second.second);
	//printf("\n");
	for (int i = 0; i < M; i++) {
		if (SameParent(arr[i].second.first, arr[i].second.second) == false) {
			//printf("%d {%d %d}\n", arr[i].first, arr[i].second.first, arr[i].second.second);
			Merge(arr[i].second.first, arr[i].second.second);
			ans += arr[i].first;
		}
	}

	for (int i = 1; i < N + 1; i++) {
		parent[i] = Find(i);
		//printf("%3d", parent[i]);
	}
	int now = parent[1];
	bool check = true;

	for (int i = 2; i < N + 1; i++) {
		if (now != parent[i]) {
			check = false;
			break;
		}
	}
	if (check == false)
		printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}