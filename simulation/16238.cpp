#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;

typedef pair<int, int> pii;
queue<pii> q;

int N, M, G;
int arr[22][22];
bool visit[22][22];
vector<pii> order;
vector<pii> dest;
int Sy, Sx, Pnum;
bool check = true;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

bool find_dest(int ypos, int xpos) {
	visit[ypos][xpos] = true;
	q.push({ ypos,xpos });
	G++;
	int cnt = -1;
	bool b_dest = false;

	while (!q.empty()) {
		int size = q.size();
		int ny, nx;
		G--;
		cnt++;
		if (G < 0) {
			check = false;
			b_dest = false;
			return b_dest;
		}

		for (int s = 0; s < size; s++) {
			pii now = q.front();
			q.pop();
			
			if (now.first == dest.at(Pnum).first && now.second == dest.at(Pnum).second) {
				Sy = now.first;
				Sx = now.second;
				G += (cnt * 2);
				b_dest = true;

				return b_dest;
			}
			for (int i = 0; i < 4; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > N || nx <= 0 || nx > N)
					continue;
				if (arr[ny][nx] != 500 && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
				/*if (ny == dest.at(Pnum).first && nx == dest.at(Pnum).second) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}*/
			}
		}
	}
	return b_dest;
}

bool find_pass(int ypos, int xpos) {
	visit[ypos][xpos] = true;
	q.push({ ypos,xpos });
	G++;

	bool b_pass = false;

	while (!q.empty()) {
		int size = q.size();
		int ny, nx;
		G--;
		if (G < 0) {
			check = false;
			b_pass = false;
			return b_pass;
		}

		for (int s = 0; s < size; s++) {
			pii now = q.front();
			q.pop();

			if (arr[now.first][now.second] != 0) {
				order.push_back({ now.first,now.second });

				for (int i = s; i < size - 1; i++) {
					now = q.front();
					q.pop();
					if (arr[now.first][now.second] != 0)
						order.push_back({ now.first,now.second });
				}

				sort(order.begin(), order.end());
				Sy = order.at(0).first;
				Sx = order.at(0).second;
				Pnum = arr[Sy][Sx];
				arr[Sy][Sx] = 0;

				order.clear();
				b_pass = true;
				
				return b_pass;
			}

			for (int i = 0; i < 4; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > N || nx <= 0 || nx > N)
					continue;
				if (arr[ny][nx] != 500 && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
		}
	}

	return b_pass;
}

void show() {
	printf("Show arr\n");
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main() {
	scanf("%d %d %d", &N, &M, &G);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0)
				arr[i][j] = 500;
		}
	}

	scanf("%d %d", &Sy, &Sx);

	int y1, x1, y2, x2;
	dest.push_back({ -1,-1 });
	for (int i = 1; i < M + 1; i++) {
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		arr[y1][x1] = i;
		dest.push_back({ y2,x2 });
	}
	
	//show();
	for (int i = 0; i < M; i++) {
		if (arr[Sy][Sx] == 0) {
			if (find_pass(Sy, Sx)) {
				while (!q.empty())
					q.pop();
				memset(visit, false, sizeof(visit));
				//printf("Passger: {%d %d}, G=%d, Pnum=%d\n", Sy, Sx, G, Pnum);

				if (find_dest(Sy, Sx)) {
					while (!q.empty())
						q.pop();
					memset(visit, false, sizeof(visit));
					//printf("Finish: {%d %d}, G=%d, Pnum=%d\n", Sy, Sx, G, Pnum);
				}
				else {
					check = false;
					break;
				}
			}
			else {
				check = false;
				break;
			}	
		}
		else {
			Pnum = arr[Sy][Sx];
			arr[Sy][Sx] = 0;

			if (find_dest(Sy, Sx)) {
				while (!q.empty())
					q.pop();
				memset(visit, false, sizeof(visit));
				//printf("Finish: {%d %d}, G=%d, Pnum=%d\n", Sy, Sx, G, Pnum);
			}
			else {
				check = false;
				break;
			}
		}
	}

	if (check)
		printf("%d\n", G);
	else
		printf("-1\n");

	return 0;
}