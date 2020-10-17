#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>


using namespace std;

typedef pair<int, int> pii;
queue <pii> q;
char arr[27][27];
int R, C;
int M_ypos, M_xpos, Z_ypos, Z_xpos;
int A_ypos, A_xpos;
bool visit[27][27];
char ans;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

void find_pos() {						
	memset(visit, false, sizeof(visit));

	visit[M_ypos][M_xpos] = true;
	q.push({ M_ypos, M_xpos });

	int ny, nx;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		char pos = arr[now.first][now.second];

		switch (pos) {
		case 'M':
			for (int i = 0; i < 4; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
			break;
		case '|':
			for (int i = 0; i < 4; i = i + 2) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;	
				}
				if (arr[ny][nx] == '.' && visit[ny][nx] == false) {
					while (!q.empty())
						q.pop();
					A_ypos = ny;
					A_xpos = nx;
				}
			}
			break;
		case '-':
			for (int i = 1; i < 4; i = i + 2) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
				if (arr[ny][nx] == '.' && visit[ny][nx] == false) {
					while (!q.empty())
						q.pop();
					A_ypos = ny;
					A_xpos = nx;
				}
			}
			break;
		case '+':
			for (int i = 0; i < 4; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
				if (arr[ny][nx] == '.' && visit[ny][nx] == false) {
					while (!q.empty())
						q.pop();
					A_ypos = ny;
					A_xpos = nx;
				}
			}
			break;
		case '1':
			for (int i = 2; i < 4; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
				if (arr[ny][nx] == '.' && visit[ny][nx] == false) {
					while (!q.empty())
						q.pop();
					A_ypos = ny;
					A_xpos = nx;
				}
			}
			break;
		case '2':
			for (int i = 0; i < 4; i = i + 3) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
				if (arr[ny][nx] == '.' && visit[ny][nx] == false) {
					while (!q.empty())
						q.pop();
					A_ypos = ny;
					A_xpos = nx;
				}
			}
			break;
		case '3':
			for (int i = 0; i < 2; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;

				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
				if (arr[ny][nx] == '.' && visit[ny][nx] == false) {
					while (!q.empty())
						q.pop();
					A_ypos = ny;
					A_xpos = nx;
				}
			}
			break;
		case '4':
			for (int i = 1; i < 3; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
				if (arr[ny][nx] == '.' && visit[ny][nx] == false) {
					while (!q.empty())
						q.pop();
					A_ypos = ny;
					A_xpos = nx;
				}
			}
			break;
		}
	}

}

