#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<int> v[502];
bool visit[502];
int ans;
typedef pair<int, int> pii;
queue<pii> q;

void bfs(int pos, int cnt) {
	q.push({ pos, cnt });
	visit[pos] = true;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		ans++;
		//printf("{%d %d}  ", now.first, now.second);

		int v_size = v[now.first].size();

		for (int i = 0; i < v_size; i++) {
			int nx = v[now.first].at(i);
			if (visit[nx] == false && now.second < 2) {
				q.push({ nx, now.second + 1 });
				visit[nx] = true;
			}
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	int s, e;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		v[s].push_back(e);
		v[e].push_back(s);
	}
	
	/*for (int i = 0; i < N; i++) {
		int v_size = v[i].size();
		printf("%d:", i);
		for (int j = 0; j < v_size; j++)
			printf("%d->", v[i].at(j));
		printf("\n");
	}*/
	bfs(1,0);

	printf("%d\n", ans-1);


	return 0;
}