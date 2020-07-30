#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int maxi(int x, int y, int z) {
	if (x > y) {
		if (x > z)
			return x;
		else
			return z;
	}
	else{
		if (y > z)
			return y;
		else
			return z;
	}
}

int main() {
	int N, M;
	int arr[1002][1002];
	int dp[1002][1002];

	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < M + 1; j++)
			scanf("%d", &arr[i][j]);

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			dp[i][j] = maxi(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
		}
	}

	printf("%d\n", dp[N][M]);


	return 0;
}