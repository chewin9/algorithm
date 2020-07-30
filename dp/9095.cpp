#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int test;
	int dp[13];
	int n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 12; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	scanf_s("%d", &test);

	for (int i = 0; i < test; i++) {
		scanf_s("%d", &n);
		printf("%d \n", dp[n]);
	}

	return 0;
}