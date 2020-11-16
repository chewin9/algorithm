#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>

using namespace std;
typedef pair<int, int> pii;

pii blue[4][6];
pii green[6][4];
int N;
int point = 0;
int ans = 0;

void show() {
	printf("\nBLUE AREA\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			printf("{%d %d}  ", blue[i][j].first, blue[i][j].second);
		}
		printf("\n");
	}

	printf("\nGREEN AREA\n");

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			printf("{%d %d}  ", green[i][j].first, green[i][j].second);
		}
		printf("\n");
	}
}

void gravity() {
	// blue area
	bool blue_check = true;
	for (int k = 0; k < 4; k++) {
		for (int i = 4; i >= 0; i--) {
			for (int j = 5; j > i; j--) {
				if (blue[k][j].first == 0 && blue[k][i].first != 0) {
					switch (blue[k][i].first) {
						blue_check = true;
					case 1:
						blue_check = true;
						for (int t = i + 1; t < j; t++) {
							if (blue[k][t].first != 0) {
								blue_check = false;
								break;
							}
						}
						if (blue_check == true) {
							blue[k][j] = blue[k][i];
							blue[k][i] = { 0,0 };
							break;
						}
						break;

					case 2:
						blue_check = true;
						for (int t = i + 1; t < j; t++) {
							if (blue[k][t].first != 0) {
								blue_check = false;
								break;
							}
						}
						if (blue_check == true) {
							blue[k][j] = blue[k][i];
							blue[k][i] = { 0,0 };
							break;
						}
						break;
						
					case 3:
						blue_check = true;
						int tmp;
						for (int t = 0; t < 4; t++) {
							if (k == t)
								continue;
							if (blue[k][i].second == blue[t][i].second) {
								tmp = t;
								break;
							}
						}

						for (int t = i + 1; t <= j; t++) {
							if (blue[k][t].first != 0 || blue[tmp][t].first != 0) {
								blue_check = false;
								break;
							}
						}
						if (blue_check == true) {
							blue[k][j] = blue[k][i];
							blue[tmp][j] = blue[tmp][i];
							blue[k][i] = { 0,0 };
							blue[tmp][i] = { 0,0 };
							break;
						}
						break;
					}
					//break;
				}
			}
		}
	}

	bool green_check = true;

	for (int k = 0; k < 4; k++) {
		for (int i = 4; i >= 0; i--) {
			for (int j = 5; j > i; j--) {
				if (green[j][k].first == 0 && green[i][k].first != 0) {
					switch (green[i][k].first) {
						//green_check = true;
					case 1:
						green_check = true;
						for (int t = i + 1; t < j; t++) {
							if (green[t][k].first != 0) {
								green_check = false;
								break;
							}
						}
						if (green_check == true) {
							green[j][k] = green[i][k];
							green[i][k] = { 0,0 };
							break;
						}
						break;

					case 2:
						green_check = true;
						int tmp;
						for (int t = 0; t < 4; t++) {
							if (t == k)
								continue;
							if (green[i][k].second == green[i][t].second) {
								tmp = t;
								break;
							}
						}

						for (int t = i + 1; t <= j; t++) {
							if (green[t][k].first != 0 || green[t][tmp].first != 0) {
								green_check = false;
								break;
							}
						}
						if (green_check == true) {
							green[j][k] = green[i][k];
							green[j][tmp] = green[i][tmp];
							green[i][k] = { 0,0 };
							green[i][tmp] = { 0,0 };
							break;
						}
						break;

					case 3:
						green_check = true;
						for (int t = i + 1; t < j; t++) {
							if (green[t][k].first != 0) {
								green_check = false;
								break;
							}
						}
						if (green_check == true) {
							green[j][k] = green[i][k];
							green[i][k] = { 0,0 };
							break;
						}
						break;
					}
					//break;
				}
			}
		}
	}

}


void put_block(int type, int ypos, int xpos, int cnt) {
	switch (type) {
	case 1:
		blue[ypos][0] = { type,cnt };
		green[0][xpos] = { type,cnt };
		break;
	case 2:
		blue[ypos][0] = { type,cnt };
		blue[ypos][1] = { type,cnt };

		green[0][xpos] = { type,cnt };
		green[0][xpos+1] = { type,cnt };

		break;
		
	case 3:
		blue[ypos][0] = { type,cnt };
		blue[ypos + 1][0] = { type,cnt };

		green[0][xpos] = { type,cnt };
		green[1][xpos] = { type,cnt };
		break;
	}
}

void get_point() {
	bool change = false;
	//blue_area
	bool blue_point = true;
	for (int i = 0; i < 6; i++) {
		blue_point = true;
		for (int j = 0; j < 4; j++) {
			if (blue[j][i].first == 0) {
				blue_point = false;
				break;
			}
		}
		if (blue_point == true) {
			for (int j = 0; j < 4; j++) {
				blue[j][i] = { 0,0 };
			}
			change = true;
			point++;
		}
	}

	//green_area
	bool green_point = true;
	for (int i = 0; i < 6; i++) {
		green_point = true;
		for (int j = 0; j < 4; j++) {
			if (green[i][j].first == 0) {
				green_point = false;
				break;
			}
		}
		if (green_point == true) {
			for (int j = 0; j < 4; j++)
				green[i][j] = { 0,0 };
			change = true;
			point++;
		}
	}

	if (change == true) {
		gravity();
		get_point();
	}
}

void check_side() {
	//blue_area
	int blue_cnt = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (blue[j][i].first != 0) {
				blue_cnt += 1;
				break;
			}
		}
	}

	switch (blue_cnt) {
	case 0:
		break;
	case 1:
		for (int i = 0; i < 4; i++)
			blue[i][5] = { 0,0 };
		break;
	case 2:
		for (int i = 0; i < 4; i++) {
			blue[i][5] = { 0,0 };
			blue[i][4] = { 0,0 };
		}
		break;
	}

	//green_area
	int green_cnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j].first != 0) {
				green_cnt += 1;
				break;
			}
		}
	}
	switch (green_cnt) {
	case 0:
		break;
	case 1:
		for (int i = 0; i < 4; i++) {
			green[5][i] = { 0,0 };
		}
		break;
	case 2:
		for (int i = 0; i < 4; i++) {
			green[5][i] = { 0,0 };
			green[4][i] = { 0,0 };
		}
		break;
	}

	if (blue_cnt != 0 || green_cnt != 0)
		gravity();
}

void get_answer() {
	//blue area
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			if (blue[i][j].first != 0)
				ans++;
		}
	}
	//green area
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j].first != 0)
				ans++;
		}
	}
}

int main() {

	scanf("%d", &N);

	int a, ypos, xpos;

	for (int t = 1; t < N + 1; t++) {
		printf("INPUT %d====================================\n", t);
		scanf("%d %d %d", &a, &ypos, &xpos);

		put_block(a,ypos,xpos,t);

		printf("===============put_block====================\n");
		show();
		gravity();
		get_point();
		gravity();
		printf("===============gravity======================\n");
		show();
		printf("===============check_side===================\n");
		check_side();
		show();
		gravity();
		printf("===============get_point====================\n");
		get_point();
		show();
	}

	get_answer();

	printf("%d\n%d\n", point, ans);

	return 0;
}