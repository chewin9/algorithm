#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
vector<ppi> arr;
vector<int> bal;
int parent[1002];
int N, M, K;
int ans = 0;

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
	else {
		bool a, b;
		a = b = false;
		for (int i = 0; i < bal.size(); i++) {	//둘다 발전소 그룹에 속하면 연결할 필요 없음
			if (x == bal[i])
				a = true;
			if (y == bal[i])
				b = true;
		}
		if (a == true && b == true)
			return true;

		return false;
	}
}
void Merge(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y)
		return;
	else {
		for (int i = 0; i < bal.size(); i++) {		//parent를 무조건 발전소로 만듬
			if (x == bal[i]) {
				parent[y] = x;
				return;
			}
			if (y == bal[i]) {
				parent[x] = y;
				return;
			}
		}
		parent[y] = x;
	}
}
int main() {
	scanf("%d %d %d", &N, &M, &K);

	int from, to, cost;
	for (int i = 0; i < K; i++) {
		scanf("%d", &from);
		bal.push_back(from);
	}

	for (int i = 1; i < N+1; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		arr.push_back({ cost, {from, to} });
	}
	sort(arr.begin(), arr.end());

	/*for (int i = 0; i < arr.size(); i++) {
		printf("%d {%d %d} -> ", arr[i].first, arr[i].second.first, arr[i].second.second);
	}
	printf("\n");*/
	for (int i = 0; i < M; i++) {
		if (SameParent(arr[i].second.first, arr[i].second.second) == false) {
			//printf("%d {%d %d}\n", arr[i].first, arr[i].second.first, arr[i].second.second);
			Merge(arr[i].second.first, arr[i].second.second);
			ans += arr[i].first;
		}
	}
	/*for (int i = 1; i < N + 1; i++) {
		printf("%3d", parent[i]);
	}*/
	printf("%d\n", ans);


	return 0;
}