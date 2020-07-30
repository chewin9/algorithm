#include<iostream>

using namespace std;

int main() {
	int dp[1002];
	int n;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i < 1001; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	scanf_s("%d", &n);

	printf("%d\n", dp[n]);

	return 0;

}