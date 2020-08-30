#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;
typedef pair<int, pii> ipi;
vector<ppi> v;
vector<ppi> tmp;
queue<ipi> q;
int arr[10][10];
int copy_arr[10][10];
int N, M;
int ans = 1e9;
int v_size;
int cctv[10];

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

void tmp_find() {
	int size = tmp.size();

	for (int s = 0; s < size; s++) {
		ppi now = tmp.at(s);
		
		for (int i = 0; i < 4; i++) {
			q.push({ i,{now.second.first, now.second.second} });
		}
		while (!q.empty()) {
			ipi aa = q.front();
			q.pop();

			int ny = aa.second.first + dy[aa.first];
			int nx = aa.second.second + dx[aa.first];
			
			if (ny <= 0 || ny > N || nx <= 0 || nx > M)
				continue;
			
			if (arr[ny][nx] != 6) {
				q.push({ aa.first, {ny,nx} });
				arr[ny][nx] = 7;
			}
		}
	}
}


void show() {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
	printf("==================\n");
}

void get_arr() {
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++)
			arr[i][j] = copy_arr[i][j];
}

void cctv_find() {

	for (int i = 0; i < v_size; i++) {
		int ypos, xpos, c_dir, c_num;
		c_num = v.at(i).first.first;
		c_dir = v.at(i).first.second;
		ypos = v.at(i).second.first;
		xpos = v.at(i).second.second;

		int put_dir;
		switch (c_num) {
		case 1:
			put_dir = (c_dir + cctv[i]) % 4;
			q.push({ put_dir, {ypos,xpos} });
			break;
		case 2:
			put_dir = (c_dir + cctv[i]) % 4;
			q.push({ put_dir, {ypos,xpos} });
			put_dir = (put_dir + 2) % 4;
			q.push({ put_dir, {ypos,xpos} });
			break;
		case 3:
			put_dir = (c_dir + cctv[i]) % 4;
			q.push({ put_dir, {ypos,xpos} });
			put_dir = (put_dir + 3) % 4;
			q.push({ put_dir, {ypos,xpos} });
			break;
		case 4:
			put_dir = (c_dir + cctv[i]) % 4;
			q.push({ put_dir, {ypos,xpos} });
			put_dir = (put_dir + 1) % 4;
			q.push({ put_dir, {ypos,xpos} });
			put_dir = (put_dir + 2) % 4;
			q.push({ put_dir, {ypos,xpos} });
			break;
		}
	}

	while (!q.empty()) {
		ipi now = q.front();
		q.pop();

		int ny, nx;
		ny = now.second.first + dy[now.first];
		nx = now.second.second + dx[now.first];

		if (ny <= 0 || ny > N || nx <= 0 || nx > M)
			continue;
		if (arr[ny][nx] != 6) {
			q.push({ now.first, {ny,nx} });
			arr[ny][nx] = 7;
		}
	}
}

void get_ans() {
	int cnt = 0;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			if (arr[i][j] == 0)
				cnt++;
		}
	}
	ans = min(ans, cnt);
}
void dfs(int pos, int cnt) {
	if (cnt == v_size) {
		get_arr();
		cctv_find();
		get_ans();
		//show();
		return;
	}
	for (int i = 0; i < 4; i++) {
		cctv[pos] = i;
		dfs(pos + 1, cnt + 1);
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0 && arr[i][j] != 6 && arr[i][j] != 5)
				v.push_back({ { arr[i][j],0 }, { i,j } });
			else if (arr[i][j] == 5) {
				tmp.push_back({ {arr[i][j],0} , {i,j} });
			}
		}
	}
	
	tmp_find();
	
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++)
			copy_arr[i][j] = arr[i][j];
	
	//show();

	v_size = v.size();

	dfs(0, 0);
	
	printf("%d\n", ans);
	return 0;
}