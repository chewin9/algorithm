#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef pair<int, int> pii;
typedef struct horse {
	int ypos;
	int xpos;
	int dir;
};
int N, K;
int arr[14][14];
horse h[12];
vector<int> order[14][14];
int ans = 0;
const int dy[] = { 0,0,0,-1,1 };
const int dx[] = { 0, 1,-1,0,0 };

int get_dir(int dir) {
	if (dir == 1)
		return 2;
	else if (dir == 2)
		return 1;
	else if (dir == 3)
		return 4;
	else
		return 3;
}
void move(int pos) {
	int ypos, xpos, dir;
	ypos = h[pos].ypos;
	xpos = h[pos].xpos;
	dir = h[pos].dir;

	vector<int> tmp = order[ypos][xpos];
	vector<int> now;
	vector<int>::iterator iter = order[ypos][xpos].begin();

	for (int i = 0; i < tmp.size(); i++) {
		if (tmp.at(i) == pos) {
			for (int j = i; j < tmp.size(); j++) {
				now.push_back(tmp.at(j));
			}
			order[ypos][xpos].erase(iter + i, order[ypos][xpos].end());
			break;
		}
	}

	int ny, nx;
	ny = ypos + dy[dir];
	nx = xpos + dx[dir];
	bool check = false;

	if (ny <= 0 || ny > N || nx <= 0 || nx > N) {		//경계 넘어갈때
		dir = get_dir(dir);
		ny = ypos + dy[dir];
		nx = xpos + dx[dir];

		h[pos].dir = dir;
		check = true;
	}

	switch (arr[ny][nx]) {
	case 0:
		for (int i = 0; i < now.size(); i++) {
			order[ny][nx].push_back(now.at(i));
			h[now.at(i)].ypos = ny;
			h[now.at(i)].xpos = nx;
		}
		break;
	case 1:
		for (int i = now.size() - 1; i >= 0; i--) {
			order[ny][nx].push_back(now.at(i));
			h[now.at(i)].ypos = ny;
			h[now.at(i)].xpos = nx;
		}
		break;
	case 2:
		if (check == true) {							//처음 경계 걸림
			for (int i = 0; i < now.size(); i++) {
				order[ypos][xpos].push_back(now.at(i));
				h[now.at(i)].ypos = ypos;
				h[now.at(i)].xpos = xpos;
			}
			break;
		}
		else {											// 경계 안걸리고 arr[ny][nx] ==2 일때.
			dir = get_dir(dir);		//방향 바꿈
			ny = ypos + dy[dir];
			nx = xpos + dx[dir];
			h[pos].dir = dir;

			if (ny <= 0 || ny > N || nx <= 0 || nx > N || arr[ny][nx] == 2) {		//방향을 바꿧는데 경계 또는 arr[ny][nx] == 2일때.
				for (int i = 0; i < now.size(); i++) {
					order[ypos][xpos].push_back(now.at(i));
					h[now.at(i)].ypos = ypos;
					h[now.at(i)].xpos = xpos;
				}
				break;
			}
			switch (arr[ny][nx]) {
			case 0:
				for (int i = 0; i < now.size(); i++) {
					order[ny][nx].push_back(now.at(i));
					h[now.at(i)].ypos = ny;
					h[now.at(i)].xpos = nx;
				}
				break;
			case 1:
				for (int i = now.size() - 1; i >= 0; i--) {
					order[ny][nx].push_back(now.at(i));
					h[now.at(i)].ypos = ny;
					h[now.at(i)].xpos = nx;
				}
				break;
			}
		}
	}

}
bool find_ans() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (order[i][j].size() >= 4)
				return true;
		}
	}
	return false;
}
void show() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("{%d %d} = ", i, j);
			for (int k = 0; k < order[i][j].size(); k++) {
				printf("{%d %d}=>", order[i][j].at(k), h[order[i][j].at(k)].dir);
			}
			printf("\n");
		}
	}
}
int main() {
	scanf("%d %d", &N, &K);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int a, b, c;
	for (int i = 1; i < K + 1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		h[i].ypos = a;
		h[i].xpos = b;
		h[i].dir = c;
		order[a][b].push_back(i);
	}
	while (1) {
		ans++;
		for (int i = 1; i < K + 1; i++) {
			move(i);
			if (find_ans())
				break;
			//printf("\n[[%d %d]] ========================== \n", ans, i);
			//show();
		}
		//show();
		if (ans > 1000) {
			ans = -1;
			break;
		}
		if (find_ans()) {
			break;
		}
	}

	if (ans == -1)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}