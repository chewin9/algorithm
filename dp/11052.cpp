#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	int arr[1002];
	int dp[1002];
	int ans = -1e9;

	scanf("%d", &n);

	for (int i = 1; i < n + 1; i++)
		scanf("%d", &arr[i]);

	dp[0] = 0;

	for (int i = 1; i < n + 1; i++) {
		dp[i] = arr[i];
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		}
	}
	for (int i = 1; i < n + 1; i++)
		ans = max(ans, dp[i]);

	printf("%d\n", ans);


	return 0;
}