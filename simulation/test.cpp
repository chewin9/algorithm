#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;

bool comp(string &s1, string &s2) {
	return s1 > s2;
}

struct my {
	bool operator () (const string &s1, const string &s2) const {
		if (s1.size() == s2.size()) {
			return s1 > s2;
		}
		else
			return s1.size() < s2.size();
	}
};

map<string, int> m;
typedef pair<string, int> psi;
set<string, greater<string> > s;
set<psi, greater<psi> > sp;
set<string, my> aa;

vector<string> v;
int main() {
	//freopen("sample_input.txt", "r", stdin);
	char c[5] = { 'a','b','c','d','e' };
	string str;
	str = "123";
	s.insert(str);
	s.insert("ABC");
	s.insert("ABC");
	s.insert("BCD");



	//sort(s.begin(), s.end(), comp);
	set<string>::iterator iter;
	/*for (iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << " ";*/


	aa.insert("ABC1");
	aa.insert("ABC2");
	aa.insert("BC");



	//sort(s.begin(), s.end(), comp);
	//set<string>::iterator iter;
	//set<string, my>::iterator iter;
	for (iter = aa.begin(); iter != aa.end(); iter++)
		cout << *iter << " ";

	iter = aa.begin();
	for (int i = 0; i < 2; i++) {
		iter++;
	}
	cout << *iter;

	sp.insert({ "A", 1 });
	sp.insert({ "B", 2 });
	sp.insert({ "C", 3 });

	set<psi>::iterator sp_iter;

	for (sp_iter = sp.begin(); sp_iter != sp.end(); sp_iter++) {
		psi tmp;
		tmp = *sp_iter;
		cout << tmp.first << " " << tmp.second << " ";
	}

	return 0;
}