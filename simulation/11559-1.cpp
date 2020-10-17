#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>	
using namespace std;

typedef pair<int, int> pii;
queue<pii> q;
char arr[12][6];
int ans = 0;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
bool check = false;
bool visit[12][6];


void link_check(int ypos, int xpos) {
	char tmp = arr[ypos][xpos];
	memset(visit, false, sizeof(visit));

	q.push({ ypos,xpos });
	visit[ypos][xpos] = true;

	int ny, nx;
	vector<pii> v;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		v.push_back({ now.first,now.second });

		for (int i = 0; i < 4; i++) {
			ny = now.first + dy[i];
			nx = now.second + dx[i];

			if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6)
				continue;
			if (arr[ny][nx] == tmp && visit[ny][nx] == false) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
	}
	if (v.size() >= 4) {
		for (int i = 0; i < v.size(); i++) {
			arr[v.at(i).first][v.at(i).second] = '.';
		}
		//v.clear();
		check = true;
	}
	v.clear();
}

void check_block() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] != '.') {
				link_check(i, j);
			}
		}
	}
}

void gravity() {
	for (int k = 0; k < 6; k++) {
		for (int i = 10; i >= 0; i--) {
			for (int j = 11; j > i; j--) {
				if (arr[j][k] == '.' && arr[i][k] != '.') {
					arr[j][k] = arr[i][k];
					arr[i][k] = '.';
					break;
				}
			}
		}
	}
}

void show() {
	printf("Show ARR\n");
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%1c", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			scanf(" %1c", &arr[i][j]);
		}
	}

	while (1) {
		check = false;
		check_block();
		if (check == false)
			break;
		ans++;
		gravity();
		//show();
	}
	printf("%d\n", ans);

	return 0;
}