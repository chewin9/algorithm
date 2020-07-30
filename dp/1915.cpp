#include<iostream>
#include<algorithm>

using namespace std;

int arr[1002][1002];
int dp[1002][1002];
int n, m;
int ans = -1e9;

int main() {
	
	scanf("%d %d", &n, &m);

	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < m + 1; j++)
			scanf("%1d", &arr[i][j]);

	for (int i = 1; i < m + 1; i++)
		dp[1][i] = arr[1][i];

	for (int i = 2; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (arr[i][j] != 0) {
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
			}
			else
				dp[i][j] = 0;
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			//printf("%2d", dp[i][j]);
			ans = max(ans, dp[i][j]);
		}
		//printf("\n");
	}

	printf("%d\n", ans*ans);


	return 0;
}