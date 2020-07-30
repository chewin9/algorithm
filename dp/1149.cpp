#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int dp[1002][3];
	int arr[1002][3];
	int n;
	int ans = 1e9;

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) 
		scanf_s("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}
	
	for (int i = 0; i < 3; i++)
		ans = min(ans, dp[n-1][i]);

	printf("%d \n", ans);


	return 0;
}