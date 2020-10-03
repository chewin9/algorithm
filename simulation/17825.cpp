#include<iostream>
#include<algorithm>
#include<string.h>


using namespace std;

int arr[11];
int hor[5];
int dice[11];
bool visit[33];
int ans = -1e9;

int jump[33][6] = {
	{0,1,2,3,4,5},		//index 0
	{2,2,3,4,5,6},
	{4,3,4,5,6,7},
	{6,4,5,6,7,8},
	{8,5,6,7,8,9},
	{10,21,22,23,24,30},	//index 5
	{12,7,8,9,10,11},
	{14,8,9,10,11,12},
	{16,9,10,11,12,13},
	{18,10,11,12,13,14},
	{20,25,26,24,30,31},	//index 10
	{22,12,13,14,15,16},
	{24,13,14,15,16,17},
	{26,14,15,16,17,18},
	{28,15,16,17,18,19},
	{30,27,28,29,24,30},	//index15
	{32,17,18,19,20,32},
	{34,18,19,20,32,32},
	{36,19,20,32,32,32},
	{38,20,32,32,32,32},
	{40,32,32,32,32,32}, //index20
	{13,22,23,24,30,31},
	{16,23,24,30,31,20},
	{19,24,30,31,20,32},
	{25,30,31,20,32,32},
	{22,26,24,30,31,20},	//indxe25
	{24,24,30,31,20,32},
	{28,28,29,24,30,31},
	{27,29,24,30,31,20},
	{26,24,30,31,20,32},
	{30,31,20,32,32,32}, //index30
	{35,20,32,32,32,32},
	{0,32,32,32,32,32}	//µµÂø
};

void go_move() {
	int tmp = 0;
	for (int i = 1; i < 11; i++) {
		int now = dice[i];
		int now_pos = hor[now];
		int next_pos = jump[now_pos][arr[i]];

		if (visit[next_pos] == true && next_pos != 32) {
			return;
		}
		else {
			visit[now_pos] = false;
			visit[next_pos] = true;
			hor[now] = next_pos;
			tmp += jump[next_pos][0];
		}
	}
	ans = max(tmp, ans);
}

void dfs(int pos,  int cnt) {
	dice[cnt] = pos;

	if (cnt == 10) {

		/*for (int i = 1; i < 11; i++) {
			printf("%2d", dice[i]);
		}
		printf("\n");*/
		memset(hor, 0, sizeof(hor));
		memset(visit, false, sizeof(visit));
		go_move();
		return;
	}
	for (int i = 1; i < 5; i++) {
		dfs(i, cnt + 1);
	}
}

int main() {
	for (int i = 1; i < 11; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i < 5; i++) {
		dfs(i, 1);
	}
	printf("%d\n", ans);
}