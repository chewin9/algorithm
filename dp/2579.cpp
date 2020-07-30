#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int arr[302];
	int dp[302][2];
	int cnt;
	int ans = -1e9;

	scanf_s("%d", &cnt);
	for (int i = 1; i <= cnt; i++)
		scanf_s("%d", &arr[i]);

	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = arr[1];

	for (int i = 2; i <= cnt; i++) {
		dp[i][0] = dp[i - 1][1] + arr[i];
		dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + arr[i];
	}

	ans = max(dp[cnt][0], dp[cnt][1]);

	printf("%d \n", ans);


	return 0;

}