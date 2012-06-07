#include <iostream>

using namespace std;

int main(){
    int t, n, pd, pg, salir = 1, cases;
    cin >> cases;
    for( int t=1; t<= cases; ++t ){
        cin >> n >> pd >> pg;
        for( int i = 1; i <= n && salir; ++i ){
            double calc = ((i*130)/100)*pg;
            int calc2 = ((i*130)/100)*pg;
            double temp = (i/100)*pd;
            int temp2 = (i/100)*pd;
            if( calc == calc2 && temp == temp2 ) salir = 0;
        }
        if( salir ) cout << "Case #" << t << ": Broken";
        else cout << "Case #" << t << ": Possible";
    }

    return 0;
}
