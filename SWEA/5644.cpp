#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>

using namespace std;

typedef struct Ap {
	int ypos;
	int xpos;
	int dist;
	int power;
}Ap;
typedef struct Man {
	int ypos;
	int xpos;
}Man;

int T, A, M,C;
int arr[3][102];
Ap ap[10];
Man man[3];
const int dy[] = { 0,-1,0,1,0 };
const int dx[] = { 0,0,1,0,-1 };
bool man_ap[3][10];
int cho[3];
int ans[102];
void dfs(int goal, int cnt, int pos) {
	if (goal == cnt) {
		int tmp = 0;
		if (man_ap[1][cho[1]] == true && man_ap[2][cho[2]] == true && cho[1] == cho[2]) {
			tmp = ap[cho[1]].power;
		}
		else {
			if (man_ap[1][cho[1]] == true)
				tmp += ap[cho[1]].power;
			if (man_ap[2][cho[2]] == true)
				tmp += ap[cho[2]].power;
		}

		ans[pos] = max(tmp, ans[pos]);

		return;
	}
	for (int i = 1; i < A + 1; i++) {
		cho[cnt] = i;
		dfs(goal, cnt + 1, pos);
	}
}
void set_data(int pos) {
	memset(man_ap, false, sizeof(man_ap));
	for (int i = 1; i < 3; i++) {
		int tmp_ypos, tmp_xpos;
		tmp_ypos = man[i].ypos;
		tmp_xpos = man[i].xpos;
		for (int j = 1; j < A + 1; j++) {
			int tmp = 0;
			tmp = abs(tmp_ypos - ap[j].ypos) + abs(tmp_xpos - ap[j].xpos);
			if (tmp <= ap[j].dist) {
				man_ap[i][j] = true;
			}
		}
	}
}

void man_move(int pos) {
	for (int i = 1; i < 3; i++) {
		man[i].ypos += dy[arr[i][pos]];
		man[i].xpos += dx[arr[i][pos]];
	}
}

void solve() {
	for (int i = 0; i < M + 1; i++) {
		//bool check = false;
		man_move(i);					//ÀÌµ¿ÇÔ
		/*printf("\n%d=======================\n",i);
		printf("man1 = {%d %d}, man2 = {%d %d}\n", man[1].ypos, man[1].xpos, man[2].ypos, man[2].xpos);
*/
		set_data(i);

		/*for (int i = 1; i < 3; i++) {
			for (int j = 1; j < A + 1; j++)
				printf("%d ", man_ap[i][j]);
			printf("\n");
		}
		printf("\n");*/
		dfs(3, 1,i);
	}
}
int main() {

	freopen("sample_input.txt", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t < T + 1; t++) {
		memset(arr, 0, sizeof(arr));
		memset(ans, 0, sizeof(ans));
		scanf("%d %d", &M, &A);


		arr[1][0] = 0;
		arr[2][0] = 0;
		for (int i = 1; i < 3; i++) {
			for (int j = 1; j < M+1; j++) {
				scanf("%d", &arr[i][j]);			//man1, man2
			}
		}
		int y, x, c, p;
		for (int i = 1; i < A + 1; i++) {
			scanf("%d %d %d %d", &x, &y, &c, &p);
			ap[i].ypos = y;
			ap[i].xpos = x;
			ap[i].dist = c;
			ap[i].power = p;
		}

		man[1].ypos = 1;
		man[1].xpos = 1;
		man[2].ypos = 10;
		man[2].xpos = 10;

		solve();
		/*for (int i = 0; i < M + 1; i++) {
			printf("%d => ", ans[i]);
		}*/
		int tmp = 0;
		for (int i = 0; i < M + 1; i++) {
			tmp += ans[i];
		}
		printf("#%d %d\n", t, tmp);

	}

	return 0;
}