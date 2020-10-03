#include<iostream>
#include<string>	
#include<algorithm>

using namespace std;

int arr[12][12];
int paper[6];
int ans = 1e9;

bool paper_check(int ypos, int xpos, int size) {
	for (int i = ypos; i < ypos + size; i++) {
		for (int j = xpos; j < xpos + size; j++) {
			if (arr[i][j] != 1)
				return false;
		}
	}
	return true;
}
void paper_atc(int ypos, int xpos, int size) {
	for (int i = ypos; i < ypos + size; i++) {
		for (int j = xpos; j < xpos + size; j++) {
			arr[i][j] = 0;
		}
	}
	paper[size]++;
}
void paper_dit(int ypos, int xpos, int size) {
	for (int i = ypos; i < ypos + size; i++) {
		for (int j = xpos; j < xpos + size; j++)
			arr[i][j] = 1;
	}
	paper[size]--;
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
		if (ypos + i > 10 || xpos + i > 10 || paper[i] == 5)
			continue;

		if (paper_check(ypos, xpos, i)) {
			paper_atc(ypos, xpos, i);
			dfs(ypos, xpos, cnt + 1);
			paper_dit(ypos, xpos, i);
		}
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dfs(0, 0,0);

	if (ans == 1e9)
		printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}