#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

typedef pair<int, int> pii;
vector<pii> v;
int arr[15][8];
bool visit[15][8];
bool clear[15][8];
int ans;
const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };
bool pang = false;
bool check = false;
int cnt = 1;

void dfs(int ypos, int xpos, int val) {
	visit[ypos][xpos] = true;

	v.push_back({ ypos,xpos });

	for (int i = 0; i < 4; i++) {
		int ny = ypos + dy[i];
		int nx = xpos + dx[i];

		if (ny <= 0 || ny > 12 || nx <= 0 || nx > 6)
			continue;
		if (arr[ny][nx] == val && visit[ny][nx] == false) {
			dfs(ny, nx, val);
		}
	}
}


void show() {
	for (int i = 1; i < 13; i++) {
		for (int j = 1; j < 7; j++)
			printf("%d", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}

void show_clear() {
	for (int i = 1; i < 13; i++) {
		for (int j = 1; j < 7; j++)
			printf("%d", clear[i][j]);
		printf("\n");
	}
	printf("\n");
}

void getArr() {
	for (int i = 1; i < 13; i++) {
		for (int j = 1; j < 7; j++) {
			if (clear[i][j] == true) {
				arr[i][j] = 0;
			}
		}
	}
}

void getGravity() {
	for (int j = 1; j < 7; j++) {
		for (int i = 11; i > 0; i--) {
			for (int k = 12; k > i; k--) {
				if (arr[i][j] != 0 && arr[k][j] == 0) {
					arr[k][j] = arr[i][j];
					arr[i][j] = 0;
					break;
				}
			}
		}
	}
}

int main() {
	char c;
	for (int i = 1; i < 13; i++) {
		for (int j = 1; j < 7; j++) {
			scanf(" %1c", &c);
			if (c == '.')
				arr[i][j] = 0;
			else if (c == 'R')
				arr[i][j] = 1;
			else if (c == 'G')
				arr[i][j] = 2;
			else if (c == 'B')
				arr[i][j] = 3;
			else if (c == 'P')
				arr[i][j] = 4;
			else
				arr[i][j] = 5;
		}
	}

	//show();

	while (1) {
		for (int i = 1; i < 13; i++) {
			for (int j = 1; j < 7; j++) {
				if (visit[i][j] == 0 && arr[i][j] != 0) {
					dfs(i, j, arr[i][j]);
					int v_size = v.size();
					if (v_size >= 4) {
						for (int i = 0; i < v_size; i++) {
							clear[v.at(i).first][v.at(i).second] = true;
						}
						check = true;
					}
					v.clear();
				}
			}
		}
		//show_clear();
		if (check == true) {
			ans += 1;
			getArr();
			getGravity();
			//show();
			check = false;
		}
		else {
			break;
		}

		memset(visit, false, sizeof(visit));
		memset(clear, false, sizeof(clear));
	}

	printf("%d\n", ans);
	//show_clear();

	return 0;
}