#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;


int N;
int arr[18][18];
int dp[18][18][3];
int ans = 0;
int main() {

	scanf("%d", &N);

	for (int i = 1; i < N+1; i++) {
		for (int j = 1; j < N+1; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	memset(dp, 0, sizeof(dp));

	dp[1][2][0] = 1;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 2; j < N + 1; j++) {
			if (arr[i][j] == 0)
				dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
			if (arr[i][j] == 0)
				dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
			if (arr[i][j] == 0 && arr[i - 1][j] == 0 && arr[i][j - 1] == 0)
				dp[i][j][2] += dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0] + dp[i - 1][j - 1][2];
		}
	}

	for (int i = 0; i < 3; i++) {
		ans += dp[N][N][i];
	}
	printf("%d\n", ans);


	return 0;
}