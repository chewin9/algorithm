#include<iostream>
#include<string.h>
using namespace std;

int main() {
	char arr1[1002];
	char arr2[1002];
	int arr1_size=0;
	int arr2_size=0;
	int i=0;
	int dp[1002][1002];
	memset(dp, 0, sizeof(dp));
	scanf("%s %s", &arr1, &arr2);

	while (arr1[i] != '\0') {
		arr1_size += 1;
		i++;
	}
	i = 0;
	while (arr2[i] != '\0') {
		arr2_size += 1;
		i++;
	}
	for (int i = 0; i < 1002; i++) {
		dp[0][i] = 0;
		dp[i][0] = 0;
	}
	/*
	for (int i = 1; i < arr1_size + 1; i++) {
		for (int j = 1; j < arr2_size + 1; j++) {
			if (arr1[i - 1] == arr2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}
	*/

	printf("%c", arr1[0]);


	return 0;
}