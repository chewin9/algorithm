#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;

typedef pair<int, int> pii;
priority_queue<pii> pq;
int N,M;
int S,E;
long long dest[1002];
vector <int> city[1002];
vector<pii> bus[1002];			//cost dest

void djk(int pos) {
	dest[pos] = 0;
	city[pos].push_back(pos);
	pq.push({ 0,pos });

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();

		int size = bus[now.second].size();

		for (int i = 0; i < size; i++) {
			int goal = bus[now.second].at(i).second;
			int cost = dest[now.second] + bus[now.second].at(i).first;

			if (dest[goal] > cost) {
				city[goal].clear();
				for (int i = 0; i < city[now.second].size(); i++)
					city[goal].push_back(city[now.second].at(i));
				city[goal].push_back(goal);
				dest[goal] = cost;
				pq.push({ cost,goal });
			}
		}
	}

}

int main() {
	scanf("%d %d", &N, &M);
	int s, e, c;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &c);
		bus[s].push_back({ c,e });
	}
	for (int i = 0; i < N + 1; i++) {
		dest[i] = 1e9;
	}
	scanf("%d %d", &S, &E);

	djk(S);

	/*for (int i = 1; i < N + 1; i++) {
		printf("city[%d]", i);
		for (int j = 0; j < city[i].size(); j++) {
			printf("%2d->", city[i].at(j));
		}
		printf("\n");

	}*/


	printf("%d\n", dest[E]);
	printf("%d\n", city[E].size());
	for (int i = 0; i < city[E].size(); i++) {
		printf("%d ", city[E].at(i));
	}
	printf("\n");

	return 0;
}