#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int, int>pii;

int R, C, T;
int arr[52][52];
int temp_arr[52][52];
vector<pii> air;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };
int ans = 0;

void spread(int ypos, int xpos) {
	int cnt = 0;
	int ny, nx;
	int now = arr[ypos][xpos];
	for (int i = 0; i < 4; i++) {
		ny = ypos + dy[i];
		nx = xpos + dx[i];
		if (ny <= 0 || ny > R || nx <= 0 || nx > C)
			continue;
		else if (arr[ny][nx] != -1){
			temp_arr[ny][nx] += (now / 5);
			cnt++;
		}
	}
	temp_arr[ypos][xpos] += (now - (now / 5)*cnt);
}
void copy_arr() {
	for (int i = 1; i < R + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			arr[i][j] = temp_arr[i][j];
		}
	}
}
void show() {
	printf("Show arr\n");
	for (int i = 1; i < R + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void up_air(int ypos, int xpos) {
	//printf("====1====\n\n");
	for (int i = xpos - 1; i > 0; i--) {
		if (i == 1)
			arr[ypos][i] = arr[ypos - 1][i];
		else {
			arr[ypos][i] = arr[ypos][i - 1];
		}
	}
	//show();
	//printf("====2====\n\n");
	for (int i = ypos - 1; i > 0; i--) {
		if (i == 1)
			arr[i][1] = arr[i][2];
		else {
			arr[i][1] = arr[i - 1][1];
		}
	}
	//show();
	//printf("====3====\n\n");
	for (int i = 2; i < C + 1; i++) {
		if (i == C)
			arr[1][i] = arr[2][i];
		else {
			arr[1][i] = arr[1][i + 1];
		}
	}
	//show();
	//printf("====4====\n\n");
	
	for (int i = 2; i < ypos + 1; i++) {
		if (i == ypos)
			arr[i][C] = arr[i][C - 1];
		else {
			arr[i][C] = arr[i + 1][C];
		}
	}
	//show();
	//printf("====5====\n\n");
	
	for (int i = C - 1; i > xpos; i--) {
		if ((i - 1) == xpos)
			arr[ypos][i] = 0;
		else {
			arr[ypos][i] = arr[ypos][i - 1];
		}
	}
	//show();
}

void down_air(int ypos, int xpos) {
	for (int i = xpos - 1; i > 0; i--) {
		if (i == 1)
			arr[ypos][i] = arr[ypos + 1][i];
		else
			arr[ypos][i] = arr[ypos][i - 1];
	}
	for (int i = ypos + 1; i < R + 1; i++) {
		if (i == R)
			arr[i][1] = arr[i][2];
		else
			arr[i][1] = arr[i + 1][1];
	}
	for (int i = 2; i < C + 1; i++) {
		if (i == C)
			arr[R][i] = arr[R - 1][i];
		else
			arr[R][i] = arr[R][i + 1];
	}
	for (int i = R - 1; i > ypos - 1; i--) {
		if (i == ypos)
			arr[i][C] = arr[i][C - 1];
		else
			arr[i][C] = arr[i - 1][C];
	}
	for (int i = C - 1; i > xpos; i--) {
		if ((i - 1) == xpos)
			arr[ypos][i] = 0;
		else {
			arr[ypos][i] = arr[ypos][i - 1];
		}
	}
}
int main() {

	scanf("%d %d %d", &R, &C, &T);

	for (int i = 1; i < R + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == -1)
				air.push_back({ i,j });
		}
	}

	while (T--) {

		for (int i = 1; i < R + 1; i++) {
			for (int j = 1; j < C + 1; j++) {
				if (arr[i][j] != 0 && arr[i][j] != -1)
					spread(i, j);
				if (arr[i][j] == -1)
					temp_arr[i][j] = -1;
			}
		}
		copy_arr();											//먼지 확산
		up_air(air.at(0).first, air.at(0).second);
		down_air(air.at(1).first, air.at(1).second);
		memset(temp_arr, 0, sizeof(temp_arr));
	}

	for (int i = 1; i < R + 1; i++)
		for (int j = 1; j < C + 1; j++)
			ans += arr[i][j];

	printf("%d\n", ans+2);
	return 0;
}