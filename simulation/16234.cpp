#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;
typedef pair<int, int> pii;
queue<pii> q;
vector<pii> v;
int N, L, R;
int arr[52][52];
int temp_arr[52][52];
bool visit[52][52];
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
bool check = true;
int ans = 0;
void find_near(int ypos, int xpos) {
	visit[ypos][xpos] = true;
	q.push({ ypos,xpos });

	int ny, nx;
	int now_cost, near_cost;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		v.push_back({ now.first, now.second });
		now_cost = temp_arr[now.first][now.second];
		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny <= 0 || ny > N || nx <= 0 || nx > N)
				continue;

			near_cost = temp_arr[ny][nx];
			int dis = abs(now_cost - near_cost);

			if (visit[ny][nx] == false && L <= dis && dis <= R) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
	}

	int v_size = v.size();

	if (v_size == 1) {
		v.clear();
	}
	else {
		int sum = 0;
		for (int i = 0; i < v_size; i++) {
			sum += temp_arr[v.at(i).first][v.at(i).second];
		}
		for (int i = 0; i < v_size; i++) {
			arr[v.at(i).first][v.at(i).second] = sum / v_size;
		}
		v.clear();
		check = false;
	}
}

void copy_arr() {
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			temp_arr[i][j] = arr[i][j];
}

int main() {
	scanf("%d %d %d", &N, &L, &R);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	
	while (check) {
		ans++;
		copy_arr();
		memset(visit, false, sizeof(visit));

		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (visit[i][j] == false) {
					find_near(i, j);
				}
			}
		}

		if (check == true)
			check = false;
		else
			check = true;

	}

	printf("%d\n", ans - 1);

	return 0;
}