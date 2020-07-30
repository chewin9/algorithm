#include<iostream>

using namespace std;

#define INF 9901

int N;
int dp[100002][3];

int main() {
	int ans = 0;
	scanf("%d", &N);

	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	for (int i = 2; i < N + 1; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % INF;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % INF;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % INF;
	}

	ans = (dp[N][0] + dp[N][1] + dp[N][2]) % INF;

	printf("%d\n", ans);

	return 0;
}