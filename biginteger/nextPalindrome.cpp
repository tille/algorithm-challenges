#include <iostream>
#include <cstring>
using namespace std;
char s[2000001] ;
char cr[2000001];

int main (){
	int testcase;
	for ( scanf ( "%d" , &testcase )  ; testcase ; testcase -- ) {
		scanf ( "%s" , s );
		int low , high , N = strlen ( s ) ;
		strncpy (cr,s,N);
		cr[N] = '\0';


		if ( N%2 ) low = N/2 , high = N/2 ;
		else low = N/2 -1; high = N/2;

		bool greater = 0;
		while ( low >=0 && high <N ) {
			if ( s[low] != s[high] ){
				if ( s[low] > s[high] ){
                    s[high] = s[low];
					greater = 1;
				}else s[high] = s[low] ;
			}
			low-- , high++ ;
		}


		if ( strcmp(s,cr) > 0 ) cout << s << endl;
		else {
			if ( N%2 ) low = N/2 , high = N/2 ;
			else low = N/2-1 , high = N/2 ;
			while ( low >=0 && high <N ){

				if ( s[low] != s[high] ) throw 1;
				if ( s[low] != '9' ) {
					s[low] = s[high] = s[low] + 1;
					for ( int i=low + 1; i<high ; i++ ) s[i] = '0' ;
					greater =1;
					break ;
				}
				low -- , high ++ ;
			}

			if ( strcmp(s,cr) > 0 ) cout << s << endl;
			else{
				if ( s[0] == '9' ){
					cout << '1' ;
					for ( int i=0 ; i<N-1 ; i++ )cout << '0' ;
					cout <<'1' ;

				}
				else{
					cout << (char)(s[0]+1) ;
					for ( int i=0 ; i<N-2 ; i++ ) cout << '0' << endl;
					cout << (char)(s[0] + 1) ;
				}
				cout << endl;
			}
		}
	}
}
