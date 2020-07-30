#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int arr[17][2];
	int dp[17];
	int ans = -1e9;
	scanf("%d", &n);
	
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dp[0] = 0;

	for (int i = 1; i < n + 1; i++) {
		if (arr[i][0] + i > n + 1) {
			dp[i] = 0;
			continue;
		}
		dp[i] = arr[i][1];
		for (int j = 1; j < i; j++) {
			if (arr[j][0] + j <= i && dp[i] < dp[j] + arr[i][1])
				dp[i] = dp[j] + arr[i][1];
		}
	}

	for (int i = 1; i < n + 1; i++)
		ans = max(ans, dp[i]);

	printf("%d\n", ans);

	return 0;
}