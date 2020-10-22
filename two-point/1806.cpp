#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int arr[10002];
int N, S;
int main() {
	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	int sum = 0;
	int left, right, ans;
	left = right = 0;
	ans = 1e9;

	while (left <= right && right <N) {
		if (sum < S) {
			sum += arr[right++];
		}
		else if (sum > S) {
			ans = min(ans, right - left);
			sum -= arr[left++];
		}
		else {
			ans = min(ans, right - left);
			sum += arr[right++];
		}
	}

	if (ans == 1e9)
		printf("0\n");
	else
		printf("%d\n", ans);

	return 0;
}