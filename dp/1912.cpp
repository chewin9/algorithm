#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	int ans = -1e9;
	int arr[100002];
	int dp[100002];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	dp[0] = arr[0];

	for (int i = 1; i < n; i++) {
		dp[i] = arr[i];
		if (dp[i] < dp[i - 1] + arr[i])
			dp[i] = dp[i - 1] + arr[i];
	}

	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);

	printf("%d\n", ans);

	return 0;
}