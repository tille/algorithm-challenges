#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef pair<string,string> shrew;

vector<shrew> male;
vector<shrew> female;
vector<shrew> son;
map<string,vector<string> > result;

void solve(string s){
	for( int i = 0; i < male.size(); ++i ){
		for( int j = 0; j < female.size(); ++j ){
			string ans="";
			for( int k = 0; k < s.size(); ++k ){				
				ans = ans + "0";
				string father = male[i].second, mother = female[j].second;
				if( s[k] == 'R' && father[k] == '1' && mother[k] == '1' ) ans[k]='1';
				else if( s[k] == 'D' && (father[k] == '1' || mother[k] == '1' ) ) ans[k]='1';
			}
			result[ans].push_back(female[j].first + "-" + male[i].first);
		}
	}
}

int main(){
	string s,name,sex,c,grandson;
	while( cin >> s ){
		while( cin >> name && name!="***" ){
			cin  >> sex >> c;
			if( sex == "M" ) male.push_back( shrew(name,c) );
			else female.push_back( shrew(name,c) );
		}
		while(cin >> name && name!="***"){
			cin >> c;
			son.push_back( shrew(name,c) );
		}
		solve(s);
		for( int i = 0; i < son.size(); ++i ){
			string goal = son[i].second;
			vector<string> p = result[goal];
			
			sort(p.begin(), p.end());
			
			printf("%s by ",son[i].first.c_str());
			for( int j = 0; j < p.size(); ++j ){
				if( j > 0 ) printf(" or ");
				printf("%s",p[j].c_str());
			}
			puts("");
		}
	}
	return 0;
}