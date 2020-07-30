#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int main() {
	int n, k;
	int arr[102];
	int dp[10002];

	scanf("%d %d", &n, &k);
	//memset(dp, k + 1, sizeof(dp));

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	dp[0] = 0;
	for (int i = 1; i < k + 1; i++)
		dp[i] = k + 1;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < k + 1; j++) {
			if (j - arr[i] >= 0)
				dp[j] = min(dp[j - arr[i]]+1, dp[j]);
		}
	}

	for (int i = 0; i < k + 1; i++) {
		printf("%d ", dp[i]);
	}

	printf("\n");

	if (dp[k] == k+1)
		printf("-1\n");
	else
		printf("%d", dp[k]);

	return 0;
}