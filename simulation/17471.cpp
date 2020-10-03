#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

int arr[12];
int N;
int ans = 1e9;
bool visit[12];
vector<int> v[12];
queue<int> q;

bool check_link() {
	/*printf("link A=");
	for (int i = 1; i < N+1; i++) {
		if (visit[i] == true)
			printf("%2d", i);
	}
	printf("\nlink B=");
	for (int i = 1; i < N+1; i++) {
		if(visit[i] == false)
			printf("%2d", i);
	}
	printf("\n\n");*/


	//==================================================================================== list 1 check
	bool check[12];
	memset(check, false, sizeof(check));

	for (int i = 1; i < N + 1; i++) {
		if (visit[i] == true) {
			q.push(i);
			check[i] = true;
			break;
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int now_size = v[now].size();

		for (int i = 0; i < now_size; i++) {
			if (visit[v[now].at(i)] == true && check[v[now].at(i)] ==false) {
				q.push(v[now].at(i));
				check[v[now].at(i)] = true;
			}
		}
	}

	for (int i = 1; i < N + 1; i++) {
		if (visit[i] == false) {
			q.push(i);
			check[i] = true;
			break;
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int now_size = v[now].size();

		for (int i = 0; i < now_size; i++) {
			if (visit[v[now].at(i)] == false && check[v[now].at(i)] == false) {
				q.push(v[now].at(i));
				check[v[now].at(i)] = true;
			}
		}
	}
	for (int i = 1; i < N + 1; i++) {
		if (check[i] == false)
			return false;
	}

	return true;


}

void get_ans() {
	int a = 0, b = 0;

	for (int i = 1; i < N + 1; i++) {
		if (visit[i] == true) {
			a += arr[i];
		}
		else
			b += arr[i];
	}
	ans = min(ans, abs(a - b));
}
void dfs(int goal, int pos, int cnt) {
	visit[pos] = true;
	if (goal == cnt) {
		if (check_link()) {
			get_ans();
		}

		visit[pos] = false;
		return;
	}
	for (int i = pos+1; i < N + 1; i++) {
		if (visit[i] == false) {
			dfs(goal, i, cnt + 1);	
		}
	}
	visit[pos] = false;
	
}
int main() {

	scanf("%d", &N);
	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &arr[i]);
	}
	int a,b;
	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			scanf("%d", &b);
			v[i].push_back(b);
		}
	}
	for (int i = 1; i < N / 2 + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			//printf("dfs (%d %d %d)\n", i, j, 1);
			dfs(i, j,1);
		}
	}
	if (ans == 1e9)
		printf("-1\n");
	else
		printf("%d\n", ans);


	return 0;
}