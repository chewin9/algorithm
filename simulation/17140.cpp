#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;
int r, c, k;
int arr[202][202];
int tmp_arr[202][202];
int max_r, max_c;
int ans = 0;
int num[102];
vector <pii> order;

bool aa(pii a, pii b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}
void copy_arr() {
	for (int i = 1; i < max_r + 1; i++) {
		for (int j = 1; j < max_c + 1; j++)
			arr[i][j] = tmp_arr[i][j];
	}
}
void fun_R() {

	int tmp_num=0;
	int tmp_c=0;

	for (int i = 1; i < max_r + 1; i++) {
		for (int j = 1; j < max_c + 1; j++) {
			tmp_num = max(tmp_num, arr[i][j]);
			num[arr[i][j]] += 1;
		}

		for (int j = 1; j < tmp_num + 1; j++) {
			if (num[j] != 0) {
				order.push_back({ j,num[j] });
			}
		}

		sort(order.begin(), order.end(), aa);

		int order_size = order.size();
		tmp_c = max(tmp_c, (order_size * 2));
		int cnt = 1;
		for (int j = 0; j < order_size; j++) {
				tmp_arr[i][cnt] = order.at(j).first;
				cnt++;
				tmp_arr[i][cnt] = order.at(j).second;
				cnt++;
		}

		memset(num, 0, sizeof(num));
		order.clear();
		tmp_num = 0;
	}

	if (tmp_c > 100)
		tmp_c = 100;
	max_c = tmp_c;
	copy_arr();
	memset(tmp_arr, 0, sizeof(tmp_arr));
}

void fun_C() {
	int tmp_num = 0;
	int tmp_r = 0;

	for (int j = 1; j < max_c + 1; j++) {
		for (int i = 1; i < max_r + 1; i++) {
			tmp_num = max(tmp_num, arr[i][j]);
			num[arr[i][j]] += 1;
		}

		for (int i = 1; i < tmp_num + 1; i++) {
			if (num[i] != 0)
				order.push_back({ i,num[i] });
		}

		sort(order.begin(), order.end(), aa);

		int order_size = order.size();
		tmp_r = max(tmp_r, (order_size * 2));
		int cnt = 1;
		for (int i = 0; i < order_size; i++) {
			tmp_arr[cnt][j] = order.at(i).first;
			cnt++;
			tmp_arr[cnt][j] = order.at(i).second;
			cnt++;
		}

		memset(num, 0, sizeof(num));
		order.clear();
		tmp_num = 0;
	}

	if (tmp_r > 100)
		tmp_r = 100;
	max_r = tmp_r;
	copy_arr();
	memset(tmp_arr, 0, sizeof(tmp_arr));
}

int main() {


	scanf("%d %d %d", &r, &c, &k);

	for (int i = 1; i < 4; i++) 
		for (int j = 1; j < 4; j++)
			scanf("%d", &arr[i][j]);
	
	max_r = max_c = 3;

	while (1) {
		if (arr[r][c] == k)
			break;
		if (ans >= 100) {
			ans = -1;
			break;
		}
		ans += 1;
		if (max_r >= max_c)
			fun_R();
		else
			fun_C();
	}

	printf("%d\n", ans);


	return 0;
}