#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int N, M;
int arr[202];
bool human[102];
int ans = 0;

bool check_finish() {
	int tmp = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (arr[i] == 0)
			tmp++;
	}
	if (tmp >= M)
		return true;
	else
		return false;
}

void check_control() {
	for (int i = N - 1; i > 0; i--) {
		if (human[i] == true) {
			if (human[i + 1] == false && arr[i + 1] >= 1) {
				human[i + 1] = true;
				human[i] = false;
				arr[i + 1] -= 1;
			}
		}
	}
	if (human[N - 1] == true)
		human[N - 1] = false;

	if (human[0] == false && arr[0] >= 1) {
		human[0] = true;
		arr[0] -= 1;
	}
}
void move_belt() {
	int tmp = arr[2 * N - 1];

	for (int i = 2 * N - 1; i > 0; i--)
		arr[i] = arr[i - 1];
	arr[0] = tmp;

	for (int i = N - 1; i > 0; i--)
		human[i] = human[i - 1];
	if (human[N - 1] == true)
		human[N - 1] = false;
	human[0] = false;
}
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < 2 * N; i++) {
		scanf("%d", &arr[i]);
	}
	memset(human, false, sizeof(human));

	while (1) {
		if (check_finish() == true)
			break;
		ans++;
		move_belt();
		check_control();
	}
	printf("%d\n", ans);



	return 0;
}