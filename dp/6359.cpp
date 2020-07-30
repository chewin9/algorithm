#include<iostream>
#include<string.h>

using namespace std;

int T, n;
int dp[102];

int main() {
	int ans;
	
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		memset(dp, -1, sizeof(dp));
		ans = 0;
		scanf("%d", &n);

		for (int i = 1; i < n + 1; i++)
			printf("%d ", dp[i]);
		printf("\n");

		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++)
				if (j%i == 0)
					dp[j] = -dp[j];
		}

		for (int i = 1; i < n + 1; i++)
			printf("%d ", dp[i]);
		printf("\n");


		for (int i = 1; i < n + 1; i++)
			if (dp[i] == 1)
				ans += 1;

		printf("%d\n", ans);
	}



	return 0;
}