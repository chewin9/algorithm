#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int n;
int arr[502][502];
int dp[502][502];

const int dx[] = { 0,1,0,-1 };
const int dy[] = { 1,0,-1,0 };

int dfs(int ypos, int xpos) {
	if (dp[ypos][xpos] != -1)
		return dp[ypos][xpos];

	if (ypos <= 0 || ypos > n || xpos <= 0 || xpos > n)
		return 0;
	
	dp[ypos][xpos] = 1;

	for (int i = 0; i < 4; i++) {
		if (arr[ypos][xpos] < arr[ypos + dy[i]][xpos + dx[i]])
			dp[ypos][xpos] = max(dp[ypos][xpos], dfs(ypos + dy[i], xpos + dx[i])+1);
	}

	return dp[ypos][xpos];

}


int main() {
	int ans = -1e9;

	scanf("%d", &n);

	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
			scanf("%d", &arr[i][j]);

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			ans = max(ans, dfs(i, j));
		}
	}

	printf("%d\n", ans);

	return 0;
}