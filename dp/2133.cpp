#include<iostream>

using namespace std;

int main() {
	int N;
	int dp[32];

	scanf("%d", &N);

	dp[0] = 1;
	dp[1] = 0;
	for (int i = 2; i < N + 1; i += 2) {
		dp[i] = 3 * dp[i - 2];
		for (int j = 4; j <= i; j += 2) {
			dp[i] += 2 * dp[i - j];
		}
	}

	printf("%d\n", dp[N]);



	return 0;
}