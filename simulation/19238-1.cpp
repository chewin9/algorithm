#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

typedef pair<int, int > pii;
queue<pii> q;
int N, M, K;
int arr[22][22];
bool visit[22][22];
int Ty, Tx;
int goal = 0;
int finish = 0;
vector<pii> dest;
vector<pii>order;
const int dy[] = { -1,0,0,1 };
const int dx[] = { 0,-1,1,0 };

bool find_person(int ypos, int xpos) {
	memset(visit, false, sizeof(visit));

	q.push({ ypos,xpos });
	int cnt = -1;
	visit[ypos][xpos] = true;
	int ny, nx;
	while (!q.empty()) {
		int size = q.size();
		cnt++;

		if (K - cnt < 0)
			return false;

		for (int s = 0; s < size; s++) {

			pii now = q.front();
			q.pop();

			if (arr[now.first][now.second] != 0 && arr[now.first][now.second] != 500) {
				order.clear();
				order.push_back({ now.first,now.second });
				for (int i = s + 1; i < size; i++) {
					now = q.front();
					q.pop();
					if (arr[now.first][now.second] != 0 && arr[now.first][now.second] != 500)
						order.push_back({ now.first, now.second });
				}
				sort(order.begin(), order.end());

				goal = arr[order.at(0).first][order.at(0).second];
				arr[order.at(0).first][order.at(0).second] = 0;
				K = K - cnt;
				Ty = order.at(0).first;
				Tx = order.at(0).second;

				/*goal = arr[now.first][now.second];
				arr[now.first][now.second] = 0;
				K = K - cnt;
				Ty = now.first;
				Tx = now.second;*/

				while (!q.empty())
					q.pop();
				return true;
			}

			for (int i = 0; i < 4; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > N || nx <= 0 || nx > N)
					continue;
				if (arr[ny][nx] != 500 && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
		}
	}
	return false;
}

bool find_dest(int ypos, int xpos) {
	memset(visit, false, sizeof(visit));

	int cnt = -1;
	q.push({ ypos,xpos });
	visit[ypos][xpos] = true;
	int ny, nx;

	int d_ypos = dest.at(goal).first;
	int d_xpos = dest.at(goal).second;


	while (!q.empty()) {
		int size = q.size();

		cnt++;

		if (K - cnt < 0)
			return false;

		for (int s = 0; s < size; s++) {
			pii now = q.front();
			q.pop();

			if (now.first == d_ypos && now.second == d_xpos) {
				while (!q.empty())
					q.pop();
				Ty = now.first;
				Tx = now.second;
				K = K + cnt;
				finish++;
				return true;
			}

			for (int i = 0; i < 4; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > N  || nx <= 0 || nx > N)
					continue;
				if (arr[ny][nx] != 500 && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
		}
	}
	return false;
}

int main() {
	scanf("%d %d %d", &N, &M,&K	);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				arr[i][j] = 500;
			}
		}
	}
	scanf("%d %d", &Ty, &Tx);

	int a, b, c, d;
	dest.push_back({ -1,-1 });
	for (int i = 1; i < M+1; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		arr[a][b] = i;
		dest.push_back({ c,d });
	}
	while (1) {
		if (finish == M)
			break;
		if (find_person(Ty, Tx) == false) {
			printf("-1\n");
			return 0;
		}
		printf("Find_pass: Ty = %d Tx = %d K = %d goal = %d\n", Ty, Tx, K, goal);
		if (find_dest(Ty, Tx) == false) {
			printf("-1\n");
			return 0;
		}
		printf("Find_dest: Ty = %d Tx = %d K = %d goal = %d\n\n", Ty, Tx, K, goal);
	}

	printf("%d\n", K);

	return 0;
}