#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	int dp[100002];
	int arr[100002];

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(max(dp[i - 1], dp[i - 2] + arr[i]), max(dp[i - 1], dp[i - 3] + arr[i - 1] + arr[i]));
	}
	printf("%d\n", dp[n]);

	return 0;
}