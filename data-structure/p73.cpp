#include<iostream>

using namespace std;

void Convert(int num, int cha) {
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char d[100];
	int cnt = 0;

	if (num == 0)
		d[0] = 0;
	else {
		while (num) {
			d[cnt++] = dchar[num % cha];
			num = num / cha;
		}
	}

	for (int i = cnt - 1; i >= 0; i--)
		printf("%c", d[i]);
}


int main() {
	int num, cha;

	printf("input number ");
	scanf("%d", &num);
	printf("input conver ");
	scanf("%d", &cha);

	printf("Conver to %d\n", cha);
	Convert(num, cha);

	return 0;
}