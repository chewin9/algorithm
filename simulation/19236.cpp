#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;
typedef struct Shark {
	int num;
	int dir;
}Shark;
Shark arr[4][4];
bool visit[18];
const int dy[] = { 0,-1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0,0,-1,-1,-1,0,1,1,1 };
vector <ppi> order;
Shark S;
int ans = -1e9;

void eat(int ypos, int xpos) {
	S = arr[ypos][xpos];
	visit[arr[ypos][xpos].num] = true;


}
void show() {
	printf("Show arr\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("{%d %d} ", arr[i][j].num, arr[i][j].dir);
		}
		printf("\n");
	}
	printf("\nShow order\n");
	for (int i = 0; i < 17; i++) {
		printf("{num: %d, dir:%d {%d %d}} ", order.at(i).first.first, order.at(i).first.second, order.at(i).second.first, order.at(i).second.second);
	}
	printf("\n\n");
}

void swap(int first, int second) {
	Shark temp = arr[order.at(first).second.first][order.at(first).second.second];
	arr[order.at(first).second.first][order.at(first).second.second] = arr[order.at(second).second.first][order.at(second).second.second];
	arr[order.at(second).second.first][order.at(second).second.second] = temp;
	
	pii tmp = order.at(first).first;
	order.at(first).first = order.at(second).first;
	order.at(second).first = tmp;

	sort(order.begin(), order.end());
}

void fish_move() {
	for (int i = 1; i < 17; i++) {
		//printf("%d move\n",i);
		if (visit[order.at(i).first.first] == false) {
			int count = 8;
			int now_ypos = order.at(i).second.first;
			int now_xpos = order.at(i).second.second;
			int now_dir = order.at(i).first.second;
			int ny, nx;
			while (count--) {
				ny = now_ypos + dy[now_dir];
				nx = now_xpos + dx[now_dir];
				if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || (order.at(S.num).second.first == ny && order.at(S.num).second.second == nx)) {
					now_dir = (now_dir + 1) % 9;
					if (now_dir == 0)
						now_dir = 1;
					continue;
				}
				else {
					order.at(i).first.second = now_dir;
					arr[now_ypos][now_xpos].dir = now_dir;
					int aa = arr[ny][nx].num;
					swap(i, aa);
					break;
				}
			}
		}
		//show();
	}
}

void dfs(int ypos, int xpos, int cnt) {
	Shark copy_arr[4][4];
	vector<ppi> copy_order;
	Shark copy_S;
	
	eat(ypos, xpos);
	copy_S = S;			//상어 상태 저장

	ans = max(ans, cnt + arr[ypos][xpos].num);

	fish_move();		//물고기 이동


	//printf("Shark: %d %d {%d %d}\n", S.num, S.dir, order.at(S.num).second.first, order.at(S.num).second.second);
	//show();

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			copy_arr[i][j] = arr[i][j];		//이전상태 저장

	for (int i = 0; i < 17; i++)
		copy_order.push_back(order.at(i));	//이전 물고기 상태 저장

	for (int t = 1; t < 4; t++) {
		int ny, nx;
		
		ny = order.at(S.num).second.first + dy[S.dir] * t;
		nx = order.at(S.num).second.second + dx[S.dir] * t;

		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
			continue;
		if (visit[arr[ny][nx].num] == false) {
			dfs(ny, nx, cnt + S.num);

			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					arr[i][j] = copy_arr[i][j];		//복구

			order.clear();
			for (int i = 0; i < 17; i++)
				order.push_back(copy_order.at(i));	//복구
			visit[arr[ny][nx].num] = false;
			S = copy_S;
			//printf("Back\n");
		}
	}
}

int main() {
	order.push_back({{ 0,0 }, { -1,-1 }});

	int a, b;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d %d", &a, &b);
			arr[i][j].num = a;
			arr[i][j].dir = b;
			order.push_back({ {a,b},{i,j} });
		}
	}
	sort(order.begin(), order.end());
	//show();
	eat(0, 0);

	dfs(0, 0, 0);

	printf("%d\n", ans);

	return 0;

}