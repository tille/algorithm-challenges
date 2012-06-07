#include <iostream>
#include <cstring>

using namespace std;

int f(char sve, char fri){
	if(sve==fri) return 1;

	if(sve=='R' && fri=='S') return 2;
	if(sve=='P' && fri=='R') return 2;
	if(sve=='S' && fri=='P') return 2;

	return 0;
}



int main(){
	int r,n,score=0;
	string game;

	cin >> r;
	cin >> game;
	cin >> n;

	int acum[r][3];
	memset(acum,0,r*3*sizeof(acum[0][0]));

	for(int i=0;i<n;i++){
		string fri;
		cin >> fri;
		for(int j=0;j<r;j++){
			score+=f(game[j],fri[j]);
			switch(fri[j]){
			case 'S': acum[j][0]++; break;
			case 'R': acum[j][1]++; break;
			case 'P': acum[j][2]++; break;
			}
			//printf("sc:%d\n",score);
		}
	}
	/*
	for(int i=0;i<r;i++)
		printf("%d %d %d\n",acum[i][0],acum[i][1],acum[i][2]);
*/

	int possi=0;
	for(int i=0;i<r;i++){
		int m = 0;
		for(int j=0;j<3;j++){
			int sum = acum[i][j]*2+acum[i][(j+1)%3];
			if(sum>m){
				m=sum;
			}
		}
		possi+=m;
	}

	cout << score << endl;
	cout << possi << endl;

	return 0;
}
