#include<iostream>
#include<set>;

using namespace std;

set<int> s;

int main() {
	int arr[4] = { 1,2,3,3 };

	for (int i = 0; i < sizeof(arr) / 4; i++) {
		s.insert(arr[i]);
	}

	int tmp = 0;
	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++)
		tmp += *iter;

	printf("%d\n", tmp);
	return 0;
}