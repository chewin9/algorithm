#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;
int cnt;
int arr[102];
int max_idx;
int min_idx;
int ans = 0;
void get_max() {
	int tmp = -1e9;
	int idx;
	for (int i = 1; i < 101; i++) {
		if (tmp < arr[i]) {
			tmp = arr[i];
			idx = i;
		}
	}
	max_idx = idx;
}
void get_min() {
	int tmp = 1e9;
	int idx = 0;
	for (int i = 1; i < 101; i++) {
		if (tmp > arr[i]) {
			tmp = arr[i];
			idx = i;
		}
	}
	min_idx = idx;
}
void dump(int cnt) {
	while (cnt--) {
		get_max();
		get_min();
		arr[max_idx] -= 1;
		arr[min_idx] += 1;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	for (int t = 1; t < 11; t++) {
		scanf("%d", &cnt);
		for (int i = 1; i < 101; i++) {
			scanf("%d", &arr[i]);
		}
		dump(cnt);
		get_max();
		get_min();
		ans = arr[max_idx] - arr[min_idx];
		printf("#%d %d\n", t, ans);
	}



	return 0;
}