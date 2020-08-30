#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;

typedef struct Dice {
	int d0, d1, d2, d3, d4, d5;
}Dice;

int N, M;
int arr[22][22];
int Sy,Sx, K;
Dice dice;
vector<int> v;

const int dy[] = { 0,0,0,-1,1 };
const int dx[] = { 0,1,-1,0,0 };

void dice_move(int dir) {

	int t0, t1, t2, t3, t4, t5;
	t0 = dice.d0;
	t1 = dice.d1;
	t2 = dice.d2;
	t3 = dice.d3;
	t4 = dice.d4;
	t5 = dice.d5;

	switch (dir) {
	case 1:
		dice.d0 = t0;
		dice.d1 = t2;
		dice.d2 = t3;
		dice.d3 = t5;
		dice.d4 = t4;
		dice.d5 = t1;
		break;
	case 2:
		dice.d0 = t0;
		dice.d1 = t5;
		dice.d2 = t1;
		dice.d3 = t2;
		dice.d4 = t4;
		dice.d5 = t3;
		break;
	case 3:
		dice.d0 = t5;
		dice.d1 = t1;
		dice.d2 = t0;
		dice.d3 = t3;
		dice.d4 = t2;
		dice.d5 = t4;
		break;
	case 4:
		dice.d0 = t2;
		dice.d1 = t1;
		dice.d2 = t4;
		dice.d3 = t3;
		dice.d4 = t5;
		dice.d5 = t0;
		break;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	scanf("%d %d", &Sy, &Sx);
	scanf("%d", &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int a;
	for (int i = 0; i < K; i++) {
		scanf("%d", &a);
		v.push_back(a);
	}


	int ny, nx;
	for (int i = 0; i < K; i++) {
		ny = Sy + dy[v.at(i)];
		nx = Sx + dx[v.at(i)];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;
		else {
			Sy = ny;
			Sx = nx;
			dice_move(v.at(i));
			if (arr[ny][nx] == 0) {
				arr[ny][nx] = dice.d2;
			}
			else if (arr[ny][nx] != 0) {
				dice.d2 = arr[ny][nx];
				arr[ny][nx] = 0;
			}
			printf("%d\n", dice.d5);
		}
	}

}