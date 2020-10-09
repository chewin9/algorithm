#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int N;
int arr[18][18];
int score[18];
int mapi;
int person;
bool live[18];
int ans = -1e9;

bool check_win() {

	for (int i = 0; i < N; i++) {
		if (live[i] == true && i != mapi)
			return false;
	}
	return true;
}
void game(int round, int cnt) {
	if (check_win()) {
		ans = max(ans, round);
		//printf("check_win()\n");
		return;
	}
	if (live[mapi] == false) {
		ans = max(ans, round);
		//printf("mapi die()\n");
		return;
	}


	if (cnt % 2 == 0) {
		for (int i = 0; i < N; i++) {
			if (mapi == i)
				continue;
			else if(live[i]==true){
				int copy_score[18];
				for (int j = 0; j < N; j++) {
					copy_score[j] = score[j];
				}
				live[i] = false;

				for (int j = 0; j < N; j++) {
					score[j] += arr[i][j];
					if (score[j] < 300)
						score[j] = 300;
					if (score[j] > 800)
						score[j] = 800;
				}
				//printf("mapi kill = %d  ", i);
				/*for (int i = 1; i < N + 1; i++) {
					if (live[i] == true)
						printf("Person[%d] = %d   ", i, score[i]);
				}*/
				game(round+1, cnt - 1);
				for (int i = 0; i < N; i++) {
					score[i] = copy_score[i];
				}
				live[i] = true;
			}
		}
	}
	else {
		int tmp = -1e9;
		int index = 0;
		for (int i = 0; i < N; i++) {
			if (tmp < score[i] && live[i] == true) {
				tmp = score[i];
				index = i;
			}
		}
		live[index] = false;
		//printf("    simin kill = %d    ", index);
		game(round, cnt - 1);

		live[index] = true;


	}

}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &score[i]);
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	scanf("%d", &mapi);

	person = N;
	/*for (int i = 1; i < N + 1; i++) {
		memset(live, true, sizeof(live));
		if (i == mapi)
			continue;
		else
			game(i,person);
	}*/
	memset(live, true, sizeof(live));

	game(0,person);

	printf("%d", ans);
	return 0;
}