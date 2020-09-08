#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;
typedef pair<int, int> pii;
vector<pii> tree[11][11];
vector<pii> order;
int N, M, K;
int arr[11][11];
int year[11][11];
int ans = 0;
const int dy[] = { -1,-1,0,1,1,1,0,-1 };
const int dx[] = { 0,-1,-1,-1,0,1,1,1 };


void get_order() {
	order.clear();

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (tree[i][j].size() != 0)
				order.push_back({ i,j });
		}
	}
}

void tree_sort() {
	int order_size = order.size();

	for (int i = 0; i < order_size; i++) {
		sort(tree[order.at(i).first][order.at(i).second].begin(), tree[order.at(i).first][order.at(i).second].end());
	}
}
void spring(int ypos, int xpos) {

	int size = tree[ypos][xpos].size();

	for (int i = 0; i < size; i++) {
		if (arr[ypos][xpos] >= tree[ypos][xpos].at(i).first) {
			arr[ypos][xpos] -= tree[ypos][xpos].at(i).first;
			tree[ypos][xpos].at(i).first += 1;
		}
		else {
			tree[ypos][xpos].at(i).second = 0;
		}
	}
}

void summer(int ypos, int xpos) {
	vector<pii>::iterator iter = tree[ypos][xpos].begin();

	for (int i = 0; i < tree[ypos][xpos].size(); i++) {
		if (tree[ypos][xpos].at(i).second == 0) {
			arr[ypos][xpos] += (tree[ypos][xpos].at(i).first / 2);
			//tree[ypos][xpos].erase(iter + i);
		}
	}

	for (int i = 0; i < tree[ypos][xpos].size(); i++) {
		if (tree[ypos][xpos].at(i).second == 0) {
			tree[ypos][xpos].erase(iter + i, tree[ypos][xpos].end());
			break;
		}
	}
}

void fall(int ypos, int xpos) {
	int tree_size = tree[ypos][xpos].size();
	int ny, nx;
	for (int i = 0; i < tree_size; i++) {
		int now = tree[ypos][xpos].at(i).first;
		
		if (now % 5 == 0) {
			for (int j = 0; j < 8; j++) {
				ny = ypos + dy[j];
				nx = xpos + dx[j];

				if (ny <= 0 || ny > N || nx <= 0 || nx > N)
					continue;
				else {
					tree[ny][nx].push_back({ 1,1 });
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			arr[i][j] += year[i][j];
}

void show() {
	printf("%d= Show arr\n", K);
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\nShow tree_size\n");
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			printf("%3d", tree[i][j].size());
		}
		printf("\n");
	}
	printf("\n");
}
int main() {

	/*vector <pii> test;
	test.push_back({ 1,1 });
	test.push_back({ 2,2 });
	test.push_back({ 3,3 });
	test.push_back({ 4,4 });
	test.push_back({ 5,5 });
	test.push_back({ 6,6 });
	vector <pii>::iterator iter = test.begin();
	test.erase(iter + 2);
	for (int i = 0; i < test.size(); i++) {
		printf("%d= {%d %d}\n", i, test.at(i).first, test.at(i).second);
	}*/

	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			scanf("%d", &year[i][j]);
			arr[i][j] = 5;
		}
	}

	int ty, tx, age;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &ty, &tx, &age);
		tree[ty][tx].push_back({ age, 1 });
	}

	while (K--) {
		get_order();
		tree_sort();
		
		int order_size = order.size();
		for (int i = 0; i < order_size; i++) {
			spring(order.at(i).first, order.at(i).second);
		}
		for (int i = 0; i < order_size; i++) {
			summer(order.at(i).first, order.at(i).second);
		}
		for (int i = 0; i < order_size; i++) {
			fall(order.at(i).first, order.at(i).second);
		}
		winter();
		//show();
	}
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (tree[i][j].size() != 0)
				ans += tree[i][j].size();
		}
	}

	printf("%d\n", ans);

	return 0;
}