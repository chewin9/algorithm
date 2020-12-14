#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<pii, pii> ppp;
vector<ppi> arr;
int parent[100002];
int N;
long long ans;

bool cmpX(const ppp &a, const ppp &b) {
	if (a.first.first < b.first.first)
		return true;
	else
		return false;
}
bool cmpY(const ppp &a, const ppp &b) {
	if (a.first.second < b.first.second)
		return true;
	else
		return false;
}
bool cmpZ(const ppp &a, const ppp &b) {
	if (a.second.first < b.second.first)
		return true;
	else
		return false;
}
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

	scanf("%d", &N);

	for (int i = 1; i < N + 1; i++)
		parent[i] = i;

	vector<ppp> tmp;
	int x, y, z;

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &x, &y, &z);
		tmp.push_back({ { x,y }, { z,i + 1 } });
	}

	sort(tmp.begin(), tmp.end(), cmpX);
	int cost;
	for (int i = 0; i < N - 1; i++) {
		cost = abs(tmp[i].first.first - tmp[i + 1].first.first);
		arr.push_back({ cost, {tmp[i].second.second, tmp[i + 1].second.second} });
	}
	sort(tmp.begin(), tmp.end(), cmpY);
	for (int i = 0; i < N - 1; i++) {
		cost = abs(tmp[i].first.second - tmp[i + 1].first.second);
		arr.push_back({ cost, {tmp[i].second.second, tmp[i + 1].second.second} });
	}
	sort(tmp.begin(), tmp.end(), cmpZ);
	for (int i = 0; i < N - 1; i++) {
		cost = abs(tmp[i].second.first - tmp[i + 1].second.first);
		arr.push_back({ cost, {tmp[i].second.second, tmp[i + 1].second.second} });
	}
	tmp.clear();
	sort(arr.begin(), arr.end());
	/*for (int i = 0; i < arr.size(); i++) {
		printf("[%d {%d %d}] =>", arr[i].first, arr[i].second.first, arr[i].second.second);
	}
	printf("\n");*/
	for (int i = 0; i < arr.size(); i++) {
		if (sameparent(arr[i].second.first, arr[i].second.second) == false) {
			merge(arr[i].second.first, arr[i].second.second);
			ans += arr[i].first;
		}
	}

	printf("%lld\n", ans);

	return 0;
}