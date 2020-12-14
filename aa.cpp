// depar	 hub	dest
//"SEOUL"	"DAEGU"	"YEOSU"

#include<iostream>
#include<map>
#include<string.h>
#include<string>
#include<vector>
#include<set>

using namespace std;

multimap<string, string> mm;
map<string, string> m;

int main() {
	
	vector<vector<string>> roads;
	roads.push_back({ "ULSAN", "BUSAN" });
	roads.push_back({ "DAEJEON", "ULSAN" });
	roads.push_back({ "DAEJEON", "GWANGJU" });
	roads.push_back({ "SEOUL", "DAEJEON" });
	roads.push_back({ "SEOUL", "ULSAN" });
	roads.push_back({ "DAEJEON", "DAEGU" });
	roads.push_back({ "GWANGJU", "BUSAN" });
	roads.push_back({ "DAEGU", "GWANGJU" });
	roads.push_back({ "DAEGU", "BUSAN" });
	roads.push_back({ "ULSAN", "DAEGU" });
	roads.push_back({ "GWANGJU", "YEOSU" });
	roads.push_back({ "BUSAN", "YEOSU" });

	for (int i = 0; i < roads.size(); i++) {
		mm.insert({ roads.at(i).at(0), roads.at(i).at(1) });
	}

	int arr[10002][10002];
	set<string>s;
	multimap<string, string>::iterator iter;

	for (iter = mm.begin(); iter != mm.end(); iter++)
		s.insert(iter->first);

	int S, M, E;
	
	set<string>::iterator siter;
	int cnt = 0;
	for (siter = s.begin(); siter != s.end(); siter++) {
		if (*siter == "SEUOL")
			S = cnt;
		else if (*siter == "DAGUE")
			M = cnt;
		else if (*siter == "YEUSU")
			E = cnt;
		cnt++;
	}
	printf("%d %d %d", S, M, E);
	//multimap<string, string>::iterator iter;
	//for (iter = mm.lower_bound("ULSAN"); iter != mm.upper_bound("ULSAN"); iter++) {
	//	cout << iter->second << " ";
	//	//printf("%s  ", *iter->second);
	//}

	return 0;
}