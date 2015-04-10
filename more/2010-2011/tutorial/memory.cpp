# define foreach (x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)

struct State {
  int b[3];

  // State(int a, int b, int c): a1(a), a2(b), a3(c){}
  int hash() const {
    return b[0] + 65*b[1] + 65*65*b[2];
  }

  bool operator < (const State &t) const {
    return hash() < t.hash();
  }
};

escoger k numeros >= 1 tal que su suma se t:
(t-1) combinado (k-1)

Escoger k numeros >= 0 tal que su suma sea t:
(t+k-1) combinado (k-1)

n combinado k = n-1 combinado k-1 + n-1 combinado k
