#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;


typedef struct Hang {
	int ypos;
	int xpos;
	int dir;
	int mass;
	int speed;
	bool live;
}Hang;

int N, M, K;
vector<Hang> h;
vector<int> arr[52][52];
int ans = 0;
const int dy[] = { -1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0,1,1,1,0,-1,-1,-1 };

void div_hang(int ypos, int xpos) {
	int total_mass = 0;
	int total_speed = 0;
	int dir_odd = 0;
	int dir_even = 0;

	for (int i = 0; i < arr[ypos][xpos].size(); i++) {
		int now = arr[ypos][xpos].at(i);

		total_mass += h.at(now).mass;
		total_speed += h.at(now).speed;
		if (h.at(now).dir % 2 == 0)
			dir_even++;
		else
			dir_odd++;
		h.at(now).live = false;
	}

	int div_mass, div_speed;
	div_mass = total_mass / 5;
	div_speed = total_speed / arr[ypos][xpos].size();
	Hang tmp;
	if (div_mass != 0) {
		if (dir_odd == 0 || dir_even == 0) {		//»óÇÏÁÂ¿ì
			for (int i = 0; i < 8; i = i + 2) {
				tmp.ypos = ypos;
				tmp.xpos = xpos;
				tmp.mass = div_mass;
				tmp.speed = div_speed;
				tmp.dir = i;
				tmp.live = true;
				h.push_back(tmp);
			}
		}
		else {
			for (int i = 1; i < 8; i = i + 2) {
				tmp.ypos = ypos;
				tmp.xpos = xpos;
				tmp.mass = div_mass;
				tmp.speed = div_speed;
				tmp.dir = i;
				tmp.live = true;
				h.push_back(tmp);
			}
		}
	}
}

void check_crush() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (arr[i][j].size() > 1)
				div_hang(i,j);
		}
	}
	vector<Hang> tmp;

	for (int i = 0; i < h.size(); i++) {
		if (h.at(i).live == true)
			tmp.push_back(h.at(i));
	}
	h.clear();
	for (int i = 0; i < tmp.size(); i++) {
		h.push_back(tmp.at(i));
	}
}

void move_hang() {
	memset(arr, 0, sizeof(arr));
	for (int s = 0; s < h.size(); s++) {
		int ypos, xpos, dir, speed;

		ypos = h.at(s).ypos;
		xpos = h.at(s).xpos;
		dir = h.at(s).dir;
		speed = h.at(s).speed;
		speed = speed % N;

		int ny, nx;
		ny = ypos;
		nx = xpos;
		for (int i = 0; i < speed; i++) {
			ny = ny + dy[dir];
			nx = nx + dx[dir];

			if (ny <= 0)
				ny = N;
			if (ny > N)
				ny = 1;
			if (nx <= 0)
				nx = N;
			if (nx > N)
				nx = 1;
		}
		h.at(s).ypos = ny;
		h.at(s).xpos = nx;
		arr[h.at(s).ypos][h.at(s).xpos].push_back(s);
	}
}

void get_ans() {
	for (int i = 0; i < h.size(); i++) {
		ans += h.at(i).mass;
	}
}

void show() {
	printf("\nShow Hang\n");
	for (int i = 0; i < h.size(); i++) {
		printf("num = %d, {%d %d}, dir = %d, mass =%d, speed =%d\n",
			i, h.at(i).ypos, h.at(i).xpos, h.at(i).dir, h.at(i).mass, h.at(i).speed);
	}
}
int main() {

	scanf("%d %d %d", &N, &M, &K);
	Hang tmp;
	int a, b, c, d, e;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
		tmp.ypos = a;
		tmp.xpos = b;
		tmp.mass = c;
		tmp.speed = d;
		tmp.dir = e;
		tmp.live = true;
		arr[a][b].push_back(i);
		h.push_back(tmp);
	}

	while (K--) {
		//show();
		move_hang();
		check_crush();
	}
	//show();
	get_ans();
	printf("%d\n", ans);
	return 0;
}