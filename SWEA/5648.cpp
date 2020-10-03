#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

typedef struct Atom {
	int ypos;
	int xpos;
	int dir;
	int power;
	bool live;
}Atom;

int arr[4002][4002];
Atom atom[1002];
int T, N;
int die = 0;
const int dy[] = { 1,-1,0,0 };
const int dx[] = { 0,0,-1,1 };

void move() {

}
int main() {

	freopen("sample_input", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t < T + 1; t++) {
		die = 0;
		memset(arr, 0, sizeof(arr));
		scanf("%d", &N);

		int x, y, d, p;
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d %d", &x, &y, &d, &p);

			atom[i].xpos = (x + 1000) * 2;
			atom[i].ypos = (y + 1000) * 2;
			atom[i].dir = d;
			atom[i].power = p;
			atom[i].live = true;

			arr[(y + 1000) * 2][(x + 1000) * 2] = 1;
		}

		while (1) {
			if (die == N)
				break;
			for (int i = 0; i < N; i++) {
				if (atom[i].live == true) {
					int ny, nx;
					ny = atom[i].ypos + dy[atom[i].dir];
					nx = atom[i].xpos + dx[atom[i].dir];
					if (ny > 4000 || ny < 0 || nx>4000 || nx < 0) {
						arr[atom[i].ypos][atom[i].xpos] -= 1;
						atom[i].live = true;
						die++;
					}
					arr[atom[i].ypos][atom[i].xpos] -= 1;
					arr[ny][nx] += 1;
					atom[i].ypos = ny;
					atom[i].xpos = nx;
				}
			}

			for (int i = 0; i < N; i++) {
				if (atom[i].live == true) {
					if (arr[atom[i].ypos][atom[i].xpos] >= 2) {
						for (int j = i; i < N; i++) {
							if (atom[i].ypos == atom[j].ypos && atom[i].xpos == atom[j].xpos && atom[j].live == true) {
								arr[atom[j].ypos][atom[j].xpos] -= 1;
								atom[j].live = false;
								die++;
							}
						}
						arr[atom[i].ypos][atom[i].xpos] -= 1;
						atom[i].live = false;
						die++;
					}
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < N + 1; i++) {
			if (atom[i].live == false)
				ans += atom[i].power;
		}
		printf("#%d %d\n", t, ans);

	}




	return 0;
}