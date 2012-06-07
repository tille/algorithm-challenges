#include <iostream>
#include <cctype>


using namespace std;

int main(){
	string ins;
	cin >> ins;
	int c=0;
	int ans=0;
	for(int i=0;i<ins.size();i++){
		if(isupper(ins[i]) && c){
			if(c%4)
				ans+=4-c%4;
			//cout << c << " " << ans << endl;
			c=1;
		}
		else
			c++;
	}

	cout << ans << endl;

	return 0;
}
