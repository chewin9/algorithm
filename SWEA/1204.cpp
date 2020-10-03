#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int arr[1002];
int cost[101];
int T;
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	
	while (T--) {
		int num=0;
		int ans=0;
		int tmp = 0;
		memset(cost, 0, sizeof(cost));
		scanf("%d", &num);

		for (int i = 1; i < 1001; i++)
			scanf("%d", &arr[i]);

		for (int i = 1; i < 1001; i++) {
			cost[arr[i]] += 1;
		}
		for (int i = 1; i < 101; i++) {
			if (tmp <= cost[i]) {
				tmp = cost[i];
				ans = i;
			}
		}
		printf("#%d %d\n", num, ans);
	}


	return 0;

}