#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int N;
	int arr[1002];
	int dp[1002];
	int ans = -1e9;
	scanf("%d", &N);

	for (int i = N; i > 0; i--)
		scanf("%d", &arr[i]);

	dp[0] = 0;

	for (int i = 1; i < N+1; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
	}
	for (int i = 1; i < N + 1; i++)
		ans = max(ans, dp[i]);

	printf("%d\n", ans);
	return 0;
}