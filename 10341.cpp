#include <bits/stdc++.h>
using namespace std;

const double E = .000000000001;

int p, q, r, s, t, u;

double com(double x) {
  return p * (1 / exp(x)) + q * sin(x) + r * cos(x) 
  + s * tan(x) + t * x * x + u;
}

int main() {
  while(cin >> p >> q >> r >> s >> t >> u) {
    double a = 0, b = 1, c;
    if(com(a) * com(b) > 0) {
      cout << "No solution\n";
      continue;
    }
    do {
      c = (a + b) / 2;
      if(com(c) * com(a) > 0) a = c;
      else b = c;
    } while(abs(b - a) >= E);
    cout << setprecision(4) << fixed;
    cout << (a + b) / 2 << '\n'; 
  }
  return 0;
}
