#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int, int> pii;		
pii blue[5][6];				//type, 같은 블록 체크
pii green[6][5];

int N;
int ans = 0;
int area = 0;
void gravity() {
	bool blue_check = true;
	for (int k = 0; k < 4; k++) {
		for (int i = 4; i >= 0; i--) {
			for (int j = 5; j > i; j--) {
				if (blue[k][i].first != 0 && blue[k][i].first != 3 && blue[k][j].first == 0) {
					blue_check = true;

					for (int t = i + 1; t <= j; t++) {
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
				}
				else if (blue[k][i].first == 3 && blue[k][j].first == 0) {
					if (blue[k][i].second == blue[k + 1][i].second) {
						blue_check = true;
						for (int t = i + 1; t <= j; t++) {
							if (blue[k + 1][t].first != 0 || blue[k][t].first !=0) {
								blue_check = false;
								break;
							}
						}
						if (blue_check == true) {
							blue[k][j] = blue[k][i];
							blue[k + 1][j] = blue[k + 1][i];
							blue[k][i] = { 0,0 };
							blue[k + 1][i] = { 0,0 };
							break;
						}
					}
					else {
						blue_check = true;
						for (int t = i + 1; t <= j; t++) {
							if (blue[k - 1][t].first != 0 || blue[k][t].first !=0) {
								blue_check = false;
								break;
							}
						}
						if (blue_check == true) {
							blue[k][j] = blue[k][i];
							blue[k - 1][j] = blue[k - 1][i];
							blue[k][i] = { 0,0 };
							blue[k - 1][i] = { 0,0 };
							break;
						}
					}
				}
			}
		}
	}

	bool green_check = true;
	for (int k = 0; k < 4; k++) {
		for (int i = 4; i >= 0; i--) {
			for (int j = 5; j > i; j--) {
				if (green[i][k].first != 2 && green[i][k].first != 0 && green[j][k].first == 0) {
					green_check = true;
					for (int t = i + 1; t <= j; t++) {
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
				}
				else if (green[i][k].first == 2 && green[j][k].first == 0) {
					if (green[i][k].second == green[i][k + 1].second) {
						green_check = true;
						for (int t = i + 1; t <= j; t++) {
							if (green[t][k + 1].first != 0 || green[t][k].first !=0) {
								green_check = false;
								break;
							}
						}
						if (green_check == true) {
							green[j][k] = green[i][k];
							green[j][k + 1] = green[i][k + 1];
							green[i][k] = { 0,0 };
							green[i][k + 1] = { 0,0 };
							break;
						}
					}
					else {
						green_check = true;
						for (int t = i + 1; t <= j; t++) {
							if (green[t][k - 1].first != 0 || green[t][k].first !=0) {
								green_check = false;
								break;
							}
						}
						if (green_check == true) {
							green[j][k] = green[i][k];
							green[j][k - 1] = green[i][k - 1];
							green[i][k] = { 0,0 };
							green[i][k - 1] = { 0,0 };
							break;
						}
					}
				}
			}
		}
	}
}

void go_tile(int type, int ypos, int xpos, int cnt) {
	switch (type) {
	case 1:
		blue[ypos][0] = { type,cnt };
		green[0][xpos] = { type,cnt };

		gravity();
		break;
	case 2:
		blue[ypos][0] = { type,cnt };
		blue[ypos][1] = { type,cnt };
		
		green[0][xpos] = { type,cnt };
		green[0][xpos+1] = { type,cnt };
		
		gravity();
		break;
	case 3:
		blue[ypos][0] = { type,cnt };
		blue[ypos+1][0] = { type,cnt };

		green[0][xpos] = { type,cnt };
		green[1][xpos] = { type,cnt };
		
		gravity();
		break;
	}
}

void get_point() {
	bool blue_check = true;
	for (int i = 5; i >= 0; i--) {
		blue_check = true;
		for (int j = 0; j < 4; j++) {
			if (blue[j][i].first == 0) {
				blue_check = false;
				break;
			}
		}
		if (blue_check == true) {
			for (int j = 0; j < 4; j++)
				blue[j][i] = { 0,0 };
			ans++;
			//gravity();
			//i = 6;
		}
	}
	

	bool green_check = true;

	for (int i = 5; i >= 0; i--) {
		green_check = true;
		for (int j = 0; j < 4; j++) {
			if(green[i][j].first == 0){
				green_check = false;
				break;
			}
		}
		if (green_check == true) {
			for (int j = 0; j < 4; j++)
				green[i][j] = { 0,0 };
			ans++;
			//gravity();
			//i = 6;
		}
	}
	gravity();
}

void check_onetwo() {
	int blue_cnt=0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (blue[j][i].first != 0) {
				blue_cnt += 1;
				break;
			}
		}
	}
	for (int i = 5; i > 5 - blue_cnt; i--) {
		for (int j = 0; j < 4; j++) {
			blue[j][i] = { 0,0 };
		}
	}
	
	int green_cnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j].first != 0) {
				green_cnt += 1;
				break;
			}
		}
	}
	for (int i = 5; i > 5 - green_cnt; i--) {
		for (int j = 0; j < 4; j++) {
			green[i][j] = { 0,0 };
		}
	}

	gravity();
	gravity();
}
void get_area() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			if (blue[i][j].first != 0) {
				area++;
			}
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j].first != 0)
				area++;
		}
	}
}

void show() {
	printf("\nBlue\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%2d", blue[i][j].first);
		}
		printf("\n");
	}

	printf("\nGreen\n");
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%2d", green[i][j].first);
		}
		printf("\n");
	}
	printf("\n");
}
int main() {

	scanf("%d", &N);

	int t, y, x;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &t, &y, &x);
		go_tile(t, y, x,i);
		//printf("tile ===================================\n");
		//show();
		get_point();
		check_onetwo();
		get_point();
		//printf("finish==================================\n");
		//show();
	}

	get_area();

	printf("%d\n%d\n", ans, area);

	return 0;

}