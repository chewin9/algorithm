#include<iostream>

using namespace std;

void Npira(int a) {
	for (int i = 0; i <a; i++) {
		for (int j = 0; j < i; j++)
			printf(" ");
		for (int j = 0; j < (a - i) * 2 - 1; j++)
			printf("%d", (i+1)%10);

		printf("\n");
	}
}

int main() {

	int a;
	printf("input num: ");
	scanf("%d", &a);

	Npira(a);
	return 0;
}