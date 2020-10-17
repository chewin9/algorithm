#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;
typedef struct Sticker {
	int arr[10][10];
	int y_size;
	int x_size;
	int dir;			//반시계
}Sticker;

Sticker st[102];
int arr[40][40];
int N, M, K;
int ans = -1e9;

bool can_att(int pos, int ypos, int xpos, int dir);
void show();
int cnt = 1;

void get_ans(int pos, int ypos, int xpos, int dir) {
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1)
				tmp++;
		}
	}
	if (tmp > ans) {
		//printf("\n%d %d %d %d", pos, ypos, xpos, dir);
		//show();
		ans = tmp;
	}
	ans = max(ans, tmp);
}
void attach_sticker(int pos, int ypos, int xpos, int dir) {
	switch (dir) {
	case 0:
		for (int i = 0; i < st[pos].y_size; i++) {
			for (int j = 0; j < st[pos].x_size; j++) {
				if (st[pos].arr[i][j] == 1) {
					arr[ypos + i][xpos + j] = st[pos].arr[i][j];
				}
			}
		}
		break;
	case 3:
		for (int i = st[pos].x_size - 1; i >= 0; i--) {
			for (int j = 0; j < st[pos].y_size; j++) {
				if (st[pos].arr[j][i] == 1) {
					arr[ypos + st[pos].x_size - i - 1][xpos + j] = st[pos].arr[j][i];
				}
			}
		}
		break;
	case 2:
		for (int i = st[pos].y_size - 1; i >= 0; i--) {
			for (int j = st[pos].x_size - 1; j >= 0; j--) {
				if (st[pos].arr[i][j] == 1) {
					arr[ypos + st[pos].y_size - i - 1][xpos + st[pos].x_size - j - 1] = st[pos].arr[i][j];
				}
			}
		}
		break;
	case 1:
		for (int i = 0; i < st[pos].x_size;  i++) {
			for (int j = st[pos].y_size - 1; j >= 0; j--) {
				if (st[pos].arr[j][i] == 1) {
					arr[ypos + i][xpos + st[pos].y_size - j - 1] = st[pos].arr[j][i];
				}
			}
		}
		break;
	}
}
void disattach(int pos, int ypos, int xpos, int dir) {
	switch (dir) {
	case 0:
		for (int i = 0; i < st[pos].y_size; i++) {
			for (int j = 0; j < st[pos].x_size; j++) {
				if(st[pos].arr[i][j] ==1)
					arr[ypos + i][xpos + j] = 0;
			}
		}
		break;
	case 3:
		for (int i = st[pos].x_size - 1; i >= 0; i--) {
			for (int j = 0; j < st[pos].y_size; j++) {
				if(st[pos].arr[j][i] ==1)
					arr[ypos + st[pos].x_size - i - 1][xpos + j] = 0;
			}
		}
		break;
	case 2:
		for (int i = st[pos].y_size - 1; i >= 0; i--) {
			for (int j = st[pos].x_size - 1; j >= 0; j--) {
				if(st[pos].arr[i][j] == 1)
					arr[ypos + st[pos].y_size - i - 1][xpos + st[pos].x_size - j - 1] = 0;
			}
		}
		break;
	case 1:
		for (int i = 0; i < st[pos].x_size; i++) {
			for (int j = st[pos].y_size - 1; j >= 0; j--) {
				if(st[pos].arr[j][i] ==1)
					arr[ypos + i][xpos + st[pos].y_size - j - 1] = 0;
			}
		}
		break;
	}
}

