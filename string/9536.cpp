#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>

using namespace std;
typedef pair<string, string> pss;
set<pss> s;
string str;
int T;
vector<string> ans;

int main() {
	scanf("%d", &T);
	cin.ignore(1000, '\n');
	for (int t = 0; t < T; t++) {
		
		s.clear();
		ans.clear();
		str.clear();

		getline(cin, str);
		//cin.ignore(1000, '\n');
		string animal;
		while (1) {
			getline(cin, animal);
			//cin.ignore(1000, '\n');

			int size = animal.size();
			char tmp = animal.at(size - 1);
			if (tmp == '?')
				break;

			string a1, b1;
			int check = 0;
			for (int i = 0; i < size; i++) {
				if (animal.at(i) != ' ') {
					if (check == 0)
						a1.push_back(animal.at(i));
					else if (check == 2)
						b1.push_back(animal.at(i));
				}
				else
					check = check + 1;
			}
			s.insert({ b1,a1 });


		}

		set<pss>::iterator iter = s.begin();
	/*	for (iter = s.begin(); iter != s.end(); iter++) {
			cout << iter->first << " " << iter->second << endl;
		}*/
		
		str.push_back(' ');
		int size = str.size();
		vector<string>::iterator viter;

		for (int i = 0; i < size; i++) {
			string tmp;
			while (1) {
				if (str.at(i) != ' ') {
					tmp.push_back(str.at(i));
					i++;
				}
				else {
					//i++;
					break;
				}
			}
			bool check = false;
			for (iter = s.begin(); iter != s.end(); iter++) {
				if (iter->first == tmp) {
					check = true;
					break;
				}
			}

			if (check == false) {
				ans.push_back(tmp);
			}
		}

		for (int i = 0; i < ans.size(); i++) {
			cout << ans.at(i) << ' ';
		}
		printf("\n");

	}
	
	return 0;
}