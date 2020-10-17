#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>

using namespace std;

typedef pair<int, int> pii;
int R, C, K;
int ans = 0;
int N, M;			//세로 가로
int arr[102][102];
map<int, int> m;
vector<pii>v;		//숫자, 횟수

bool my(pii a, pii b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else
		return a.second < b.second;
}

void game() {
	map<int, int>::iterator iter;
	int size, cnt, tmp;

	if (N >= M) {
		tmp = 0;
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < M + 1; j++) {
				if (arr[i][j] != 0)
					m[arr[i][j]]++;
				arr[i][j] = 0;
			}

			for (iter = m.begin(); iter != m.end(); iter++)
				v.push_back({ iter->first, iter->second });

			sort(v.begin(), v.end(), my);

			size = v.size();
			cnt = 1;

			tmp = max(tmp, size * 2);

			for (int j = 0; j < size; j++) {
				arr[i][cnt++] = v.at(j).first;
				arr[i][cnt++] = v.at(j).second;
			}

			m.clear();
			v.clear();
		}
		M = tmp;
	}
	else {
		int tmp = 0;
		for (int i = 1; i < M + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (arr[j][i] != 0)
					m[arr[j][i]]++;
				arr[j][i] = 0;
			}

			for (iter = m.begin(); iter != m.end(); iter++)
				v.push_back({ iter->first, iter->second });

			sort(v.begin(), v.end(), my);

			size = v.size();
			cnt = 1;
			tmp = max(tmp, size * 2);

			for (int j = 0; j < size; j++) {
				arr[cnt++][i] = v.at(j).first;
				arr[cnt++][i] = v.at(j).second;
			}
			v.clear();
			m.clear();
		}
		N = tmp;
	}
}

int main() {
	scanf("%d %d %d", &R, &C, &K);
	
	N = M = 3;

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	while (1) {
		if (arr[R][C] == K)
			break;
		ans++;
		if (ans > 100)
			break;
		game();
	}

	if (ans > 100)
		printf("-1\n");
	else
		printf("%d\n", ans);


	return 0;
}