#include <iostream>
#include <math.h>

using namespace std;

#define MAXN 27

double AB, AC, AD, BC, BD, CD;
double m[MAXN];

double det(){
  
  double a6  = m[12]*( m[18]*m[24] - m[23]*m[19] ) - m[13]*( m[17]*m[24] - m[21]*m[19] ) + m[14]*( m[17]*m[23] - m[21]*m[18] );
  double a7  = m[12]*( m[19]*m[25] - m[23]*m[20] ) - m[14]*( m[17]*m[25] - m[22]*m[20] ) + m[15]*( m[17]*m[23] - m[22]*m[19] );
  double a8  = m[12]*( m[18]*m[25] - m[23]*m[20] ) - m[13]*( m[17]*m[25] - m[22]*m[20] ) + m[15]*( m[17]*m[23] - m[22]*m[18] );
  double a9  = m[12]*( m[18]*m[24] - m[23]*m[19] ) - m[13]*( m[17]*m[24] - m[22]*m[19] ) + m[14]*( m[17]*m[23] - m[22]*m[18] );
  double a10 = m[13]*( m[19]*m[25] - m[20]*m[24] ) - m[14]*( m[18]*m[25] - m[23]*m[20] ) + m[15]*( m[18]*m[24] - m[23]*m[19] );
  double a11 = m[11]*( m[19]*m[25] - m[24]*m[20] ) - m[14]*( m[16]*m[25] - m[21]*m[20] ) + m[15]*( m[16]*m[24] - m[21]*m[19] );
  double a12 = m[11]*( m[18]*m[25] - m[23]*m[20] ) - m[13]*( m[16]*m[25] - m[21]*m[20] ) + m[15]*( m[16]*m[23] - m[21]*m[18] );
  double a13 = m[11]*( m[18]*m[24] - m[23]*m[19] ) - m[13]*( m[16]*m[24] - m[21]*m[19] ) + m[14]*( m[16]*m[23] - m[21]*m[18] );
  double a14 = m[12]*( m[19]*m[25] - m[24]*m[20] ) - m[14]*( m[17]*m[25] - m[22]*m[20] ) + m[15]*( m[17]*m[24] - m[22]*m[19] );
  double a15 = m[11]*( m[19]*m[25] - m[24]*m[20] ) - m[14]*( m[16]*m[25] - m[21]*m[20] ) + m[15]*( m[21]*m[19] - m[16]*m[24] );
  double a16 = m[11]*( m[17]*m[24] - m[22]*m[20] ) - m[12]*( m[16]*m[25] - m[21]*m[20] ) + m[15]*( m[16]*m[22] - m[21]*m[17] );
  double a17 = m[11]*( m[17]*m[24] - m[22]*m[19] ) - m[12]*( m[16]*m[24] - m[21]*m[19] ) + m[14]*( m[16]*m[22] - m[21]*m[17] );
  double a18 = m[12]*( m[18]*m[25] - m[22]*m[20] ) - m[13]*( m[17]*m[25] - m[22]*m[20] ) + m[15]*( m[17]*m[23] - m[22]*m[18] );
  double a19 = m[11]*( m[18]*m[25] - m[23]*m[20] ) - m[13]*( m[16]*m[25] - m[21]*m[20] ) + m[15]*( m[16]*m[23] - m[21]*m[18] );
  double a20 = m[11]*( m[17]*m[25] - m[22]*m[20] ) - m[12]*( m[16]*m[25] - m[21]*m[20] ) + m[15]*( m[16]*m[23] - m[21]*m[18] );
  double a21 = m[11]*( m[17]*m[23] - m[21]*m[18] ) - m[12]*( m[16]*m[23] - m[21]*m[18] ) + m[13]*( m[16]*m[22] - m[21]*m[17] );
  double a22 = m[12]*( m[18]*m[24] - m[23]*m[19] ) - m[13]*( m[17]*m[24] - m[22]*m[19] ) + m[14]*( m[17]*m[23] - m[22]*m[18] );
  double a23 = m[11]*( m[18]*m[24] - m[23]*m[19] ) - m[13]*( m[16]*m[24] - m[21]*m[19] ) + m[14]*( m[16]*m[23] - m[21]*m[18] );
  double a24 = m[13]*( m[19]*m[25] - m[24]*m[20] ) - m[14]*( m[18]*m[25] - m[23]*m[20] ) + m[15]*( m[18]*m[24] - m[23]*m[19] );
  double a25 = m[11]*( m[17]*m[23] - m[22]*m[18] ) - m[12]*( m[16]*m[23] - m[21]*m[18] ) + m[13]*( m[16]*m[22] - m[21]*m[17] );
  
  double a5  = m[6]*a22 - m[7]*a23 + m[8]*a24 - m[9]*a25;
  double a4  = m[6]*a18 - m[7]*a19 + m[8]*a20 - m[10]*a21;
  double a3  = m[6]*a14 - m[7]*a15 + m[9]*a16 - m[10]*a17;
  double a2  = m[6]*a10 - m[8]*a11 + m[9]*a12 - m[10]*a13;
  double a1  = m[7]*a6 - m[8]*a7 + m[9]*a8 - m[10]*a9;
  double a0  = m[1]*a1 - m[2]*a2 + m[3]*a3 - m[4]*a4 + m[5]*a5;
  return a0;
}

void tartaglia(){
  m[6] = m[11] = m[16] = m[21] = m[2] = m[3] = m[4] = m[5] = 1;
  m[1] = m[7] = m[13] = m[19] = m[25] = 0;
  m[8] = m[12] = AB;
  m[9] = m[17] = AC;
  m[22] = m[10] = AD;
  m[18] = m[14] = BC;
  m[15] = m[23] = BD;
  m[20] = m[24] = CD;
  cout << sqrt( det() / 288 ) << endl;
}

int main(){
  int t;
  cin >> t;
  while( t-- ){
    cin >> AB >> AC >> AD >> BC >> BD >> CD;
    tartaglia();
  }
  return 0;
}