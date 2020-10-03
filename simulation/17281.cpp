#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int arr[52][12];
int N;
int ans = -1e9;
int choose[10];
bool visit[10];
bool home[4];			//0 home 1 1ro 2ro 3ro

int get_point(int cnt) {
	if (home[3] == true)
		cnt++;
	for (int i = 3; i > 0; i--)
		home[i] = home[i - 1];
	//home[1] = true;
	return cnt;
}
void play_game() {
	memset(home, false, sizeof(home));
	int out = 0;
	int cnt = 0;
	int cur = 1;
	bool check = false;

	for (int i = 1; i < N + 1; i++) {
		out = 0;
		for (int j = 0; j < 4; j++)
			home[j] = false;

		while (out < 3) {
			home[0] = true;
			if (arr[i][choose[cur]] == 0) {
				out++;
			}
			else {
				for (int j = 3; j >= 0; j--) {
					if (home[j] == false)
						continue;
					int tmp = j + arr[i][choose[cur]];
					if (tmp > 3)
						cnt++;
					else
						home[tmp] = true;
					home[j] = false;
				}
			}

			cur++;
			if (cur == 10)
				cur = 1;
		}
	}
	ans = max(cnt, ans);

	//while (in <N+1) {
	//	check = false;
	//	for (int i = pre; i < 10; i++) {
	//		switch (arr[in][choose[i]]) {
	//		case 0:
	//			out++;
	//			break;
	//		case 1:
	//			if (home[3] == true)
	//				cnt++;
	//			for (int i = 3; i > 0; i--)
	//				home[i] = home[i - 1];
	//			home[1] = true;
	//			/*cnt = get_point(cnt);
	//			home[1] = true;*/
	//			break;
	//		case 2:
	//			if (home[3] == true)
	//				cnt++;
	//			if (home[2] == true)
	//				cnt++;
	//			home[3] = home[1];
	//			home[1] = false;
	//			home[2] = true;
	//			/*for (int i = 0; i < 2; i++)
	//				cnt = get_point(cnt);
	//			home[2] = true;*/
	//			break;
	//		case 3:
	//			for (int i = 3; i > 0; i--)
	//				if (home[i] == true)
	//					cnt++;
	//			for (int i = 1; i < 4; i++)
	//				home[i] = false;
	//			home[3] = true;
	//			/*
	//			for (int i = 0; i < 3; i++)
	//				cnt = get_point(cnt);
	//			home[3] = true;*/
	//			break;
	//		case 4:
	//			for (int i = 1; i < 4; i++) {
	//				if (home[i] == true) {
	//					home[i] = false;
	//					cnt++;
	//				}
	//			}
	//			cnt++;
	//			break;
	//		}
	//		if (out == 3) {
	//			out = 0;
	//			memset(home, false, sizeof(home));
	//			in++;
	//			pre = i + 1;
	//			check = true;
	//			break;
	//		}
	//	}
	//	if (check == false)
	//		pre = 1;
	//}
	////printf("[%d]\n", cnt);
	//ans = max(cnt, ans);
}

//void dfs(int pos, int val) {
//	//choose[pos] = val;
//	//visit[val] = true;
//	if (pos == 4) {
//		choose[pos] = 1;
//		visit[1] = true;
//		for (int i = 2; i < 10; i++)
//			if (visit[i] == false) {
//				dfs(pos + 1, i);
//				visit[i] = false;
//			}
//	}
//	if (pos != 4) {
//		choose[pos] = val;
//		visit[val] = true;
//	}
//	if (pos == 9) {
//		/*printf("==================\n");
//		for (int i = 1; i < 10; i++) {
//			printf("%2d", choose[i]);
//		}*/
//		//printf("\n");
//
//		play_game();
//		
//
//		visit[val] = false;
//		return;
//	}
//	for (int i = 2; i < 10; i++) {
//		if (visit[i] == false) {
//			dfs(pos + 1, i);
//			visit[i] = false;
//		}
//	}
//}

void dfs(int pos, int val) {
	visit[val] = true;
	choose[pos] = val;

	if (pos == 9) {
		if (choose[4] != 1)
			return;
		/*printf("==================\n");
		for (int i = 1; i < 10; i++) {
			printf("%2d", choose[i]);
		}*/
		play_game();
		visit[val] = false;
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (visit[i] == false) {
			dfs(pos + 1, i);
			visit[i] = false;
		}
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < 10; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int j = 1; j < 10; j++) {
		memset(choose, 0, sizeof(choose));
		memset(visit, false, sizeof(visit));
		/*choose[4] = 1;
		visit[1] = true;*/

		dfs(1, j);
	}

	printf("%d\n", ans);
	return 0;
}