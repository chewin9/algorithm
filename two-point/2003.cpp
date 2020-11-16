#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int arr[10002];
int N, M;
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	int start, end, sum,ans;
	start = end = sum = ans = 0;

	while (1) {
		if (sum > M)
			sum -= arr[start++];
		else if (end == N)
			break;
		else
			sum += arr[end++];

		if (sum == M)
			ans++;
	}

	printf("%d\n", ans);


	return 0;
}