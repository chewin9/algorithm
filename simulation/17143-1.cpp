#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;

typedef struct Shark{
	int ypos;
	int xpos;
	int speed;
	int dir;
	int size;
	bool live;
}Shark;
typedef pair<int, int> pii;

int R, C, M;
int arr[102][102];
vector<Shark> sh;
vector<pii> order;		//크기, 번호
const int dy[] = { 0,-1,1,0,0 };
const int dx[] = { 0,0,0,1,-1 };
int man = 0;
int ans = 0;

void show() {
	for (int i = 1; i < R + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void fishing() {
	for (int i = 1; i < R + 1; i++) {
		if (arr[i][man] != 0) {
			ans += sh.at(arr[i][man]).size;
			sh.at(arr[i][man]).live = false;
			break;
		}
	}
}

int change_dir(int dir) {
	if (dir == 1)
		return 2;
	else if (dir == 2)
		return 1;
	else if (dir == 3)
		return 4;
	else
		return 3;
}
void move_fish() {
	memset(arr, 0, sizeof(arr));

	for (int s = 0; s < order.size(); s++) {
		if (sh.at(order.at(s).second).live == true) {
			//printf("%d-> ", s);
			int now = order.at(s).second;
			int ypos, xpos, speed, dir;

			ypos = sh.at(now).ypos;
			xpos = sh.at(now).xpos;
			speed = sh.at(now).speed;
			dir = sh.at(now).dir;

			if (dir == 1 || dir == 2) {
				speed = speed % (2 * (R - 1));
			}
			else
				speed = speed % (2 * (C - 1));

			int ny, nx;
			for (int i = 0; i < speed; i++) {
				ny = ypos + dy[dir];
				nx = xpos + dx[dir];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C) {
					dir = change_dir(dir);
					i--;
				}
				else {
					ypos = ny;
					xpos = nx;
				}
			}

			sh.at(now).ypos = ypos;
			sh.at(now).xpos = xpos;
			sh.at(now).dir = dir;

			if (arr[ypos][xpos] == 0) {
				arr[ypos][xpos] = now;
			}
			else {
				sh.at(now).live = false;
			}

		}
	}
}

int main() {
	
	scanf("%d %d %d", &R, &C, &M);
	Shark tmp;
	sh.push_back(tmp);
	int r, c, s, d, z;
	for (int i = 1; i < M + 1; i++) {
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		tmp.ypos = r;
		tmp.xpos = c;
		tmp.speed = s;
		tmp.dir = d;
		tmp.size = z;
		tmp.live = true;
		sh.push_back(tmp);
		order.push_back({ z,i });
	}

	sort(order.begin(), order.end(), greater<>() );

	/*for (int i = 0; i < order.size(); i++) {
		printf("{%d %d} -> ", order.at(i).first, order.at(i).second);
	}*/
	for (int i = 0; i < order.size(); i++) {
		int now = order.at(i).second;
		int ypos = sh.at(now).ypos;
		int xpos = sh.at(now).xpos;

		if (arr[ypos][xpos] == 0) {
			arr[ypos][xpos] = now;
		}
		else {
			sh.at(now).live = false;
		}
	}
	//show();
	while (1) {
		//printf("man %d\n", man);
		man++;
		if (man > C)
			break;
		fishing();
		move_fish();
	}
	printf("%d\n", ans);

	return 0;
}