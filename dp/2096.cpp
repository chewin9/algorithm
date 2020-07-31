#include<iostream>
#include<algorithm>
#include<string.h>	

using namespace std;

int n;
int cost[3];
int max_dp[2][3];
int min_dp[2][3];

int main() {
	scanf("%d", &n);

	int max_ans = -1e9;
	int min_ans = 1e9;

	memset(max_dp, 0, sizeof(max_dp));
	memset(min_dp, 0, sizeof(min_dp));

	for (int i = 1; i < n + 1; i++) {
		scanf("%d %d %d", &cost[0], &cost[1], &cost[2]);

		max_dp[1][0] = max(max_dp[0][0], max_dp[0][1]) + cost[0];
		max_dp[1][1] = max(max(max_dp[0][0], max_dp[0][1]), max_dp[0][2]) + cost[1];
		max_dp[1][2] = max(max_dp[0][1], max_dp[0][2]) + cost[2];

		min_dp[1][0] = min(min_dp[0][0], min_dp[0][1]) + cost[0];
		min_dp[1][1] = min(min(min_dp[0][0], min_dp[0][1]), min_dp[0][2]) + cost[1];
		min_dp[1][2] = min(min_dp[0][1], min_dp[0][2]) + cost[2];

		max_dp[0][0] = max_dp[1][0];
		max_dp[0][1] = max_dp[1][1];
		max_dp[0][2] = max_dp[1][2];

		min_dp[0][0] = min_dp[1][0];
		min_dp[0][1] = min_dp[1][1];
		min_dp[0][2] = min_dp[1][2];
	}

	for (int i = 0; i < 3; i++) {
		max_ans = max(max_ans, max_dp[0][i]);
		min_ans = min(min_ans, min_dp[0][i]);
	}

	printf("%d %d\n", max_ans, min_ans);

	return 0;
}