bool check_link() {
	char now = arr[A_ypos][A_xpos];
	int ny, nx;
	char next;
	switch (now) {
	case '|':
		for (int i = 0; i < 4; i = i + 2) {
			ny = A_ypos + dy[i];
			nx = A_xpos + dx[i];
			if (ny <= 0 || ny > R || nx <= 0 || nx > C)
				return false;
			if (arr[ny][nx] == '.')
				return false;								//¹«Á¶°Ç ¾ÈµÊ

			if (i == 0) {
				if (arr[ny][nx] == '-' || arr[ny][nx] == '2' || arr[ny][nx] == '3')
					return false;
			}
			else if (i == 2) {
				if (arr[ny][nx] == '-' || arr[ny][nx] == '1' || arr[ny][nx] == '4')
					return false;
			}
		}
		return true;
		break;
	case '-':
		for (int i = 1; i < 4; i = i + 2) {
			ny = A_ypos + dy[i];
			nx = A_xpos + dx[i];
			if (ny <= 0 || ny > R || nx <= 0 || nx > C)
				return false;
			if (arr[ny][nx] == '.')
				return false;								//¹«Á¶°Ç ¾ÈµÊ

			if (i == 1) {
				if (arr[ny][nx] == '|' || arr[ny][nx] == '3' || arr[ny][nx] == '4')
					return false;
			}
			else if (i == 3) {
				if (arr[ny][nx] == '1' || arr[ny][nx] == '1' || arr[ny][nx] == '2')
					return false;
			}
		}
		return true;
		break;
	case '+':
		for (int i = 0; i < 4; i++) {
			ny = A_ypos + dy[i];
			nx = A_xpos + dx[i];
			if (ny <= 0 || ny > R || nx <= 0 || nx > C)
				return false;
			if (arr[ny][nx] == '.')
				return false;

			if (i == 0) {
				if (arr[ny][nx] == '-' || arr[ny][nx] == '2' || arr[ny][nx] == '3')
					return false;
			}
			else if (i == 1) {
				if (arr[ny][nx] == '|' || arr[ny][nx] == '3' || arr[ny][nx] == '4')
					return false;
			}
			else if (i == 2) {
				if (arr[ny][nx] == '-' || arr[ny][nx] == '1' || arr[ny][nx] == '4')
					return false;
			}
			else if (i == 3) {
				if (arr[ny][nx] == '|' || arr[ny][nx] == '1' || arr[ny][nx] == '2')
					return false;
			}
		}
		return true;
		break;
	case '1':
		for (int i = 2; i < 4; i++) {
			ny = A_ypos + dy[i];
			nx = A_xpos + dx[i];
			if (ny <= 0 || ny > R || nx <= 0 || nx > C)
				return false;
			if (arr[ny][nx] == '.')
				return false;								//¹«Á¶°Ç ¾ÈµÊ

			if (i == 2) {
				if (arr[ny][nx] == '-' || arr[ny][nx] == '1' || arr[ny][nx] == '4')
					return false;
			}
			else if (i == 3) {
				if (arr[ny][nx] == '|' || arr[ny][nx] == '1' || arr[ny][nx] == '2')
					return false;
			}
		}
		return true;
		break;
	case '2':
		for (int i = 0; i < 4; i = i+3) {
			ny = A_ypos + dy[i];
			nx = A_xpos + dx[i];
			if (ny <= 0 || ny > R || nx <= 0 || nx > C)
				return false;
			if (arr[ny][nx] == '.')
				return false;								//¹«Á¶°Ç ¾ÈµÊ

			if (i == 0) {
				if (arr[ny][nx] == '-' || arr[ny][nx] == '2' || arr[ny][nx] == '3')
					return false;
			}
			else if (i == 3) {
				if (arr[ny][nx] == '|' || arr[ny][nx] == '1' || arr[ny][nx] == '2')
					return false;
			}
		}
		return true;
		break;
	case '3':
		for (int i = 0; i < 2; i++) {
			ny = A_ypos + dy[i];
			nx = A_xpos + dx[i];
			if (ny <= 0 || ny > R || nx <= 0 || nx > C)
				return false;
			if (arr[ny][nx] == '.')
				return false;								//¹«Á¶°Ç ¾ÈµÊ

			if (i == 0) {
				if (arr[ny][nx] == '-' || arr[ny][nx] == '2' || arr[ny][nx] == '3')
					return false;
			}
			else if (i == 1) {
				if (arr[ny][nx] == '|' || arr[ny][nx] == '3' || arr[ny][nx] == '4')
					return false;
			}
		}
		return true;
		break;
	case '4':
		for (int i = 1; i < 3; i++) {
			ny = A_ypos + dy[i];
			nx = A_xpos + dx[i];
			if (ny <= 0 || ny > R || nx <= 0 || nx > C)
				return false;
			if (arr[ny][nx] == '.')
				return false;								//¹«Á¶°Ç ¾ÈµÊ

			if (i == 1) {
				if (arr[ny][nx] == '|' || arr[ny][nx] == '3' || arr[ny][nx] == '4')
					return false;
			}
			else if (i == 2) {
				if (arr[ny][nx] == '-' || arr[ny][nx] == '1' || arr[ny][nx] == '4')
					return false;
			}
		}
		return true;
		break;
	}
}

void bfs(int ypos, int xpos) {
	memset(visit, false, sizeof(visit));
	q.push({ ypos,xpos });
	visit[ypos][xpos] = true;

	int ny, nx;
	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		char pos = arr[now.first][now.second];

		switch (pos) {
		case 'M':
			for (int i = 0; i < 4; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
			break;
		case '|':
			for (int i = 0; i < 4; i = i + 2) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
			break;
		case '-':
			for (int i = 1; i < 4; i = i + 2) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
			break;
		case '+':
			for (int i = 0; i < 4; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
			break;
		case '1':
			for (int i = 2; i < 4; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
			break;
		case '2':
			for (int i = 0; i < 4; i = i + 3) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
			break;
		case '3':
			for (int i = 0; i < 2; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;

				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
			break;
		case '4':
			for (int i = 1; i < 3; i++) {
				ny = now.first + dy[i];
				nx = now.second + dx[i];

				if (ny <= 0 || ny > R || nx <= 0 || nx > C)
					continue;
				if (arr[ny][nx] != '.' && visit[ny][nx] == false) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
			break;
		}
	}
}
bool check_ans() {
	for (int i = 1; i < R + 1; i++) {
		for (int j = 1; j < C + 1; j++)
			if (arr[i][j] != '.' && visit[i][j] == false)
				return false;
	}
	return true;
}
int main() {
	scanf("%d %d ", &R, &C);

	for (int i = 1; i < R + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			scanf(" %1c", &arr[i][j]);
			if (arr[i][j] == 'M') {
				M_ypos = i;
				M_xpos = j;
			}
			if (arr[i][j] == 'Z') {
				Z_ypos = i;
				Z_xpos = j;
			}
		}
	}
	find_pos();
	char road[8] = { '|', '-','1','2','3','4','+' };
	for (int i = 0; i < 8; i++) {
		arr[A_ypos][A_xpos] = road[i];
		if (check_link()) {
			bfs(M_ypos, M_xpos);
			if (check_ans()) {
				ans = road[i];
				break;
			}
		}
	}

	printf("%d %d %c", A_ypos, A_xpos, ans);

	return 0;
}