bool can_att(int pos, int ypos, int xpos, int dir) {
	switch (dir) {
	case 0:
	case 2:
		if (ypos + st[pos].y_size - 1 >= N || xpos + st[pos].x_size - 1 >= M)
			return false;
		break;
		
	case 1:
	case 3:
		if (ypos + st[pos].x_size - 1 >= N || xpos + st[pos].y_size - 1 >= M)
			return false;
		break;

	}
	int y_size, x_size;
	y_size = st[pos].y_size;
	x_size = st[pos].x_size;
	switch (dir) {
	case 0:
		for (int i =  0; i <  y_size; i++) {
			for (int j =  0; j <  x_size; j++) {
				if (arr[ypos + i][xpos + j] == 1 && st[pos].arr[i][j] == 1) 
					return false;
				//printf("%2d", st[pos].arr[i][j]);
			}
			//printf("\n");
		}
		//printf("\n");
		return true;
		break;
	case 3:
		for (int i = x_size - 1; i >= 0; i--) {
			for (int j = 0; j < y_size; j++) {
				if (arr[ypos + x_size-i-1][xpos + j] == 1 && st[pos].arr[j][i] == 1)
					return false;
				//printf("%2d", st[pos].arr[j][i]);
			}
			//printf("\n");
		}
		//printf("\n");
		return true;
		break;
	case 2:
		for (int i = y_size - 1; i >= 0; i--) {
			for (int j = x_size - 1; j >= 0; j--) {
				if (arr[ypos + y_size - i - 1][xpos + x_size - j - 1] == 1 && st[pos].arr[i][j] == 1)
					return false;
				//printf("%2d", st[pos].arr[i][j]);
			}
			//printf("\n");
		}
		//printf("\n");
		return true;
		break;
	case 1:
		for (int i = 0; i < x_size; i++) {
			for (int j = y_size - 1; j >= 0; j--) {
				if (arr[ypos + i][xpos + y_size - j - 1] == 1 && st[pos].arr[j][i] == 1)
					return false;
				//printf("%2d", st[pos].arr[j][i]);
			}
			//printf("\n");
		}
		//printf("\n");
		return true;
		break;
	}
	return true;
}

void show() {
	printf("\nShow ARR\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
}

void dfs(int pos, int ypos, int xpos, int dir) {
	
	//붙이기전 arr 저장
	int copy_arr[40][40];
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M ; j++) 
			copy_arr[i][j] = arr[i][j];
	//붙이자 이제
	attach_sticker(pos, ypos, xpos, dir);
	//printf("\nDFS %d %d %d %d", pos, ypos, xpos, dir);
	//show();
	get_ans(pos,ypos,xpos,dir);


	//bool check = true;
	//for (int s = pos + 1; s < K; s++) {
	//		for (int i = 0; i < N; i++) {
	//			for (int j = 0; j < M; j++) {
	//				//if (arr[i][j] == 0 && check == true) {
	//				if(check == true){
	//					for (int k = 0; k < 4; k++) {
	//						if (can_att(s, i, j, k) == true && check == true) {
	//							check = false;
	//							dfs(s, i, j, k);
	//							/*for (int i = 0; i < N; i++)
	//								for (int j = 0; j < M; j++)
	//									arr[i][j] = copy_arr[i][j];*/
	//							disattach(s, i, j, k);
	//						}
	//					}
	//				}
	//			}
	//		}
	//}

	bool check = true;
	for (int s = pos + 1; s < K; s++) {
		for (int k = 0; k < 4; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					//if (arr[i][j] == 0 && check == true) {
					if (check == true) {
						if (can_att(s, i, j, k) == true && check == true) {
							check = false;
							dfs(s, i, j, k);
							/*for (int i = 0; i < N; i++)
								for (int j = 0; j < M; j++)
									arr[i][j] = copy_arr[i][j];*/
							disattach(s, i, j, k);
						}
					}
				}
			}
		}
	}

	//disattach(pos, ypos, xpos, dir);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = copy_arr[i][j];
}
int main() {
	scanf("%d %d %d", &N, &M, &K);

	int a, b;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &a, &b);
		st[i].y_size = a;
		st[i].x_size = b;
		st[i].dir = 0;
		for (int j = 0; j < a; j++) {
			for (int k = 0; k < b; k++) {
				scanf("%d", &st[i].arr[j][k]);
			}
		}
	}
	bool check = true;
	for (int s = 0; s < K; s++) {
		//if (check == true) {
		for (int k = 0; k < 4; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (check == true) {
						if (can_att(s, i, j, k) == true) {
							check = false;
							dfs(s, i, j, k);
							disattach(s, i, j, k);
						}
					}
				}
			}
		}
		//}
	}



	//for (int i = 0; i < 4; i++) {
	//	can_att(1, 0, 0, i);
	//	/*memset(arr, 0, sizeof(arr));
	//	attach_sticker(1, 0, 0, i);
	//	show();*/
	//}
	if (ans == -1e9)
		printf("0\n");
	else
		printf("%d\n", ans);
	return 0;
}