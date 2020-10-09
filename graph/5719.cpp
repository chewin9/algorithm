#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<set>

using namespace std;

typedef pair<int, int> pii;
vector<pii> v[502];
priority_queue<pii, vector<pii>, greater<> >pq;
int N, M;
int S, D;
priority_queue<int> ans[502];
set<int>s[502];
bool visit[502];
void djk(int pos) {
	ans[pos].push(0);
	pq.push({ 0,pos });

	while (!pq.empty()) {
		pii now = pq.top();
		pq.pop();

		int here = now.second;
		int cost = now.first;
		if (visit[here] == true)
			continue;
		visit[here] = true;
		int size = v[here].size();

		for (int i = 0; i < size; i++) {
			int dest = v[here].at(i).second;
			int dest_cost = v[here].at(i).first + cost;

			ans[dest].push(dest_cost);
			pq.push({ dest_cost,dest });
			
			//if (/*ans[dest].size() < 3 || */ans[dest].top() != dest_cost) {
			//	ans[dest].push(dest_cost);
			//	pq.push({ dest_cost, dest });
			//}
			/*else if (ans[dest].top() > dest_cost) {
				ans[dest].pop();
				ans[dest].push(dest_cost);
				pq.push({ dest_cost, dest });
			}*/
		}
	}
}
//bool comp(int a, int b) {
//	return a > b;
//}
int main() {
	while (1) {

		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0)
			break;

		scanf("%d %d", &S, &D);
		int U, V, P;
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &U, &V, &P);
			v[U].push_back({ P,V });
		}
		/*for (int i = 0; i < N; i++) {
			ans[i].push(0);
		}*/
		djk(S);

		for (int i = 0; i < N; i++) {
			printf("ans[%d]=", i);
			int aa = ans[i].size();
			for (int j = 0; j < aa; j++) {
				printf("%d->", ans[i].top());
				s[i].insert(ans[i].top());
				ans[i].pop();
			}
			printf("\n");
		}

		set<int>::iterator iter;

		for (int i = 0; i < N; i++) {
			for (iter = s[i].begin(); iter != s[i].end(); iter++) {
				printf("%d->", *iter);
			}
			printf("\n");
		}
	}

	/*priority_queue<int, vector<int>, less<> > t;
	t.push(1);
	t.push(2);
	t.push(5);
	t.push(4);


	while (!t.empty()) {
		printf("%d->", t.top());
		t.pop();
	}
	printf("\n");
	vector<int>v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	sort(v.begin(), v.end(), less<>() );

	for (int i = 0; i < v.size(); i++) {
		printf("%d->", v.at(i));
	}*/




	return 0;
}