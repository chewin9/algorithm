#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> pii;
vector<pii> v[802];
priority_queue<pii> pq;		//{cost, dest}

int N, E;
long long dest[3][802];


long long ans;
int v1, v2;

void djk(int num, int pos) {
	dest[num][pos] = 0;

	pq.push({ 0,pos });

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();

		int size = v[now.second].size();

		int here = now.second;

		for (int i = 0; i < size; i++) {
			int goal = v[here].at(i).second;
			long long cost = dest[num][here] + v[here].at(i).first;

			if (dest[num][goal] > cost) {
				dest[num][goal] = cost;
				pq.push({ cost, goal });
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &E);
	int s, e, c;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &s, &e, &c);
		v[s].push_back({ c,e });
		v[e].push_back({ c,s });
	}
	scanf("%d %d", &v1, &v2);

	for (int i = 0; i < N + 1; i++) {
		dest[0][i] = 1e9;
		dest[1][i] = 1e9;
		dest[2][i] = 1e9;
	}

	djk(0, 1);
	djk(1, v1);
	djk(2, v2);
	
	/*for (int i = 0; i < 3; i++) {
		printf("dest[%d] =>", i);
		for (int j = 1; j < N + 1; j++) {
			printf("%3lld", dest[i][j]);
		}
		printf("\n");
	}*/

	ans = min(dest[0][v1] + dest[1][v2] + dest[2][N], dest[0][v2] + dest[2][v1] + dest[1][N]);
	if (ans >= 1e9)
		printf("-1\n");
	else
		printf("%lld\n", ans);
	return 0;
}