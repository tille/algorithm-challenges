#include <iostream>
#include <string>

using namespace std;

class CCipher{
  public:
  string decode(string cipherText, int shift){
    string ans = "";
    
    for( int i = 0; i < cipherText.size(); ++i ){
      int carry = (int(cipherText[i]) - int('A')) - shift;

      if( carry < 0 ) ans += char( int('Z') + carry + 1 );
      else ans += char( int(cipherText[i]) - shift );
    }
    
    return ans;
  }
};