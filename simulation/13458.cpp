#include<iostream>
#include<string.h>


using namespace std;

int arr[1000002];
int N, B, C;
long long ans = 0;

int main() {

	scanf("%d", &N);

	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &B, &C);

	for (int i = 1; i < N + 1; i++) {
		if (arr[i] - B > 0) {
			ans += (arr[i] - B) / C;
			if ((arr[i] - B) % C != 0)
				ans += 1;
		}
		ans += 1;
	}

	printf("%lld",ans);
	return 0;

}