#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
vector<ppi> arr;

int parent[1002];
int N, M;
int max_ans;
int min_ans;

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

	for (int i = 0; i < N+1; i++)
		parent[i] = i;

	int from, to, cost;
	for (int i = 0; i < M+1; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		if (cost == 0)
			cost = 1;
		else
			cost = 0;
		arr.push_back({ cost,{from,to} });
	}
	sort(arr.begin()+1, arr.end());
	//printf("MIN\n\n");
	for (int i = 0; i < arr.size(); i++) {
		//printf("%d {%d %d} ->", arr[i].first, arr[i].second.first, arr[i].second.second);
		if (sameparent(arr[i].second.first, arr[i].second.second) == false) {
			merge(arr[i].second.first, arr[i].second.second);
			min_ans += arr[i].first;
		}
	}
	
	//printf("\nMAX\n\n");
	for (int i = 0; i < N+1; i++)
		parent[i] = i;
	sort(arr.begin()+1, arr.end(), greater<>());
	for (int i = 0; i < arr.size(); i++) {
		//printf("%d {%d %d} -> ", arr[i].first, arr[i].second.first, arr[i].second.second);
		if (sameparent(arr[i].second.first, arr[i].second.second) == false) {
			merge(arr[i].second.first, arr[i].second.second);
			max_ans += arr[i].first;
		}
	}
	//printf("\n%d %d", max_ans, min_ans);

	printf("%d\n", max_ans*max_ans - min_ans * min_ans);

	return 0;
}