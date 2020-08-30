#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

const int dy[] = { 0,-1,0,1 };
const int dx[] = { 1,0,-1,0 };
int arr[102][102];
int N, ypos, xpos;
int dir, g;

typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;

vector<pii>v;
vector<ppi> dra;

int ans=0;

int get_dir(int y1, int x1) {
	if (y1 == 0 && x1 == 1) {
		return 1;
	}
	else if (y1 == -1 && x1 == 0)
		return 2;
	else if (y1 == 0 && x1 == -1)
		return 3;
	else
		return 0;
}

void cuv(int ypos, int xpos, int dir, int gernal) {
	arr[ypos][xpos] = true;
	v.push_back({ ypos,xpos });
	
	int ny, nx;
	ny = ypos + dy[dir];
	nx = xpos + dx[dir];
	if (ny < 0 || ny>100 || nx < 0 || nx>100)
		return;
	v.push_back({ ny,nx });
	arr[ny][nx] = true;

	while (gernal--) {
		int size = v.size();
		pii stand = v.at(size - 1);
		int stand_ypos, stand_xpos;
		stand_ypos = stand.first;
		stand_xpos = stand.second;

		for (int s = size - 1; s > 0; s--) {
			pii now = v.at(s);
			pii pre = v.at(s - 1);
			int now_ypos, now_xpos;
			int pre_ypos, pre_xpos;
			int use_dir;

			now_ypos = now.first;
			now_xpos = now.second;
			pre_ypos = pre.first;
			pre_xpos = pre.second;

			use_dir = get_dir(now_ypos - pre_ypos, now_xpos - pre_xpos);

			int next_ypos, next_xpos;

			next_ypos = stand_ypos + dy[use_dir];
			next_xpos = stand_xpos + dx[use_dir];

			if (next_ypos < 0 || next_ypos > 100 || next_xpos < 0 || next_xpos > 100)
				continue;
			else {
				v.push_back({ next_ypos,next_xpos });
				arr[next_ypos][next_xpos] = true;
				stand_ypos = next_ypos;
				stand_xpos = next_xpos;
			}
		}
	}
}

void show() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {

	scanf("%d", &N);
	int a, b, c, d;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		dra.push_back({ {b,a},{c,d} });
	}

	for (int i = 0; i < N; i++) {
		cuv(dra.at(i).first.first, dra.at(i).first.second, dra.at(i).second.first, dra.at(i).second.second);
		
		//printf("Start {%d %d}\n", dra.at(i).first.first, dra.at(i).first.second);
		
		int v_size = v.size();

		/*for (int j = 0; j < v_size; j++) {
			printf("{%d %d}=>", v.at(j).first, v.at(j).second);
		}
		printf("\n");*/
		v.clear();
	}

	//show();

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j] == true) {
				if (arr[i + 1][j] == true && arr[i][j + 1] == true && arr[i + 1][j + 1] == true)
					ans++;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}