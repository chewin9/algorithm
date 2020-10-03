#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;

typedef pair<int, string> pis;
queue<pis> q;
int T;
int A, B;
bool visit[10002];
void bfs(int pos) {
	visit[pos] = true;
	q.push({ pos,"" });

	int num, tmp;
	string str;
	string str_tmp;
	while (!q.empty()) {
		pis now = q.front();
		q.pop();

		num = now.first;
		str = now.second;

		if (num == B) {
			while (!q.empty())
				q.pop();
			
			int str_size = str.size();
			for (int i = 0; i < str_size; i++)
				printf("%c", str.at(i));
			printf("\n");
			return;
		}

		//============================================ L
		tmp = 0;
		tmp = num % 1000 * 10 + num / 1000;
		str_tmp = str;
		if (visit[tmp] == false) {
			str_tmp.push_back('L');
			q.push({ tmp,str_tmp });
			visit[tmp] = true;
		}

		//============================================ R
		tmp = 0;
		tmp = (num - (num % 10)) / 10 + num % 10 * 1000;
		str_tmp = str;
		if (visit[tmp] == false) {
			str_tmp.push_back('R');
			q.push({ tmp, str_tmp });
			visit[tmp] = true;
		}
		//============================================ S
		tmp = 0;
		str_tmp = str;
		if (num == 0)
			tmp = 9999;
		else
			tmp = num - 1;
		if (visit[tmp] == false) {
			str_tmp.push_back('S');
			q.push({ tmp, str_tmp });
			visit[tmp] = true;
		}
		//============================================ D
		tmp = 0;
		str_tmp = str;
		tmp = num * 2 % 10000;
		if (visit[tmp] == false) {
			str_tmp.push_back('D');
			q.push({ tmp, str_tmp });
			visit[tmp] = true;
		}
	}
}

int main() {
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		memset(visit, false, sizeof(visit));
		
		scanf("%d %d", &A, &B);

		bfs(A);
	}


	printf("\n");

	return 0;
}