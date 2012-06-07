#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

char chess[9][9], token;
int B, W;

bool debug( int i , int j, char TALES ){
    if( i >= 0 && i <= 7 && j >= 0 && j<= 7 && chess[i][j] = TALES ) return true;
    else return false;
}

void peon( int type, int i, int j ){
    if( type == 0 && debug(i+1,j-1,'K') && debug(i+1,j+1,'K') ) W = 1;
    else if( type == 1 && debug(i-1,j-1,'k') && debug(i-1,j+1,'k') ) B = 1;
}

void torre( int type ){
    if( type == 0 && debug(i+1,j-1,'K') && debug(i+1,j+1,'K') ) W = 1;
    else if( type == 1 && debug(i-1,j-1,'k') && debug(i-1,j+1,'k') ) B = 1;
}

void alfil( int type ){
    if( type == 0 && debug(i+1,j-1,'K') && debug(i+1,j+1,'K') ) W = 1;
    else if( type == 1 && debug(i-1,j-1,'k') && debug(i-1,j+1,'k') ) B = 1;
}

void dama( int type ){
    if( type == 0 && debug(i+1,j-1,'K') && debug(i+1,j+1,'K') ) W = 1;
    else if( type == 1 && debug(i-1,j-1,'k') && debug(i-1,j+1,'k') ) B = 1;
}

void rey( int type ){

}

void caballo( int type ){
    if( type == 0 && debug(i+1,j-1,'K') && debug(i+1,j+1,'K') ) W = 1;
    else if( type == 1 && debug(i-1,j-1,'k') && debug(i-1,j+1,'k') ) B = 1;
}

void solve(){
    for( int i = 0; i < 8; ++i ){
        for( int j = 0; j < 8; ++j ){
            switch( chess[i][j] ){
                case 'p': peon(0,i,j); break;
                case 'P': peon(1,i,j); break;
                case 'n': caballo(0,i,j); break;
                case 'N': caballo(1,i,j); break;
                case 'b': alfil(0,i,j); break;
                case 'B': alfil(1,i,j); break;
                case 'r': torre(0,i,j); break;
                case 'R': torre(1,i,j); break;
                case 'q': dama(0,i,j); break;
                case 'Q': dama(1,i,j); break;
                case 'k': rey(0,i,j); break;
                case 'K': rey(1,i,j); break;
            }
        }
    }
}

int main(){
    int exit = 0;
    while( exit != 64 ){
        for( int i = 0; i < 8; ++i ){
            for( int j = 0; j < 8; j++ ){
                cin >> token;
                if( token == '.' ) exit++;
                chess[i][j] = token;
            }
        }
        if( exit != 64 ) solve();
    }
    return 0;
}
