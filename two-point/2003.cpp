#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int arr[10002];
int N, M;
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &arr[i]);
	}

	int sum = 0;
	int left, right;
	left = right = 1;
	int cnt = 0;

	while (1) {
		if (sum >= M)
			sum -= arr[left++];
		else if (right == N+1)
			break;
		else
			sum += arr[right++];

		if (sum == M)
			cnt++;
	}

	printf("%d\n", cnt);


	return 0;
}