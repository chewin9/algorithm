#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;

typedef struct Horse {
	int ypos;
	int xpos;
	int dir;
	int num;
};
int N;
int K;
int ans = 0;
int map[14][14];
vector<int> arr[14][14];
//vector<Horse> arr[14][14];
Horse h[12];

const int dy[] = { 0,0,0,-1,1 };
const int dx[] = { 0,1,-1,0,0 };

void show();

int get_dir(int dir) {
	if (dir == 1)
		return 2;
	else if (dir == 2)
		return 1;
	else if (dir == 3)
		return 4;
	else if (dir == 4)
		return 3;
}

bool check_game() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j].size() >= 4) {
				//printf("ANSWER===========\n");
				//show();
				return true;
			}
		}
	}
	return false;

	/*int ypos, xpos;
	ypos = h[1].ypos;
	xpos = h[1].xpos;
	for (int i = 2; i < K + 1; i++) {
		if (h[i].ypos != ypos || h[i].xpos != xpos)
			return false;
	}
	return true;*/
}

bool move() {
	vector<int> h_tmp;
	vector<int>::iterator iter;
	//vector<Horse> h_tmp;
	//vector<Horse>::iterator iter;
	int ny, nx;
	int n_ypos, n_xpos, n_dir;
	int tmp;
	bool check = true;
	for (int k = 1; k < K + 1; k++) {
		check = true;
		n_ypos = h[k].ypos;
		n_xpos = h[k].xpos;
		n_dir = h[k].dir;
		int size = arr[n_ypos][n_xpos].size();

		//==================================================================== 지금 말을 기준으로 위에잇는애 다 꺼내
		for (int i = 0; i < size; i++) {
			if (arr[n_ypos][n_xpos].at(i) == k) {
				tmp = i;
				for (int j = i; j < size; j++) {
					h_tmp.push_back(arr[n_ypos][n_xpos].at(j));
				}
				break;
			}
		}
		iter = arr[n_ypos][n_xpos].begin();
		arr[n_ypos][n_xpos].erase(iter + tmp, arr[n_ypos][n_xpos].end());

		//==================================================================== 이제 움직이자
		
		ny = n_ypos + dy[n_dir];
		nx = n_xpos + dx[n_dir];

		if (ny <= 0 || ny > N || nx <= 0 || nx > N || map[ny][nx] == 2) {
			if (map[ny][nx] == 2)
				check = false;
			n_dir = get_dir(n_dir);

			h[h_tmp.at(0)].dir = n_dir;
			ny = n_ypos + dy[n_dir];
			nx = n_xpos + dx[n_dir];

			if (ny <= 0 || ny > N || nx <= 0 || nx > N || map[ny][nx] ==2 ) {
				/*if (check == false) {
					n_dir = get_dir(n_dir);
					h[h_tmp.at(0)].dir = n_dir;
				}*/
				size = h_tmp.size();
				for (int i = 0; i < size; i++) {
					arr[n_ypos][n_xpos].push_back(h_tmp.at(i));
				}
				h_tmp.clear();
				if (check_game() == true)
					return true;
				continue;
			}
		}

		switch (map[ny][nx]) {
		case 0:
			size = h_tmp.size();
			for (int i = 0; i < size; i++) {
				h[h_tmp.at(i)].ypos = ny;
				h[h_tmp.at(i)].xpos = nx;
			}
			for (int i = 0; i < size; i++) {
				arr[ny][nx].push_back(h_tmp.at(i));
			}
			h_tmp.clear();
			break;
		case 1:
			size = h_tmp.size();
			for (int i = 0; i < size; i++) {
				h[h_tmp.at(i)].ypos = ny;
				h[h_tmp.at(i)].xpos = nx;
			}
			for (int i = size - 1; i >= 0; i--) {
				arr[ny][nx].push_back(h_tmp.at(i));
			}
			h_tmp.clear();
			break;
		}

		if (check_game() == true)
			return true;
	}
	return false;
}

void show() {
	printf("Horse state\n");
	for (int i = 1; i < K + 1; i++) {
		printf("Horse %d {%d %d}, dir= %d\n", i, h[i].ypos, h[i].xpos, h[i].dir);
	}

	printf("Horse arr\n");
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j].size() != 0) {
				int size = arr[i][j].size();
				printf("arr {%d %d} = ", i, j);
				for (int s = 0; s < size; s++) {
					printf("{horse %d, dir %d} ->", arr[i][j].at(s), h[arr[i][j].at(s)].dir);
				}
				printf("\n");
			}
		}
	}
	printf("\n");
}

void game() {
	while (1) {
		if (ans > 1000)
			return;
		ans++;
		if (move() == true)
			return;
		//show();
		
		/*if (check_game() == true)
			return;*/
	}
}
int main() {
	scanf("%d %d", &N, &K);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int a, b, c;
	for (int i = 1; i < K + 1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		h[i].ypos = a;
		h[i].xpos = b;
		h[i].dir = c;
		h[i].num = i;
		arr[a][b].push_back(i);
		//arr[a][b].push_back(h[i]);
	}
	//show();
	game();

	if (ans > 1000)
		printf("-1\n");
	else
		printf("%d\n", ans);


	return 0;
}