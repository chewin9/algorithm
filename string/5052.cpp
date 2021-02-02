#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<string>

using namespace std;

int T, N;
vector<int> arr;
bool check;
void Solve() {
	for (int i = 0; i < N - 1; i++) {
		string stand = to_string(arr[i]);
		int stand_size = stand.size();
		for (int j = i + 1; j < N; j++) {
			string comp = to_string(arr[j]);
			int comp_size = comp.size();
			
			int t;

			t = comp.find(stand);
			if (t != -1) {
				check = false;
				return;
			}
		}
	}
}

int main() {
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		arr.clear();
		check = true;

		scanf("%d", &N);
		int tmp;
		for (int i = 0; i < N; i++) {
			scanf("%d", &tmp);
			arr.push_back(tmp);
		}
		sort(arr.begin(), arr.end());

		Solve();

		/*for (int i = 0; i < N; i++) {
			printf("%d -> ", arr[i]);
		}
		printf("\n");*/
		if (check == true) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

	}


	return 0;
}