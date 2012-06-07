#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int y,x;
	cin>>y>>x;
	string mat [y];
	for (int i = 0; i < y; ++i)
		cin>>mat[i];
	vector <string> v;
	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < (int)mat[i].size(); ++j) {
			
			string s;
			if (i == 0 || mat[i-1][j]=='#'){
				for (int a = i; a < y; ++a) {
					if (mat[a][j]=='#')
					break;
					s += mat[a][j];
				}
				if ((int)s.size()>1)
				v.push_back(s);
			}
			string w;
			if (j == 0 || mat[i][j-1]=='#'){
				for (int a = j; a < x; ++a) {
					if (mat[i][a] == '#')
					break;
					w += mat[i][a];
				}
				if ((int)w.size()>1)
					v.push_back(w);
			}
		}
	}
	sort(v.begin(),v.end());
	cout<<v[0]<<endl;
}
