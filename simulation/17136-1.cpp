#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int paper[6];
int arr[10][10];
int ans = 1e9;

bool can_attach(int ypos, int xpos, int cnt) {
	for (int i = ypos; i < ypos + cnt; i++) {
		for (int j = xpos; j < xpos + cnt; j++) {
			if (arr[i][j] == 0)
				return false;
		}
	}
	return true;
}
void attach(int ypos, int xpos, int cnt) {
	for (int i = ypos; i < ypos + cnt; i++) {
		for (int j = xpos; j < xpos + cnt; j++) {
			arr[i][j] = 0;
		}
	}
	paper[cnt]++;
}
void disattach(int ypos, int xpos, int cnt) {
	for (int i = ypos; i < ypos + cnt; i++) {
		for (int j = xpos; j < xpos + cnt; j++) {
			arr[i][j] = 1;
		}
	}
	paper[cnt]--;
}
void dfs(int ypos, int xpos, int cnt) {
	while (arr[ypos][xpos] == 0) {
		xpos++;
		if (xpos >= 10) {
			xpos = 0;
			ypos++;
			if (ypos >= 10) {
				ans = min(ans, cnt);
				return;
			}
		}

	}

	if (ans <= cnt)
		return;

	for (int i = 5; i > 0; i--) {
		if (ypos + i > 10 || xpos + i > 10 || paper[i] >= 5)
			continue;

		if (can_attach(ypos, xpos, i) == true) {
			attach(ypos, xpos, i);
			dfs(ypos, xpos, cnt + 1);
			disattach(ypos, xpos, i);
		}
	}
}
int main() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dfs(0, 0, 0);
	if (ans == 1e9)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}