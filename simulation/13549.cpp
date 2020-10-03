#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<deque>
using namespace std;

typedef pair<int, int> pii;
queue<pii> q;
deque<pii> dq;
int N, K;
int ans=0;
bool visit[100002];

int main() {

	memset(visit, false, sizeof(visit));

	scanf("%d %d", &N, &K);

	dq.push_back({ N,0 });
	visit[N] = true;

	int next = 0;
	while (!dq.empty()) {
		pii now = dq.front();
		dq.pop_front();

		if (now.first == K) {
			/*while (!q.empty())
				q.pop();*/
			ans = now.second;
			//break;
		}

		//======================================= x*2;
		next = now.first * 2;
		if (next <= 100000) {
			if (visit[next] == false){// && next <= 100000) {
				dq.push_front({ next, now.second });
				visit[next] = true;
			}
		}

		//======================================= x+1;
		next = now.first + 1;
		if (next <= 100000) {
			if (visit[next] == false) {// && next <= 100000) {
				dq.push_back({ next,now.second + 1 });
				visit[next] = true;
			}
		}

		//======================================= x-1;
		next = now.first - 1;
		if (next >= 0) {
			if (visit[next] == false) {// && next >= 0) {
				dq.push_back({ next, now.second + 1 });
				visit[next] = true;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}