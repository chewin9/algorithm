#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;
int T, D, W, K;
int arr[15][22];
int ans = 1e9;
bool madi[22];
int num[15];

void test(int goal) {
	int cnt, tmp;
	bool check = false;
	for (int k = 1; k < W + 1; k++) {
		for (int i = 1; i < D - K + 2; i++) {
			if (madi[i] == true)
				tmp = num[i];
			else
				tmp = arr[i][k];			
			cnt = 1;
			check = false;

			if (cnt >= K) {
				check = true;
				break;
			}

			for (int j = i + 1; j < D + 1; j++) {
				int a;
				if (madi[j] == true)
					a = num[j];
				else
					a = arr[j][k];

				if (tmp == a){// || madi[j] == true) {
					cnt++;
					if (cnt >= K) {
						check = true;
						break;
					}
				}
				else
					break;
			}
			if (check == true)
				break;
		}
		if (check == false)
			return;
	}
	ans = min(ans, goal);
}

void check_num(int pos, int goal, int cnt) {
	if (goal == cnt) {
		test(goal);
		return;
	}
	
	for (int i = pos; i < D + 1; i++) {
		if (madi[i] == true) {
			for (int j = 0; j<2; j++){
				num[i] = j;
				check_num(i + 1, goal, cnt + 1);
				//num[i] = -1;
			}
		}
	}
}
void dfs(int pos, int goal, int cnt) {
	if (ans != 1e9)
		return;

	madi[pos] = true;
	if (goal == cnt) {
		/*for (int i = 1; i < D + 1; i++) {
			if (madi[i] == true)
				printf("O -> ");
			else
				printf("X -> ");
		}
		printf("\n");*/
		check_num(1, goal, 0);
		//test(goal);

		madi[pos] = false;
		return;
	}
	for (int i = pos + 1; i < D + 1; i++) {
		dfs(i, goal, cnt + 1);
	}
	madi[pos] = false;
}


int main() {
	//freopen("sample_input.txt", "r", stdin);

	/*D = 4;
	K = 2;
	for (int k = 1; k < K + 1; k++) {
		printf("%d==============\n", k);
		for (int i = 1; i < D - k + 2; i++) {
			dfs(i, k, 1);
		}
	}*/
	scanf("%d", &T);

	for (int t = 1; t < T + 1; t++) {
		ans = 1e9;
		memset(madi, false, sizeof(madi));
		scanf("%d %d %d", &D, &W, &K);
		for (int i = 1; i < D + 1; i++)
			for (int j = 1; j < W + 1; j++)
				scanf("%d", &arr[i][j]);
		
		test(0);
		if (ans == 1e9) {
			for (int k = 1; k < K + 1; k++) {
				for (int i = 1; i < D - k + 2; i++) {
					dfs(i, k, 1);
				}
			}
		}
		
		printf("#%d %d\n", t, ans);
	}

}