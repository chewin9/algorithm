#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

typedef struct Shark{
	int ypos;
	int xpos;
	int speed;
	int dir;
	int size;
}Shark;
typedef pair<int, int> pii;

int arr[102][102];
bool visit[102][102];
int R, C, M;
bool live[10002];
vector<Shark> sh;
const int dy[] = { 0, -1, 1, 0, 0 };
const int dx[] = { 0,  0, 0, 1, -1 };
int ans = 0;
vector <pii> order;

bool big(pii a, pii b) {
	return a > b;
}
void shark_move() {
	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < M; i++) {
		if (live[order.at(i).second] == true) {
			//printf("Shark move size= %d\n", order.at(i).first);
			int now = order.at(i).second;
			int now_ypos, now_xpos, now_dir, now_speed, now_size;
			int ny, nx;

			now_ypos = sh.at(now).ypos;
			now_xpos = sh.at(now).xpos;
			now_dir = sh.at(now).dir;
			now_speed = sh.at(now).speed;
			now_size = sh.at(now).size;

			if (now_dir == 1 || now_dir == 2) {
				now_speed = now_speed % (2 * (R - 1));
			}
			else {
				now_speed = now_speed % (2 * (C - 1));
			}
			for (int j = 0; j < now_speed; j++) {
				ny = now_ypos + dy[now_dir];
				nx = now_xpos + dx[now_dir];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C) {
					if (now_dir == 1)
						now_dir = 2;
					else if (now_dir == 2)
						now_dir = 1;
					else if (now_dir == 3)
						now_dir = 4;
					else if (now_dir == 4)
						now_dir = 3;
					j--;
				}
				else {
					now_ypos = ny;
					now_xpos = nx;
				}
			}
			sh.at(now).ypos = now_ypos;
			sh.at(now).xpos = now_xpos;
			sh.at(now).dir = now_dir;
			sh.at(now).speed = now_speed;
			
			if (arr[now_ypos][now_xpos] == 0) {
				arr[now_ypos][now_xpos] = now_size;
			}
			else {
				live[now] = false;
			}
		}
	}
}

void man_move(int pos) {
	int now = pos + 1;

	for (int i = 1; i < R + 1; i++) {
		if (arr[i][now] != 0) {
			ans += arr[i][now];
			//printf("man fish %d\n", arr[i][now]);
			for (int j = 0; j < M; j++) {
				if (order.at(j).first == arr[i][now]) {
					live[order.at(j).second] = false;
					break;
				}
			}
			break;
		}
	}
}
void show() {
	printf("Show arr\n");
	for (int i = 1; i < R + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main() {
	scanf("%d %d %d", &R, &C, &M);
	Shark tmp;
	memset(live, true, sizeof(live));
	memset(arr, 0, sizeof(arr));

	int r, c, s, d, z;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		tmp.ypos = r;
		tmp.xpos = c;
		tmp.speed = s;
		tmp.dir = d;
		tmp.size = z;
		sh.push_back(tmp);
		order.push_back({ z,i });
		if(arr[r][c] ==0)
			arr[r][c] = z;
		else {
			if (arr[r][c] > z)
				live[i] = false;
			else {
				for (int j = i; j >= 0; j--) {
					if (order.at(j).first == arr[r][c]) {
						live[order.at(j).second] = false;
						arr[r][c] = z;
						break;
					}
				}
			}
		}
	}

	sort(order.begin(), order.end(), big);

	for (int i = 0; i < C + 1; i++) {
		//show();
		man_move(i);
		shark_move();
	}

	printf("%d\n", ans);


	return 0;
}