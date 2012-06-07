#include <iostream>
#include <cstring>

using namespace std;

bool isvowel(char c){
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return true;
	return false;
}


int main(){
	char line[200];
	cin.getline(line,101);

	int len=strlen(line);
	for(int i=0;i<len;i++){
		cout << line[i];
		if(isvowel(line[i]))
			i+=2;
	}
	cout << endl;


	return 0;
}
