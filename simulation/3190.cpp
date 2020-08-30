#include<iostream>
#include<deque>
#include<vector>
#include<string.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
deque<pii> d;
vector<pic> v;

int N, L, K;
int arr[102][102];
int Sy, Sx;
int ans;
int dir = 3;
int n_cnt;
char n_dir;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

void check_dir() {
	int now = -1;
	char c;
	for (int i = 0; i < L; i++) {
		if (v.at(i).first == ans) {
			now = i;
			break;
		}
	}
	if (now == -1)
		return;
	else {
		c = v.at(now).second;
		if (c == 'D') {
			dir = (dir + 3) % 4;
		}
		else {
			dir = (dir + 1) % 4;
		}
		if(now+1<L)
			n_cnt = v.at(now + 1).first;

		return;
	}
}

void dfs(int ypos, int xpos) {
	ans++;
	int nx, ny;
	ny = ypos + dy[dir];
	nx = xpos + dx[dir];

	if (ny <= 0 || ny > N || nx <= 0 || nx > N || arr[ny][nx] == 0) 
		return;

	printf("sec=%d {%d %d}, {%d %d} \n", ans,ypos, xpos, ny, nx);
	//d.push_front({ ypos,xpos });
	//arr[ypos][xpos] = 0;
	d.push_front({ ny,nx });
	if (arr[ny][nx] != 1) {
		pii exit = d.back();
		d.pop_back();
		arr[exit.first][exit.second] = -1;
	}
	arr[ny][nx] = 0;

	if(n_cnt == ans)
		check_dir();

	dfs(ny, nx);
}

int main() {
	scanf("%d %d", &N, &K);
	memset(arr, -1, sizeof(arr));

	int a, b;
	char c;

	for (int i = 0; i< K; i++) {
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf("%d %c", &a, &c);
		v.push_back({ a,c });
	}

	Sy = 1, Sx = 1;

	n_cnt = v.at(0).first;
	d.push_front({ 1,1 });
	arr[1][1] = 0;
	dfs(Sy, Sx);

	printf("%d\n", ans);
	return 0;
}