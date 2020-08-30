#include<iostream>

using namespace std;



int T, N;
char U[3][3] = { 'w', };

int main() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%c", U[i][j]);
		}
	}
}