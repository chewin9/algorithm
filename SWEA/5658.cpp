#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<set>

using namespace std;

int N, T, K;
char arr[32];
set<string, greater<string> > s;
string ans;
int answer;

void solve() {
	int cnt = N / 4;

	//char abc[10];
	string str;

	int tmp = 0;
	for (int i = 0; i <4; i++) {
		for (int j = 0; j < cnt; j++) {
			//abc[j] = arr[i*cnt + j];
			str.push_back(arr[i*cnt + j]);
		}
		s.insert(str);
		str.clear();
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < cnt+1; j++) {
			//abc[j] = arr[i*cnt + j];
			str.push_back(arr[i*cnt + j]);
		}
		s.insert(str);
		str.clear();
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 2; j < cnt+2; j++) {
			//abc[j] = arr[i*cnt + j];
			str.push_back(arr[i*cnt + j]);
		}
		s.insert(str);
		str.clear();
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 3; j < cnt+3; j++) {
			//abc[j] = arr[i*cnt + j];
			str.push_back(arr[i*cnt + j]);
		}
		s.insert(str);
		str.clear();
	}


	set<string>::iterator iter = s.begin();

	printf("Test\n");
	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << ' ';
	}
	printf("\n\n");

	iter = s.begin();

	for (int i = 0; i < K-1; i++)
		iter++;

	ans = *iter;
}

void get_answer() {
	int tmp = 0;
	for (int i = 0; i < N / 4; i++) {
		if ('A' <= ans.at(i) && ans.at(i) <= 'Z')
			tmp = ans.at(i) - 'A' + 10;
		else
			tmp = ans.at(i) - '0';

		answer += tmp * pow(16, N / 4 - 1 - i);

	}
}
void get_string() {
	int cnt = N / 4;
	string str;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < N / 4; j++) {
			str.push_back(arr[i*cnt + j]);
		}
		s.insert(str);
		str.clear();
	}
}
void get_arr() {
	char tmp = arr[N-1];
	for (int i = N-1; i > 0; i--)
		arr[i] = arr[i - 1];
	arr[0] = tmp;

	/*for (int i = 0; i < N; i++) {
		printf("%c", arr[i]);
	}
	printf("\n");*/
}
int main() {

	/*char asd = '9';

	printf("%d", asd-'0');*/

	freopen("sample_input.txt", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t < T + 1; t++) {
		s.clear();
		answer = 0;
		memset(arr, 0, sizeof(arr));
		scanf("%d %d", &N, &K);

		for (int i = 0; i < N; i++) {
			scanf(" %1c", &arr[i]);
		}
		

		for (int i = 0; i < N/4; i++) {
			get_string();
			get_arr();
		}
		
		set<string>::iterator iter = s.begin();
		/*for (iter = s.begin(); iter != s.end(); iter++)
			cout << *iter << ' ';

		printf("\n");*/
		iter = s.begin();
		for (int i = 0; i < K-1; i++)
			iter++;

		ans = *iter;
		get_answer();
		
		printf("#%d %d\n", t, answer);

	}



	return 0;
}