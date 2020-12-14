#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>

using namespace std;
typedef pair<int, int>pii;
typedef pair<double, pii> pdi;

vector<pdi> arr;
int N;
int parent[102];
double ans = 0;

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

	double xpos=0, ypos=0;
	double cost=0;
	typedef pair<double, double> pdd;
	vector<pdd> tmp;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		scanf("%lf %lf", &xpos, &ypos);
		tmp.push_back({ xpos, ypos });
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			cost = pow(tmp[i].first - tmp[j].first, 2) + pow(tmp[i].second - tmp[j].second, 2);
			cost = sqrt(cost);
			//printf("%lf \n", cost);
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

	printf("%0.2f\n", ans);

	return 0;
}