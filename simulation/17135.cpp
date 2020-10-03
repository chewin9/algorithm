#include<iostream>
#include<algorithm>
#include<string.h>
#include<set>
#include<vector>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ipi;
set <pii> s;
vector <pii> v;
int arr[17][17];
int ori_arr[17][17];
int N, M, D;
int ans = 0;
int arch[3];
vector<pii> ori_v;
typedef struct enemi {
	int ypos;
	int xpos;
	bool live;
}enemi;


void get_arr() {
	v.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = ori_arr[i][j];
		}
	}
	for (int i = 0; i < ori_v.size(); i++)
		v.push_back({ ori_v.at(i).first, ori_v.at(i).second });
}
bool mybool(ipi a, ipi b) {
	if (a.first == b.first) {
		return a.second.second < b.second.second;
	}
	else
		return a.first < b.first;
}
void game() {
	int c = N;
	int cnt = 0;
	vector<ipi> tmp;
	set<pii>::iterator iter;

	while (c--) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < v.size(); j++) {
				if (v.at(j).first < N) {
					int a = N - v.at(j).first + abs(v.at(j).second - arch[i]);
					if (a <= D) {
						tmp.push_back({ a,{v.at(j).first, v.at(j).second} });
					}
				}
			}
			sort(tmp.begin(), tmp.end(), mybool);
			if(tmp.size() >0)
				s.insert({ tmp.at(0).second.first, tmp.at(0).second.second });
			tmp.clear();
		}
		cnt += s.size();
		for (iter = s.begin(); iter != s.end(); iter++) {
			pii now = *iter;
			//printf("%d %d ", now.first, now.second);
			for (int i = 0; i < v.size(); i++) {
				if (now.first == v.at(i).first && now.second == v.at(i).second) {
					v.at(i).first = N;
					break;
				}
			}
		}
		s.clear();
		for (int i = 0; i < v.size(); i++) {
			v.at(i).first += 1;
		}
	}
	//printf("\n\n\n");
	ans = max(cnt, ans);
}
void dfs(int pos, int val) {
	arch[pos] = val;
	if (pos == 2) {
		/*for (int i = 0; i < 3; i++) {
			printf("%d ", arch[i]);
		}
		printf("=========\n");*/
		get_arr();
		game();

		return;
	}
	for (int i = val+1; i < M; i++) {
		dfs(pos+1, i);
	}

}
int main() {
	scanf("%d %d %d", &N, &M, &D);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &ori_arr[i][j]);
			if (ori_arr[i][j] == 1) {
				ori_v.push_back({ i,j });
			}
		}
	}

	/*for (int i = 0; i < v.size(); i++) {
		printf("%d %d => ", v.at(i).first, v.at(i).second);
	}*/

	for (int i = 0; i <= M - 3; i++) {
		dfs(0, i);
	}
	printf("%d\n", ans);


	return 0;
}