#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000002

int f[MAXN];

void build_failure_function(const string &pattern) {
  int m = pattern.size();
  f[0] = 0;

  for (int i = 1; i < m; ++i) {
    f[i] = f[i-1];
    while (f[i] > 0 && pattern[i] != pattern[f[i]])
      f[i] = f[f[i] -1];

    if (pattern[i] == pattern[f[i]])
      f[i]++;
  }
}

int main() {
  string s;
  while (cin >> s && s != ".") {
    build_failure_function(s);

    int lon = s.size();
    int ans = 1;
    while (f[lon-1] > 0 && f[lon-1] >= lon/2) {
      if (f[lon-1]*2 == lon) ans = s.size()/f[lon-1];
      lon = f[lon-1];
    }
    cout << ans << endl;
  }

  return 0;
}

// este problema tiene una solucion O(1) despues de hacer la tabla de kmp
// se encuentra el minimo periodo k del string s que es k = n - f[n-1]
// luego se verifica que k este un numero entero de veces en la cadena
// es decir: (n%k==0) ? n/k : 1

// la solucion actual verifica si el prefijo/sufijo mas largo de la cadena es menor 
// que la longitud del string divida 2, entonces: con ese prefijo no se puede formar la cadena
// si la cadena puede ser formada es decir tiene un prefijo/sufijo igual o mayor que la 
// mitad del string, entonces: si el prefijo es igual quiere decir que ans = n / prefijo.size
// mientras prefijo[i] > 0 y prefijo[i] sean iguales o mayores que i/2 se debe continuar verificando
// la solucion es la mayor de estos resultados.
